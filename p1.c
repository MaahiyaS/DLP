#include<stdio.h>

int main()
{
    char c[20];
    printf("enter a string:");
    scanf("%s", c);

    if (c[0] == 'a' || c[0] == 'b')
        {
            int n = strlen(c);
            if (n >= 2 && c[n - 2] == 'b' && c[n - 1] == 'b')
            {
                for(int i=0; i<(n-2); i++)
                {
                    if(c[i]!='a')
                    {
                        printf("Invalid string\n");
                        return 0;
                    }
                }
                printf("Valid String\n");
            }
            else
            {
                printf("Invalid string\n");
            }
        }
    else
    {
        printf("Invalid string\n");
    }

return 0;
}
