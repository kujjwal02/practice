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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result{nullptr};
        if (lists.empty())
            return result;
        result = lists[0];
        for(auto i=1; i< lists.size(); ++i) {
            result = merge2Lists(result, lists[i]);
        }

        return result;

    }

    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;

        if (l1->val > l2->val)
            swap(l1, l2);

        auto pos = l1;
        ListNode* temp;
        while(pos->next != nullptr && l2 != nullptr) {
            if(pos->next->val > l2->val) {
                temp = l2;
                l2 = temp->next;
                temp->next = pos->next;
                pos->next = temp;
            }
            pos = pos->next;
        }

        if (pos->next == nullptr)
            pos->next = l2;

        return l1;
    }
};;

int main() {
    Solution solution;
    
    system("pause");
    return 0;
}
