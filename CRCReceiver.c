#include <stdio.h>
#include <string.h>
int main()
{
    char dw[100];
    char div[100];
    char dw1[100];
    int count = 0;
    printf("Enter the Dataword :: ");
    scanf("%s", &dw);
    printf("Enter the Divisor :: ");
    scanf("%s", &div);
    int dl = strlen(dw);
    int divl = strlen(div);
    // for (int i = 0; i < divl - 1; i++)
    // {
    //     dw[dl + i] = '0';
    // }
    // dw[dl + divl - 1] = '\0';
    // printf("\nYour updated dataword after adding 0 :: %s", dw);
    strcpy(dw1, dw);
    for (int i = 0; i < dl; i++)
    {
        if (dw1[i] == '1')
        {
            for (int j = 0; j < divl; j++)
            {
                if (dw1[i + j] == div[j])
                {
                    dw1[i + j] = '0';
                }
                else
                    dw1[i + j] = '1';
            }
        }
    }
    for (int i = 0; i < strlen(dw1); i++)
    {
        if (dw1[i] == '0')
            count++;
    }
    printf("\nCount=%d", count);
    if (count == strlen(dw1))
    {
        printf("\nNo Error");
    }
    else
    {
        printf("\nError");
    }
    printf("\nActual Data :: ");
    for (int i = 0; i < strlen(dw) - divl + 1; i++)
        printf("%c", dw[i]);
}