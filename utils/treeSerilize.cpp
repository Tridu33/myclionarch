#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
#include "TreeNode.h"
#include "bits/stdc++.h"
using namespace std;
/*

题目描述
请实现2个函数，分别用来序列化和反序列化二叉树。

*/
class SolutionSerialize
{
public:
    char* Serialize(TreeNode *root) {
        if (root == nullptr)
            return nullptr;
        string *result = new string();
        SerializeCore(root, *result);
        return (char*)(*result).data();
    }
    void SerializeCore(TreeNode *root, string &result) {
        if (root == nullptr)
            result.append("$,");
        else
        {
            result.append(to_string(root->val).data()).append(",");
            SerializeCore(root->left, result);
            SerializeCore(root->right, result);
        }
    }
    TreeNode* Deserialize(char *str) {
        if (str == nullptr)
            return nullptr;
        TreeNode* root = nullptr;
        DeserializeCore(&str, &root);
        return root;
    }
    void DeserializeCore(char** str,TreeNode** root)
    {
        char* begin = *str;
        char* sperator = strchr(begin, ',');
        if (sperator == nullptr)
            return;

        int len = sperator - begin;
        char val[20] = { 0 };
        strncpy(val, begin, len);
        *str = sperator + 1;//str指针往后移动

        if (val[0] == '$')
            *root = nullptr;
        else
        {
            *root = new TreeNode(atoi(val));
            DeserializeCore(str, &(*root)->left);
            DeserializeCore(str, &(*root)->right);
        }
    }

    //分行打印
    void PrintFromTopToBottom2(TreeNode* root) {
        //vector<int> result;
        if (root == nullptr)
            return;// result;
        queue<TreeNode*> data;
        data.push(root);
        int toBePrinted = 1;
        int nextLevel = 0;
        while (!data.empty())
        {
            TreeNode* node = data.front();
            data.pop();
            toBePrinted--;
            //result.push_back(node->val);
            cout << node->val << " ";
            if (node->left != nullptr)
            {
                data.push(node->left);
                nextLevel++;
            }
            if (node->right != nullptr)
            {
                data.push(node->right);
                nextLevel++;
            }
            if (toBePrinted == 0)
            {
                toBePrinted = nextLevel;
                nextLevel = 0;
                cout << endl;
            }
        }
        return;// result;
    }
};

TreeNode *CreateBiTree(int *a, int n, int start)//按层序输入，结点为空时，输入'#'
{
    if (a[start] == '#')return nullptr;
    TreeNode* root = new TreeNode();//新建一个根结点
    root->val = a[start];//给根结点 root 的 成员变量 data、lchild、rchild 赋初值
    root->left = nullptr;
    root->right = nullptr;
    int lnode = 2 * start + 1;
    int rnode = 2 * start + 2;
    if (lnode > n - 1) root->left = nullptr;
    else root->left = CreateBiTree(a, n, lnode);
    if (rnode > n - 1) root->right = nullptr;
    else root->right = CreateBiTree(a, n, rnode);
    return root;
}
/*
        5

    2       8
1     3   6     9
#   11

TreeNode t1(5);
TreeNode t2(2); t1.left = &t2;
TreeNode t3(8); t1.right = &t3;
TreeNode t4(1); t2.left = &t4;
TreeNode t5(3); t2.right = &t5;
TreeNode t6(6); t3.left = &t6;
TreeNode t7(9); t3.right = &t7;
TreeNode t8(11); t4.right = &t8;
*/


class Solution {
private:
    int globalval = 0;
public:
    void inputfunction(){
        //
        cout << "重定向输入文件 in.txt ：" <<endl;
        return ;
    }
    void problem(){
        cout<< "code for problem here" << endl;
        return ;
    }
    void outputfunction(){
        //
        cout << "重定向输出文件 out.txt ：" <<endl;
        return ;
    }
};
int main(int argc, char *argv[])
{
    TreeNode *t0;
    int data[] = { 5, 2, 8, 1, 3, 6, 9, '#', 11 };
    t0 = CreateBiTree(data, sizeof(data) / sizeof(data[0]), 0);
    SolutionSerialize solution;
    char* result = solution.Serialize(t0);
    cout << result << endl;
    TreeNode *pRoot = solution.Deserialize(result);
    solution.PrintFromTopToBottom2(pRoot);
    // =====problerm
    Solution sol;
    return 0;
}