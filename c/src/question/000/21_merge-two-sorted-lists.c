/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 21. 合并两个有序链表
 * link: https://leetcode-cn.com/problems/merge-two-sorted-lists/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

struct ListNode mr2ListHead = {0,NULL};

#define INSERT_LIST_NEXT(list,node) \
    list->next = node;\
    node = node->next;\
    list = list->next;

struct ListNode* mergeTwoLists21(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *listl1 = l1;
    struct ListNode *listl2 = l2;
    struct ListNode *tmplist = &mr2ListHead;

    mr2ListHead.next = NULL;
    
    // 遍历，插入
    while ((listl1 != NULL) && (listl2 != NULL)) {
        if (listl1->val < listl2->val) { // 插入l1            
            INSERT_LIST_NEXT(tmplist,listl1);
        } else if (listl1->val == listl2->val) { // 依次插入L1和L2
            INSERT_LIST_NEXT(tmplist,listl1);
            INSERT_LIST_NEXT(tmplist,listl2);
        } else { // 插入l2            
            INSERT_LIST_NEXT(tmplist,listl2);
        }
    }

    // 插入l1。L2为空
    while (listl1 != NULL) {
        INSERT_LIST_NEXT(tmplist,listl1);
    }

    // 插入l2，l1为空
    while (listl2 != NULL) {
        INSERT_LIST_NEXT(tmplist,listl2);
    }

    return mr2ListHead.next;
}

struct ListNode* mergeTwoLists2(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode list = {0};
    struct ListNode *tmp = &list;
    // 遍历，插入
    while ((l1 != NULL) && (l2 != NULL)) {
        if (l1->val <= l2->val) { // 插入l1
            tmp->next = l1;
            l1 = l1->next;
        } else { // 插入l2
            tmp->next = l2;
            l2 = l2->next;
        }
        tmp = tmp->next;
    }

    // 插入l1。L2为空
    while (l1 != NULL) {
        tmp->next = l1;
        l1 = l1->next;
        tmp = tmp->next;
    }

    // 插入l2，l1为空
    while (l2 != NULL) {
        tmp->next = l2;
        l2 = l2->next;
        tmp = tmp->next;
    }

    return list.next;
}