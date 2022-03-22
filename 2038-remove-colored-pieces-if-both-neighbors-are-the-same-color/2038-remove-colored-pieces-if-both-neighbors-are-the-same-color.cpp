//
// Created by loki on 2022/3/22.
//

#include "../common.h"

bool winnerOfGame(string colors) {
    if (colors.size() < 3){
        return false;
    }
    int a_count = 0;
    int b_count = 0;
    stack<char> s;
    colors += 'C';
    for (int i = 0; i < colors.size(); ++i) {
        int count = 0;
        char last_color = 'C';
        while(!s.empty() && s.top() != colors[i]){
            count++;
            last_color = s.top();
            s.pop();
        }
        if (last_color == 'A' && count >= 3){
            a_count += count-2;
        }else if (last_color == 'B' && count >= 3){
            b_count += count-2;
        }
        s.push(colors[i]);
    }
    return a_count - 1 >= b_count;
}