/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 2. 两数相加
 * link: https://leetcode-cn.com/problems/add-two-numbers/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */
#include "public.h"

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    ListNode* L = (ListNode*)malloc(sizeof(ListNode));
    L->next = NULL;
    ListNode* p = L;
    int C = (l1->val + l2->val) / 10;
    L->val = (l1->val + l2->val) % 10;
    l1 = l1->next;
    l2 = l2->next;
    for (; l1 != NULL || l2 != NULL || C != 0;) //C为进位判断
    {
        int s1=0, s2 = 0;
        int sum;
        if (l1 != NULL)
        {
            s1 = l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            s2 = l2->val;
            l2 = l2->next;
        }
        sum = s1 + s2 + C;
        C = sum / 10;
        ListNode* s = (ListNode*)malloc(sizeof(ListNode));
        s->next = NULL;
        s->val = sum % 10;
        p->next = s;
        p = p->next;
    }
    return L;
}