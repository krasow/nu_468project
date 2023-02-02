#include <fstream>
#include <string>
#include <list>
#include <vector>

#DEFINE MAX_LENGTH 25

using namespace std;

void dict_cpu(std::vector<string> passwords, std::vector<string> dictionary);
void readFile(const char* filename, list<string>& lines);