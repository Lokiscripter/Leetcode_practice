//
// Created by loki on 2022/4/7.
//

#include "../common.h"

bool rotateString(string s, string goal) {
    string str = s+s;
    return str.find(goal) != string::npos && s.length() == goal.length();
}