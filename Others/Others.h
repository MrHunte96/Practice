#pragma once

#include <vector>
#include <iostream>

namespace Others
{
    using Array2D = std::vector<std::vector<T>>;
    Array2D PrefixSumOfMatrix(Array2D& matrix);

    void TestPrefixSumOfMatrix();
}