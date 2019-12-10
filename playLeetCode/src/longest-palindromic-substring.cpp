
#include "longest-palindromic-substring.h"
#include <string>
#include <vector>
#include "../base.h"
using std::string;


class oldSolution {
public:
    string longestPalindrome(string s) {

        int i_value = 0;
        int j_value = 0;
        int max_len = 0;

        for (int i = 0; i < s.size(); ++i) {
            for (int j = i + max_len; j < s.size(); ++j) {
                if (i == j) {
                    ++j; 
                }
                if (isPalindrom(s, i, j)) {
                    if (max_len < j - i + 1) {
                        max_len = j - i + 1;
                        i_value = i;
                        j_value = j;
                    }
                }
            }
        }

        return s.substr(i_value, j_value - i_value + 1);
    }

private:
    // 检查是 [i,j] 是否是回文结构
    bool isPalindrom(const string& s, int i, int j) {
        
        int len = j - i + 1; 

        for (int k = 0; k < len / 2; ++k) {
            if (s[i + k] != s[j - k]) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        std::vector<char> manaStr(2*s.size() + 2);
        manaStr[0] = '$';
        manaStr[1] = '#';
        for (int i = 0; i < s.size(); ++i) {
            manaStr[2 * i + 2] = s[i];
            manaStr[2 * i + 3] = '#';
        }
        std::vector<int> rd(manaStr.size(), 0);
        int pos = 0, mx = 0;
        int start = 0, max_len = 0;

        for (int i = 1; i < manaStr.size(); i++) {
            int len = 1;
            if (i < mx) {
                len = rd[2 * pos - i];
                if (len > mx - i) {
                    len = mx - i;
                }
            }
            while (true) {
                if (i + len >= manaStr.size())
                    break;
                if (i - len < 0)
                    break;
                if (manaStr[i - len] != manaStr[i + len])
                    break;
                len++;
            }
            rd[i] = len;
            if (mx < i + len) {
                mx = i + len;
                pos = i;
            }
            if (max_len < len - 1) {
                max_len = len - 1;
                start = (i - len) / 2;
            }
        }
        return s.substr(start, max_len);
    }
};



int longest_palindromic_substring::test() {
    
    Solution s;
    CHECK_EQ(s.longestPalindrome("babad"), "bab");
    CHECK_EQ(s.longestPalindrome("cbbd"), "bb");
    CHECK_EQ(s.longestPalindrome("ccc"), "ccc");
    CHECK_EQ(s.longestPalindrome("aaaa"), "aaaa");

    return 0;
}