#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int area(int pt1, int pt2, vector<int>& height){
        return (pt2 - pt1) * min(height[pt1], height[pt2]);
    }

    int maxArea(vector<int>& height) {
        int length = height.size();
        int pt1 = 0;
        int pt2 = length - 1;
        int result = area(pt1, pt2, height);

        // base case:
        if (length == 2){
            return area(pt1, pt2, height);
        }

        while (pt2 != pt1){

            result = max(result, area(pt1, pt2, height));

            if (height[pt2] > height[pt1]){
                pt1++;
                continue;
            }else{
                pt2--;
            }

        }
        return result;
    }
};

int main() {
    // Define a vector of integers
    vector<int> numbers;

    // Add elements to the vector
    numbers.push_back(8);
    numbers.push_back(20);
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(4);
    numbers.push_back(5);
    numbers.push_back(6);

    Solution sol = Solution();
    cout << sol.maxArea(numbers);


    return 0;
}

