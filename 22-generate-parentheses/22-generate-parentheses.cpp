//
// Created by loki on 2022/5/5.
//

#include "../common.h"

// open表示左括号的个数，close表示右边括号的个数
void backtrack(vector<string> &ans,string cur,int open,int close,int n){
    if (cur.length() == n*2){
        ans.emplace_back(cur);
        return;
    }
    if (open < n){
        cur.push_back('(');
        backtrack(ans,cur,open+1,close,n);
        cur.pop_back();
    }
    if (close < open){
        cur.push_back(')');
        backtrack(ans,cur,open,close+1,n);
        cur.pop_back();
    }
    return;
}

vector<string> generateParenthesis(int n){
    vector<string> ans;
    string current;
    backtrack(ans,current,0,0,n);
    return ans;
}