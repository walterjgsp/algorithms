// Problem Statement
//Given a parentheses string s containing only the characters '(' and ')'. A parentheses string is balanced if:
//
//* Any left parenthesis '(' must have a corresponding two consecutive right parenthesis '))'.
//* Left parenthesis '(' must go before the corresponding two consecutive right parenthesis '))'.
//In other words, we treat '(' as openning parenthesis and '))' as closing parenthesis.
//
//For example, "())", "())(())))" and "(())())))" are balanced, ")()", "()))" and "(()))" are not balanced.
//
//You can insert the characters '(' and ')' at any position of the string to balance it if needed.
//
//Return the minimum number of insertions needed to make s balanced.
#include "0175_minimum_insertions_balance_parentheses.hpp"
#include <bits/stdc++.h>

using namespace std;

int Solution::minInsertions(string s) {
    string newS, helper;

    for (auto c : s) {
        int lastIndex = newS.size() - 1;
        if (c == '(') {
            newS.push_back('{');
        } else if (!newS.empty() && newS[lastIndex] == ')') {
            newS[lastIndex] = '}';
        } else {
            newS.push_back(')');
        }
    }

    int result = 0;
    for (auto c: newS) {
        if (c == ')') {
            result++;
            c = '}';
        }
        if (!helper.empty() && c == '}' && helper.back() == '{') helper.pop_back();
        else helper.push_back(c);
    }

    while (!helper.empty()) {
        if (helper.back() == '{') {
            result += 2;
            helper.pop_back();
        } else {
            helper.pop_back();
            result++;
        }
    }

    return result;
}
