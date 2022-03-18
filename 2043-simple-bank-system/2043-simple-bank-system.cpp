//
// Created by loki on 2022/3/18.
//

#include "../common.h"

class Bank {
public:
    Bank(vector<long long>& balance) {
        this->users = balance;
        this->n= balance.size();
    }

    bool transfer(int account1, int account2, long long money) {
        if ( account1 > n || account2 > n){
            return false;
        }
        if (users[account1-1] < money ){
            return false;
        }
        users[account1-1] -= money;
        users[account2-1] += money;
        return true;
    }

    bool deposit(int account, long long money) {
        if (account > n)
            return false;
        users[account-1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (account > n)
            return false;
        if (users[account-1] < money){
            return false;
        }
        users[account-1] -= money;
        return true;
    }

private:
    vector<long long> users;
    int n;
};