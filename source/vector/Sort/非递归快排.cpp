#include<bits/stdc++.h>
using namespace std;
int partition(vector<int> a,int l,int r){
    int s=l,e = r-1;
    int pivot = a[r];
    while(s<=e){
        while(s<=e && a[s] <= pivot) s--;
        while(s<=e && a[e] >= pivot) e--;
        if(s<=e) swap(a[s],a[e]);//开始不相等
    }
    swap(a[s],a[r]);
    return s;
}
void quicksort(vector<int> vec,int l,int r){
    int pivot_index = partition(vec,l,r);
    quicksort(vec,l,pivot_index-1);
    quicksort(vec,pivot_index+1,r);
}
int main(){
    quicksort(vec,0,vec.size());
    return 0;
}



// 非递归


void quickSortNoRecursive(vector<int> ,int l,int r){
    stack<int> stk;
    stk.push(l);
    stk.push(r);
    while(!stk.empty()){
        if(l > r);
    }
}




















