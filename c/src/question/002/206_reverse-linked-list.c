/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 206. 反转链表
 * link: https://leetcode-cn.com/problems/reverse-linked-list/submissions/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/10/13.
 */

#include "public.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode invert = {0,NULL};
    struct ListNode* temp = head;

    while (temp != NULL) {
        struct ListNode* next = temp->next;
        temp->next = invert.next;
        invert.next = temp;
        temp = next;
    }

    return invert.next;
}