#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* CreateList(const vector<int> &vec) {
    if (vec.empty()) {
        return nullptr;
    }
    auto head = new ListNode(vec.at(0));
    ListNode* p = head;
    for (size_t i = 1; i < vec.size(); i++) {
        auto q = new ListNode(vec.at(i));
        p->next = q;
        p = p->next;
    }
    return head;
}

int main(int argc, char **argv) {
    vector<int> vec = {6,2,3,4,5};//input by leecode or newcoder
    vec.shrink_to_fit();
    ListNode* head = CreateList(vec);
    while (head != nullptr) {
        cout << head->val << endl;
        head = head->next;
    }
    return 0;
}