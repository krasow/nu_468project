#ifndef HASH_KERNELS
#define HASH_KERNELS
#define ll long long
#define MAX_LENGTH 25
#define BLOCK_SIZE 32


// gpu cracking kernels
void dict_kernel(std::vector<string> passwords, std::vector<string> dictionary);
void crack_kernel(std::vector<string> passwords);


#endif