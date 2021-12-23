/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 
 struct TreeNode{
     int val;
     struct TreeNode * left;
     struct TreeNode * right;
 };
 
 
 struct LinkNode {
     int val;
     LinkNode* next;
 };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 the root of binary tree
     * @return int整型vector<vector<>>
     */
    void pre_dfs(vector<int> & vec,TreeNode* root){
        if(root == nullptr) return;
        vec.push_back(root->val);
        pre_dfs(vec,root->left);
        pre_dfs(vec,root->right);
        return;
    }
    void ino_dfs(vector<int> & vec,TreeNode* root){
        if(root == nullptr) return;
        ino_dfs(vec,root->left);
        vec.push_back(root->val);
        ino_dfs(vec,root->right);
        return;
    }
    void pos_dfs(vector<int> & vec,TreeNode* root){
        if(root == nullptr) return;
        pos_dfs(vec,root->left);
        pos_dfs(vec,root->right);
        vec.push_back(root->val);
        return;
    }
    vector<vector<int> > threeOrders(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> pre_vec,ino_vec,pos_vec;
        pre_dfs(pre_vec,root);
        ino_dfs(ino_vec,root);
        pos_dfs(pos_vec,root);
        res.push_back(pre_vec);
        res.push_back(ino_vec);
        res.push_back(pos_vec);
        return res;
    }
};