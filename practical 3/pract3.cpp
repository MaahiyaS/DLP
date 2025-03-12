#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>

using namespace std;

const string keywords[] = {"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};
const int num_keywords = 10;

string symbolTable[100];
int symbolCount = 0;


bool isKeyword(const string& word) {
    for (int i = 0; i < num_keywords; i++) {
        if (word == keywords[i]) {
            return true;
        }
    }
    return false;
}

bool isInSymbolTable(const string& word) {
    for (int i = 0; i < symbolCount; i++) {
        if (symbolTable[i] == word) {
            return true;
        }
    }
    return false;
}

void addToSymbolTable(const string& word) {
    if (!isInSymbolTable(word)) {
        symbolTable[symbolCount++] = word;
    }
}

void lexicalAnalyzer(ifstream &file) {
    char ch;
    string buffer = "";
    bool inString = false, inComment = false;

    while (file.get(ch)) {
        if (inComment) {
            if (ch == '*' && file.peek() == '/') {
                file.get(ch);
                inComment = false;
            }
            continue;
        }

        if (ch == '/') {
            char next = file.peek();
            if (next == '/') {
                while (file.get(ch) && ch != '\n');
                continue;
            } else if (next == '*') {
                file.get(ch);
                inComment = true;
                continue;
            }
        }

        if (isalnum(ch) || ch == '_') {
            buffer += ch;
        } else {
            if (!buffer.empty()) {
                if (isKeyword(buffer)) {
                    cout << "Keyword: " << buffer << endl;
                } else if (isdigit(buffer[0])) {
                    cout << "Constant: " << buffer << endl;
                } else {
                    cout << "Identifier: " << buffer << endl;
                    addToSymbolTable(buffer);
                }
                buffer = "";
            }

            if (isspace(ch)) {
                continue;
            } else if (ch == '"' || ch == '\'') {
                string str = "";
                str += ch;
                while (file.get(ch) && ch != '"' && ch != '\'') {
                    str += ch;
                }
                str += ch;
                cout << "String: " << str << endl;
            } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '<' || ch == '>') {
                cout << "Operator: " << ch << endl;
            } else if (ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == ';' || ch == ',') {
                cout << "Punctuation: " << ch << endl;
            } else {
                cout << "Lexical Error: Invalid character '" << ch << "'" << endl;
            }
        }
    }
}

int main() {
    ifstream file("input2.c");
    if (!file) {
        cout << "Error: Could not open file input.c" << endl;
        return 1;
    }

    lexicalAnalyzer(file);
    file.close();

    cout << "\nSymbol Table:\n";
    for (int i = 0; i < symbolCount; i++) {
        cout << symbolTable[i] << endl;
    }

    return 0;
}
