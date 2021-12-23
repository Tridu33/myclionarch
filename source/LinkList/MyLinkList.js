
class LinkNode {
    constructor(val, next) {
        this.val = val;
        this.next = next;
    }
}
// 在构造函数中定义实例属性，在原型中定义共享属性的模式，是目前使用最广泛的方式。
// 通常情况下，我们都会默认使用这种方式来定义引用类型变量。
var MyLinkedList = function() {
    let arg=arguments;
    let aru=arguments.length;
    if(aru == 0){
        this._size = 0;
        this._tail = null;
        this._head = null;
    }else if(aru == 1 && arg[0] instanceof Array){
        // 这里是多态参数重载的粗糙实现
        this._size = 0;
        this.arr2ll(arg[0])
    }
    return this;
};

var MyLinkedList = function() {
    this._size = 0;
    this._tail = null;
    this._head = null;
};


MyLinkedList.prototype.getNode = function(index) {
    if(index < 0 || index >= this._size) return null;
    // 创建虚拟头节点
    let cur = new LinkNode(0, this._head);
    // 0 -> head
    while(index-- >= 0) {
        cur = cur.next;
    }
    return cur;
};
MyLinkedList.prototype.get = function(index) {
    if(index < 0 || index >= this._size) return -1;
    // 获取当前节点
    return this.getNode(index).val;
};

MyLinkedList.prototype.addAtHead = function(val) {
    const node = new LinkNode(val, this._head);
    this._head = node;
    this._size++;
    if(!this._tail) {
        this._tail = node;
    }
};

MyLinkedList.prototype.addAtTail = function(val) {
    const node = new LinkNode(val, null);
    this._size++;
    if(this._tail) {
        this._tail.next = node;
        this._tail = node;
        return;
    }
    this._tail = node;
    this._head = node;
};

MyLinkedList.prototype.addAtIndex = function(index, val) {
    if(index > this._size) return;
    if(index <= 0) {
        this.addAtHead(val);
        return;
    }
    if(index === this._size) {
        this.addAtTail(val);
        return;
    }
    // 获取目标节点的上一个的节点
    const node = this.getNode(index - 1);
    node.next = new LinkNode(val, node.next);
    this._size++;
};

MyLinkedList.prototype.deleteAtIndex = function(index) {
    if(index < 0 || index >= this._size) return;
    if(index === 0) {
        this._head = this._head.next;
        this._size--;
        return;
    }
    // 获取目标节点的上一个的节点
    const node = this.getNode(index - 1);
    node.next = node.next.next;
    // 处理尾节点
    if(index === this._size - 1) {
        this._tail = node;
    }
    this._size--;
};

//----------------------------------------------

MyLinkedList.prototype.print = function (){
    let cur = this._head;
    for(let tmp = 1; tmp <= this._size; tmp++){
        process.stdout.write(cur.val.toString());
        process.stdout.write(' ');
        //console.log();
        cur = cur.next;
    }
    return null;
}

MyLinkedList.prototype.arr2ll = function (arr){
    for(let i in arr){
        this.addAtTail(arr[i]);
    }
    return this;
}

// 用法

// 参数未重载的写法
arr = [1,2,3,4];
let ll = new MyLinkedList();
ll.arr2ll(arr).print();// ll.print();

//重载的写法（自动检测有无参数决定是否根据arr生成链表、或者生成空链表）
let ll2 = new MyLinkedList(arr);
ll2.print();


// Your MyLinkedList object will be instantiated and called as such:
// var obj = new MyLinkedList()
// let index = 0;
// let val = 1,val2 = 2;
// var param_1 = obj.get(index)
// obj.addAtHead(val)
// obj.print()
// obj.addAtTail(val2)
// obj.print()
// obj.addAtIndex(index,val)
// obj.print()
// obj.deleteAtIndex(index)
// obj.print()




