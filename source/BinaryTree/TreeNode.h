//
// Created by HUMAN on 2021/09/14.
//

#ifndef ARR2LINKLIST_CPP_TREENODE_H
#define ARR2LINKLIST_CPP_TREENODE_H

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() :
            val(-1), left(NULL), right(NULL) {}
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {}
};

#endif //ARR2LINKLIST_CPP_TREENODE_H
