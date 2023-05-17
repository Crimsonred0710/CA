#include <stdio.h>
#include <string.h>
int main()
{
    char str[100], s0[10] = {'0'}, s1[10] = {'1'};
    int c = 0, count = 0;
    int dwl = 0;
    printf("Enter the dataword :: ");
    scanf("%s", &str);
    printf("You entered dataword :: %s", str);
    dwl = strlen(str);
    printf("\nDataword Length :: %d", dwl);
    for (int i = 0; i < dwl; i++)
    {
        if (str[i] == '1')
            count++;
    }
    printf("\nNumber of 1's :: %d", count);
    printf("\nEnter e Even or o for Odd parity :: ");
    char ch;
    scanf(" %c", &ch);
    switch (ch)
    {
    case 'e':
        if (count % 2 == 0)
        {
            strcat(str, s0);
        }
        else
        {
            strcat(str, s1);
        }
        printf("Updated Codeword :: %s", str);
        break;
    case 'o':
        if (count % 2 == 0)
        {
            strcat(str, s1);
        }
        else
        {
            strcat(str, s0);
        }
        printf("Updated Codeword :: %s", str);
        break;
    default:
        printf("Wrong Input");
    }
}