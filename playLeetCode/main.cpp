#include <iostream>
#include <string>
#include "src/longest-substring-without-repeating-characters.h"
#include "src/median-of-two-sorted-arrays.h"
#include "src/longest-palindromic-substring.h"
#include "src/add-two-numbers.h"
#include "src/valid-parentheses.h"
#include "src/longest-valid-parentheses.h"

using namespace std;


#define ADD_TEST(x)         \
do                          \
{                           \
    x::test();    \
} while(0)


int main(int argc, char** argv) {
    cout << "Hello World!" << endl;

    ADD_TEST(add_two_numbers);
    ADD_TEST(valid_parentheses);
    ADD_TEST(longest_substring_without_repeating_characters);
    ADD_TEST(median_of_two_sorted_arrays);
    ADD_TEST(longest_palindromic_substring);
    ADD_TEST(longest_valid_parentheses);






#ifdef _WIN32
    system("pause");
#endif
    return 0;
}
