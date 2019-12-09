#include "median-of-two-sorted-arrays.h"

#include <string>
#include <vector>
#include "../base.h"

using std::string;
using std::vector;
//
//class Solution {
//public:
//    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//        int total = nums1.size() + nums2.size();
//        if (total & 0x1) {
//            // 奇数
//            return find_Kth(nums1, nums2, (total + 1) / 2);
//        }
//        else {
//            return ((double)find_Kth(nums1, nums2, total / 2) +
//                    (double)find_Kth(nums1, nums2, total / 2 + 1)) / 2;
//        }
//
//
//    }
//private:
//    int min(int a, int b) {
//        if (a < b)
//            return a;
//        else
//            return b;
//    }
//
//    int find_Kth(const vector<int>& nums1, const vector<int>& nums2, int k) {
//        const int* p1 = nums1.begin();
//        const int* p2 = nums2.begin();
//        //int s1 = 0, s2 = 0;
//        int m = nums1.size();
//        int n = nums2.size();
//        CHECK_GT(m + n, k)
//
//        while (true) {
//            VAR_PRINT(m);
//            VAR_PRINT(n);
//            VAR_PRINT(k);
//            //VAR_PRINT(s1);
//            //VAR_PRINT(s2);
//            if (m == 0) {
//                //VAR_PRINT(nums2[s2 + k - 1]);
//                //return nums2[s2 + k - 1];
//                return p2[k - 1];
//            }
//            if (n == 0) {
//                //VAR_PRINT(nums1[s1 + k - 1]);
//                //return nums1[s1 + k - 1];
//                return p1[k - 1];
//            }
//            if (k == 1) {
//                //VAR_PRINT(min(nums1[s1], nums2[s2]));
//                //return min(nums1[s1], nums2[s2]);
//                return min(*p1, *p2);
//            }
//
//            //int index = k/2 - 1;
//            int index1 = min(k / 2 - 1, m - 1);
//            int index2 = min(k / 2 - 1, n - 1);
//
//            //if (nums1[s1 + index1] < nums2[s2 + index2]) {
//            if (p1[index1] < p2[index2]) {
//                // 两数组中间数比较，nums1的中间数比较小，排除 nums1[p1]~nums[p1+index1]这些元素
//                //s1 += index1 + 1;
//                p1 += index1 + 1;
//                m -= index1 + 1;
//                k -= index1 + 1;
//                VAR_PRINT(__LINE__);
//            }
//            //else if (nums1[s1 + index1] == nums2[s2 + index2]) {
//            //    // 两数组的中间数一样大，说明前面的都可以排除
//            //    k -= index1 + index2 + 2;
//            //    s1 += index1 + 1;
//            //    m -= index1 + 1;
//            //    s2 += index2 + 1;
//            //    n -= index2 + 1;
//            //    VAR_PRINT(__LINE__);
//
//            //}
//            else { // nums1[p1 + index1] > nums2[p2 + index2]
//                // 两数组中间数比较，nums2的中间数比较小，排除 nums2[p2]~nums2[p2+index2]这些元素
//                //s2 += index2 + 1;
//                p2 += index2 + 1;
//                n -= index2 + 1;
//                k -= index2 + 1;
//                VAR_PRINT(__LINE__);
//
//            }
//        }
//    }
//};
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        if (total & 0x1) {
            // 奇数
            return find_Kth(nums1, nums2, (total + 1) / 2);
        }
        else {
            return ((double)find_Kth(nums1, nums2, total / 2) +
                (double)find_Kth(nums1, nums2, total / 2 + 1)) / 2;
        }


    }
private:
    int min(int a, int b) {
        if (a < b)
            return a;
        else
            return b;
    }

    int find_Kth(const vector<int>& nums1, const vector<int>& nums2, int k) {
        auto p1 = nums1.begin();
        auto p2 = nums2.begin();
        int m = nums1.size();
        int n = nums2.size();

        while (true) {
            if (m == 0) {
                return p2[k - 1];
            }
            if (n == 0) {
                return p1[k - 1];
            }
            if (k == 1) {
                return min(*p1, *p2);
            }

            //int index1 = min(k / 2 - 1, m - 1);
            //int index2 = min(k / 2 - 1, n - 1);
            int index1 = min(k / 2, m);
            int index2 = min(k / 2, n);

            if (p1[index1-1] < p2[index2-1]) {
                // 两数组中间数比较，nums1的中间数比较小，排除 nums1[p1]~nums[p1+index1]这些元素
                p1 += index1;
                m -= index1;
                k -= index1;
            }
            else { // nums1[p1 + index1] > nums2[p2 + index2]
                // 两数组中间数比较，nums2的中间数比较小，排除 nums2[p2]~nums2[p2+index2]这些元素
                p2 += index2;
                n -= index2;
                k -= index2;
            }
        }
    }
};

int median_of_two_sorted_arrays::test() {
    Solution s;
    //CHECK_EQ(s.findMedianSortedArrays([1.0, 3.0], [2.0]), 2.0);
    vector<int> v1, v2;
    v1.push_back(1);
    v1.push_back(3);
    v2.push_back(2);

    CHECK_EQ(s.findMedianSortedArrays(v1, v2), 2);
    v1.clear();
    v1.push_back(1);
    v1.push_back(2);
    v2.clear();
    v2.push_back(3);
    v2.push_back(4);
    CHECK_EQ(s.findMedianSortedArrays(v1, v2), 2.5f);

    v1.clear();
    v1.push_back(0);
    v1.push_back(0);

    v2.clear();
    v2.push_back(0);
    v2.push_back(0);

    CHECK_EQ(s.findMedianSortedArrays(v1, v2), 0);


    v1.clear();
    v1.push_back(2);

    v2.clear();
    v2.push_back(1);
    v2.push_back(3);
    v2.push_back(4);

    CHECK_EQ(s.findMedianSortedArrays(v1, v2), 2.5);


    return 0;
}

