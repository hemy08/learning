/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description:
 * link:
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2021/6/4.
 */

#ifndef HEMYCODEREPO_DEBUG_H
#define HEMYCODEREPO_DEBUG_H

typedef enum {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL,
    EMERGENCY,
    BUTT
}SYS_LOG_LEVEL;

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Func Name：LogServerCurrentTime
 * Description：获取系统当前时间
 * Params：
 *      (uchar_t pcTimeStr)
 * History
 *      Creste by zhaojunwei 2019/01/24
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void LogServerCurrentTime(unsigned char *pcTimeStr);
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Func Name：LogServerRecordLog
 * Description：写日志文件
 * Params：
 *      (uint32_t uiflag)
 * History
 *      Creste by zhaojunwei 2019/01/24
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void RecordLog(const unsigned char* pcFile, const unsigned char* pcFunc, uint32_t uiLineNo, uint32_t uiLogLev, const unsigned char* pcLogFmt, ...);

void RecordLogSimple(const unsigned char* pcFunc, uint32_t uiLineNo, uint32_t uiLogLev, const unsigned char* pcLogFmt, ...);

#define PRINT_LOG(logLev, fmt, ...) \
    RecordLog(__FILE__, __FUNCTION__,(uint32_t)__LINE__, (uint32_t)logLev, fmt, ##__VA_ARGS__)

#define PRINT_CONSOLE(logLev, fmt, ...) \
    RecordLogSimple(__FUNCTION__,(uint32_t)__LINE__, (uint32_t)logLev, fmt, ##__VA_ARGS__)

void LogFmt(const char* pcLogFmt, ...);

#define LOG(format, args...) \
do { \
    LogFmt(("%s : " format), __FUNCTION__, ##args); \
}while (0)
#endif //HEMYCODEREPO_DEBUG_H
