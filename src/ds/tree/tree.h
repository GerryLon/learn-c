#ifndef _DS__TREE_H
#define _DS__TREE_H 1

#include "../../common/common.h"
#include "../ds.h"

typedef struct _treeNode {
    void* data;
    struct _treeNode* left;
    struct _treeNode* right;
} TreeNode;

int insertNode(TreeNode** root, fptrCompareData compare, void* data);

// traverse
int preOrderTraverse(const TreeNode* root, fptrDispayData display);
int inOrderTraverse(const TreeNode* root, fptrDispayData display);
int postOrderTraverse(const TreeNode* root, fptrDispayData display);
int destroyTree(TreeNode* root);
#endif // _DS__TREE_H
