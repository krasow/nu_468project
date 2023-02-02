#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <chrono>
#define ll long long

using namespace std;

void readFile(const char* filename, vector<string>& lines)
{
    lines.clear();
    ifstream file(filename);
    string s;
    while (getline(file, s))
        lines.push_back(s);
    cout << "Done Reading" << endl;
}


bool equal_passwords(string guess, string answer) {
    return (answer.compare(guess) == 0);
}

vector<string> next_prefixes(vector<string> prev) {
    string possible = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()`~,./?<>;:'[]{}\\|-_=+";
    vector<string> curr;

    for (auto& prefix : prev) {
        for (int i = 0; i < possible.length(); i++) {
            char c = possible[i];
            string new_prefix = prefix + c;
            curr.push_back(new_prefix);
        }
    }
    return curr;
}


void crack() {
    int flag = 1;
    int max_length = 25;
    map <int, vector<string> > prefixes;
    vector<string> empty_string;
    empty_string.push_back("");
    prefixes[0] = empty_string;

    vector<string> passwords;
    readFile("cracked.txt", passwords);

    // For each password
    for (auto& answer : passwords) {
        // For all possible lengths
        for (int length = 0; length <= max_length; length++) {
            // Look at all prefixes of that length
            for (auto& i : prefixes[length]) {
                // If the password is equal to that prefix, stop
                cout << i << endl;
                if (equal_passwords((string) i, answer)) {
                    flag = 0;
                    cout << i << endl;
                    break;
                }
            }
            // Stop if done
            if (!flag) {
                break;
            } else {
                // Otherwise generate the next set of prefixes to be used in the next iteration.
                if (length == 25) { break; }
                prefixes[length + 1] = next_prefixes(prefixes[length]);
            }
            cout << "Onto next set of prefixes" << endl;
        }
        if (flag == 0) {
            break;
        }
    }

    
}

int main () {
    auto start = chrono::high_resolution_clock::now();
    crack();
    auto stop = chrono::high_resolution_clock::now();
    auto duration_brute_force = chrono::duration_cast<chrono::microseconds>(stop - start).count();
    cout << duration_brute_force << endl;
    return 0;
}