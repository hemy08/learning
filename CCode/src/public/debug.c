/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description:
 * link:
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2021/6/4.
 */

#include "public.h"
#include "stdarg.h"

unsigned char* g_ucLogLevel[BUTT] = {
        "DEBUG",
        "INFO",
        "WARN",
        "ERROR",
        "EMERG"
};

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Func Name：LogServerCurrentTime
 * Description：获取系统当前时间
 * Params：
 *      (unsigned char pcTimeStr)
 * History
 *      Creste by zhaojunwei 2019/01/24
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void LogServerCurrentTime(unsigned char *pcTimeStr)
{
    struct timeval d_stTv;
    struct tm * d_stTm;
    time_t  t;
    (void)gettimeofday (&d_stTv, NULL);
    time(&t);
    d_stTm = localtime(&t);
    (void)sprintf(pcTimeStr, "%02d_%02d_%02d-%02d:%02d:%02d.%06lu",
                  (1900 + d_stTm->tm_year),
                  (1 + d_stTm->tm_mon),
                  d_stTm->tm_mday,
                  d_stTm->tm_hour,
                  d_stTm->tm_min,
                  d_stTm->tm_sec,
                  d_stTv.tv_usec);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Func Name：LogServerRecordLog
 * Description：写日志文件
 * Params：
 *      (uint32_t uiflag)
 * History
 *      Creste by zhaojunwei 2019/01/24
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void RecordLog(const unsigned char* pcFile, const unsigned char* pcFunc, uint32_t uiLineNo, uint32_t uiLogLev, const unsigned char* pcLogFmt, ...)
{
    va_list ArgList;
    unsigned char    acLogTime[33] = {0};
    unsigned char    szBuffer[513] = "";

    unsigned char *fILE = strrchr(pcFile,'\\');

    va_start(ArgList, pcLogFmt);
    vsprintf_s(szBuffer, 513, pcLogFmt, ArgList);
    va_end(ArgList);

    LogServerCurrentTime(acLogTime);

    printf("[%s %s - %s - %s:%d] %s\r\n",
            acLogTime, g_ucLogLevel[uiLogLev], fILE + 1, pcFunc, uiLineNo, szBuffer);
    (void)va_end(ArgList);
}

void RecordLogSimple(const unsigned char* pcFunc, uint32_t uiLineNo, uint32_t uiLogLev, const unsigned char* pcLogFmt, ...)
{
    va_list ArgList;
    unsigned char    szBuffer[513] = "";

    va_start(ArgList, pcLogFmt);
    vsprintf_s(szBuffer, 513, pcLogFmt, ArgList);
    va_end(ArgList);

    printf("[%s - %s:%d] %s\r\n",  g_ucLogLevel[uiLogLev], pcFunc, uiLineNo, szBuffer);
    (void)va_end(ArgList);
}


void LogFmt(const char* pcLogFmt, ...) {
    va_list ArgList;
    unsigned char    szBuffer[513] = "";

    va_start(ArgList, pcLogFmt);
    vsprintf_s(szBuffer, 513, pcLogFmt, ArgList);
    va_end(ArgList);

    printf("%s \n",  szBuffer);
    (void)va_end(ArgList);
}