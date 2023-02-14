#include "hash.h"

#include <chrono>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <cuda.h>

using namespace std::chrono;

// form https://www.google.com/search?client=firefox-b-1-d&q=store+file+into+array+in+c%2B%2B
void readFile(const char* filename, vector<string>& lines)
{
    lines.clear();
    ifstream file(filename);
    string s;
    while (getline(file, s))
        lines.push_back(s);
}

bool equal_passwords(string guess, string answer) {
    return (answer.compare(guess) == 0);
}


int main(){
    // stores the list of dictionary
    std::vector<string> dictionary; 
    readFile("wordlist.10000", dictionary);

    // stores the list of passwords wanting to crack
    std::vector<string> passwords;
    readFile("cracked.txt", passwords);

    auto start = high_resolution_clock::now();
    dict_cpu(passwords, dictionary);
    auto stop = high_resolution_clock::now();
    auto duration_dict_cpu = duration_cast<microseconds>(stop - start).count();

    start = high_resolution_clock::now();
    crack_cpu(passwords);
    stop = high_resolution_clock::now();
    auto duration_brute_force = duration_cast<microseconds>(stop - start).count();



    cout << duration_dict_cpu << duration_brute_force << endl;

    
    
    return 0;



}