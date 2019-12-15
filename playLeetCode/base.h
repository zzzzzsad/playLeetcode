#ifndef _PLAY_LEETCODE_BASE_H_
#define _PLAY_LEETCODE_BASE_H_


#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#define CHECK_EQ(x, y)                                          \
    {                                                           \
    std::string str_x = ToStr(x);                               \
    std::string str_y = ToStr(y);                               \
    if (str_x == str_y) {                                       \
        printf("[%s:%d] Check OK!\n",__FUNCTION__, __LINE__);   \
    } else {                                                    \
        printf("[%s:%d] Check Failed: %s == %s \n",             \
            __FUNCTION__, __LINE__, #x, #y);                    \
        printf("My value is %s\n", str_x.c_str());              \
    }                                                           \
    }


#define CHECK_GT(x, y)                                          \
    if ((x) <= (y)) {                                           \
        printf("[%s:%d] Check Failed: %s > %s \n",              \
            __FUNCTION__, __LINE__, #x, #y);                    \
        std::cout << "The value is " << x << ", " << y << std::endl;    \
    }

#define VAR_PRINT(x)                                            \
    do {                                                        \
        std::cout << #x << "=" << x << std::endl;               \
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

template<typename T>
std::string ToStr(T val) {
    std::ostringstream oss;
    oss << val;
    return oss.str();
}

#endif //_PLAY_LEETCODE_BASE_H_