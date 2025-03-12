%{
#include <stdio.h>
%}

%%

[0-9]+    { printf("%s\n", yytext); }  // Match numbers and print them

.|\n      { /* Ignore other characters */ }

%%

int main() {
    printf("Enter the input string: ");
    yylex();  // Call the lexer
    return 0;
}

int yywrap() {
    return 1;
}
