//
// Created by loki on 2022/3/13.
//

#include "../common.h"

// 题意里，utf-8是要循环判断的，因为data可能超过4个字节，即使前四个字节都符合，进入第五个字节要进入第二轮循环判断。
bool validUtf8(vector<int>& data) {
    int bitIndex = 0;//用于判断data首字节后一共有几个字节
    for(const int num : data) {
        if(bitIndex == 0) {
            if((num >> 5) == 0b110) bitIndex = 1;
            else if((num >> 4) == 0b1110) bitIndex = 2;
            else if((num >> 3) == 0b11110) bitIndex = 3;
            else if(num >> 7) return false;
        } else {
            if((num >> 6) != 0b10) return false;
            --bitIndex;
        }
    }
    return bitIndex == 0;
}