//
// Created by z00579768 on 2023年01月16日
//

#include "public.h"
#include "stdbool.h"

bool CheckCommandValid(const char *pCmd)
{
    bool bValid = false;
    unsigned int uiIndex = 0;

    /* 字符合法性校验
     * 白名单为数字、大小写字母、[' ' | '/' | '.' | '+' | '-' | '|' | '_']
     * 可能的命令形式：
     * chmod 770 /xxx/xxx/xxx/xxx.xx -R
     * ps afx | grep xxx
     * sed -i (1,100d) xxx.xx
     * cat xxx | grep DDNS_Server_Port | awk -F \"=\" 'sub(/^[[:blank:]]*\/,\"\",$2) {printf $2}'
     */
    while (pCmd[uiIndex] != '\0') {
        if (CHECK_CMD_CHAR_VALID(pCmd[uiIndex])) {
            bValid = true;
        } else {
            LOG("invalid cmd(%s)!!!", pCmd);
            LOG("invalid position (%c)!!!", pCmd[uiIndex]);
            bValid = false;
            break;
        }
        uiIndex++;
    }
    return bValid;
}
