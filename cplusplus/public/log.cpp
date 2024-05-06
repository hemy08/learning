//
// Created by z00579768 on 2024/4/28.
//
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdarg>

using namespace std;

void WriteLog(const char* format, ...) {
    ofstream logFile("log.txt", ios::app);  // 打开日志文件用于追加

    string log_content;

    va_list arg_ptr;
    va_start(arg_ptr, format);
    int len = vsnprintf(nullptr, 0, format, arg_ptr);
    va_end(arg_ptr);

    if (len > 0) {
        char * content = new char[len + 1];
        va_start(arg_ptr, format);
        vsnprintf(content, len + 1, format, arg_ptr);
        va_end(arg_ptr);
        content[len] = 0;
        log_content = content;
        delete [] content; //动态的数组需要删除
        // m_len += len;//获取到当前的长度 累计起来
    }

    if (logFile.is_open()) {
        time_t t = time(nullptr);  // 获取当前时间
        char timestamp[80];
        strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %X", localtime(&t));

        logFile << "[" << timestamp << "] " << log_content << endl;  // 写入时间戳和消息
        logFile.close();  // 关闭文件
    } else {
        cerr << "Unable to open log file!" << endl;
    }
    cout << log_content << endl;
}