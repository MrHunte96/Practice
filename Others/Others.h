#pragma once
#include <vector>

namespace Others
{
  std::vector<int> PrefixSumOf1DArray(const std::vector<int>& matrix);
  std::vector<std::vector<int>> PrefixSumOf2DArray(const std::vector<std::vector<int>>& matrix);

  void TestPrefixSumOfMatrix();
}
