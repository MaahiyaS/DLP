%{
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int has_lower = 0, has_upper = 0, has_digit = 0, has_symbol = 0, length = 0;
%}

%%

[a-z]          { has_lower = 1; length++; }  // Detects lowercase letters
[A-Z]          { has_upper = 1; length++; }  // Detects uppercase letters
[0-9]          { has_digit = 1; length++; }  // Detects digits
[*;#$@]        { has_symbol = 1; length++; } // Detects allowed symbols
[^\n]          { length++; }                 // Count all valid characters
\n            { 
                if (length >= 9 && length <= 15 && has_lower && has_upper && has_digit && has_symbol) 
                    printf("Valid password\n");
                else 
                    printf("Invalid password\n");

                // Reset flags for next input
                has_lower = has_upper = has_digit = has_symbol = 0;
                length = 0;
              }

%%

int main() {
    printf("Enter password: ");
    yylex();   // Start Lexical Analysis
    return 0;
}

int yywrap() {
    return 1;
}
