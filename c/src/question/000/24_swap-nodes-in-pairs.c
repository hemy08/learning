/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 24. 两两交换链表中的节点
 * link: https://leetcode-cn.com/problems/swap-nodes-in-pairs/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/10/13.
 */

#include "public.h"

#define INSERT_LIST_NEXT(list, node) \
    (list)->next = node;\
    (node) = (node)->next;\
    (list) = (list)->next;

#define INSERT_LIST(list, node) \
    (list)->next = node;\
    (list) = (list)->next;\
    (list)->next = NULL;

struct ListNode* mergeTwoListsForSwapPairs(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode head = {0,NULL};
    struct ListNode *temp = &head;

    // 遍历，插入
    while ((list1 != NULL) && (list2 != NULL)) {
        INSERT_LIST_NEXT(temp, list1);
        INSERT_LIST_NEXT(temp, list2);
    }

    // 插入l1。L2为空
    while (list1 != NULL) {
        INSERT_LIST_NEXT(temp, list1);
    }

    // 插入l2，l1为空
    while (list2 != NULL) {
        INSERT_LIST_NEXT(temp, list2);
    }

    return head.next;
}

struct ListNode* swapPairs(struct ListNode* head)
{
    if ((head == NULL) || (head->next == NULL)) {
        return head;
    }

    struct ListNode list1 = {0,NULL};
    struct ListNode list2 = {0,NULL};

    // 先拆成两个链表，然后重新合并
    struct ListNode* temp = head;
    struct ListNode* temp1 = &list1;
    struct ListNode* temp2 = &list2;
    int flag = 1;
    while (temp != NULL) {
        struct ListNode* next = temp->next;
        if (flag == 1) {
            INSERT_LIST(temp1, temp);
            flag++;
        } else {
            INSERT_LIST(temp2, temp);
            flag--;
        }
        temp = next;
    }

    return mergeTwoListsForSwapPairs(list2.next, list1.next);
}

// 递归
// 相当于两两一组，一直找到链表的尾巴，然后倒着交换
struct ListNode* swapPairsRecursive(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* newHead = head->next;
    head->next = swapPairs(newHead->next);
    newHead->next = head;
    return newHead;
}


// 迭代法
struct ListNode* swapPairsIteration(struct ListNode* head) {
    struct ListNode resHead = {0, head};
    struct ListNode* temp = &resHead;

    // 只有1个节点, 或者没有节点
    if ((head == NULL) || (head->next == NULL)) {
        return head;
    }

    // 只有两个节点
    if (head->next->next == NULL) {
        temp = head;
        head = head->next;
        head->next = temp;
        temp->next = NULL;
        return head;
    }

    while (temp->next != NULL && temp->next->next != NULL) {
        struct ListNode* node1 = temp->next;
        struct ListNode* node2 = temp->next->next;
        temp->next = node2;
        node1->next = node2->next;
        node2->next = node1;
        temp = node1;
    }

    return resHead.next;
}


/*
void main()
{
    struct ListNode node4 = {4,NULL};
    struct ListNode node3 = {3, &node4};
    struct ListNode node2 = {2, &node3};
    struct ListNode node1 = {1, &node2};

    struct ListNode *head = swapPairs(&node1);
}*/
