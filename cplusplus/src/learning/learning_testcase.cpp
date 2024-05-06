#include <iostream>
#include <string>
#include <limits>
#include "public.h"
#include "learning_public.h"
#include "learning_testcase.h"

using namespace std;

void Learning_TestCase_Main() {
    WriteLog("Learning_TestCase_Main Begin!");
    DataTypes::PrintDataTypes();
    TestCase_ClassAndDerivedClass();
    TestCase_StorageDuration();
    WriteLog("Learning_TestCase_Main End!");
}