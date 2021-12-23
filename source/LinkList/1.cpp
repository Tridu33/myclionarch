#include<bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:

public:
    ListNode*  reverselinkList(ListNode* head) {
        ListNode* p = head;
        return p;
    }
};

int main() {
    ListNode* head = new ListNode(-1);
    Solution sol;
    auto iobj = sol.reverselinkList(head);
    cout << typeid( iobj ).name() << endl;
    return 0;
}












