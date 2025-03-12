%{
#include <stdio.h>
#include <string.h>
%}

%%

[Cc]harusat    { printf("university"); }  // Replace "charusat" (case-insensitive) with "university"
.|\n           { printf("%s", yytext); }  // Print all other characters as they are

%%

int main() {
    printf("Enter the input text:\n");
    yylex();  // Call the lexer
    return 0;
}

int yywrap() {
    return 1;
}
