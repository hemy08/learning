//
// Created by z00579768 on 2024/3/8.
//


#include "stack.h"


// 初始化栈
Stack* StackCreate() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

// 判断栈是否为空
bool StackIsEmpty(Stack* stack) {
    return stack->top == NULL;
}

// 入栈操作
void StackPush(Stack* stack, char value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

// 出栈操作
char StackPop(Stack* stack) {
    if (StackIsEmpty(stack)) {
        return -1;
    }
    Node* temp = stack->top;
    char value = temp->data;
    stack->top = temp->next;
    free(temp);
    return value;
}

// 查看栈顶元素
char StackPeek(Stack* stack) {
    if (StackIsEmpty(stack)) {
        return -1;
    }
    return stack->top->data;
}

// 销毁栈，释放所有节点内存
void StackDestroy(Stack* stack) {
    Node* temp;
    while (!StackIsEmpty(stack)) {
        temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
    free(stack);
}
