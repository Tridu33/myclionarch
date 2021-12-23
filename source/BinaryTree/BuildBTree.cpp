//Binary Search Tree
#include<iostream>
#include<cstdio>

using namespace std;

struct TreeNode{
    int data;
    TreeNode* leftChild;
    TreeNode* rightChild;
    TreeNode(int x): data(x),leftChild(NULL),rightChild(NULL){}
};

TreeNode* Insert(TreeNode* root,int x,int father){
    if(root==NULL){
        root = new TreeNode(x);
        cout<<father<<endl;
    }
    else if(x<root->data){
        root->leftChild = Insert(root->leftChild,x,root->data);
    }
    else if(x>root->data){
        root->rightChild = Insert(root->rightChild,x,root->data);
    }
    return root;
}

int main(){
    int N;
    int temp;
    TreeNode* root = NULL;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>temp;
        root = Insert(root,temp,-1);
    }
    return 0;
}