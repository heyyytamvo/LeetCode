#include <iostream>
#include <vector>

using namespace std;

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;


int solution(vector<int> &A) {
    // Implement your solution here
    int size = static_cast<int>(A.size());
    vector<int> maxLeft;
    vector<int> maxRight;


    // base case
    if (size == 2){
        return 0;
    }

    int maxLeftValue = -1;
    for (int i = 0; i < size; i++){
        maxLeftValue = max(A[i], maxLeftValue);
        maxLeft.push_back(maxLeftValue);
    }

    int maxRightValue = -1;
    for (int i = size - 1; i >= 0; i--){
        maxRightValue = max(A[i], maxRightValue);
        maxRight.push_back(maxRightValue);
    }

    int result = 0;
    for (int i = 0; i < size; i++){
        result = max(result,( min(maxLeft[i], maxRight[size - i]) - A[i]));
    }

    // // debug
    // for (int i = 0; i < size; i++){
    //     cout << maxLeft[i] << " ";
    // }

    // cout << endl;

    // for (int i = 0; i < size; i++){
    //     cout << maxRight[i] << " ";
    // }

    // cout << endl;

    return result;
}

int main(){
    int a[11] = {1, 3, 2, 1, 2, 1, 5, 3, 3, 4, 2};

    vector<int> vec;
    for (int i = 0; i < 11; i++){
        vec.push_back(a[i]);
    }
    cout << solution(vec) << endl;
}
