#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char data_word[100], str[100];
    int dl, sl;
    printf("Enter the codeword : ");
    gets(data_word);
    printf("Enter the segment length : ");
    scanf("%d", &sl);
    if (sl & (sl - 1) != 0)
    {
        printf("Invalid segment length\n");
        exit(0);
    }
    char str1[100] = {'\0'};
    dl = strlen(data_word);
    if (dl % sl != 0)
    {
        int i = sl - (dl % sl);
        for (int j = 0; j < i; j++)
        {
            str[j] = '0';
        }
    }
    strcat(str, data_word);
    int sum[sl];
    for (int i = 0; i < sl; i++)
    {
        sum[i] = 0;
    }
    int carry = 0;
    for (int i = 0; i < dl; i += sl)
    {
        for (int j = 0; j < sl; j++)
        {
            int k = (int)(str[i + sl - j - 1]) - 48;
            int s = carry + sum[sl - j - 1] + k;
            carry = s / 2;
            sum[sl - j - 1] = s % 2;
        }
        if (carry == 1)
        {
            for (int i = sl - 1; i >= 0; i--)
            {
                int s = carry + sum[i];
                carry = s / 2;
                sum[i] = s % 2;
            }
        }
    }
    for (int i = 0; i < sl; i++)
    {
        if (sum[i] == 0)
        {
            printf("Error in data transmission");
            exit(0);
        }
    }
    printf("No error in data");
}