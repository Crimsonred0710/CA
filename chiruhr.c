#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    char cw[100], str[100] = {'\0'};
    printf("Enter the codeword : ");
    gets(cw);
    int dl = strlen(cw);
    int pb = 0;
    while (1)
    {
        if ((int)pow(2, pb) >= dl + 1)
        {
            break;
        }
        pb++;
    }
    int n = 0;
    for (int i = 0; i < pb; i++)
    {
        int pos = pow(2, i);
        int ans = 0;
        for (int j = pos; j <= pb + dl; j += (pos * 2))
        {
            for (int k = j; k <= j + pos - 1 && k <= dl; k++)
            {
                ans = ans ^ (cw[dl - k] - 48);
            }
        }
        str[n] = (char)(ans + 48);
        n++;
    }
    for (int i = 0; i < strlen(str) / 2; i++)
    {
        char ch = str[i];
        str[i] = str[strlen(str) - i - 1];
        str[strlen(str) - i - 1] = ch;
    }
    n = atoi(str);
    int k = 0;
    int num = 0;
    while (n > 0)
    {
        int m = n % 10;
        num = num + (m * (int)pow(2, k));
        k++;
        n /= 10;
    }
    if (num == 0)
    {
        printf("valid code word");
    }
    else
    {
        printf("Error at position %d", num);
    }
}