#include <string>

using namespace std;

static string alpha[26] = {"A", "B", "C", "D", "E", "F",
                           "G", "H", "I", "J", "K", "L",
                           "M", "N", "O", "P", "Q", "R",
                           "S", "T", "U", "V", "W", "X",
                           "Y", "Z"
                          };
class Solution
{
public:
    string convertToTitle(int n)
    {
        if (n / 27 == 0) {
            int m = n % 27;
            if (m != 0 ) {
                return alpha[m - 1];
            } else {
                return "";
            }
        } else {
            int m = n % 26;
            if (m != 0) {
                return convertToTitle(n / 26) + alpha[m - 1];
            } else {
                return convertToTitle(n / 27) + "Z";
            }
        }
    }

};
