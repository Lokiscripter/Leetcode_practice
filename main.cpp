//
// Created by loki on 2022/3/5.
//

#include "common.h"

#include<stdio.h>

int f(int Int){
    if (Int==0)return Int;
    return(Int+f(Int-1));
};
int main(){
    int inT=9;
    cout<<"result="<<f(inT)<<'\n';
}