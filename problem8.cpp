#include <iostream>
#include <string>
#include <cmath>
using namespace std;


class Solution {
public:

    bool is_digit(char c){
        int result = c - '0';
        return ((result >= 0) && (result <= 9));
    }


    int myAtoi(string s) {
        int index_1 = -1;
        int index_2 = -1;
        bool sign_exist = false;
        int k = 0;

        // no input
        if (s.size() == 0){
            return 0;
        }

        // only 1 digit
        if ((s.size() == 1) && is_digit(s[0])){
            return stoi(s);
        }

        if (s.size() == 1 && !is_digit(s[0])){
            return 0;
        }

        // removing white space in the begining
        while (k < s.size())
        {
            char c = s[k];
            if (c != ' '){
                break;
            }
            k++;
        }

        // if word exist before number, return 0
        int word_index = -1;
        int digit_index = -1;
        for (int i = k; i < s.size(); i++){
            if ((word_index != -1) && (digit_index != -1)){
                break;
            }

            if (!(is_digit(s[i]) || (s[i] == '-') || (s[i] == '+'))){
                if (word_index == -1){
                    word_index = i;
                }
            }else if (is_digit(s[i])){
                if (digit_index == -1){
                    digit_index = i;
                }
                
            }
        }

        // only word detected
        if ((word_index != -1) && (digit_index == -1)){
            return 0;
        }

        // no word or digit detected
        if ((word_index == -1) && (digit_index == -1)){
            return 0;
        }

        // word exist before digit
        if ((word_index != -1) && (digit_index != -1) && (word_index < digit_index)){
            return 0;
        }
        


        // beginning with k
        for (int i = k; i < s.size(); i++){
            char c = s[i];
        
            if (sign_exist && ((i + 1) < s.size())){
                // cout << "at i = " << i << endl;
                if (((s[i] == '-') || (s[i] == '+')) && ((s[i - 1] == '-') || (s[i - 1] == '+'))){
                    
                    return 0;
                }
            }

            //detect sign
            if (((index_1 == -1) && (c == '-')) || ((index_1 == -1) && (c == '+'))){
                sign_exist = true;
                index_1 = i;
                continue;
            }

            
            if (is_digit(c) && (index_1 == -1)){
                index_1 = i;
                continue;
            }

            if (is_digit(c) && (index_1 != -1)){      
                index_2 = i;
            }
        }


        if (index_2 == -1){
            index_2 = index_1;
        }
        string mySubtr = s.substr(index_1, index_2 + 1);
        int _32signed;
        

        
        try
        {
            _32signed = stoi(mySubtr);
        }
        catch(const std::exception& e)
        {
            if (mySubtr[0] == '-'){
                return -2147483648;
            }else{
                return 2147483647;
            }
        }

        return _32signed;
    }
};