#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    printf("enter receiver's dataword :: ");
    scanf("%s", &str);
    printf("Enter e for even parity check and o for odd pariye chcek :: ");
    int count = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '1')
            count++;
    }
    char ch;
    scanf(" %c", &ch);
    switch (ch)
    {
    case 'e':
        if (count % 2 == 0)
            printf("No error");
        else
            printf("Error");
        break;
    case 'o':
        if (count % 2 == 0)
            printf("Error");
        else
            printf("Not Error");
        break;
    default:
        printf("You entered wrongly ");
    }
}
