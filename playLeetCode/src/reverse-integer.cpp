#include "reverse-integer.h"
#include "../base.h"

class Solution {
public:
    int reverse(int x) {
        if (x < 0) {
            return (-1 * reverse(-1 * x));
        }
        if (x == 0x80000000) return 0;
        int result = 0;
        while (x != 0) {
            int tmp = x % 10;
            if (result > 214748364 || (result == 214748364 && tmp > 7))
                return 0;
            result = result * 10 + tmp;
            x /= 10;
        }

        return result;
    }
};


int reverse_interger::test() {
    Solution s;
    CHECK_EQ(s.reverse(123), 321);
    CHECK_EQ(s.reverse(-123), -321);
    CHECK_EQ(s.reverse(120), 21);
    CHECK_EQ(s.reverse(1534236469), 0)
    return 0;
}