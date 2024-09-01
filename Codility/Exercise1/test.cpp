#include <iostream>
#include <string>
#include <algorithm> // For std::max
using namespace std;

bool isValidChar(char c) {
    return (isdigit(c) || isalpha(c)); // Use standard library functions
}

bool isDigit(char c) {
    return isdigit(c); // Use standard library functions
}

bool isLetter(char c) {
    return isalpha(c); // Use standard library functions
}

bool isValidPassword(int numLetter, int numDigit) {
    return (numLetter % 2 == 0) && (numDigit % 2 == 1);
}

int solution(string S) {
    int result = 0;
    string currentString = "";
    bool foundAtLeast1Pass = false;

    int index = 0;
    int numLetter = 0;
    int numDigit = 0;

    while (index < static_cast<int>(S.size())) {
        char currentChar = S[index];

        if (!isValidChar(currentChar)) {
            // Reset counts and current string
            numLetter = 0;
            numDigit = 0;
            currentString.clear();
            index++;

            // Skip invalid characters until the next space or end of string
            while (index < static_cast<int>(S.size()) && S[index] != ' ') {
                index++;
            }
            continue;
        }

        if (isDigit(currentChar)) {
            currentString += currentChar;
            numDigit++;
        } else if (isLetter(currentChar)) {
            currentString += currentChar;
            numLetter++;
        }

        index++;

        // If current character is a space or the end of the string, check the valid password
        if (currentChar == ' ' || index == static_cast<int>(S.size())) {
            if (isValidPassword(numLetter, numDigit)) {
                foundAtLeast1Pass = true;
                result = max(result, static_cast<int>(currentString.length()));
            }
            // Reset counts and current string for the next potential password
            numLetter = 0;
            numDigit = 0;
            currentString.clear();
        }
    }

    return foundAtLeast1Pass ? result : -1; // Return -1 if no valid password was found
}

int main() {
    string s = "test 5 a0A pass007 ?xy1";
    cout << s << endl;
    cout << solution(s) << endl;
    return 0;
}