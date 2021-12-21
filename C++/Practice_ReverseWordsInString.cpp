#include "Helper.h"

// Reverse words in a string (No library allowed)
char* ReverseWordsInString(const char* string)
{
    return nullptr;
}

// Reverse words in a string
std::string ReverseWordsInString(const std::string& string)
{
    return std::string();
}

void Test0(bool useLib)
{
    StartTest();
    const char* input = nullptr;
    const char* expected = "";

    bool equal;
    if (useLib)
    {
        // std::string can't create from nullptr
        //std::string output_string = ReverseWordsInString(std::string(input));
        equal = true; //IsEqual(output_string, std::string(expected));
    }
    else
    {
        const char* output_char = ReverseWordsInString(input);
        equal = IsEqual(output_char, expected);
        delete output_char;
    }

    if (equal) TestSucceed()
    else TestFailure()
}

void Test1(bool useLib)
{
    StartTest();
    const char* input = "";
    const char* expected = "";

    bool equal;
    if (useLib)
    {
        std::string output_string = ReverseWordsInString(std::string(input));
        equal = IsEqual(output_string, std::string(expected));
    }
    else
    {
        const char* output_char = ReverseWordsInString(input);
        equal = IsEqual(output_char, expected);
        delete output_char;
    }

    if (equal) TestSucceed()
    else TestFailure()
}

void Test2(bool useLib)
{
    StartTest();
    const char* input = "This is a sentence";
    const char* expected = "sentence a is This";

    bool equal;
    if (useLib)
    {
        std::string output_string = ReverseWordsInString(std::string(input));
        equal = IsEqual(output_string, std::string(expected));
    }
    else
    {
        const char* output_char = ReverseWordsInString(input);
        equal = IsEqual(output_char, expected);
        delete output_char;
    }

    if (equal) TestSucceed()
    else TestFailure()
}

void Test3(bool useLib)
{
    StartTest();
    const char* input = "Word";
    const char* expected = "Word";

    bool equal;
    if (useLib)
    {
        std::string output_string = ReverseWordsInString(std::string(input));
        equal = IsEqual(output_string, std::string(expected));
    }
    else
    {
        const char* output_char = ReverseWordsInString(input);
        equal = IsEqual(output_char, expected);
        delete output_char;
    }

    if (equal) TestSucceed()
    else TestFailure()
}

void Test4(bool useLib)
{
    StartTest();
    const char* input = "The quick brown fox jumps over the lazy dog";
    const char* expected = "dog lazy the over jumps fox brown quick The";

    bool equal;
    if (useLib)
    {
        std::string output_string = ReverseWordsInString(std::string(input));
        equal = IsEqual(output_string, std::string(expected));
    }
    else
    {
        const char* output_char = ReverseWordsInString(input);
        equal = IsEqual(output_char, expected);
        delete output_char;
    }

    if (equal) TestSucceed()
    else TestFailure()
}

/********************************* Driver *************************************/
int main()
{
    // Reset Color
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);

    {
        StartTestCases("Reverse words in a string - char*");
        Test0(false);
        Test1(false);
        Test2(false);
        Test3(false);
        Test4(false);
    }
    {
        StartTestCases("Reverse words in a string - std::string");
        Test0(true);
        Test1(true);
        Test2(true);
        Test3(true);
        Test4(true);
    }

    // Reset Color
    SetConsoleTextAttribute(hConsole, 7);
    return 0;
}