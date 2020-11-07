
#include <iostream>
#include "utstack.h"

const int problemNumber = 1;

// Задача 1 
const int nBracketTypes = 3;
const char brackets[nBracketTypes][2] = { {'(', ')'},{'{', '}'},{'[', ']'} };

char closingBracket(const char openingBracket) {
    for (int i = 0; i < nBracketTypes; i++)
        if (brackets[i][0] == openingBracket)
            return brackets[i][1];
    return '\0';
}

char openingBracket(const char closingBracket) {
    for (int i = 0; i < nBracketTypes; i++)
        if (brackets[i][1] == closingBracket)
            return brackets[i][0];
    return '\0';
}

void bracketChecker(int argc, char* argv[])
{
    if (argc > 1) {
        TStack<char> bracketStack(100);
        bool mistakeFlag = false;
        for (int i = 0; i < strlen(argv[1]); i++) {
            if (closingBracket(argv[1][i]) != '\0')
                bracketStack.push(argv[1][i]);
            if (openingBracket(argv[1][i]) != '\0') {
                if (bracketStack.empty()) mistakeFlag = true;
                else if (argv[1][i] != closingBracket(bracketStack.top())) mistakeFlag = true;
                else bracketStack.pop();
            }
        }
        if (!bracketStack.empty()) mistakeFlag = true;
        std::cout << "The brackets in expression " << argv[1] << " are placed ";
        if (mistakeFlag) std::cout << "incorrectly\n";
        else std::cout << "correctly\n";
    }
    else std::cout << "No expression found\n";
}

// Задача 3

template<class T> class StackWithMinimum : public TStack<T> {
private:
    TStack<T> minimums;
public:
    StackWithMinimum() : TStack<T>() {
        minimums.TStack::TStack();
    }
    StackWithMinimum(int maxs) : TStack<T>(maxs) {
        minimums.TStack::TStack(maxs);
    }
    StackWithMinimum(const StackWithMinimum& s) : TStack<T>(s) {
        minimums.TStack::TStack(s.minimums);
    }
    void push(T elem) {
        if (empty() || elem < minimums.top()) minimums.push(elem);
        else minimums.push(minimums.top());
        TStack<T>::push(elem);
    }
    void pop() {
        minimums.pop();
        TStack<T>::pop();
    }
    int minimum() {
        return minimums.top();
    }
};

int main(int argc, char* argv[]) {
    switch (problemNumber) {
    case 1: {
        bracketChecker(argc, argv);
        break;
    }
    case 3: {
        StackWithMinimum<int> swm(5);
        swm.push(3); std::cout << swm.minimum() << std::endl;
        swm.push(5); std::cout << swm.minimum() << std::endl;
        swm.push(1); std::cout << swm.minimum() << std::endl;
        swm.push(2); std::cout << swm.minimum() << std::endl;
        swm.pop(); std::cout << swm.minimum() << std::endl;
        swm.pop(); std::cout << swm.minimum() << std::endl;
        swm.pop(); std::cout << swm.minimum() << std::endl;
        break;
    }
    }
}