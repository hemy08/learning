#include <iostream>
#include <string>
#include <limits>
#include "learning_public.h"

using namespace std;

string str1 = "��ռ�ֽ�����";
string str2 = "\t���ֵ��";
string str3 = "��Сֵ��";

#define PRINT_DATA_TYPES_SIZE_VALUE(x, str1,str2, str3) \
    cout << #x << str1 << sizeof(x) << str2 << dec << scientific << (numeric_limits<x>::max)() << str3 << (numeric_limits<x>::min)() << endl;


void DataTypes::PrintDataTypes() {
    cout << "type: \t\t" << "************size**************"<< endl;
    PRINT_DATA_TYPES_SIZE_VALUE(bool, ": \t\t" + str1, str2, "\t\t\t" + str3);
    PRINT_DATA_TYPES_SIZE_VALUE(char, ": \t\t" + str1, str2, "\t\t\t" + str3);
    PRINT_DATA_TYPES_SIZE_VALUE(signed char, ": \t" + str1, str2, "\t\t\t" + str3);
    PRINT_DATA_TYPES_SIZE_VALUE(unsigned char, ": \t" + str1, str2, "\t\t\t " + str3);
    PRINT_DATA_TYPES_SIZE_VALUE(wchar_t, ": \t" + str1, str2, "\t\t\t" + str3);
    PRINT_DATA_TYPES_SIZE_VALUE(short, ": \t\t" + str1, str2, "\t\t\t" + str3);
    PRINT_DATA_TYPES_SIZE_VALUE(int, ": \t\t" + str1, str2, "\t\t" + str3);
    PRINT_DATA_TYPES_SIZE_VALUE(unsigned, ": \t" + str1, str2, "\t\t" + str3);
    PRINT_DATA_TYPES_SIZE_VALUE(long, ": \t\t" + str1, str2, "\t\t" + str3);
    PRINT_DATA_TYPES_SIZE_VALUE(unsigned long, ": \t" + str1, str2, "\t\t" + str3);
    PRINT_DATA_TYPES_SIZE_VALUE(double, ": \t" + str1, str2, "\t\t" + str3);
    PRINT_DATA_TYPES_SIZE_VALUE(long double, ": \t" + str1, str2, "\t\t" + str3);
    PRINT_DATA_TYPES_SIZE_VALUE(float, ": \t\t" + str1, str2, "\t\t" + str3);
    PRINT_DATA_TYPES_SIZE_VALUE(size_t, ": \t" + str1, str2, "\t" + str3);
    cout << "string: \t" << str1 << sizeof(string) << endl;
    // << "\t���ֵ��" << (numeric_limits<string>::max)() << str3 << (numeric_limits<string>::min)() << endl;
    cout << "type: \t\t" << "************size**************"<< endl;
}

