
// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int res = 0;
    int maxlevel = 0;
    
    int findTheLastLeftVal(TreeNode* root) {
        dfs(root, 1);
        return res;
    }

    void dfs(TreeNode* root, int level){
        if(root == NULL) return;

        dfs(root->left, level + 1);

        if(level > maxlevel){
            maxlevel = level;
            res = root->val;
        }

        dfs(root->right, level + 1);
    }
};



int main(){
    
    TreeNode * testNULL = nullptr;

    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);//
    root->right->right = new TreeNode(5);

    Solution sol;
    cout<<sol.findTheLastLeftVal(testNULL)<<endl;
    cout<<sol.findTheLastLeftVal(root)<<endl;

    return 0;
}







