/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description:
 * link:
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2021/9/30.
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

// 注意入参的存储长度
bool helpBST(struct TreeNode* root, long lower, long upper)
{
    if (root == NULL) {
        return true;
    }

    if ((root->val >= upper) || (root->val <= lower)) {
        return false;
    }

    return helpBST(root->left, lower, root->val) && helpBST(root->right, root->val, upper);
}

bool isValidBST(struct TreeNode* root){
    return helpBST(root, INT64_MIN, INT64_MAX);
}

