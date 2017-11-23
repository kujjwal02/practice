#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        ListNode** current = &result;
        int carry = 0;
        while(l1 && l2) {   
            *current = new ListNode((l1->val + l2->val + carry) % 10);
            carry = (l1->val + l2->val + carry) / 10;
//          if (!result)
//              result = current;
            current = &((*current)->next);
            l1 = l1->next;
            l2 = l2->next;
        }
        
        ListNode* remaining = (l1 ? l1 : l2);
        while(remaining) {
            *current = new ListNode((carry + remaining->val) % 10);
            carry = (carry + remaining->val) / 10;
            current = &((*current)->next);
            remaining = remaining->next;
        }

        if (carry > 0)
            *current = new ListNode(carry);

        return result;
    }
};
int main() {
    ListNode *l1, *l2;
    l1 = new ListNode(3);
    l1->next = new ListNode(7);
//  l1->next->next = new ListNode(3);
    l2 = new ListNode(9);
    l2->next = new ListNode(2);
//  l2->next->next = new ListNode(8);
    Solution solution;
    ListNode* res = solution.addTwoNumbers(l1, l2);
    while(res) {
        cout << res->val << '\n';
        res = res->next;
    }
    system("pause");
    return 0;
}
