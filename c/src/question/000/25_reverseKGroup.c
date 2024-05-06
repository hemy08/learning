/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 25. K 个一组翻转链表
 * link: https://leetcode.cn/problems/reverse-nodes-in-k-group/description/?company_slug=tencent
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include "public.h"

struct ListNode* myReverseList(struct ListNode* head)
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

struct ListNode* getLastNode(struct ListNode* head, int node_num) {
    node_num--;
    while (node_num > 0) {
        head = head->next;
        node_num--;
        if (head == NULL) {
            break;
        }
    }
    return head;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode protect = {0,NULL};
    protect.next = head;
    struct ListNode* first_node = &protect;
    // 拆分链表，按照K长度拆分
    while (head != NULL) {
        struct ListNode* last_node = getLastNode(head, k);
        if (last_node == NULL) {
            break;
        }
        struct ListNode* next_head = last_node->next;
        last_node->next = NULL;
        //分组遍历
        first_node->next = myReverseList(head);
        head->next = next_head;
        first_node = head;
        head = next_head;
    }

    return protect.next;
}