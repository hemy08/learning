/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 237. 删除链表中的节点
 * link: https://leetcode-cn.com/problems/delete-node-in-a-linked-list/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00226060 on 2020/6/15.
 */
#include "public.h"

void deleteNode(struct ListNode* node) {
    // 将next节点值赋值给当前节点，然后删除next节点，题目并没有说要地址删除
    node->val = node->next->val;
    node->next = node->next->next;
}