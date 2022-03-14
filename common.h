//
// Created by loki on 2022/3/1.
//

#ifndef LEETCODE_PRACTICE_COMMON_H
#define LEETCODE_PRACTICE_COMMON_H

#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>

using namespace std;

string convert(string s, int numRows);

int addDigits(int num);

string nearestPalindromic(string n);

long long subArrayRanges(vector<int>& nums);

vector<int> goodDaysToRobBank(vector<int>& security, int time);

string convertToBase(int num,int BASE);

string convertToBase7(int num);

int minSwaps(vector<int>& nums);

vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries);

bool validUtf8(vector<int>& data);
#endif //LEETCODE_PRACTICE_COMMON_H
