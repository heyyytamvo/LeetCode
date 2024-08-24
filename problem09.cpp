#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        // base case 0
        if (s.size() == 0){
            return true;
        }

        // base case 1
        if (s.size() == 1){
            return true;
        }

        // base case 2
        if (s.size() == 2){
            if (s[0] == s[1]){
                return true;
            }
            return false;
        }

        int pt1 = 0;
        int pt2 = s.size() - 1;

        // odd
        while (pt1 != pt2){
            if ((pt2 - pt1) == 1){
                break;
            }

            if (s[pt1] == s[pt2]){
                pt1++;
                pt2--;
                continue;
            }else{
                return false;
            }
        }

        if (s[pt1] != s[pt2]){
            return false;
        }
        return true;
    }
};