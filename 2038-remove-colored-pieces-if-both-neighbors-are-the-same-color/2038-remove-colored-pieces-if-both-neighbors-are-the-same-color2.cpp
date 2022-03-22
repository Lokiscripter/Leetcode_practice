//
// Created by loki on 2022/3/22.
//

#include "../common.h"

bool winnerOfGame(string colors) {
    if (colors.size() < 3){
        return false;
    }
    int n = colors.size();
    int a_count = 0;
    int b_count = 0;
    for (int i = 1; i < n-1; ++i) {
        if (colors[i] == 'A' && colors[i-1] == 'A' && colors[i+1] == 'A') a_count++;
        if (colors[i] == 'B' && colors[i-1] == 'B' && colors[i+1] == 'B') b_count++;
    }
    return a_count > b_count;
}