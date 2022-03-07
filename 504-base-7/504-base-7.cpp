//
// Created by loki on 2022/3/7.
//

#include "common.h"

// 10进制转n进制的模板

string convertToBase(int num,int BASE){
    if (num == 0)
        return "0";
    string ans;
    int record= abs(num);
    int k;
    while(record){
        k = record % BASE;
        record /= BASE;
        ans = to_string(k) + ans;
    }
    return num < 0 ? "-"+ans:ans;
}

string convertToBase7(int num){
    return convertToBase(num,7);
}