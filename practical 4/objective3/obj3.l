%{
#include <stdio.h>

int char_count = 0, word_count = 0, line_count = 0;
%}

%%

\n        { line_count++; char_count++; }  // Count lines and newline as a character
[ \t]+    { char_count++; }               // Count spaces and tabs as characters
[^\n \t]+ { word_count++; char_count += yyleng; } // Count words and characters

%%

int main() {
    printf("Reading input from file...\n");
    yylex();  // Process input

    // Print the final counts
    printf("Characters : %d\n", char_count);
    printf("Words : %d\n", word_count);
    printf("Lines : %d\n", line_count);

    return 0;
}

int yywrap() {
    return 1;
}
