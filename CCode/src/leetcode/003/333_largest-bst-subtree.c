/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 333. 最大 BST 子树
 * link: https://leetcode-cn.com/problems/largest-bst-subtree/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00226060 on 2020/6/15.
 */

#include "public.h"

int g_max_cur;
bool largestBSTSubtreeCalc(struct TreeNode* root, int* maxNum, int* leftVal, int* rightVal){
    bool leftFlag = false;
    bool rightFlag = false;
    int leftVal1 = 0;
    int rightVal1 = 0;
    int leftVal2 = 0;
    int rightVal2 = 0;
    int leftMax = 0;
    int rightMax = 0;

    // 结束条件
    // 叶子节点
    if (root->left == NULL && root->right == NULL) {
        *leftVal = root->val;
        *rightVal = root->val;
        *maxNum = 1;
        if (g_max_cur < *maxNum) {
            g_max_cur = *maxNum;
        }
        return true;
    }

    if (root->left != NULL) {
        leftFlag = largestBSTSubtreeCalc(root->left, &leftMax, &leftVal1, &rightVal1);
    }

    if (root->right != NULL) {
        rightFlag = largestBSTSubtreeCalc(root->right, &rightMax, &leftVal2, &rightVal2);
    }

    // 本树是二叉树需满足以下条件：
    // 左子树是搜索二叉树，而且根节点大于左子树的最右节点
    // 右子树是搜索二叉树，而且根节点小于右子树的最左节点
    if (leftFlag == true && rightFlag == true) {
        if (root->val > rightVal1 && root->val < leftVal2) {
            *leftVal = leftVal1;
            *rightVal = rightVal2;
            *maxNum = leftMax + rightMax + 1;
            if (g_max_cur < *maxNum) {
                g_max_cur = *maxNum;
            }
            return true;
        } else {
            return false;
        }
    }

    if (root->left == NULL && rightFlag == true) {
        if (root->val < leftVal2) {
            *leftVal = root->val;
            *rightVal = rightVal2;
            *maxNum = rightMax + 1;
            if (g_max_cur < *maxNum) {
                g_max_cur = *maxNum;
            }
            return true;
        } else {
            return false;
        }
    }

    if (root->right == NULL && leftFlag == true) {
        if (root->val > rightVal1) {
            *leftVal = leftVal1;
            *rightVal = root->val;
            *maxNum = leftMax + 1;
            if (g_max_cur < *maxNum) {
                g_max_cur = *maxNum;
            }
            return true;
        } else {
            return false;
        }
    }

    return false;
}

int largestBSTSubtree(struct TreeNode* root){
    int leftVal = 0;
    int rightVal = 0;
    int maxNum = 0;
    if (root == NULL) {
        return 0;
    }

    g_max_cur = 0;
    largestBSTSubtreeCalc(root, &maxNum, &leftVal, &rightVal);
    return g_max_cur;
}

