#pragma once
#include <vector>

namespace Algorithms
{
  std::vector<int> PrefixSumOf1DArray(const std::vector<int>& matrix);
  std::vector<std::vector<int>> PrefixSumOf2DArray(const std::vector<std::vector<int>>& matrix);

  void TestPrefixSumOfMatrix();
}
