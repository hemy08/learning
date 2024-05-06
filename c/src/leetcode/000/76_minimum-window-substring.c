/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 76. 最小覆盖子串
 * link: https://leetcode-cn.com/problems/minimum-window-substring/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/8/29.
 */

#include "leetcode_com_def_c.h"
#include "public.h"

/*
 * 老方案，未优化，超时
 * */
/*
#define MAX_CHAR_NUM 255

void counterCharNum(char *start, const char *end, int *counts, int len)
{
    while ((start != end) && (*start != '\0')) {
        counts[*start]++;
        start++;
    }
}

bool checkInclude(const char * t, const int *count_s, const int *count_t)
{
    int len_t = (int)strlen(t);

    for (int i = 0; i < len_t; i++) {
        if (count_t[t[i]] > count_s[t[i]]) {
            return false;
        }
    }

    return true;
}

char *findSingleWindowRight(const char *t, char *start, char *end, int *count_s, const int *count_t)
{
    // 左侧移动过了end
    if (end <= start) {
        end = start;
    }

    while (*end != '\0') {
        if (checkInclude(t, count_s, count_t)) {
            return end;
        }
        count_s[*end]++;
        end++;
    }

    if (checkInclude(t, count_s, count_t)) {
        return end;
    }

    return NULL;
}

char *findMinWindow(const char *s, const char *t, const int *count_t)
{
    int count_s[MAX_CHAR_NUM] = {0};
    char* result = NULL;
    char *start, *end;
    int len_s = (int)strlen(s);
    int len_t = (int)strlen(t);
    int result_l = len_s + 1;

    result = (char*)malloc(len_s + 1);
    if (result == NULL) {
        return "";
    }
    memset(result, 0, len_s + 1);
    memset(count_s, 0, sizeof(count_s));

    start = s;
    end = start + len_t - 1;
    char *pos = start;
    while ((pos != end) && (*pos != '\0')) {
        count_s[*pos]++;
        pos++;
    }

    while (start <= end) {
        // 找窗口的end
        end = findSingleWindowRight(t, start, end, count_s, count_t);
        if (end == NULL) {
            return result;
        }

        int len = end - start;
        // 窗口的左侧不能移动
        if (result_l > len) {
            memset(result, 0, len_s + 1);
            memcpy(result, start, len);
            result_l = len;
            result[result_l] = '\0';
        }
        count_s[*start]--;
        start++;
    }

    return result;
}

char *minWindow(const char * s, char * t)
{
    int len_s = (int)strlen(s);
    int len_t = (int)strlen(t);
    int count_s[MAX_CHAR_NUM] = {0};
    int count_t[MAX_CHAR_NUM] = {0};

    if (len_t > len_s) {
        return "";
    }

    // 计算T串各个字符的个数,不包含end
    counterCharNum(t, t + len_t, count_t, sizeof(count_t));
    if (len_s == len_t) {
        // 计算S各个字符的个数,不包含end
        counterCharNum(s, s + len_s, count_s, sizeof(count_s));
        if (checkInclude(t, count_s, count_t)) {
            return s;
        }
        return "";
    }

    return findMinWindow(s, t, count_t);
}
*/
#define MAX_CHAR_NUM 255

void getSlidingWindows(const char *left, const char *right, char *result, int *resultSize, int *maxLen)
{
    int len = (int)(right - left);
    if (*maxLen > len) {
        memset(result, 0, resultSize);
        memcpy(result, left, len);
        *maxLen = len;
        result[*maxLen] = '\0';
    }
}

void deleteSlidingWindowLeftInvalidChar(char **left, int *count_s, const int *count_t)
{
    char *begin = *left;
    while ((count_t[*begin] == 0) || (count_s[*begin] > count_t[*begin])) {
        count_s[*begin]--;
        begin++;
    }

    *left = begin;
}

void moveSlidingWindowRightFrame(char **right, int *count_s, const int *count_t, int *sum_s)
{
    char *end = *right;
    count_s[*end]++;
    if (count_s[*end] <= count_t[*end]) {
        (*sum_s)++;
    }
    end++;
    *right = end;
}

char *minWindow(const char *s, const char *t)
{
    int count_s[MAX_CHAR_NUM] = {0};
    int count_t[MAX_CHAR_NUM] = {0};
    char* result = NULL;
    char *left, *right;
    int len_s = (int)strlen(s);
    int len_t = (int)strlen(t);
    int sum_s = 0;
    int result_l = len_s + 1;

    if (len_t > len_s) {
        return "";
    }

    memset(count_s, 0, sizeof(count_s));
    memset(count_t, 0, sizeof(count_t));

    result = (char*)malloc(len_s + 1);
    if (result == NULL) {
        return "";
    }
    memset(result, 0, len_s + 1);

    for (int i = 0; i < len_t; i++) {
        count_t[t[i]]++;
    }

    // 找到第一个满足条件的子串的end
    left = s;
    right = s;
    while ((left <= right) && (*left != '\0') && (*right != '\0')) {
        // right 向右移动，不在T中的跳过
        if (count_t[*right] == 0) {
            right++;
            continue;
        }

        // right在T中，并且个数不到count_t[*right]， 计数一个,sum_s只记录S字符串中在T字符串出现过的字符个数。
        moveSlidingWindowRightFrame(&right, count_s, count_t, &sum_s);

        // 找到了满足条件的子串，sum_s与T的长度相同时，说明找到了一个满足条件的子串
        if (len_t == sum_s) {
            // 从left开始，删除多余的字符
            deleteSlidingWindowLeftInvalidChar(&left, count_s, count_t);
            getSlidingWindows(left, right, result, len_s + 1, &result_l);

            // 去掉最左侧的一个值，继续
            sum_s--;
            count_s[*left]--;
            left++;
        }

        if (count_t[*left] == 0) {
            left++;
        }
    }

    return result;
}

/*
int main()
{
    char *s = TEST_76_LONG_S;
    char *t = TEST_76_LONG_T;
    char *result = NULL;

    result = minWindow(s, t);
    printf("result : %s", result);
    return 0;
}*/
