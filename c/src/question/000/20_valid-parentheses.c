/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 20. 有效的括号
 * link: https://leetcode-cn.com/problems/valid-parentheses/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/*
 * 数组处理出入栈一
 */
#define CHECK_LEFT_STR_MATCH(buf,left,index)  \
    if (index == 0) {\
        return false;\
    }\
    index--;\
    if (buf[index] == *left) {\
        buf[index] = '\0';\
        continue;\
    } else {\
        return false;\
    }


bool isValid20(char * s)
{
    unsigned int strLen = 0;
    unsigned int i = 0;
    unsigned int count = 0;
    char *pLeft = NULL;

    strLen = strlen(s);
    // 必须是偶数
    if ((strLen%2) != 0) {
        return false;
    }

    pLeft = (char*)malloc(strLen);
    if (pLeft == NULL) {
        return false;
    }

    memset(pLeft,0,strLen);
    // 右括号的顺序必须按照左括号的顺序来,类似栈，找到一个左侧，则入栈，找到一个右侧则出栈
    for (i = 0; i < strLen; i++) {
        if ((s[i] == '(')  || (s[i] == '{') || (s[i] == '[')) { // 找到左侧括号
            // 存储左侧括号,++
            pLeft[count] = s[i];
            count++;
        } else if (s[i] == ')') { // 左右侧匹配到了,出栈，--
            CHECK_LEFT_STR_MATCH(pLeft,"(",count);
        } else if (s[i] == '}') { // 左右侧匹配到了,出栈，--
            CHECK_LEFT_STR_MATCH(pLeft,"{",count);
        } else if (s[i] == ']') { // 左右侧匹配到了,出栈，--
            CHECK_LEFT_STR_MATCH(pLeft,"[",count);
        } else {
            return false;
        }
    }

    if (count == 0)
        return true;
    else
        return false;
}

/*
 * 数组处理出入栈二，使用数组做栈，函数调用处理出栈
 */
bool CheckBracketMatchForArr(char sL, char *stack,  unsigned int *top)
{
    unsigned int index = *top;
    // 没有入栈，或者与栈顶不是一对，返回false
    if ((index == 0) || (stack[index - 1] != sL)) {
        return false;
    }

    // 出栈
    stack[index] = '\0';
    index--;
    *top = index;
    return true;
}

bool isValidByArray(char* s) {
    unsigned int n = 0;
    unsigned int i = 0;
    unsigned int top = 0;
    char *stack = NULL;

    n = strlen(s);
    // 必须是偶数，如果是奇数，肯定是不满足条件的
    if ((n % 2) != 0) {
        return false;
    }

    // 使用数组，表示栈数据存储，申请内存
    stack = (char*)malloc(n);
    if (stack == NULL) {
        return false;
    }
    memset(stack,0,n);

    // 遍历字符串，记录top，当左侧括号出现时，入栈，top++
    for (i = 0; i < n; i++) {
        // 超过一半的时候，就需要开始出栈了，否则必然不匹配
        if (top > n/2) {
            free(stack);
            return false;
        }
        // 找到一个左侧括号，直接入栈
        if ((s[i] == '(')  || (s[i] == '{') || (s[i] == '[')) { // 找到左侧括号
            stack[top] = s[i];
            top++;
            continue;
        }

        // 如果是右侧括号，当与栈顶是一对的时候，进行出栈，否则直接返回false
        if ((s[i] == ')') && (CheckBracketMatchForArr('(', stack, &top) == false)) {
            free(stack);
            return false;
        }

        if ((s[i] == '}') && (CheckBracketMatchForArr('{', stack, &top) == false)) {
            free(stack);
            return false;
        }

        if ((s[i] == ']') && (CheckBracketMatchForArr('[', stack, &top) == false)) {
            free(stack);
            return false;
        }
    }

    // 如果括号是匹配的，则top是一定为0
    free(stack);
    return top == 0;
}
/*
 * 数组处理出入栈三、优化字符对比，减少复杂度
 */

char pairs(char a) {
    if (a == '}') return '{';
    if (a == ']') return '[';
    if (a == ')') return '(';
    return 0;
}

bool isValidByArrayWithParis(char* s) {
    unsigned int n = 0;
    unsigned int i = 0;
    unsigned int top = 0;
    char *stack = NULL;

    n = strlen(s);
    // 必须是偶数，如果是奇数，肯定是不满足条件的
    if ((n % 2) != 0) {
        return false;
    }

    // 使用数组，表示栈数据存储，申请内存
    stack = (char*)malloc(n);
    if (stack == NULL) {
        return false;
    }
    memset(stack,0,n);

    // 遍历字符串，记录top，当左侧括号出现时，入栈，top++
    for (i = 0; i < n; i++) {
        // 超过一半的时候，就需要开始出栈了，否则必然不匹配
        if (top > n/2) {
            free(stack);
            return false;
        }
        char ch = pairs(s[i]);
        // 找到一个左侧括号，直接入栈
        if (ch != 0) { // 找到左侧括号
            stack[top] = s[i];
            top++;
        } else {
            if (CheckBracketMatchForArr(ch, stack, &top) == false) {
                free(stack);
                return false;
            }
        }
    }

    // 如果括号是匹配的，则top是一定为0
    free(stack);
    return top == 0;
}

/*
 * 使用链表实现栈，然后通过栈调用，完成处理
 */

char charPairs(char a) {
    if (a == '}') return '{';
    if (a == ']') return '[';
    if (a == ')') return '(';
    return 0;
}

bool isValidBracket(char* s) {
    unsigned int n = 0;
    unsigned int i = 0;
    unsigned int top = 0;
    Stack *stack = NULL;

    n = strlen(s);
    // 必须是偶数，如果是奇数，肯定是不满足条件的
    if ((n % 2) != 0) {
        return false;
    }

    stack = StackCreate();
    // 遍历字符串，记录top，当左侧括号出现时，入栈，top++
    for (i = 0; i < n; i++) {
        // 超过一半的时候，就需要开始出栈了，否则必然不匹配
        if (top > n/2) {
            StackDestroy(stack);
            return false;
        }
        char ch = charPairs(s[i]);
        // 找到一个左侧括号，直接入栈
        if (ch == 0) { // 找到左侧括号
            StackPush(stack, s[i]);
        } else {
            if (StackIsEmpty(stack) || (StackPeek(stack) != ch)) {
                StackDestroy(stack);
                return false;
            }
            StackPop(stack);
        }
    }

    // 如果括号是匹配的，栈一定是空的
    if (StackIsEmpty(stack)) {
        return true;
    }
    StackDestroy(stack);
    return false;
}

void TEST_20_isValidBracket()
{
    PRINT_CONSOLE(INFO, "Begin");
    assert(isValidBracket("()") == true);
    assert(isValidBracket("([])") == true);
    assert(isValidBracket("([{}])") == true);
    assert(isValidBracket("()[]{}") == true);
    assert(isValidBracket("([)]") == false);
    assert(isValidBracket("(]") == false);
    assert(isValidBracket("((()") == false);
    assert(isValidBracket("([{([])}])") == true);
    PRINT_CONSOLE(INFO, "End");
}