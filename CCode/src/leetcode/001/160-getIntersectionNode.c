/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description:
 * link:
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2021/6/4.
 */

#include "public.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if ((headA == NULL) || (headB == NULL)) {
        return NULL;
    }

    struct ListNode *nodeA = headA;
    while (nodeA != NULL) {
        struct ListNode *nodeB = headB;
        while (nodeB != NULL) {
            if (nodeA == nodeB) {
                return nodeA;
            }
            nodeB = nodeB->next;
        }
        nodeA = nodeA->next;
    }

    return NULL;
}


void TEST_getIntersectionNode_1() {
    // common
    struct ListNode node_3 = {5,NULL};
    struct ListNode node_2 = {4, &node_3};
    struct ListNode node_1 = {8, &node_2};

    // headA
    struct ListNode nodeA_1 = {1, &node_1};
    struct ListNode headA = {4, &nodeA_1};

    // headB
    struct ListNode nodeB_2 = {1, &node_1};
    struct ListNode nodeB_1 = {0, &nodeB_2};
    struct ListNode headB = {5, &nodeB_1};

    struct ListNode *result = getIntersectionNode(&headA, &headB);
    assert(result == &node_1);
    PRINT_CONSOLE(INFO, "success");
}

void TEST_getIntersectionNode_2() {
    // common
    struct ListNode node_2 = {4, NULL};
    struct ListNode node_1 = {2, &node_2};

    // headA
    struct ListNode headA = {3, &node_1};

    // headB
    struct ListNode nodeB_2 = {1, &node_1};
    struct ListNode nodeB_1 = {9, &nodeB_2};
    struct ListNode headB = {0, &nodeB_1};

    struct ListNode *result = getIntersectionNode(&headA, &headB);
    assert(result == &node_1);
    PRINT_CONSOLE(INFO, "success");
}

void TEST_getIntersectionNode_3() {
    // headA
    struct ListNode headA_1 = {5, NULL};
    struct ListNode headA = {1, &headA_1};

    // headB
    struct ListNode nodeB_2 = {4, NULL};
    struct ListNode nodeB_1 = {6, &nodeB_2};
    struct ListNode headB = {2, &nodeB_1};

    struct ListNode *result = getIntersectionNode(&headA, &headB);
    assert(result == NULL);
    PRINT_CONSOLE(INFO, "success");
}

void TEST_getIntersectionNode()
{
    PRINT_CONSOLE(INFO, "Begin");
    TEST_getIntersectionNode_1();
    TEST_getIntersectionNode_2();
    TEST_getIntersectionNode_3();
    PRINT_CONSOLE(INFO, "End");
}