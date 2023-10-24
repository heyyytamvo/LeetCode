#include <vector>
#include <iostream>

using namespace std;

// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int size = s.size();
        
//         vector< vector<bool> > M = vector< vector<bool> > (size, vector<bool>(size, false));
//         for (int i = 0; i < size; i++){
//             M[i][i] = true;
//         }  

//         for (int i = 1; i < size; i++){

//             int right = i + 1;
//             int left = i - 1;

//             while ((right < size) && (left >= 0)){
//                 M[i][left] = (s[left] == s[right]);
//                 right++;
//                 left--;
//             }
//         } 
//     }
// };


// void test(string s){
//     int size = s.size();
        
//     vector< vector<bool> > M = vector< vector<bool> > (size, vector<bool>(size, false));
//     for (int i = 0; i < size; i++){
//         M[i][i] = true;
//         N[i][i] = true;
//     }  


//     for (int i = 0; i < size; i++){
//         int right = i + 1;
//         int left = i - 1;

//         while ((right < size) && (left >= 0)){
//             M[i][left] = (s[left] == s[right]);
//             M[i][right] = (s[left] == s[right]);
//             right++;
//             left--;
//         }
//     }

//     for (int i = 0; i < size; i++){
//         for (int j = 0; j < size; j++){
//             cout << M[i][j] << ' ';
//         }
//         cout << endl;
//     } 
// }

// int main(){
//     test("babad");
//     cout << "-----" << endl;
//     test("cbbd");
//     return 0;
// }