#include "longest-substring-without-repeating-characters.h"

#include <string>
using std::string;




class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const char* pBegin = s.c_str();
        const char* pEnd = pBegin;
        int max_len = 0;
        while (pEnd < s.c_str() + s.size()) {
            const char* p = pBegin;
            for (; p < pEnd; p++) {
                if (*p == *pEnd) {
                    break;
                }
            }
            if (p == pEnd) {
                // 指针搜索到了结尾，说明该区间没重复
                int value = pEnd - pBegin + 1;
                if (value > max_len) {
                    max_len = value;
                }
                pEnd++;
            }
            else {
                // 没到结尾就出来了，说明有重复了
                pBegin = p + 1;
            }
        }
        return max_len;
    }
};









int longest_substring_without_repeating_characters::test() {

    Solution s;
    CHECK_EQ(s.lengthOfLongestSubstring(" "), 1);
    CHECK_EQ(s.lengthOfLongestSubstring("abcabcbb"), 3);
    CHECK_EQ(s.lengthOfLongestSubstring("bbbbb"), 1);
    CHECK_EQ(s.lengthOfLongestSubstring("pwwkew"), 3);


    return 0;
}
