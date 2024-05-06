/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 97. 交错字符串
 * link: https://leetcode-cn.com/problems/interleaving-string/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00226060 on 2020/6/23.
 */

#include "public.h"

bool isInterleave1(char * s1, char * s2, char * s3)
{
    int len_s1, len_s2, len_s3;
    bool result = false;

    len_s1 = (int)strlen(s1);
    len_s2 = (int)strlen(s2);
    len_s3 = (int)strlen(s3);

    if ((len_s1 == 0) && (len_s2 == 0) && (len_s3 == 0)) {
        return true;
    }

    // s1为空
    if (len_s1 == 0) {
        if (strcmp(s2, s3) == 0) {
            return true;
        }
        return false;
    }

    // s2为空
    if (len_s2 == 0) {
        if (strcmp(s1, s3) == 0) {
            return true;
        }
        return false;
    }

    // 长度匹配不上
    if ((len_s1 + len_s2) != len_s3) {
        return false;
    }

    // 长度匹配上， 字符串是否匹配
    if (*s1 == *s3) {
        result |= isInterleave1(s1 + 1, s2, s3 + 1);
    }
    if (result) {
        return true;
    }

    if (*s2 == *s3) {
        result |= isInterleave1(s1 , s2 + 1, s3 + 1);
    }

    return result;
}


/*
 * 动态规划解法
 * dp[i][j] 取决于dp[i][j-1]和dp[i-1][j]的值
 * s3[i+j] == s1[i]时， dp[i][j] = dp[i][j - 1]
 * s3[i+j] == s2[j]时， dp[i][j] = dp[i - 1][j]
 */
bool isInterleave2(char* s1, char* s2, char* s3) {
    int n = strlen(s1);
    int m = strlen(s2);
    int t = strlen(s3);

    int f[n + 1][m + 1];
    memset(f, 0, sizeof(f));

    if (n + m != t) {
        return false;
    }

    f[0][0] = true;
    if (s1[0] == s3[0]) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                int p = i + j - 1;
                f[i][j] |= (f[i - 1][j] && s1[i - 1] == s3[p]);
                if (j > 0) {
                    f[i][j] |= (f[i][j - 1] && s2[j - 1] == s3[p]);
                }
            }
        }
    }

    if (f[n][m]) {
        return f[n][m];
    }

    if (s2[0] == s3[0]) {
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int p = i + j - 1;
                f[i][j] |= (f[i][j - 1] && s2[j - 1] == s3[p]);
                if (i > 0) {
                    f[i][j] |= (f[i - 1][j] && s1[i - 1] == s3[p]);
                }
            }
        }
    }

    return f[n][m];
}


bool isInterleave3(char* s1, char* s2, char* s3) {
    int n = strlen(s1), m = strlen(s2), t = strlen(s3);

    int f[n + 1][m + 1];
    memset(f, 0, sizeof(f));

    if (n + m != t) {
        return false;
    }

    f[0][0] = true;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            int p = i + j - 1;
            if (i > 0) {
                f[i][j] |= (f[i - 1][j] && s1[i - 1] == s3[p]);
            }
            if (j > 0) {
                f[i][j] |= (f[i][j - 1] && s2[j - 1] == s3[p]);
            }
        }
    }

    return f[n][m];
}

// char boolStr[2][6] = {"false", "true"};

/*
void main()
{
    char a[256] = "aabcc";
    char b[256] = "dbbca";
    char c[256] = "aadbbcbcac";

    bool result = isInterleave1(a,b,c);

    printf("%s\n", boolStr[result]);
}*/
