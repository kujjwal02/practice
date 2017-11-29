#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>
#include <unordered_set>

using namespace std;

static int some = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        //ensure l1.value < l2.value
        if (l1->val > l2->val)
            swap(l1, l2);

        ListNode* pos = l1;
        ListNode* temp;
        while(pos->next != nullptr && l2 != nullptr) {
            if (pos->next->val > l2->val) {
                temp = l2;
                l2 = temp->next;
                temp->next = pos->next;
                pos->next = temp;
                pos = pos->next;
            }
            else
                pos = pos->next;
        }

        if(pos->next == nullptr)
            pos->next = l2;
        return l1;
    }
};

void print(ListNode* root) {
    while(root) {
        cout << root->val << '\n';
        root = root->next;
    }
}

int main() {
    Solution solution;
//  ListNode* l1 = new ListNode(1);
//  l1->next = new ListNode(3);
//  l1->next->next = new ListNode(5);
//  l1->next->next->next = new ListNode(9);
//  ListNode* l2 = new ListNode(2);
//  l2->next = new ListNode(4);
//  l2->next->next = new ListNode(6);
//  l2->next->next->next = new ListNode(7);
//  l2->next->next->next->next = new ListNode(8);
//  l2->next->next->next->next->next = new ListNode(11);
//  l2->next->next->next->next->next->next = new ListNode(12);
    ListNode* l1 = new ListNode(-7);
    ListNode* l2 = new ListNode(-10);
    l2->next = new ListNode(-10);
    l2->next->next = new ListNode(-9);
    l2->next->next->next = new ListNode(-4);
    l2->next->next->next->next = new ListNode(1);
    l2->next->next->next->next->next = new ListNode(6);
    l2->next->next->next->next->next->next = new ListNode(6);
    print(solution.mergeTwoLists(l2, l1));
    system("pause");
    return 0;
}
