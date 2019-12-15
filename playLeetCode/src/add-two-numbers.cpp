#include "add-two-numbers.h"

#include <vector>
#include "../base.h"
using std::vector;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) { }
};

std::ostream& operator<<(std::ostream& out, const ListNode& node) {
    return out << node.val;
}

std::ostream& operator<<(std::ostream& out, ListNode* pnode) {
    ListNode* ptemp = pnode;
    out << "[" << *ptemp;
    while (ptemp = ptemp->next){
        out << "->" << *ptemp;
    }
    out << "]";
    return out;
}

ListNode* LNCreate(const std::vector<int>& valList) {
    ListNode* phead = new ListNode(valList[0]);
    ListNode* ptail = phead;
    for (int i = 1; i < valList.size(); ++i) {
        ListNode* ptemp = new ListNode(valList[i]);
        ptail->next = ptemp;
        ptail = ptemp;
    }
    return phead;
}

template <typename Val>
inline ListNode* LNCreate(Val val) {
    return new ListNode(val);
}
 
template <typename Val, typename... Vals>
inline ListNode* LNCreate(Val val, Vals... vals) {
    ListNode* pnode = new ListNode(val);
    pnode->next = LNCreate(vals...);
    return pnode;
}

inline bool LNEqual(ListNode* p1, ListNode* p2) {
    while (p1 || p2) {
        if (!p1) return false;
        if (!p2) return false;
        if (p1->val != p2->val) return false;
        p1 = p1->next;
        p2 = p2->next;
    }
    return true;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int a1, a2, carry = 0;
        ListNode* pResult = NULL;
        ListNode* pTail = NULL;
        int sum, value;

        while (l1 || l2 || carry) {
            if (l1) {
                a1 = l1->val;
                l1 = l1->next;
            } else {
                a1 = 0;
            }
            if (l2) {
                a2 = l2->val;
                l2 = l2->next;
            } else {
                a2 = 0;
            }
            sum = a1 + a2 + carry;
            carry = sum / 10;
            value = sum % 10;

            ListNode* ptemp = new ListNode(value);
            if (pTail) {
                pTail->next = ptemp;
                pTail = ptemp;
            } else {
                pResult = ptemp;
                pTail = ptemp;
            }
        }
        return pResult;
    }
};

int add_two_numbers::test() {
    Solution s;
    CHECK_EQ(s.addTwoNumbers(LNCreate(2, 4, 3), LNCreate(5, 6, 4)),LNCreate(7, 0, 8));

    return 0;
}