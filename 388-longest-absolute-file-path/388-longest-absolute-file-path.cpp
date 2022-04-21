//
// Created by loki on 2022/4/21.
//

#include "../common.h"

// C++自己写分隔字符串函数
void SplitString(string& s, vector<string>& v, const string& c)
{
    string::size_type pos1,pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while (pos2!=string::npos){
        v.push_back(s.substr(pos1,pos2-pos1));
        pos1 = pos2 + c.size();
        pos2 = s.find(c,pos1);
    }
    if (pos1 != s.length())
        v.push_back(s.substr(pos1));
}

int lengthLongestPath(string input)
{
    int res=0;
    unordered_map<int,int> d;
    d[-1]=0;
    vector<string> lines;
    SplitString(input,lines,"\n");
    for (string line:lines) {
        int depth = count(line.begin(),line.end(),'\t');
        d[depth] = d[depth-1] + line.size() - depth;
        if (std::string::npos != line.find('.')) {
            res = max(res, d[depth] + depth);
        }
    }
    return res;
}