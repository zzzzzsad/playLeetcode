#include "valid-parentheses.h"
#include <string>
#include <stack>
#include "../base.h"

using std::string;
using std::stack;

class Solution {
public:
    bool isValid(string s) {
        stack<int> sta;
        if (s.size() % 2 != 0) {
            return false;
        }
        for (int i = 0; i < s.size(); i++) {
            if (sta.empty()) {
                sta.push(s[i]);
            }
            else if (
                sta.top() == '(' && s[i] == ')' ||
                sta.top() == '[' && s[i] == ']' ||
                sta.top() == '{' && s[i] == '}') {
                sta.pop();
            }
            else {
                sta.push(s[i]);
            }
        }
        return sta.empty();
    }
};

int valid_parentheses::test() {
    Solution s;

    CHECK_EQ(s.isValid("()"), true);
    CHECK_EQ(s.isValid("()[]{}"), true);
    CHECK_EQ(s.isValid("(]"), false);
    CHECK_EQ(s.isValid("([)]"), false);
    return 0;
}
