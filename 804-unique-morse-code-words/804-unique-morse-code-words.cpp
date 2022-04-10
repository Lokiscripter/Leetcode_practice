//
// Created by loki on 2022/4/10.
//

#include "../common.h"

int uniqueMorseRepresentations(vector<string>& words) {
    vector<string> morse_code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..",
                                 "--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    unordered_set<string> res;
    for (string &word :words) {
        string s;
        for (char c : word) {
            s += morse_code[c-'a'];
        }
        res.insert(s);
    }
    return res.size();
}