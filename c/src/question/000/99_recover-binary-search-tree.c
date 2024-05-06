/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 99. 恢复二叉搜索树
 * link: https://leetcode-cn.com/problems/recover-binary-search-tree/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/8/8.
 */

#include "public.h"

#define SWP_NODE_VAL(a,b) \
do {\
    int tmp = (a)->val; \
    (a)->val = (b)->val; \
    (b)->val = tmp;       \
} while(0);

void recoverTreeSub(struct TreeNode* root, struct TreeNode* node)
{
    if ((node == NULL) || (root == NULL)) {
        return;
    }

    // 左侧节点
    if (node->left != NULL) {
        SWP_NODE_VAL(root, node->left)
        SWP_NODE_VAL(node, node->left)
    }

    // 右侧节点
    if (node->right != NULL) {
        SWP_NODE_VAL(node->right, root)
        SWP_NODE_VAL(node->right, node)
    }

    // 左侧比root大的跟root值交换
    recoverTreeSub(root, node->left);
    // 右侧壁root小的跟root值交换
    recoverTreeSub(root, node->right);
}

void findTreeRootLeft(struct TreeNode* root, struct TreeNode* node)
{
    if ((node == NULL) || (root == NULL)) {
        return;
    }

    if (node->val > root->val) {
        SWP_NODE_VAL(node, root);
    }
    findTreeRootLeft(root, node->left);
    findTreeRootLeft(root, node->right);
}

void findTreeRootRight(struct TreeNode* root, struct TreeNode* node)
{
    if ((node == NULL) || (root == NULL)) {
        return;
    }

    if (node->val > root->val) {
        SWP_NODE_VAL(node, root);
    }
    findTreeRootLeft(root, node->left);
    findTreeRootLeft(root, node->right);
}

void recoverTree(struct TreeNode* root)
{

    if (root == NULL) {
        return;
    }

    // 左侧比root大的值，和root的值交换
    struct TreeNode* pCur = root->left;
    while (pCur != NULL) {
        if (pCur->val > root->val) {
            SWP_NODE_VAL(pCur, root);
        }
        pCur = pCur->left;
    }
    // 右侧比root小的值，和root的值交换
}
