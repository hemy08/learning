/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 61. 旋转链表
 * link: https://leetcode-cn.com/problems/rotate-list/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/7/30.
 */

#include "public.h"

/*
 * 强行解题
 */
struct ListNode* rotateRight(struct ListNode* head, int k)
{
    struct ListNode* node = head;
    int curVal = 0;
    int nextVal = 0;
    int count = 0;

    if ((head == NULL) || (k  == 0)) {
        return head;
    }

    while (node != NULL) {
        node = node->next;
        count++;
    }
    k = k % count;

    while (k) {
        curVal = head->val;
        node = head;
        while(node->next != NULL) {
            nextVal = node->next->val;
            node->next->val = curVal;
            curVal = nextVal;
            node = node->next;
            count++;
        }
        head->val = curVal;
        k--;
    }

    return head;
}


/*
 * 1、成环形链表
 * 2、
 */
struct ListNode* rotateRight2(struct ListNode* head, int k)
{
    struct ListNode* node = head;
    int curVal = 0;
    int nextVal = 0;
    int count = 0;

    if ((head == NULL) || (head->next == NULL) || (k  == 0)) {
        return head;
    }

    // 计算节点
    while (node->next != NULL) {
        node = node->next;
        count++;
    }

    // 对K处理，让k < count
    int n = k % (count + 1);
    if (n == 0) {
        return head;
    }

    // 右移n次，相当于head后移count + 1 - n - 1个位置
    int num = count - n;
    struct ListNode* p = head;

    // 成环
    node->next = head;
    while (num > 0) {
        p = p->next;
        num--;
    }

    head = p->next;
    p->next = NULL;
    return head;
}