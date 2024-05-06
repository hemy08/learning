/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 1472. 设计浏览器历史记录
 * link: https://leetcode-cn.com/problems/design-browser-history/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

/*
 * 输入：
["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
[["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]
输出：
[null,null,null,null,"facebook.com","google.com","facebook.com",null,"linkedin.com","google.com","leetcode.com"]

解释：
BrowserHistory browserHistory = new BrowserHistory("leetcode.com");
browserHistory.visit("google.com");       // 你原本在浏览 "leetcode.com" 。访问 "google.com"
browserHistory.visit("facebook.com");     // 你原本在浏览 "google.com" 。访问 "facebook.com"
browserHistory.visit("youtube.com");      // 你原本在浏览 "facebook.com" 。访问 "youtube.com"
browserHistory.back(1);                   // 你原本在浏览 "youtube.com" ，后退到 "facebook.com" 并返回 "facebook.com"
browserHistory.back(1);                   // 你原本在浏览 "facebook.com" ，后退到 "google.com" 并返回 "google.com"
browserHistory.forward(1);                // 你原本在浏览 "google.com" ，前进到 "facebook.com" 并返回 "facebook.com"
browserHistory.visit("linkedin.com");     // 你原本在浏览 "facebook.com" 。 访问 "linkedin.com"
browserHistory.forward(2);                // 你原本在浏览 "linkedin.com" ，你无法前进任何步数。
browserHistory.back(2);                   // 你原本在浏览 "linkedin.com" ，后退两步依次先到 "facebook.com" ，然后到 "google.com" ，并返回 "google.com"
browserHistory.back(7);                   // 你原本在浏览 "google.com"， 你只能后退一步到 "leetcode.com" ，并返回 "leetcode.com"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-browser-history
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * */

#include "public.h"

/*#define MAX_HISTORY_LIST 10000

typedef struct {
    int index;
    int cur_index;
    char url[MAX_HISTORY_LIST][32];
} BrowserHistory;*/


BrowserHistory* browserHistoryCreate(char * homepage) {
    BrowserHistory *historyList = NULL;
    historyList = (BrowserHistory *)malloc(sizeof(BrowserHistory));
    memset(historyList,0,sizeof(BrowserHistory));

    historyList->index = 0;
    historyList->cur_index = 0;
    if (homepage != NULL) {
        strcpy(historyList->url[0], homepage);
    }

    return historyList;
}

void browserHistoryVisit(BrowserHistory* obj, char * url) {
    if ((obj == NULL) || (url == NULL)) {
        return;
    }

    obj->cur_index++;
    obj->index = obj->cur_index;
    strcpy(obj->url[obj->cur_index], url);
    printf("\nVisit index %d, cur_index %d, url[%s], cur_url [%s]", obj->index, obj->cur_index, url, obj->url[obj->cur_index]);
}

char * browserHistoryBack(BrowserHistory* obj, int steps) {
    if (obj == NULL) {
        return NULL;
    }

    if ((obj->cur_index - steps) <= 0) {
        obj->cur_index = 0;
    } else {
        obj->cur_index -= steps;
    }

    printf("\nBack index %d, cur_index %d, cur_url [%s]", obj->index, obj->cur_index, obj->url[obj->cur_index]);
    return obj->url[obj->cur_index];
}

char * browserHistoryForward(BrowserHistory* obj, int steps) {
    if (obj == NULL) {
        return NULL;
    }

    // 往前，到顶，停在顶
    if ((obj->cur_index + steps) < obj->index) {
        obj->cur_index += steps;
    } else {
        obj->cur_index = obj->index;
    }

    printf("\nForward index %d, cur_index %d, cur_url [%s]", obj->index, obj->cur_index, obj->url[obj->cur_index]);
    return obj->url[obj->cur_index];
}

void browserHistoryFree(BrowserHistory* obj) {
    if (obj == NULL) {
        return;
    };

    free(obj);
}

/**
 * Your BrowserHistory struct will be instantiated and called as such:
 * BrowserHistory* obj = browserHistoryCreate(homepage);
 * browserHistoryVisit(obj, url);

 * char * param_2 = browserHistoryBack(obj, steps);

 * char * param_3 = browserHistoryForward(obj, steps);

 * browserHistoryFree(obj);
*/