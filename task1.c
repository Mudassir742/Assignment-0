#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char c;
    FILE *file;
    int count = 0;

    if (*argv[1] == 'a')
        file = fopen("q1_a.txt", "r");
    else if (*argv[1] == 'b')
        file = fopen("q1_b.txt", "r");
    else if (*argv[1] == 'c')
        file = fopen("q1_c.txt", "r");
    
    if (file)
    {
        while (!feof(file))
        {
            c = getc(file); //read only one character at a time...
            if (c >= '0' && c <= '9')
                count++;
        }
        printf("Total World Count : %d\n", count);
    }
    else
        printf("File Not found\n");

    return 0;
}