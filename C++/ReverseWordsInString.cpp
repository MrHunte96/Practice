#include "Helper.h"
#include <sstream>

// Reverse words in a string (No library allowed)
char* ReverseWordsInString(const char* string)
{
    if (string == nullptr) return new char[1]{ '\0' };

    long long length = 0;

    // Get string length & num of words
    const char* startptr = string;
    const char* endptr = string;

    while ((*startptr++) != '\0') length++;

    char* result = new char[length + 1];
    result[length] = '\0';
    char* rptr = result;

    startptr = string;

    int copiedlen = 0;
    while (true)
    {
        if (*startptr == '\0' && *endptr == '\0')
            break;

        if (*endptr == ' ' || *endptr == '\0')
        {
            int strlen = static_cast<int>(endptr - startptr);
            // copy to result
            while(startptr != endptr)
                result[length - copiedlen - (endptr - startptr)] = *(startptr++);

            if(copiedlen!=0)
                result[length - copiedlen] = ' ';
            copiedlen += strlen + 1;

            if(*endptr == ' ')
                startptr = endptr + 1;
        }
        endptr++;
    }

    return result;
}

// Reverse words in a string
std::string ReverseWordsInString(const std::string& string)
{
    std::stringstream ss(string);
    std::string result;
    std::string token;

    while (std::getline(ss, token, ' '))
        result = token + (result.empty() ? "" : " ") + result;

    return result;
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