/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 
 * link: 
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/9/7.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include "pub_stub.h"
#include "pub_typedef.h"
#include "citfdef.h"
#include "qsort_comp_itf.h"
#include "assert.h"
#include "debug.h"

#ifndef ____HEMY_CODE_REPO__SRC__PUBLIC__COMMON__H____
#define ____HEMY_CODE_REPO__SRC__PUBLIC__COMMON__H____

#define MAX_VAL(a, b)  (((a) > (b)) ? (a) : (b))
#define MIN_VAL(a, b)  (((a) > (b)) ? (b) : (a))

void OutPutArrays(int *nums, int numSize);

static inline int GetMinValue(int a, int b) {
    return a > b ? b : a;
}

static inline int GetMaxValue(int a, int b) {
    return a > b ? a : b;
}

/*
 * 函 数 名  : MINIOS_StringToHexStr
 * 功能描述  : 将密钥转换为字符串
 * 输入参数  : unsigned char *pucString, 字符串
 * 输出参数  : char *pcHexStr  16进制格式字符串
 * 返 回 值  : 无
 */
void StringToHexStr(unsigned char *pucString, char *pcHexStr, unsigned int uiLen);

/*
 * 函 数 名  : MINIOS_HexStrToString
 * 功能描述  : 将16进制格式字符串转换为字符串
 * 输入参数  : char *pcHexStr   16进制字符串
 * 输出参数  : unsigned char *pucString  字符串
 * 返 回 值  : 无
 */
void HexStrToString(char *pcHexStr, unsigned char *pucString, unsigned int ucStringLen);

/*
 * 函 数 名  : ConvertUTF8toGBK
 * 功能描述  : UTF-8编码的字符转为gbk编码
 * 输入参数  : char *inbuf 输入字符串，UTF-8编码
 * 输出参数  : char *outbuf  输出字符串，gbk编码
 * 返 回 值  : 成功0，失败-1
 */
int ConvertUTF8toGBK(char *inbuf, size_t inlen, char *outbuf, size_t outlen);

/*
 * 函 数 名  : ConvertGBKToUTF8
 * 功能描述  : gbk编码转为UTF-8编码
 * 输入参数  : char *inbuf 输入字符串，gbk编码
 * 输出参数  : char *outbuf  输出字符串，utf编码
 * 返 回 值  : 成功0，失败-1
 */
int ConvertGBKToUTF8(char *inbuf, size_t inlen, char *outbuf, size_t outlen);

/*
 * 函 数 名  : UTF8Check
 * 功能描述  : 校验字符串是否为utf-8编码
 * 输入参数  : const char* str 输入字符串
 * 输出参数  : 无
 * 返 回 值  : 成功0，失败-1
 */
int UTF8Check(const char* str, size_t length);

/*
 * 函 数 名  : Base64Encode
 * 功能描述  : base64编码函数
 * 输入参数  : const char* str 输入字符串
 * 输出参数  : char **output 输出字符串， int *outlen 输出字符串长度，使用者释放内存
 * 返 回 值  : 成功0，失败-1
 */
int Base64Encode(const char *input, int inlen, char **output, unsigned int *outlen);

/*
 * 函 数 名  : Base64Decode
 * 功能描述  : base64解码函数
 * 输入参数  : const char* str 输入字符串
 * 输出参数  : char **output 输出字符串， int *outlen 输出字符串长度，使用者释放内存
 * 返 回 值  : 成功0，失败-1
 */
int Base64Decode(const char *input, int inlen, char **outptr, unsigned int *outlen);

/*
 * 函 数 名  : base64_encode
 * 功能描述  : base64 编码
 * 输入参数  : const char* str 输入字符串
 * 输出参数  : 无
 * 返 回 值  : 成功返回编码码后字符串，失败返回NULL，使用者释放内存
 */
char *base64_encode (const unsigned char *src, unsigned int len);

/*
 * 函 数 名  : base64_decode
 * 功能描述  : base64 解码
 * 输入参数  : const char* str 输入字符串
 * 输出参数  : unsigned int *decsize 输出字符串长度
 * 返 回 值  : 成功返回解码后字符串，失败返回NULL，使用者释放内存
 */
unsigned char *base64_decode(const char *src, unsigned int len, unsigned int *decsize);


#define PROTOCOL_NONE 0
#define PROTOCOL_HTTP 1
#define PROTOCOL_HTTPS 2

/*
 * 函 数 名  : ConvertUrlProtocol
 * 功能描述  : url协议转换
 * 输入参数  : const char* pUrl 输入url，带http/https的
 * 输出参数  : 无
 * 返 回 值  : 成功0，失败返回-1
 */
int ConvertUrlProtocol(const char* pUrl, int protocol);

#define CHECK_CMD_CHAR_VALID(chr) \
    (((chr) >= 'A' && (chr) <= 'Z') || ((chr) >= 'a' && (chr) <= 'z') || ((chr) >= '0' && (chr) <= '9') \
    || ((chr) == ' ') || ((chr) == '/') || ((chr) == '\'') || ((chr) == '.') || ((chr) == '+') \
    || ((chr) == '-') || ((chr) == '=') || ((chr) == ':') || ((chr) == '|') || ((chr) == '_') \
    || ((chr) == '"') || ((chr) == '&') || ((chr) == '{') || ((chr) == '}') || ((chr) == ',') \
    || ((chr) == '$') || ((chr) == '*') || ((chr) == '@'))
/*
 * 函 数 名  : CheckCommandValid
 * 功能描述  : CMD命令白名单校验
 * 输入参数  : const char* pCmd 输入命令
 * 输出参数  : 无
 * 返 回 值  : 通过true，未通过false
 */
bool CheckCommandValid(const char *pCmd);

#endif //____HEMY_CODE_REPO__SRC__PUBLIC__COMMON__H____

