#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

    string revertString(string s, int lengthS){
        string result = "";
        if (lengthS == 0){
            return "";
        }
        string subS = s.substr(0, s.length() - 1);
        return result += s[lengthS - 1] + revertString(subS, lengthS - 1);
    }
    int reverse(int x) {
        string x_string  = to_string(x);

        string result;

        if (x == 0){
            return x;
        } else if (x < 0){
            result = "-";
            result += revertString(x_string.substr(1, x_string.length() - 1), x_string.length() - 1);
        }else {
            result = revertString(x_string, x_string.length());
        }

        char* endptr = NULL;
        long long ll = strtoll(result.c_str(), &endptr, 10);

        if ((ll < -2147483648) || (ll > 2147483647)){
            return 0;
        }
        
        return ll;
    }
};