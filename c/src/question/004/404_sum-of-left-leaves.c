/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 404. 左叶子之和
 * link: https://leetcode-cn.com/problems/sum-of-left-leaves/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/9/19.
 */

#include "public.h"

int isLeafNode(struct TreeNode* node) {
    return ((node->left == NULL) && (node->right == NULL));
}

int sumOfLeftLeaves(struct TreeNode* root)
{
    int left = 0;

    if (root == NULL) {
        return 0;
    }

    // 左子节点为空，找右子节点
    if (root->left != NULL) {
        // 叶子节点是没有子节点的，判断左子节点的左侧是不是叶子节点
        if (isLeafNode(root->left)) {
            left += root->left->val;
        } else {
            left += sumOfLeftLeaves(root->left);
        }
    }

    // 找右子节点
    left += sumOfLeftLeaves(root->right);

    return left;
}