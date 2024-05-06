/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 369. 给单链表加一
 * link: https://leetcode-cn.com/problems/plus-one-linked-list/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00226060 on 2020/6/15.
 */

#include "public.h"

struct ListNode* plusOneLinkedList(struct ListNode* head){
    struct ListNode* stack[1000];
    int index = 0;
    struct ListNode* tmpHead = head;
    int i = 0;
    struct ListNode* tmp;
    int add = 1;
    struct ListNode* retHead;

    if (head == NULL) {
        return NULL;
    }

    while (head != NULL) {
        stack[++index] = head;
        head = head->next;
    }

    for (i = index; i > 0; i--) {
        tmp = stack[i];
        if ((tmp->val + add) <= 9) {
            tmp->val = tmp->val + add;
            break;
        } else {
            add = (tmp->val + add) / 10;
            tmp->val = (tmp->val + add) % 10;
        }
    }

    // 到了头结点还没找到不为9的数字
    if (i == 0) {
        retHead = (struct ListNode*)malloc(sizeof(struct ListNode));
        retHead->val = 1;
        retHead->next = tmpHead;
        return retHead;
    }

    return tmpHead;
}