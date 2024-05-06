//
// Created by z00579768 on 2024/4/8.
//
#include <unordered_map>
#include <stack>
#include "string"
#include "leetcode.h"
#include <cassert>

using namespace std;

bool Solution::Twenty_IsValidParentheses(string s) {
    int n = s.size();
    if (n % 2 == 1) {
        return false;
    }

    unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
    };
    stack<char> stk;
    for (char ch: s) {
        if (pairs.count(ch)) {
            if (stk.empty() || stk.top() != pairs[ch]) {
                return false;
            }
            stk.pop();
        }
        else {
            stk.push(ch);
        }
    }
    return stk.empty();
}

void TestCase_ValidParentheses_001(){
    auto *quest = new Solution();

    assert(quest->Twenty_IsValidParentheses("()") == true);
    assert(quest->Twenty_IsValidParentheses("([])") == true);
    assert(quest->Twenty_IsValidParentheses("([{}])") == true);
    assert(quest->Twenty_IsValidParentheses("()[]{}") == true);
    assert(quest->Twenty_IsValidParentheses("([)]") == false);
    assert(quest->Twenty_IsValidParentheses("(]") == false);
    assert(quest->Twenty_IsValidParentheses("((()") == false);
    assert(quest->Twenty_IsValidParentheses("([{([])}])") == true);
}
