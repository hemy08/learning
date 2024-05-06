/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 225. 用队列实现栈
 * link: https://leetcode-cn.com/problems/implement-stack-using-queues/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/8/13.
 */

#include "public.h"

/*typedef struct {
    struct ListNode *head;
    struct ListNode *tail;
} MyStack;*/

/** Initialize your data structure here. */
MyStack* myStackCreate()
{
    MyStack *stack = (MyStack*)malloc(sizeof(MyStack));
    if (stack == NULL) {
        return NULL;
    }

    stack->head = NULL;
    stack->tail = NULL;

    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x)
{
    struct ListNode *tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (tmp == NULL) {
        return;
    }
    tmp->val = x;

    // 第一个节点
    if (obj->head == NULL) {
        tmp->next = NULL;
        obj->head = tmp;
        obj->tail = tmp;
        return;
    }

    // 倒着往前加，方便出栈，tail不变，head往前
    tmp->next = obj->head;
    obj->head = tmp;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj)
{
    struct ListNode *tmp = NULL;
    int val;

    // 没有节点
    if (obj->head == NULL) {
        return -1;
    }

    val = obj->head->val;
    // 只有一个节点
    if (obj->head == obj->tail) {
        free(obj->head);
        obj->head = NULL;
        obj->tail = NULL;
        return val;
    }

    // 出栈，入栈的时候是倒着存放的，所以这里出栈的时候，出head就可以
    tmp = obj->head->next;
    free(obj->head);
    obj->head = tmp;
    return val;
}

/** Get the top element. */
int myStackTop(const MyStack* obj)
{
    // 没有节点
    if (obj->head == NULL) {
        return -1;
    }

    return obj->head->val;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(const MyStack* obj)
{
    if (obj->head == NULL) {
        return true;
    }

    return false;
}

void myStackFree(MyStack* obj)
{
    struct ListNode *tmp = obj->head;
    while (obj->head != NULL) {
        tmp = obj->head->next;
        free(obj->head);
        obj->head = tmp;
    }
}


/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/