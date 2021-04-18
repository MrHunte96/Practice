#pragma once
#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& os, const std::vector<int>& arr);
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<int>>& mtx);
