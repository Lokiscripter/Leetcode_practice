//
// Created by loki on 2022/3/3.
//

#include "../common.h"

// https://leetcode-cn.com/problems/add-digits/
int addDigits(int num){
    if ( num == 0){
        return num;
    }
    return num % 9 == 0 ? 9 : num % 9;
}