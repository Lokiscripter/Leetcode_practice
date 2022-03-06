//
// Created by loki on 2022/3/6.
//

#include "common.h"

vector<int> goodDaysToRobBank(vector<int>& security, int time){
    int n = security.size();
    vector<int> a(n, 0); //初始化数组，判断递增递减
    for(int i=1; i<n; i++){
        if(security[i]>security[i-1])
            a[i] = 1; //表示当前元素比前者大
        else if(security[i]<security[i-1])
            a[i] = -1; //表示当前元素比前者小
        else
            a[i] = 0; //不增不减
    }

    vector<int> b(n, 0); //表示递增累计个数
    vector<int> c(n, 0); //表示递减累计个数
    for(int i=1; i<n; i++){
        b[i] = b[i-1] + (a[i] == 1 ? 1 : 0);
        c[i] = c[i-1] + (a[i] == -1 ? 1 : 0);
    }

    vector<int> ans;
    for(int i=time; i<n-time; i++){
        if(b[i]-b[i-time]==0 && c[i+time]-c[i]==0) //表示b[i-time]到b[i]之间不存在递增，c[i]至c[i+time]不存在递减
            ans.push_back(i);
    }
    return ans;
}