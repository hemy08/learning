/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 19. 删除链表的倒数第N个节点
 * link: https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode *p,*q,*dev;
    dev=(struct ListNode*)malloc(sizeof(struct ListNode));
    dev->val=0;
    dev->next=head;//为了对付特殊情况，所以创建一个新的节点，该节点位于head之前
    p=dev;
    q=dev;
    int cnt=0;
    while(p){//双指针，等p->next执行n+2边的时候，q->next开始执行
        cnt++;
        p=p->next;
        if(cnt>n+1)
            q=q->next;
    }
    q->next=q->next->next;//删除倒数第n个节点
    return dev->next;//只能这样写，否则写“return head”的话有几组测试样例不能通过
}


// 快慢指针思想
struct ListNode* removeNthFromEndFastSlow(struct ListNode* head, int n)
{
    struct ListNode *fast,*slow;
    struct ListNode dev = {0,head};
    dev.val=0;
    dev.next=head;//为了对付特殊情况，所以创建一个新的节点，该节点位于head之前
    fast = &dev;
    slow = &dev;
    // 快指针先走n步
    while ((n != 0) && (fast->next != NULL)) {
        fast = fast->next;
        n--;
    }

    // 如果走n步后，快指针为空了，说明可能是删除头结点
    if (fast->next == NULL) {
        // n还没走完，指针到尾节点了，说明n比指针长度长
        if (n != 0) {
            return NULL;
        }
        // 删除的是头节点
        return head->next;
    }

    // 快慢指针同时走，找到倒数第n个
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;
    return dev.next;
}