/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 270. 最接近的二叉搜索树值
 * link: https://leetcode-cn.com/problems/closest-binary-search-tree-value/
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

// 二叉搜索树的特点
int closestValue(struct TreeNode* root, double target)
{
    int left, right;
    if (root == NULL) {
        return 0;
    }

    // target 在左子节点
    printf("val %d \n", root->val);
    if (root->val > target) {
        // 左子节点为空，返回root
        if (root->left == NULL) {
            return root->val;
        }

        // 继续往左，找到第一个比target小的节点，返回值
        left = closestValue(root->left, target);
        if ((root->val - target) > (target - left)) {
            return left;
        }
    } else {
        if (root->right == NULL) {
            return root->val;
        }

        // 继续往右，找到第一个比target大的节点，返回值
        right = closestValue(root->right, target);
        if ((target - root->val) > (right - target)) {
            return right;
        }
    }

    return root->val;
}

// 遍历，记录每个节点与目标值的差值，找到相对较小的，记录差值以及当前的节点，返回差值最小的
// 当前节点比target大，则往左子节点找，比target小，则往右子节点找
int closestValue2(struct TreeNode* root, double target)
{
    if (root == NULL) {
        return -1;
    }

    double min = 0xffffffff;
    int minFind = root->val;
    double cur_min = 0;
    struct TreeNode* node = root;

    while (true) {
        if (node == NULL) {
            return minFind;
        }
        if (node->val < target) {
            cur_min = target - node->val;
            node = node->right;
        } else {
            cur_min = node->val - target;
            node = node->left;
        }

        if (cur_min < min) {
            minFind = node->val;
            min = cur_min;
        }
    }
}