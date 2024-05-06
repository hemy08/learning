/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 1008. 先序遍历构造二叉树
 * link: https://leetcode-cn.com/problems/construct-binary-search-tree-from-preorder-traversal/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00226060 on 2020/6/18.
 */

#include "public.h"

#define TREE_NODE_INIT(n) \
    (n)->val = 0;\
    (n)->left = NULL;\
    (n)->right = NULL;

void InsertNode(struct TreeNode *root, int value)
{
    // 左侧子树
    if (value < root->val) {
        if (root->left == NULL) {
            struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            if (node == NULL) {
                return;
            }
            TREE_NODE_INIT(node);
            node->val = value;
            root->left = node;
            return;
        } else {
            InsertNode(root->left, value);
        }
    } else {
        if (root->right == NULL) {
            struct TreeNode * node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            if (node == NULL) {
                return;
            }
            TREE_NODE_INIT(node);
            node->val = value;
            root->right = node;
            return;
        } else {
            InsertNode(root->right, value);
        }
    }
}

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize)
{
    struct TreeNode* root = NULL;
    int num = 0;

    if ((preorder == NULL) || (preorderSize == 0)) {
        return NULL;
    }

    root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (root == NULL) {
        return NULL;
    }
    TREE_NODE_INIT(root);
    root->val = preorder[0];
    num++;
    while (num < preorderSize) {
        InsertNode(root, preorder[num]);
        num++;
    }

    return root;
}

/*
void main()
{
    int s[100] = {8,5,1,7,10,12};
    struct TreeNode *root;

    root = bstFromPreorder(s,6);

    printf("end.");
}*/
