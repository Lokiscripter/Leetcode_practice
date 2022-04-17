//
// Created by loki on 2022/4/17.
//

#include "../common.h"

string mostCommonWord(string paragraph, vector<string>& banned) {
    unordered_set<string> banned_s(banned.begin(),banned.end());
    string s;
    auto cmp = [](pair<string,int> p1,pair<string,int> p2){
        return p2.second > p1.second;
    };
    priority_queue<pair<string,int>,vector<pair<string,int>>, decltype(cmp)> q(cmp);
    unordered_map<string,int> m;
    for (int i = 0; i <= paragraph.size(); ++i) {
        if (isalpha(paragraph[i]) && i < paragraph.size()){
            s += tolower(paragraph[i]);
        }else if(s.size() > 0){
            if (!banned_s.count(s)){
                m[s]++;
            }
            s="";
        }
    }
    for (auto p : m) {
        q.push(make_pair(p.first,p.second));
    }
    return q.top().first;
}