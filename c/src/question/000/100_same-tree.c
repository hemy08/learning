/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 100. 相同的树
 * link: https://leetcode-cn.com/problems/same-tree/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/8/7.
 */

#include "public.h"

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if (p == NULL) {
        // 其中一个为NULL，返回false
        if (q != NULL) {
            return false;
        }

        // 都为NULL， 返回true
        return true;
    } else {
        if (q == NULL) {
            return false;
        }
    }

    if (p->val != q->val) {
        return false;
    }

    if (isSameTree(p->left, q->left)) {
        return isSameTree(p->right, q->right);
    }

    return false;
}