//
// Created by loki on 2022/3/28.
//

#include "../common.h"



class CQueue {
public:
    stack<int> s_in; // 负责入栈
    stack<int> s_out; // 负责出栈
    CQueue() {

    }

    void appendTail(int value) {
        s_in.push(value);
    }

    int deleteHead() {
        if (!s_out.empty()){ //如果out栈不为空，说明out已经接收过来自in的出栈元素，直接出栈
            int tmp_out = s_out.top();
            s_out.pop();
            return tmp_out;
        }else{ // 如果out为空，那么把in栈全部压到out栈，然后从out栈出栈，相当于out实际上是in的倒序，因此出栈的时候，出out就符合队列出去的顺序
            while (!s_in.empty()){
                int tmp_in = s_in.top();
                s_in.pop();
                s_out.push(tmp_in);
            }
            if (!s_out.empty()){
                int tmp_out = s_out.top();
                s_out.pop();
                return tmp_out;
            } else{
                return -1;
            }
        }
    }
};