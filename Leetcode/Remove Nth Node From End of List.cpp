#include <iostream>
#include <string>
#include <unordered_map>

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
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        ListNode* second = head;
        ListNode* temp;
        while (second && n) {
            second = second->next;
            --n;
        }
            

        if (n)
            return nullptr;

        if(!second) {
            temp = head;
            head = temp->next;
            delete temp;
            return head;
        }

        while(second->next != nullptr) {
            first = first->next;
            second = second->next;
        }

        if (first == head) {
            temp = head->next;
            head->next = temp->next;
            delete temp;
            return head;
        }

        temp = first->next;
        first->next = temp->next;
        delete temp;
        return head;
            
    }
};

void print(ListNode* head) {
    while(head) {
        cout << head->val << '\t';
        head = head->next;
    }
}

int main() {
    Solution solution;
    ListNode* test = new ListNode(1);
    test->next = new ListNode(2);
    print(solution.removeNthFromEnd(test, 1));
    system("pause");
    return 0;
}
