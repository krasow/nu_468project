#ifndef HASH
#define HASH

#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <boost/range/irange.hpp>

#define ll long long
#define MAX_LENGTH 25
#define BLOCK_SIZE 32

using namespace std;

// cpu cracking functions
void dict_cpu(std::vector<string> passwords, std::vector<string> dictionary);
void crack_cpu(std::vector<string> passwords);

// main common functions
void readFile(const char* filename, list<string>& lines);
bool equal_passwords(string guess, string answer);

#endif