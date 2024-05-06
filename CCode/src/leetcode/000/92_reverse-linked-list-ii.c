/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 92. 反转链表 II
 * link: https://leetcode-cn.com/problems/reverse-linked-list-ii/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00226060 on 2020/6/23.
 */

#include "public.h"

struct ListNode* reverseBetween(struct ListNode* head, int m, int n)
{
    struct ListNode* node = head;
    struct ListNode* node2 = head;
    int mid = 0;
    int count = 0;
    if (head == NULL) {
        return NULL;
    }

    while (node) {
        count++;
        // m之前的
        if (count < m) {
            node = node->next;
            continue;
        }

        if (n <= count) {
            break;
        }

        // 从m开始到n的，交换值
        int num = 0;
        node2 = node;
        while (node2) {
            if (num == (n - count)) {
                break;
            }
            node2 = node2->next;
            num++;
        }
        // printf("%d, %d\n", node->val, node2->val);
        int tmp = node2->val;
        node2->val = node->val;
        node->val = tmp;
        n--;
        node = node->next;
    }

    return head;
}