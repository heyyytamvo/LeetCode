#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        map<int, int> index;
        vector<int> result = vector<int> (2, -1);

        for (int i = 0; i < len; i++){
            int current = nums[i];
            int complement = target - current;

            if (index.count(complement) > 0){
                result[0] = i;
                result[1] = index[complement];
                return result;
            }else{
                index.insert(make_pair(current, i));
            }
        }
        return result;
    }
};
