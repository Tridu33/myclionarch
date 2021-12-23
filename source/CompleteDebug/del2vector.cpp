/* 每隔两个删除约瑟夫环，链表版本和数组版本
 * */
#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* next;
    node(int _x):val(_x),next(nullptr){;}
};
int main(){
    int n;
    while(cin >> n){
        if(n<=1000){
            n = n;
        }else{
            n= 999;
        }
        node* head = new node(0),*p = head;
        for(int i =1;i<n;i++){
            p->next = new node(i);
            p = p->next;
        }
        p->next = head;// loop
        /*
         node* tmp = head->next;
         cout << head->val << ' ';
         while(tmp!= head){
             cout << tmp->val << ' ';
             tmp = tmp->next;
         }
        */
        node* cur = head;
        for(int i =1; i<n; i++){
            cur = cur->next;
            node* del = cur->next;
            //cout << "del: " << cur->next->val<< endl;
            cur->next = cur->next->next;
            delete del;
            cur = cur->next;
        }
        cout << cur->val << endl;
    }
    return 0;
}

/*


#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin >> n){
        if(n<=1000){
            n = n;
        }else{
            n= 999;
        }
        vector<int> arr(n,0);
        for(int i =0;i<n;i++){
            arr[i] = i;
        }
        int curindex = 0,startindex = 0,resNumber = n;
        while(resNumber>1){
            int counter = 0;
            while(counter <= 3){
                if(arr[curindex] != -1){
                    counter++;
                    if(counter == 3){
                        arr[curindex] = -1;
                        cout << "del index: " << curindex <<endl;
                        resNumber--;
                        break;
                    }
                    curindex = (curindex +  1)%n;
                }else{
                    curindex = (curindex +  1)%n;//skip -1
                }
            }
        }
        for(auto x : arr){
            if (x != -1){
                cout << "res : " << x << endl;
                break;
            }
        }
    }
    return 0;
}

 * */