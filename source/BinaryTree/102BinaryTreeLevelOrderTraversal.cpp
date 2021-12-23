
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> res;
        while(!q.empty()){//que.size() != 0  
            int size = q.size();
            vector<int> level;
            while(size --){
                TreeNode * cur = q.front();q.pop();
                if(cur == nullptr){
                    continue;
                }
                level.push_back(cur->val);
                q.push(cur->left);
                q.push(cur->right);
            }
            if(level.size()!= 0){
            //if(level.size()== 0){
            res.push_back(level);
            }  
        } 

        return res;
    }
};




//DFS

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root,res,0);
        return res;
    }
        
    void dfs(TreeNode * root,vector<vector<int>>& res,int level){
        if(!root){return;};
        /*
        Line 1034: Char 9: runtime error: reference binding to null pointer of type 'std::vector<int, std::allocator<int>>' (stl_vector.h)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior /usr/bin/../lib/gcc/x86_64-linux-gnu/9/../../../../include/c++/9/bits/stl_vector.h:1043:9
        */
        //if(level > res.size()){
        if(level >= res.size()){//等号不能少
        res.push_back(vector<int>());
        };
        res[level].push_back(root->val);
        dfs(root->left,res,level+1);
        dfs(root->right,res,level+1);
    }

};




















