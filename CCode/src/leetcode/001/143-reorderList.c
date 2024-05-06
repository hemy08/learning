#include "public.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define INSERT_LIST_NEXT(list, node) \
    (list)->next = node;\
    (node) = (node)->next;\
    (list) = (list)->next;

#define INSERT_LIST(list, node) \
    (list)->next = node;\
    (list) = (list)->next;\
    (list)->next = NULL;

//  从链表中间拆分为两个两边
void List_SpiltMiddle(struct ListNode* head, struct ListNode** list1, struct ListNode** list2)
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* tail = NULL;

    while ((slow != NULL) && (fast->next != NULL)) {
        tail = slow;
        slow = slow->next;
        fast = fast->next->next;
        if (fast == NULL) {
            break;
        }
    }

    *list1 = head;

    tail->next = NULL;
    *list2 = slow;
}

struct ListNode* List_Inverted(struct ListNode* head)
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

struct ListNode* List_Merged(struct ListNode* list1, struct ListNode* list2)
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

void reorderList(struct ListNode* head)
{
    struct ListNode *list1 = NULL;
    struct ListNode *list2 = NULL;

    if ((head == NULL) || (head->next == NULL)){
        return head;
    }

    // 第一步，拆分成两个链表，list1，list2
    List_SpiltMiddle(head, &list1, &list2);

    // 第二步， 翻转list2
    list2 = List_Inverted(list2);

    // 第三步，合并list1和list2
    head = List_Merged(list1, list2);
}