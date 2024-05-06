//
// Created by z00579768 on 2024/3/8.
//

#ifndef LEETCODE_STACK_H
#define LEETCODE_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"

// 定义链表节点结构体
typedef struct Node {
    char data;
    struct Node* next;
} Node;

// 定义栈结构体
typedef struct Stack {
    Node* top;
} Stack;

Stack* StackCreate();
bool StackIsEmpty(Stack* stack);
void StackPush(Stack* stack, char value);
char StackPop(Stack* stack);
char StackPeek(Stack* stack);
void StackDestroy(Stack* stack);

#endif //LEETCODE_STACK_H
