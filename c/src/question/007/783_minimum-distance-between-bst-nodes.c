/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 783. 二叉搜索树节点最小距离
 * link: https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/10/12.
 */

#include "public.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/*
 * 首先要想到二叉搜索树的特点，对于所有node，node->left以及子树的值都比node值小，node->right以及子树的值都比node值大。
 * 对于node节点，满足题目条件的只有以下几种情况：
 *   node->left 或者 node->right 就是尾节点，后面再没有子树了，那么以node为根节点的二叉搜索树，满足题目条件的只有两个值，最最小即可；
 *       node->val - node->left->val
 *       node->right->val - node->val;
 *   node->left 不是尾节点，根据二叉树的特点，与node差值最小的值只能是left子树中最右端的值，即：node->left->right.....->right->val;
 *   同样的，对于右侧子节点也是一样，与node差值最小的应该是node->right->left.........->left->val
 */

// 二叉搜索树，左侧都比root小，右侧都比root大
// 找差值最小的，对root，就是找left->right或者right->left
int minDiffInBST(struct TreeNode* root)
{
    int tmp = INT_MAX;
    int left = INT_MAX;
    int right = INT_MAX;
    if (root == NULL) {
        return 0;
    }

    if (root->left != NULL) {
        struct TreeNode* node = root->left;
        while (node->right != NULL) {
            node = node->right;
        }
        left = root->val - node->val;
        tmp = minDiffInBST(root->left);
        if (tmp < left) {
            left = tmp;
        }
    }

    if (root->right != NULL) {
        struct TreeNode* node = root->right;
        while (node->left != NULL) {
            node = node->left;
        }
        right = node->val - root->val;
        tmp = minDiffInBST(root->right);
        if (tmp < right) {
            right = tmp;
        }
    }

    if (left > right) {
        return right;
    }

    return left;
}