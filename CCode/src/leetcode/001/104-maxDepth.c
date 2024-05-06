/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description:
 * link:
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2021/9/26.
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

void TreeForwardSearch104(const struct TreeNode *root, int dep, int *maxDep)
{
    if (dep > *maxDep) {
        *maxDep = dep;
    }

    if (root == NULL) {
        return;
    }

    TreeForwardSearch104(root->left, dep + 1, maxDep);
    TreeForwardSearch104(root->right, dep + 1, maxDep);
}

int maxDepth(struct TreeNode* root){
    int maxDep = 0;
    TreeForwardSearch104(root, 0, &maxDep);
    return maxDep;
}

int maxDepthWhile(struct TreeNode* root)
{
    if (root == NULL) {
        return 0;
    }

    int a = maxDepthWhile(root->left);
    int b = maxDepthWhile(root->right);

    if (a > b) {
        return a + 1;
    }
    return b + 1;
}