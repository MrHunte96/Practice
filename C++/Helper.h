#pragma once
#include <Windows.h>
#include <iostream>
#include <vector>
//#include <algorithm>

// Debug output for test cases
class Test
{
    std::string m_testName;
    HANDLE hConsole;

    void eraseRunning();
public:
    Test(const std::string& name);
    ~Test();
    
    void printSucceed();
    void printFailure();
};

class PrintTestName
{
public:
    PrintTestName(const char* str);
    ~PrintTestName();
};
#define StartTestCases(x) PrintTestName ptn(x);
#define StartTest() Test test(__FUNCTION__);
#define TestSucceed() test.printSucceed();
#define TestFailure() test.printFailure();

// Print Matrix
std::ostream& operator<<(std::ostream& os, const std::vector<int>& arr);
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<int>>& mtx);

// Equality
template<typename T>
bool IsEqual(const T& val1, const T& val2)
{
    return val1 == val2;
}
//template<>
//bool IsEqual(const std::vector<int>& vec1, const std::vector<int>& vec2)
//{
    //return true;// std::equal(vec1.begin(), vec1.end(), vec2.begin());
//}