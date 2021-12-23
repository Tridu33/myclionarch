#include <iostream>
#include <vector>
#include <unistd.h>
//#if defined(_WIN32)
//    #define PAUSE "pause"
//#elif defined(unix) || defined(__unix__) || defined(__unix)
#define PAUSE "read -p 'Press Enter to continue...' var"
//#endif
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
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

    vector<int> vec = {6,2,3,4,5};
    // input by leecode or newcoder
    vec.shrink_to_fit();
    std::system(PAUSE);// 单独运行可执行文件有用，但是使用clion重定向的话没用，不使用重定向有用
    ListNode* head = CreateList(vec);
    while (head != nullptr) {
        cout << head->val << endl;
        head = head->next;
    }
    return 0;
}