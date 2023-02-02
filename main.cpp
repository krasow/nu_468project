#include <chrono>
using namespace std::chrono;

// form https://www.google.com/search?client=firefox-b-1-d&q=store+file+into+array+in+c%2B%2B
void readFile(const char* filename, list<string>& lines)
{
    lines.clear();
    ifstream file(filename);
    string s;
    while (getline(file, s))
        lines.push_back(s);
}

int main(){
    // stores the list of dictionary
    std:vector<string> dictionary; 
    readFile("wordlist.10000", dictionary);

    // stores the list of passwords wanting to crack
    std::vector<string> passwords;
    readFile("passwords.100", passwords);

    auto start = high_resolution_clock::now();
    dict_cpu(passwords, dictionary);

    auto stop = high_resolution_clock::now();
    auto duration_dict_cpu = duration_cast<microseconds>(stop - start).count();
    
    cout << duration_dict_cpu << endl;





}