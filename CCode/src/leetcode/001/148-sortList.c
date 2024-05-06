#include "public.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define MAX_ARR_LEN 102400

int comp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

struct ListNode* sortList(struct ListNode* head){
    struct ListNode* s = head;
    int tmp[MAX_ARR_LEN] = {0};
    int count = 0, i = 0;

    while ((count != MAX_ARR_LEN) && (s != NULL)) {
        tmp[count] = s->val;
        s = s->next;
        count++;
    }

    qsort(tmp, count, sizeof(int), comp);

    s = head;
    while ((i <= count) && (s != NULL)) {
        s->val = tmp[i];
        s = s->next;
        i++;
    }

    return head;
}