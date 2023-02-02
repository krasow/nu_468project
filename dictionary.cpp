#include "hash.h"
void dict_cpu(std::vector<string> passwords, std::vector<string> dictionary){

    // stores the brute force word
    string brute;

    for (auto &pwd : passwords){
        cout << pwd << endl;
    //brute will clear due to the next password attempting to be cracked
    nextpassword:brute.clear();
        for (int i : boost::irange(1, MAX_LENGTH)) {
            for (auto &word : dictionary) {
                if (brute.compare(pwd)){
                    //cout << "cracked: " << brute << endl;
                    goto nextpassword;
                }
            }
        }
    }
}   
