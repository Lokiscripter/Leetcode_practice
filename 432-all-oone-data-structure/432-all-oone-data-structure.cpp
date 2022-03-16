//
// Created by loki on 2022/3/16.
//

#include "../common.h"

class AllOne {
public:
    set<pair<int, string>> s; // set是有序的
    unordered_map<string, int> m;
    AllOne() {

    }

    void inc(string key) {
        int count=m[key]++;
        if(count)
            s.erase({count, key});
        s.insert({m[key], key});
    }

    void dec(string key) {
        if(m[key]<=0) return;
        int count=m[key]--;
        s.erase({count, key});
        if(m[key])
            s.insert({m[key], key});
    }

    string getMaxKey() {
        if(s.empty()) return "";
        return s.rbegin()->second;
    }

    string getMinKey() {
        if(s.empty()) return "";
        return s.begin()->second;
    }
};