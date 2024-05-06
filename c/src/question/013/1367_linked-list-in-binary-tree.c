/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 1367. 二叉树中的列表
 * link: https://leetcode-cn.com/problems/linked-list-in-binary-tree/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

bool findPath(struct ListNode *head, struct TreeNode *root)
{
    if (head == NULL) {
        // head为null，不管root是不是null，说明找到了匹配的路径
        return true;
    }

    // head没完，root已经没了，需要返回去继续找其他的路径
    if (root == NULL) {
        return false;
    }

    // head 和 root 都不是null,要么左侧子树连续相同，要么右侧子树连续相同
    if (head->val == root->val) {
        return (findPath(head->next, root->left) || findPath(head->next, root->right));
    }

    return false;
}

bool isSubPath(struct ListNode *head, struct TreeNode *root)
{
    if (head == NULL) {
        return true;
    }

    if (root == NULL) {
        return false;
    }

    // head和root的值相同，两侧都后移，先检查左侧子树，再检查右侧子树
    if (root->val == head->val) {
        // 第一个root和head相同，从左侧或者右侧找路径，找到了，直接返回
        if (findPath(head->next, root->left) || findPath(head->next, root->right)) {
            return true;
        }
    }

    // 不相同，root下移，先左侧后右侧,找下一个与head相同的头结点
    return (isSubPath(head, root->left) || isSubPath(head, root->right));
}