//递归解法：

class Solution {
public:
    void prebintree(TreeNode * root,vector<int> &res){//记得传地址而不是传值&res
        if(root == nullptr) {
            return;
        }
        res.push_back(root->val);
        prebintree(root->left,res);
        prebintree(root->right,res);
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector <int> res;
        prebintree(root,res);
        return res;
    }
};


//iter solution

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        vector <int> res;
        stack <TreeNode*> stk;
        stk.emplace(root);
        while(!stk.empty()){
            TreeNode* node = stk.top();
            res.emplace_back(node->val);
            stk.pop();
            if(node->right != nullptr) stk.emplace(node->right);
            if(node->left  != nullptr) stk.emplace(node->left);
        }
        return res;
    }
};
 

//Morris 遍历