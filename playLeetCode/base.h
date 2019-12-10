#ifndef _PLAY_LEETCODE_BASE_H_
#define _PLAY_LEETCODE_BASE_H_


#include <stdio.h>
#include <iostream>
#include <vector>

#define CHECK_EQ(x, y)                                          \
    if (x == y) {                                               \
        printf("[%s:%d] Check OK!\n",__FUNCTION__, __LINE__);   \
    } else {                                                    \
        printf("[%s:%d] Check Failed: %s == %s \n",             \
            __FUNCTION__, __LINE__, #x, #y);                    \
        std::cout << "My value is " << x << std::endl;          \
    }

#define CHECK_GT(x, y)                                          \
    if ((x) <= (y)) {                                           \
        printf("[%s:%d] Check Failed: %s > %s \n",              \
            __FUNCTION__, __LINE__, #x, #y);                    \
        std::cout << "The value is " << x << ", " << y << std::endl;    \
    }


#define VAR_PRINT(x)        \
    do {                    \
        std::cout << #x << "=" << x << std::endl;   \
    } while(0)


template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec) {
    std::cout << "[";
    for (auto v : vec) {
        std::cout << v << ",";
    }
    std::cout << "]";
    return out;
}

#endif //_PLAY_LEETCODE_BASE_H_