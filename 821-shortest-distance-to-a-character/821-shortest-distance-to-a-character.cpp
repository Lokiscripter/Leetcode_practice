//
// Created by loki on 2022/4/19.
//

#include "../common.h"

// 解法1 ： 两次遍历，双指针
vector<int> shortestToChar(string s, char c) {
    vector<int> ans(s.length(),0);
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == c){
            ans[i] = 0;
        }else{
            int left = i;
            int right = i;
            while(left > 0 && s[left] != c){
                left--;
            }
            int left_index = s[left] == c ? left : INT_MAX;
            while(right < s.length()-1 && s[right] != c){
                right++;
            }
            int right_index = s[right] == c ? right : INT_MAX;
            ans[i] = min(abs(i-left_index), abs(i-right_index));
        }
    }
    return ans;
}

// 解法2：BFS
// 起始令ans[i] = -1，然后把所有c字符的下标入队，更新ans[i]=0，然后以这些下标作为起点跑BFS，通过ans[i]是否等于-1判断是否重复入队

vector<int> shortestToChar_bfs(string s, char c) {
    vector<int> ans(s.length(),-1);
    queue<int> q;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == c){
            ans[i] = 0;
            q.push(i);
        }
    }
    vector<int> dir = {-1,1};
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for (int di : dir) {
            int index = t + di;
            if (index >= 0 && index < s.length() && ans[index] == -1){
                ans[index] = ans[t] + 1;
                q.push(index);
            }
        }
    }
    return ans;
}
