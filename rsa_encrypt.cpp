#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#define ll long long


using namespace std;


vector<ll> to_num_arr(string plaintext) {
    vector<ll> answer;
    for (auto p : plaintext) {
        answer.push_back((int) p);
    }
    return answer;
}

vector<ll> encrypt_arr(vector<ll> nums, ll e, ll n) {
    vector<ll> answer;

    for (auto num : nums) {
        ll text = 1;
        for (ll i=0; i < e; i++) {
            text *= num;
            text %= n;
        }
        answer.push_back(text);
    }
    return answer;
}

vector<ll> decrypt(vector<ll> encrypted_arr, ll d, ll n) {
    vector<ll> decrypted;


    for (auto q : encrypted_arr) {
        ll answer = 1;
        for (ll i=0; i<d; i++) {
            answer *= q;
            answer %= n;
        }
        decrypted.push_back(answer);
    }

    return decrypted;
}


int main() {
    ll prime_one = 53;
    ll prime_two = 59;
    ll n = prime_one * prime_two;

    ll totient = (prime_one - 1) * (prime_two - 1);

    // TODO: Find a better way to pick these values
    ll e = 3;
    // ll k = 2;
    ll d = 503;

    string plaintext; 
    getline(cin, plaintext);
    vector<ll> encrypted = encrypt_arr(to_num_arr(plaintext), e, n);
    for (auto r : encrypted) {
        cout << r << " ";
    }
    cout << endl;
    cout << endl;

    vector<ll> decrypted = decrypt(encrypted, d, n);

    for (auto t : decrypted) {
        cout << t << " ";
    }
    cout << endl;
    cout << endl;

    // decrypt(encrypt(plaintext, d, n), d, n);
    return 0;
}


// ll lcm(ll value_one, ll value_two) {
//     return (value_one * value_two) / gcd(value_one, value_two);
// }


