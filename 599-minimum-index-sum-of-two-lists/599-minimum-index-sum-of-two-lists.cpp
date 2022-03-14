//
// Created by loki on 2022/3/14.
//

#include "../common.h"

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2){
    map<int,vector<string>> ans;
    unordered_map<string,int> m1;
    unordered_map<string,int> m2;
    for (int i = 0;i<list1.size();i++) {
        m1[list1[i]]=i;
    }
    for (int i = 0;i<list2.size();i++) {
        m2[list2[i]]=i;
    }
    int current_index = INT_MAX;
    for (auto &p1:m1) {
        string m1_s = p1.first;
        int m1_index = p1.second;
        if (m2.count(m1_s)!=0){
            int index = m2[m1_s] + m1_index;
            if (index > current_index){
                continue;
            }
            ans[index].push_back(m1_s);
            current_index = index;
        }
    }
    return ans.begin()->second;
}
