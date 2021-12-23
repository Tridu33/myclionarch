class MyLinkedList {
private:
    // 打印链表
    void printLinkedList() {
        LinkedNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
    int _size;
    LinkedNode* _dummyHead;
public:
    //Linked ListStructure
    struct LinkedNode{
        int val;
        LinkedNode *next;
        LinkedNode(int val):val(val),next(nullptr){}
    }
    /** Initialize your data structure here. */
    MyLinkedList() {
        _dummy = new LinkedNode(-1);
        _size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index > _size - 1 || index <0){return -1};//invalid
        LinkedNode *p = _dummy->next;
        while(index-- ){ // 如果--index 就会陷入死循环
            p = p->next;
        }
        return p->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        LinkedNode* newhead = new LinkedNode(val);
        newhead->next = _dummy->next;
        _dummy->next = newhead;
        _size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        LinkedNode* newtail = new LinkedNode(val);
        LinkedNode *cur = _dummy->next;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        cur->next = newtail;
        _size++;
    }
  
    // 在第index个节点之前插入一个新节点，例如index为0，那么新插入的节点为链表的新头节点。
    // 如果index 等于链表的长度，则说明是新插入的节点为链表的尾结点
    // 如果index大于链表的长度，则返回空  
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > _size){
            return;
        };//_size - 1 is wrong for add in tail situation
        LinkedNode *newnode = new LinkedNode(val);
        //LinkedNode *cur = _dummy->next;//wrong
        LinkedNode *cur = _dummy;
        while(index--){
            cur = cur->next;
        }; // 如果--index 就会陷入死循环
        newcode->next = cur->next;
        cur->next = newnode;
        _size++;
    }
    // 删除第index个节点，如果index 大于等于链表的长度，直接return，注意index是从0开始的
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= size || index <0){
            return;
        };
        LinkedNode *cur = _dummy;
        while(index--){
            cur = cur->next;
        }
        LinkedNode *tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;//local variabls局部变量退出作用域自动清楚，前面的cur也没有写呀。
        _size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */