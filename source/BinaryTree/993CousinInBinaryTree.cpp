//
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
 * 
 */
//bfs
//超时
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == nullptr) return false;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* xnode = nullptr;
        TreeNode* ynode = nullptr;
        TreeNode* xpnode = nullptr;
        TreeNode* ypnode = nullptr;
        while(q.size()!= 0){
            int size = q.size();
            while(size--){
                TreeNode* cur = q.front();
                q.pop();//综合了stackoverflow的一些类似问题，对于c++来说这么做的主要原因应该是exception的安全问题和性能的损耗问题
                
                if(cur->left != nullptr){
                    //默写错误q.push(cur);
                    q.push(cur->left);
                    if(cur->left->val == x){
                        xnode = cur->left;
                        xpnode = cur;
                    }
                    if(cur->left->val == y){
                        ynode = cur->left;
                        ypnode = cur;
                    }
                    
                }
                if(cur->right != nullptr){
                    //默写错误q.push(cur);
                    q.push(cur->right)
                    if(cur->right->val == x){
                        xnode = cur->right;
                        xpnode = cur;
                    }
                    if(cur->right->val == y){
                        ynode = cur->right;
                        ypnode = cur;
                    }
                    
                }
            }
        if(xnode == nullptr && ynode  == nullptr){
            continue;
        }else if(xnode != nullptr && ynode != nullptr){
            return xpnode != ypnode;
        }else{
            return false;
        }
        }

    return false;
    }
};


class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val == x || root->val == y)return false;
        queue<TreeNode*> treeQ;
        treeQ.push(root);
        while(int k = treeQ.size()){//赋值语句的返回值是所赋的值//b = a = 10;
            int count = 0;
            while(k--){
                TreeNode* curnode = treeQ.front();
                treeQ.pop();
                bool left = curnode->left && (curnode->left->val == x || curnode->left->val == y);
                bool right = curnode->right && (curnode->right->val == x || curnode->right->val == y);
                if(left && right)return false;
                if(left || right)count++;
                if(curnode->left)treeQ.push(curnode->left);
                if(curnode->right)treeQ.push(curnode->right);
            }
            if(count==2)return true;
            if(count==1)return false;
        }
        return false;
    }
};



while queue 不空：
    cur = queue.pop()
    for 节点 in cur的所有相邻节点：
        if 该节点有效且未访问过：
            queue.push(该节点)



作者：GoatKeeper
链接：https://leetcode-cn.com/problems/cousins-in-binary-tree/solution/bfs-gan-jue-bi-dfsgeng-rong-yi-li-jie-by-goatkeepe/

//dfs
class Solution {
public:
    TreeNode* p1 =nullptr;
    TreeNode * p2 = nullptr;
    int h1 = -1;
    int  h2 = -1;
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root,x,y,0);
        cout<<h1<<h2<<(p1 != p2)<<(h1 == h2)<<endl;
    return (p1 != p2) && (h1 == h2);
    }
    void dfs(TreeNode* root, int x,int y , int level){
        if(!root) return;
        if(root->left != nullptr && root->left->val == x){
            p1 = root;
            h1 = level;
        }
        if(root->right != nullptr && root->right->val == x){
            p1 = root;
            h1 = level;
        }
        if(root->left != nullptr && root->left->val == y){
            p2 = root;
            h2 = level;
        }
        //这里搞错了
        // if(root->right != nullptr && root->right->val == x){
        //     p2 = root;
        //     h2 = level;
        // }
        // if(root->left != nullptr && root->left->val == y){
        //     p1 = root;
        //     h1 = level;
        // }
        if(root->right != nullptr && root->right->val == y){
            p2 = root;
            h2 = level;
        }
        dfs(root->left,x,y,level + 1);
        dfs(root->right,x,y,level + 1);
    }
};
































*/

