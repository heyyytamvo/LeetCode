#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {

public:
    vector<int> defactor(int num){
        vector<int> result;
        int myNum = num;
        int base[4] = {1000, 100, 10, 1};

        for (int i = 0; i < 4; i++){
            result.push_back(round(myNum / (base[i])));
            myNum = myNum - (round(myNum / (base[i])) * base[i]);
        }

        return result;
    }

    string intToRoman(int num) {
        string result = "";
        vector<int> defactor_list = defactor(num);
        for (int i = 0; i < 4; i++){
            // 1000
            if (i == 0){
                if (defactor_list[i] == 0){
                    continue;
                }else{
                    result += string(defactor_list[i], 'M');
                }
                cout << result << endl;
            }

            // 100
            else if (i == 1){
                // case 9
                if (defactor_list[i] == 9){
                    result += "CM";
                }
                //case 5 .. 8
                else if (defactor_list[i] >= 5){
                    result += string(1, 'D') + string(defactor_list[i] - 5, 'C');
                }
                //case 4
                else if (defactor_list[i] == 4){
                    // Todo
                    result += "CD";
                }
                // case 1 2 3
                else{
                    result += string(defactor_list[i], 'C');
                }
                cout << result << endl;
            }

            // 10
            else if (i == 2){
                // case 9
                if (defactor_list[i] == 9){

                    result += "XC";
                }
                //case 5 .. 8
                else if (defactor_list[i] >= 5){
                    result += string(1, 'L') + string((defactor_list[i] - 5), 'X');
                }
                //case 4
                else if (defactor_list[i] == 4){
                    // Todo
                    result += "XL";
                }
                // case 1 2 3
                else{
                    result += string(defactor_list[i], 'X');
                }

                cout << result << endl;
            }

            // 1
            else{
                // case 9
                if (defactor_list[i] == 9){

                    result += "IX";
                }
                //case 5 .. 8
                else if (defactor_list[i] >= 5){
                    result += string(1, 'V') + string(defactor_list[i] - 5, 'I');
                }
                //case 4
                else if (defactor_list[i] == 4){
                    // Todo
                    result += "IV";
                }
                // case 1 2 3
                else{
                    result += string(defactor_list[i], 'I');
                }
                cout << result << endl;
            }
        }
        return result;
    }
};