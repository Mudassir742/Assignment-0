#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool check_vowel(char str[], int start, int end)
{
    int i;
    bool flag = false;
    for (i = start; i <= end && flag != true; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            flag = true;
    }
    return flag;
}

int main(int argc, char *argv[])
{
    char str[100];
    FILE *file;

    if (*argv[1] == 'a')
        file = fopen("q3_a.txt", "r");
    else if (*argv[1] == 'b')
        file = fopen("q3_b.txt", "r");

    if (file)
    {
        FILE *ptr;
        ptr = fopen("Invert.txt", "w");

        while (fgets(str, 100, file))
        {
            int j = 0, k = 0, len = 0, i = 0;
            char arr1[100];
            for (i = 0; i <= strlen(str); i++)
            {
                if ((str[i] == ' ') || (str[i] == '\0'))
                {
                    if (check_vowel(str, len, i - 1))
                    {
                        int j;
                        for (j = i - 1; j >= len; j--)
                        {
                            arr1[k] = str[j];
                            k++;
                        }
                        arr1[k] = ' ';
                        k++;
                    }
                    len = i + 1;
                }
            }

            arr1[strlen(str) + 1] = '\0';
            fputs(str, ptr);
            fputc('\n', ptr);
            fputs(arr1, ptr);
        }
        fclose(ptr);
        fclose(file);
    }
    else
        printf("File Not found\n");

    return 0;
}