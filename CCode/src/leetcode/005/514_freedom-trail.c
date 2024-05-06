/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 514. 自由之路
 * link: https://leetcode-cn.com/problems/freedom-trail/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/11/11.
 */

#include "public.h"

int findRotateSteps(char * ring, char * key)
{

}


/*
int findRotateSteps(char* ring, char* key) {
    int n = strlen(ring), m = strlen(key);
    int pos[26][n], posSize[26];
    memset(posSize, 0, sizeof(posSize));
    for (int i = 0; i < n; ++i) {
        int x = ring[i] - 'a';
        pos[x][posSize[x]++] = i;
    }
    int dp[m][n];
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    for (int i = 0; i < posSize[key[0] - 'a']; i++) {
        int x = pos[key[0] - 'a'][i];
        dp[0][x] = fmin(x, n - x) + 1;
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < posSize[key[i] - 'a']; ++j) {
            int x = pos[key[i] - 'a'][j];
            for (int k = 0; k < posSize[key[i - 1] - 'a']; ++k) {
                int y = pos[key[i - 1] - 'a'][k];
                dp[i][x] = fmin(dp[i][x], dp[i - 1][y] + fmin(abs(x - y), n - abs(x - y)) + 1);
            }
        }
    }
    int ret = dp[m - 1][0];
    for (int i = 1; i < n; ++i) {
        ret = fmin(ret, dp[m - 1][i]);
    }
    return ret;
}*/
