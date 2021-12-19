#include "Helper.h"

// Prefix sum of 2D Array/Martix
// More information : https://www.geeksforgeeks.org/prefix-sum-array-implementation-applications-competitive-programming/
std::vector<int> PrefixSumOfArray(const std::vector<int>& arr)
{
    // Empty matrix
    if (arr.size() == 0)
        return std::vector<int>();

    // Initialize return variable
    std::vector<int> result;
    result.resize(arr.size());

    // Set top-left [0][0] entry
    result[0] = arr[0];

    // Sum the entries
    for (size_t x = 1; x < arr.size(); ++x)
        result[x] = result[x - 1] + arr[x];

    return result;
}

// Prefix sum of 2D Array/Martix
// More information : https://www.geeksforgeeks.org/prefix-sum-2d-array/
std::vector<std::vector<int>> PrefixSumOfMatrix(const std::vector<std::vector<int>>& matrix)
{
    // Empty matrix
    if (matrix.size() == 0)
        return std::vector<std::vector<int>>();

    // Get width and height of matrix
    size_t height = matrix.size();
    size_t width = matrix[0].size();

    // Initialize return variable
    std::vector<std::vector<int>> result;
    result.resize(height);
    for (auto& vec : result)
        vec.resize(width);

    // Set top-left [0][0] entry
    result[0][0] = matrix[0][0];

    // Set first column entry
    for (size_t y = 1; y < height; ++y) // y
        result[y][0] = result[y - 1][0] + matrix[y][0];

    // Set first row entry
    for (size_t x = 1; x < width; ++x) // x
        result[0][x] = result[0][x - 1] + matrix[0][x];

    // Fill up the other entries
    for (int y = 1; y < height; ++y) // y
        for (int x = 1; x < width; ++x) // x
            result[y][x] = result[y - 1][x] + result[y][x - 1]
            - result[y - 1][x - 1] + matrix[y][x];

    return result;
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
    std::vector<std::vector<int>> input{ {10,20,30}, {5,10,20}, {2,4,6} };
    std::vector<std::vector<int>> expected{ {10,30,60}, {15,45,95}, {17,51,107} };
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

    return 0;
}