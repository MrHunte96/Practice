#include "Helper.h"
#include <iomanip>

Test::Test(const std::string& name) :
    m_testName { name },
    hConsole { GetStdHandle(STD_OUTPUT_HANDLE) }
{
    SetConsoleTextAttribute(hConsole, 14); // yellow
    std::cout << m_testName << " Running...";
}

Test::~Test()
{
    SetConsoleTextAttribute(hConsole, 7); // grayish
}

void Test::eraseRunning()
{
    int count = 11 + (int)m_testName.size();
    for(int n = 0; n < count; ++n)
        printf("\b \b");
    std::cout << std::flush;
}

void Test::printSucceed()
{
    eraseRunning();
    SetConsoleTextAttribute(hConsole, 10); // green
    std::cout << m_testName << "() - Success" << std::endl;
}

void Test::printFailure()
{
    eraseRunning();
    SetConsoleTextAttribute(hConsole, 12); // red 
    std::cout << m_testName << "() - Failed" << std::endl;
}

/******************************************************************************/

PrintTestName::PrintTestName(const char* str)
{
    std::cout << "********** " << str << " **********\n";
}

PrintTestName::~PrintTestName()
{
    std::cout << std::endl;
}

/******************************************************************************/

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