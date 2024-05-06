/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 234. 回文链表
 * link: https://leetcode-cn.com/problems/palindrome-linked-list/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00226060 on 2020/7/13.
 */

#include "public.h"

bool isPalindromeForLinked(struct ListNode* head)
{
    struct ListNode* tmpHead = NULL;
    struct ListNode* loop = head;
    int count = 0;

    if (head == NULL) {
        return true;
    }

    while(loop != NULL) {
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = loop->val;
        node->next = tmpHead;
        tmpHead = node;
        loop = loop->next;
        count++;
    }

    loop = head;
    int midNum = (count + 1) / 2;
    while((tmpHead != NULL) && (loop != NULL) && (midNum != 0)) {
        if (tmpHead->val != loop->val) {
            return false;
        }

        tmpHead = tmpHead->next;
        loop = loop->next;
        midNum--;
    }

    return true;
}

// 双指针操作
bool isPalindromePoints(struct ListNode* head){
    struct ListNode* p=head;
    struct ListNode* q=head;
    //首先利用快慢指针找到链表中间节点
    while(q&&q->next!=NULL){
        p=p->next;
        q=q->next->next;
    }
    //将链表的后半段反转
    struct ListNode* cur,*temp=NULL;
    while(p){
        cur=p->next;
        p->next=temp;
        temp=p;
        p=cur;
    }
    // 将后半段反转的链表与前半段依次比较
    while(temp&&head){
        if(temp->val!=head->val)
            return false;
        temp=temp->next;head=head->next;
    }
    return true;
}
