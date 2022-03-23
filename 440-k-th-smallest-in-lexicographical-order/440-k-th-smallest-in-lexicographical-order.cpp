//
// Created by loki on 2022/3/23.
//

#include "../common.h"

typedef long long ll;

// prefix即为数字i,计算以数字 i 开头且不超过最大数字 n 的数字个数
ll get_count(ll prefix, ll n)
{
    ll cnt = 0;
    for (ll a = prefix, b = prefix + 1; a <= n; a *= 10, b *= 10) {
        cnt += min(n + 1, b) - a;
    }
    return cnt;
}

int findKthNumber(int n, int k)
{
    ll prefix=1;
    ll p=1;
    while(p<k){
        ll cnt=get_count(prefix,n);
        if(p+cnt > k){
            prefix *= 10;
            p++;
        }
        else if(p+cnt <= k){
            prefix++;
            p += cnt;
        }
    }
    return prefix;
}