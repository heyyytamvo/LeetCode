#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    string number(ListNode* node){
        if (node->next == nullptr){
            return to_string(node->val);
        }
        string result = "";
        result += number(node->next);
        result += to_string(node->val);
        return result;
    }

    string addingTwoString(string &a, string &b){
        stringstream result;
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;

        while (i >= 0 || j >= 0 || carry > 0) {
            int digit1 = (i >= 0) ? (a[i] - '0') : 0;
            int digit2 = (j >= 0) ? (b[j] - '0') : 0;
            int sum = digit1 + digit2 + carry;

            result << (sum % 10);
            carry = sum / 10;

            i--;
            j--;
        }

        string sumStr = result.str();
        reverse(sumStr.begin(), sumStr.end());
        return sumStr;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ListNode* result = new ListNode(); 
        string l1_int = number(l1);
        string l2_int = number(l2);
        string result = addingTwoString(l1_int, l2_int);
        
        int lenString = result.size();

        ListNode* output = new ListNode(result[(lenString - 1)] - '0');
        ListNode* current = output;
        for (int i = lenString - 2; i >= 0; i--){
            ListNode* temp = new ListNode(result[i] - '0');
            current->next = temp;
            current = current->next;
        }

        return output;
    }
};

string number(ListNode* node){
        if (node->next == nullptr){
            return to_string(node->val);
        }
        string result = "";
        result += number(node->next);
        result += to_string(node->val);
        return result;
    }

    string addingTwoString(string &a, string &b){
        long long temp = stoll(a) + stoll(b);
        string result = to_string(temp);
        return result;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ListNode* result = new ListNode(); 
        string l1_int = number(l1);
        string l2_int = number(l2);
        string result = addingTwoString(l1_int, l2_int);
        
        int lenString = result.size();

        ListNode* output = new ListNode(result[(lenString - 1)] - '0');
        ListNode* current = output;
        for (int i = lenString - 2; i >= 0; i--){
            ListNode* temp = new ListNode(result[i] - '0');
            current->next = temp;
            current = current->next;
        }

        return output;
    }