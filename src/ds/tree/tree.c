#include "../../ds/tree/tree.h"

// BST insert
int insertNode(TreeNode** root, fptrCompareData compare, void* data) {
    // create new node
    TreeNode* treeNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (treeNode == NULL) {
        printf("%s() malloc() err\n", __func__);
        return -1;
    }
    treeNode->data = data;
    treeNode->left = NULL;
    treeNode->right = NULL;

    // tree is empty
    if (*root == NULL) {
        *root = treeNode;
        return 0;
    }

    // save root temporarily
    TreeNode* tmpRoot = *root;

    while (1) {
        if (compare(data, (*root)->data) < 0) {
            if ((*root)->left == NULL) {
                (*root)->left = treeNode;
                break;
            } else {
                (*root) = (*root)->left;
            }
        } else {
            if ((*root)->right == NULL) {
                (*root)->right = treeNode;
                break;
            } else {
                (*root) = (*root)->right;
            }
        }
    }

    // reset root
    *root = tmpRoot;
    return 0;
}

int preOrderTraverse(const TreeNode* root, fptrDispayData display) {
    if (root != NULL) {
        display(root->data);
        preOrderTraverse(root->left, display);
        preOrderTraverse(root->right, display);
    }
    return 0;
}
