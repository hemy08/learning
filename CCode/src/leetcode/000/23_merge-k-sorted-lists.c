/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 23. 合并K个排序链表
 * link: https://leetcode-cn.com/problems/merge-k-sorted-lists/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/8/2.
 */

#include "public.h"

struct ListNode mrKListHead = {0,NULL};

#define INSERT_LIST_NEXT(list, node) \
    list->next = node;\
    node = node->next;\
    list = list->next;

struct ListNode* mergeTwoListsForK(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *listl1 = l1;
    struct ListNode *listl2 = l2;
    struct ListNode *tmplist = &mrKListHead;

    mrKListHead.next = NULL;

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

    return mrKListHead.next;
}

/*
 * 直接往第一个上合并,比较耗时
 * */
struct ListNode* mergeKLists1(struct ListNode** lists, int listsSize)
{
    if ((lists == NULL) || (listsSize == 0)) {
        return NULL;
    }

    struct ListNode *result = lists[0];
    for(int i = 1; i < listsSize;i++) {
        result = mergeTwoListsForK(result, lists[i]);
    }

    return result;
}

/*
 *  list[0],list[n]  list[1],list[n-1] ..... list[k]list[n-k]
 *  按照这个两两合并到list[0]~~~list[k]中，然后以k为新的表，再次合并
 *  直到所有的都合并完毕
 */
struct ListNode* mergeKLists2(struct ListNode** lists, int listsSize)
{
    if ((lists == NULL) || (listsSize == 0)) {
        return NULL;
    }

    if (listsSize == 1) {
        return lists[0];
    }

    int begin = 0;
    int end = listsSize - 1;
    while (end > 1) {
        printf("1 begin %d, end %d\n",begin,end);
        while (begin < end) {
            lists[begin] = mergeTwoListsForK(lists[begin], lists[end]);
            begin++;
            end--;
        }
        printf("2 begin %d, end %d\n",begin,end);
        // 奇数个，最后剩下了最中间的那个，下次以这个为end处理
        // 偶数个，begin > end, 最后合并的是最中间的俩，所以end = begin - 1;
        if (begin > end) {
            end = begin - 1;
        }
        begin = 0;
    }
    lists[0] = mergeTwoListsForK(lists[0], lists[1]);

    return lists[0];
}


/*
 *  list[0],list[n]  list[1],list[n-1] ..... list[k]list[n-k]
 *  按照这个两两合并到list[0]~~~list[k]中，然后以k为新的表，再次合并
 *  自己递归调用
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    if ((lists == NULL) || (listsSize == 0)) {
        return NULL;
    }

    if (listsSize == 1) {
        return lists[0];
    }

    // 循环，最后一个和第一个合并
    // 第一轮
    // 1-9,2-8,3-7,4-6,5  合并后在 1,2,3,4,5
    // 第二轮
    // 1-5,2-4,3 合并后在1,2,3
    // 第三轮
    // 1-3,2 合并后在1,2
    // 最后1,2合并

    int begin = 0;
    int end = listsSize - 1;

    while (begin < end) {
        lists[begin] = mergeTwoListsForK(lists[begin], lists[end]);
        begin++;
        end--;
    }

    if (begin > end) {
        end = begin - 1;
    }

    return mergeKLists(lists, end);
}