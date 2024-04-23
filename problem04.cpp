#include <iostream>
#include <vector>
#include<queue>
using namespace std;

class Solution {

public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int> pq;
        double result;
        for (int i = 0; i < nums1.size(); i++){
            pq.push(nums1[i]);
        }    

        for (int i = 0; i < nums2.size(); i++){
            pq.push(nums2[i]);
        }
        int total_size = nums1.size() + nums2.size();
        double a;
        double b;
        if ((total_size % 2) == 0){
            for (int x = 0; x <= (total_size / 2); x++){
                if (x == ((total_size / 2) - 1)){
                    a = pq.top();
                    pq.pop();
                    continue;
                }
                if (x == (total_size / 2)){
                    b = pq.top();
                    pq.pop();
                    continue;
                }
                pq.pop();
            }
            result = (a + b) / 2;
        }else{
            int count = 0;
            while (count < (total_size / 2)){
                pq.pop();
                count++;
            }
            result = pq.top();
        }       
        return result; 
    }
};