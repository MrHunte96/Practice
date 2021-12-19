#include "Helper.h"

// Prefix sum of 2D Array/Martix
std::vector<int> PrefixSumOfArray(const std::vector<int>& arr)
{
    // TO DO
    return std::vector<int>();
}

// Prefix sum of 2D Array/Martix
std::vector<std::vector<int>> PrefixSumOfMatrix(const std::vector<std::vector<int>>& matrix)
{
    // TO DO
    return std::vector<std::vector<int>>();
}

void Test0_Array()
{
    StartTest();
    std::vector<int> input{ };
    std::vector<int> expected{ };
    std::vector<int> output = PrefixSumOfArray(input);

    if (IsEqual(output, expected)) TestSucceed()
    else TestFailure()
}

void Test1_Array()
{
    StartTest();
    std::vector<int> input{ 1, -1, 1, -1 };
    std::vector<int> expected{ 1, 0, 1, 0 };
    std::vector<int> output = PrefixSumOfArray(input);

    if (IsEqual(output, expected)) TestSucceed()
    else TestFailure()
}

void Test2_Array()
{
    StartTest();
    std::vector<int> input{ 10, 20, 10, 5, 15 };
    std::vector<int> expected{ 10, 30, 40, 45, 60 };
    std::vector<int> output = PrefixSumOfArray(input);

    if (IsEqual(output, expected)) TestSucceed()
    else TestFailure()
}

void Test0_Matrix()
{
    StartTest();
    std::vector<std::vector<int>> input{ };
    std::vector<std::vector<int>> expected{ };
    std::vector<std::vector<int>> output = PrefixSumOfMatrix(input);

    if (IsEqual(output, expected)) TestSucceed()
    else TestFailure()
}

void Test1_Matrix()
{
    StartTest();
    std::vector<std::vector<int>> input { {10,20,30}, {5,10,20}, {2,4,6} };
    std::vector<std::vector<int>> expected { {10,30,60}, {15,45,95}, {17,51,107} };
    std::vector<std::vector<int>> output = PrefixSumOfMatrix(input);

    if (IsEqual(output, expected)) TestSucceed()
    else TestFailure()
}

void Test2_Matrix()
{
    StartTest();
    std::vector<std::vector<int>> input{ {10,20}, {5,10}, {2,4} };
    std::vector<std::vector<int>> expected{ {10,30}, {15,45}, {17,51} };
    std::vector<std::vector<int>> output = PrefixSumOfMatrix(input);

    if (IsEqual(output, expected)) TestSucceed()
    else TestFailure()
}

void Test3_Matrix()
{
    StartTest();
    std::vector<std::vector<int>> input{ {10,20,30}, {5,10,20} };
    std::vector<std::vector<int>> expected{ {10,30,60}, {15,45,95} };
    std::vector<std::vector<int>> output = PrefixSumOfMatrix(input);

    if (IsEqual(output, expected)) TestSucceed()
    else TestFailure()
}

/********************************* Driver *************************************/
int main()
{
    // Reset Color
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);

    {
        StartTestCases("Prefix Sum of Array");
        Test0_Array();
        Test1_Array();
    }
    {
        StartTestCases("Prefix Sum of Matrix");
        Test0_Matrix();
        Test1_Matrix();
        Test2_Matrix();
        Test3_Matrix();
    }

    // Reset Color
    SetConsoleTextAttribute(hConsole, 7);
    return 0;
}