

//二叉树最后一行 最左边的值

#include "bits/stdc++.h"
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){};
};




class Solution{
private:
    //int globallevel = 0;//当前未知已经访问到的最大层数max level；假设不使用全局变量
    int res = -1;//level最大的层第一个中序遍历访问到的。

public:
    //recursive 
    int findTheLastLeftVal(TreeNode * root){
            int globallevel = 0;
            dfs(root,0,globallevel);//globallevel指访问完中节点 将会 下一次访问到的最大层数
            return res;
    }

    //左中右
    void dfs(TreeNode * root,int curlevel,int & globallevel){
        if(root == nullptr) return;//如果为空返回

        dfs(root->left, curlevel + 1,globallevel);//左中右

        if(curlevel > globallevel){//如果访问到最高层
            globallevel = curlevel;//更新当前全局访问最高层
            res = root->val;
        }

        dfs(root->right, curlevel + 1,globallevel);//level 最大层 且 此层 globallevel 第一次访问到的值-->更新res,globallevel;
        
    }





/*
public:
    //层次遍历
    int findTheLastLeftVal(TreeNode * root){
            int res;
            deque<TreeNode *> q;
            if(root == nullptr) return -1;
            res = root->val;
            //int level = 1;//初始层数
            q.push_back(root);
            while( !q.empty() ){            
                int size = q.size();//本层数量
                res = q.front()->val;//每次遍历一层更新最左边的值
                while(size--){
                    TreeNode* cur = q.front();//
                    q.pop_front();
                    if(cur-> left  != nullptr) q.push_back(cur->left);
                    if(cur-> right != nullptr) q.push_back(cur->right);
                }
                //level++;//层数
            }
            return res;
        }

*/



};

int main(){
    
    TreeNode * testNULL = nullptr;

    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);//
    root->right->right = new TreeNode(5);

    TreeNode * root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);

    Solution sol;
    cout<<sol.findTheLastLeftVal(testNULL)<<endl;
    cout<<sol.findTheLastLeftVal(root)<<endl;
    cout<<sol.findTheLastLeftVal(root2)<<endl;

    return 0;
}
























