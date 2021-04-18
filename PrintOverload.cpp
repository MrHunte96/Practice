#include "PrintOverload.h"
#include <iomanip>

std::ostream& operator<<(std::ostream& os, const std::vector<int>& arr)
{
  os << "[";
  for (size_t x = 0; x < arr.size(); ++x)
  {
    os << std::setw(3) << arr[x];
    if (x < arr.size() - 1)
      os << ", ";
  }
  os << "]" << std::endl;

  return os;
}

std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<int>>& mtx)
{
  for (size_t y = 0; y < mtx.size(); ++y)
  {
    os << "[";
    for (size_t x = 0; x < mtx[y].size(); ++x)
    {
      os << std::setw(3) << mtx[y][x];
      if (x < mtx[y].size() - 1)
        os << ", ";
    }
    os << "]" << std::endl;
  }

  return os;
}