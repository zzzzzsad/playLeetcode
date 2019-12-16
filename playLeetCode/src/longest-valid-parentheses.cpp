#include "longest-valid-parentheses.h"

#include <string>
#include <iostream>
#include <stack>
#include "../base.h"

using std::string;
using std::stack;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> sta;
        int start = 0;
        int count;
        int max_count = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                sta.push(i);
            }
            else {
                if (sta.empty()) {
                    start = i + 1;
                }
                else {
                    sta.pop();
                    if (sta.empty()) {
                        count = i - start + 1;
                    }
                    else {
                        count = i - sta.top();
                    }
                    if (max_count < count)
                        max_count = count;
                }
            }
        }
        return max_count;
    }
};

int longest_valid_parentheses::test() {
    Solution s;

    CHECK_EQ(s.longestValidParentheses("(()"), 2);
    CHECK_EQ(s.longestValidParentheses(")()())"), 4);
    return 0;
}