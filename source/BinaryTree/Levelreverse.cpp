/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 
 struct TreeNode{
     int val;
     struct Treenode* left;
     struct TreeNode* right;
 };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr){
             return res;
        };
        deque<TreeNode*> q;
        q.push_back(root);
        int level = 0;
        while(!q.empty()){
            int cursize = q.size();
            vector<int> curlevel;
            while(cursize--){
                TreeNode* cur = q.front();
                q.pop_front();
                curlevel.push_back(cur->val);
                if(cur->left != nullptr) q.push_back(cur->left);
                if(cur->right != nullptr) q.push_back(cur->right);
            };
            res.push_back(curlevel);
            level++;
        };
        return res;
    }
};