//
// Created by z00579768 on 2024/4/28.
//
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdarg>

using namespace std;

void WriteLog(const char* format, ...) {
    ofstream logFile("log.txt", ios::app);  // ����־�ļ�����׷��

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
        delete [] content; //��̬��������Ҫɾ��
        // m_len += len;//��ȡ����ǰ�ĳ��� �ۼ�����
    }

    if (logFile.is_open()) {
        time_t t = time(nullptr);  // ��ȡ��ǰʱ��
        char timestamp[80];
        strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %X", localtime(&t));

        logFile << "[" << timestamp << "] " << log_content << endl;  // д��ʱ�������Ϣ
        logFile.close();  // �ر��ļ�
    } else {
        cerr << "Unable to open log file!" << endl;
    }
    cout << log_content << endl;
}