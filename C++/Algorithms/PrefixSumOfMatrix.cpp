#pragma once
#include "Algorithms.h"
#include "../Others/PrintOverload.h"

namespace Algorithms
{  
  // Prefix sum of 2D Array/Martix
  // More information : https://www.geeksforgeeks.org/prefix-sum-array-implementation-applications-competitive-programming/
  std::vector<int> PrefixSumOf1DArray(const std::vector<int>& arr)
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
  std::vector<std::vector<int>> PrefixSumOf2DArray(const std::vector<std::vector<int>>& matrix)
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

  void TestPrefixSumOfMatrix()
  {
    //std::vector<std::vector<int>> a{{-1,1},{1,-1}};
    //std::vector<std::vector<int>> a{{0,1,0},{1,1,1},{0,1,0}};
    //std::vector<std::vector<int>> a{{0,1,1,1,0,1},{0,0,0,0,0,1},{0,0,1,0,0,1},{1,1,0,1,1,0},{1,0,0,1,0,0}};
    std::vector<int> mtx1D{ 10, 20, 10, 5, 15 };
    std::vector<std::vector<int>> mtx2D{ {10,20,30}, {5,10,20}, {2,4,6} };

    std::cout << "PrefixSumOf1DArray\nInput:\n" << mtx1D 
              << "Output:\n" << PrefixSumOf1DArray(mtx1D) << std::endl;

    std::cout << "PrefixSumOf2DArray\nInput:\n" << mtx2D
              << "Output:\n" << PrefixSumOf2DArray(mtx2D) << std::endl;
  }
}