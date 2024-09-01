#include <iostream>
#include <string>
using namespace std;


bool isDigit(char c){
    return ((c >= 48) && (c <= 57));
}

bool isLetter(char c){
    return (((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122)));
}

bool isValidChar(char c){
    return isDigit(c) || isLetter(c);
}

bool isValidPassword(int numLetter, int numDigit){
    return ((numLetter % 2) == 0) && ((numDigit % 2) == 1);
}

int solution(string &S) {
    // Implement your solution here
    int result = 0;
    string currentString = "";
    int foundAtLeast1Pass = false;
    
    int index = 0;
    int numLetter = 0;
    int numDigit = 0;
    

    while (index < static_cast<int>(S.size())){
        char currentChar = S[index];



        if (isDigit(currentChar)){
            currentString += currentChar;
            numDigit++;
        }

        if (isLetter(currentChar)){
            currentString += currentChar;
            numLetter++;
        }

        
        // if currentChar is space, check the valid password
        if (currentChar == ' '){
            if (isValidPassword(numLetter, numDigit)){
                foundAtLeast1Pass = true;
                result = max(result, static_cast<int>(currentString.length()));
                currentString.clear();
            }
            
            numLetter = 0;
            numDigit = 0;
            currentString.clear();
            index++;
            continue;
        }

        if (!isValidChar(currentChar)){
            // reset
            numLetter = 0;
            numDigit = 0;
            currentString.clear();
            while (index < static_cast<int>(S.size())){
                index++;
                if (S[index] == ' '){
                    break;
                }
            }
            index++;
            continue;
        }

        index++;
    }
    
    return foundAtLeast1Pass ? result : -1;;
}