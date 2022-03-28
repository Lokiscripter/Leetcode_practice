//
// Created by loki on 2022/3/28.
//

#include "../common.h"

bool hasAlternatingBits(int n) {
    long a = n ^ (n >> 1);
    return (a & (a + 1)) == 0;
}