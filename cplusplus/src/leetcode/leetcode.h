//
// Created by z00579768 on 2024/4/8.
//

#ifndef LEETCODE_CPP_QUESTIONS_H
#define LEETCODE_CPP_QUESTIONS_H

#include <vector>
#include "string"

using namespace std;

class Solution {
public:
    static bool Twenty_IsValidParentheses(string s);

};

class TwoSum {
public:
    static vector<int> Base(vector<int> &nums, int target);
    static vector<int> WithHash(vector<int> &nums, int target);
};

#endif //LEETCODE_CPP_QUESTIONS_H
