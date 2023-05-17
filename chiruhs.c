#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    char dw[100], str[100];
    printf("Enter the dataword : ");
    gets(dw);
    int dl = strlen(dw);
    int pb = 0;
    while (1)
    {
        if ((int)pow(2, pb) >= strlen(dw) + pb + 1)
        {
            break;
        }
        pb++;
    }
    printf("The no of redundant bits : %d", pb);
    for (int i = 0; i < pb; i++)
    {
        str[(dl + pb) - (int)pow(2, i)] = 'R';
    }
    int j = 0;
    for (int i = 0; i < pb + dl; i++)
    {
        if (str[i] == 'R')
            continue;
        else
        {
            str[i] = dw[j];
            j++;
        }
    }
    printf("\nThe codeword is : %s", str);
    for (int i = 0; i < pb; i++)
    {
        int pos = pow(2, i);
        int crt = 0;
        for (int j = pos; j <= pb + dl; j += (pos * 2))
        {
            for (int k = j; k <= j + pos - 1 && k <= pb + dl; k++)
            {

                if (str[dl + pb - k] == 'R')
                    continue;
                if (str[dl + pb - k] == '1')
                    crt++;
            }
        }
        if (crt % 2 == 0)
        {
            str[(dl + pb) - (int)pow(2, i)] = '0';
        }
        else
        {
            str[(dl + pb) - (int)pow(2, i)] = '1';
        }
    }
    printf("\nThe codeword is : %s", str);
}