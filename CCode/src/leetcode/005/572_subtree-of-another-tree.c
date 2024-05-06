/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 572. 另一个树的子树
 * link: https://leetcode-cn.com/problems/subtree-of-another-tree/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

bool checkTreeSame(struct TreeNode* s, struct TreeNode* t)
{
    // 都为空，返回true
    if ((s == NULL) && (t == NULL)) {
        return true;
    }

    // 有一个为空，返回false
    if ((s == NULL) || (t == NULL)) {
        return false;
    }

    // 值相同
    if (s->val != t->val) {
        return false;
    }

    // 左侧, 相同的时候，需要判断右侧是否相同。不同的时候，直接返回，找下一个t的根节点相同的节点。
    if (checkTreeSame(s->left, t->left) == false) {
        return false;
    }

    // 右侧, 相同的时候，标识找到了。不同的时候，需要找下一个t的根节点相同的s节点。
    if (checkTreeSame(s->right, t->right) == false) {
        return false;
    }

    // 左右侧都相同，返回true
    return true;
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t)
{
    // 根节点是否相同
    if (s == NULL) {
        return false;
    }

    if (checkTreeSame(s, t)) {
        return true;
    }

    if (isSubtree(s->left, t) || isSubtree(s->right, t)) {
        return true;
    }

    return false;
}