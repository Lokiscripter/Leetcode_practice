//
// Created by loki on 2022/3/26.
//

#include "../common.h"

int calPoints(vector<string>& ops) {
    vector<int> record;
    for (int i = 0; i < ops.size(); ++i) {
        if (ops[i] == "+"){
            record.push_back(accumulate(record.end()-2,record.end(),0));
        }
        else if (ops[i] == "C"){
            record.pop_back();
        }
        else if (ops[i] == "D"){
            record.push_back(record.back()*2);
        }
        else{
            record.push_back(atoi(ops[i].c_str()));
        }
    }
    return accumulate(record.begin(),record.end(),0);
}