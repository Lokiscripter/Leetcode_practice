//
// Created by loki on 2022/3/17.
//

#include "../common.h"

string longestWord(vector<string>& words){
    sort(words.begin(),words.end(),[](const string &a,const string &b){
             return a.size() != b.size() ? a.size() < b.size() : a > b;
         }
    );
    string ans;
    unordered_set<string> candidates={""};
    for (auto &word : words) {
        if (candidates.count(word.substr(0,word.length()-1)) != 0){
            candidates.emplace(word);
            ans = word;
        }
    }
    return ans;
}