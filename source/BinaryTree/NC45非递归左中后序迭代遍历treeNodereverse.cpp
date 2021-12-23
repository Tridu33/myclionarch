/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 
 struct TreeNode{
     int val;
     struct TreeNode* left;
     struct TreeNode* right;
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
//         pre_dfs(pre_vec,root);
//         ino_dfs(ino_vec,root);
//         pos_dfs(pos_vec,root);
        // pre
        stack<TreeNode *> stk;
        if(root != nullptr) stk.push(root);
        while(!stk.empty()){
            TreeNode* curNode = stk.top();
            if(curNode != nullptr){
                stk.pop();//cancer duplicate memary
                if(curNode->right != nullptr) stk.push(curNode->right);
                if(curNode->left != nullptr) stk.push(curNode->left);
                stk.push(curNode);
                stk.push(nullptr);
            }else{
                stk.pop();// nullptr
                curNode = stk.top();
                stk.pop();
                pre_vec.push_back(curNode->val);// pre_vec
            };
        };
        // ino
        while(!stk.empty()){
            stk.pop();//stk.clear()
        }
        if(root != nullptr) stk.push(root);
        while(!stk.empty()){
            TreeNode* curNode = stk.top();
            if(curNode != nullptr){
                stk.pop();//cancer duplicate memary
                if(curNode->right != nullptr) stk.push(curNode->right);//r
                stk.push(curNode);
                stk.push(nullptr);
                if(curNode->left != nullptr) stk.push(curNode->left);
            }else{
                stk.pop();// nullptr
                curNode = stk.top();
                stk.pop();
                ino_vec.push_back(curNode->val);// ino_vec
            };
        };
        // pos
        while(!stk.empty()){
            stk.pop();//stk.clear()
        }
        if(root != nullptr) stk.push(root);
        while(!stk.empty()){
            TreeNode* curNode = stk.top();
            if(curNode != nullptr){
                stk.pop();//cancer duplicate memary
                stk.push(curNode);
                stk.push(nullptr);
                if(curNode->right != nullptr) stk.push(curNode->right);//r
                if(curNode->left != nullptr) stk.push(curNode->left);

            }else{
                stk.pop();// nullptr
                curNode = stk.top();
                stk.pop();
                pos_vec.push_back(curNode->val);// pos_vec
            };
        };
        //
        res.push_back(pre_vec);
        res.push_back(ino_vec);
        res.push_back(pos_vec);
        return res;
    }
};