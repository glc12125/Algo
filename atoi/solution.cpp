#include <string>
#include <math.h>
#include <iostream>

using namespace std;

const int MAX = 2147483647;
const int MIN = -2147483648;

class Solution
{

public:
    inline std::string trim_right_copy(
        const std::string &s,
        const std::string &delimiters = " \f\n\r\t\v" )
    {
        return s.substr( 0, s.find_last_not_of( delimiters ) + 1 );
    }

    inline std::string trim_left_copy(
        const std::string &s,
        const std::string &delimiters = " \f\n\r\t\v" )
    {
        return s.substr( s.find_first_not_of( delimiters ) );
    }

    inline std::string trim_copy(
        const std::string &s,
        const std::string &delimiters = " \f\n\r\t\v" )
    {
        return trim_left_copy( trim_right_copy( s, delimiters ), delimiters );
    }

    int myAtoi(string str)
    {
        if (str.empty()) {
            return 0;
        }
        str = trim_copy(str);
        const char *cStr = str.c_str();
        int index = 0;
        bool negative = false;
        if (cStr[0] == '-') {
            ++index;
            negative = true;
        } else if (cStr[0] == '+') {
            ++index;
        }

        const char *a = cStr;
        int indexCopy = index;
        size_t s = 0;
        while (a[indexCopy] > 47 && a[indexCopy] < 58 && a[indexCopy] != '\n') {
            ++s;
            ++indexCopy;
        }
        int w = s - 1;
        long result = 0;
        bool initialNum = false;
        for (; index < s + 1; ++index) {
            if (cStr[index] < 48 || cStr[index] > 57) {
                break;
            } else {
                result += (cStr[index] - 48) * (int)pow(10, w--);
            }
        }

        if (negative) {
            result = -result;
            if (result > 0 || result < MIN) {
                return MIN;
            } else {
                return (int)result;
            }
            return result < MIN ? MIN : result;
        } else {
            if (result < 0 || result > MAX) {
                return MAX;
            } else {
                return (int)result;
            }
        }

    }
};
