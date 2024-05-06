/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description:
 * link:
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2021/9/30.
 */

#include "public.h"

void helperLeftOrder(struct TreeNode* root, int *data, int *index) {
    if (root == NULL) {
        data[(*index)++] = INT32_MAX;
        return;
    }
    helperLeftOrder(root->left, data, index);
    helperLeftOrder(root->right, data, index);
    data[(*index)++] = root->val;
}

void helperRightOrder(struct TreeNode* root, int *data, int *index) {
    if (root == NULL) {
        data[(*index)++] = INT32_MAX;
        return;
    }
    helperRightOrder(root->right, data, index);
    helperRightOrder(root->left, data, index);
    data[(*index)++] = root->val;
}

#define MAX_NODE_NUM  10000

bool isSymmetric(struct TreeNode* root){
    int left[MAX_NODE_NUM] = {0};
    int right[MAX_NODE_NUM] = {0};
    int len_left = 0;
    int len_right = 0;

    helperLeftOrder(root->left, left, &len_left);
    helperRightOrder(root->right, right, &len_right);

    if (len_left != len_right) {
        return false;
    }

    for (int i = 0; i < len_left; i++) {
        if (left[i] != right[i]) {
            return false;
        }
    }

    return true;
}