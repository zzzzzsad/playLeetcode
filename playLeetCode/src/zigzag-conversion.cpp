#include "zigzag-conversion.h"
#include <string>
#include <vector>
#include <list>
#include "../base.h"

using std::string;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }
        if (numRows >= s.size()) {
            return s;
        }
        std::vector<std::string> rows(numRows); 
        int section = numRows - 1;
        for (int i = 0; i < s.size(); ++i) {
            int index = i % section;
            if ((i / section) % 2 == 0) {
                rows[index].push_back(s[i]);
            } else {
                //index = numRows - index - 1;
                rows[numRows - index - 1].push_back(s[i]);
            }
        }
        for (int i = 1; i < numRows; ++i) {
            rows[0] += rows[i];
        }
        return rows[0];
    }
};

int zigzag_conversion::test() {
    Solution s;
    CHECK_EQ(s.convert("LEETCODEISHIRING", 3), "LCIRETOESIIGEDHN");
    return 0;
}