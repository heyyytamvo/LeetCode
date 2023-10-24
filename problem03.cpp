#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> index;
        int length = s.size();
        int result = 0;
        int i = 0;
        int j = 0;

        while (i < length && j < length){
            char current = s[j];
            // cout << "Current char: " << current << endl;
            // cout << "j is " << j << endl;
            // cout << "i is " << i << endl;
            if (index.count(current) == 0){
                // cout << "Current char is not in map, now its key value is " << current << " " << j << endl;
                index.insert(make_pair(current, j));        
            }else{
                // cout << "Current char exists in map" << endl;
                if (index[current] >= i){
                    // cout << "The last time I saw the character is at: " << index[current] << ", where belongs to the current substring" << endl;
                    // cout << "Update i to " << index[current] + 1 << endl;
                    // cout << "Update index[current] to " << j << endl;
                    i = index[current] + 1;
                    index[current] = j;
                }else{
                    // cout << "The last time I saw the character is at: " << index[current] << ", where does not belong to the current substring" << endl; 
                    // cout << "DO NOT UPDATE i but index[current] " << endl;
                    index[current] = j;
                }
            }
            result = max(result, j - i + 1);
            j++;
        }
        
        return result;
    }
};