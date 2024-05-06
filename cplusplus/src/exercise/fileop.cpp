//
// Created by z00579768 on 2024/4/9.
//

#include <fstream>
#include <cstdint>
#include <cstdarg>
#include <sstream>

using namespace std;

const char* g_file1 = "./func1.csv";
const char* g_file2 = "./func2.csv";

void WriteFile(std::ofstream& file, const char *fmt, ...)
{
    char buffer[1024] = {0};
    va_list args;
    va_start(args, fmt);
    int ret = vsprintf(buffer, fmt, args);
    if (ret < 0) {
        va_end(args);
        return;
    }
    va_end(args);
    file << buffer << endl;
}

void func1(std::ofstream& file) {
    int32_t a = 10;
    float b = 0.5;
    bool c = false;
    char *pStr = (char*)"hello world";

    // 将 bool 转换为字符串，并添加足够的空格来模拟8个字符的空位
    std::stringstream ss;
    ss << (c ? "TRUE" : "FALSE");
    std::string boolStr = ss.str();
    boolStr.insert(boolStr.end(), 8 - boolStr.length(), ' '); // 添加空格直到达到8个字符长度
    WriteFile(file, "%-7d %-7.1f %s%s", a, b, boolStr.c_str(), pStr);
}

void func2(std::ofstream& file) {
    int64_t d = -15;
    uint64_t e = 5;
    char *pStr = (char*)"hello world";
    WriteFile(file, "%-7d %-7d %s", d, e, pStr);
}

void TestCase_FileOperation_001() {
    remove(g_file1);
    ofstream file1(g_file1);
    if (!file1) {
        return;
    }
    WriteFile(file1, "a\tb\tc\tpStr");
    for (int i = 0; i < 10; ++i) {
        func1(file1);
    }
    file1.close();

    remove(g_file2);
    ofstream file2(g_file2);
    if (!file2) {
        return;
    }
    WriteFile(file2, "d\td\tstr");
    for (int i = 0; i < 10; ++i) {
        func2(file2);
    }
    file2.close();
}