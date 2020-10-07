#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void add_record(FILE *ptr, char name[], char roll_no[], char email[])
{
    ptr = fopen("record.txt", "a");
    fputs(name, ptr);
    fputc('\n', ptr);

    fputs(roll_no, ptr);
    fputc('\n', ptr);

    fputs(email, ptr);
    //fputc('\n', ptr);

    fclose(ptr);
}

void read_record(FILE *ptr)
{
    char read[30];
    int choice, line = 0;
    bool flag = true;

    printf("0 For Reading your record\n 1 & 2 for Reading fellow Student\n");

    printf("Enter choice : ");
    scanf("%d", &choice);

    printf("\n");

    ptr = fopen("record.txt", "r");

    if (ptr)
    {
        if (choice == 0)
        {
            printf("......My Record......\n\n");

            fgets(read, 30, ptr);
            printf("Name    :%s", read);

            fgets(read, 30, ptr);
            printf("Roll_No :%s", read);

            fgets(read, 30, ptr);
            printf("Email   :%s", read);

            printf("......................\n\n");
        }
        else if (choice > 0)
        {
            while (!feof(ptr) && flag)
            {
                fgets(read, 30, ptr); //skipping unwanted lines....
                fgets(read, 30, ptr);
                fgets(read, 30, ptr);

                line++; //counting lines....
                if (line == choice)
                {
                    printf("......Fellow Student Record......\n\n");

                    fgets(read, 30, ptr);
                    printf("Name    :%s", read);

                    fgets(read, 30, ptr);
                    printf("Roll_No :%s", read);

                    fgets(read, 30, ptr);
                    printf("Email   :%s", read);

                    printf("..................................\n\n");
                    flag = false;
                }
                printf("%s", read);
            }
            fclose(ptr);
        }
        else
            printf("Invalid Choice\n");
    }
    else
        printf("FIle Not found\n");
}

void delete_record(FILE *ptr)
{

    char read[30];
    int choice, line = 0;

    printf("0 For Deleting  your record\n 1 & 2 for Deleting fellow Student\n");

    printf("Enter choice : ");
    scanf("%d", &choice);

    printf("\n");

    ptr = fopen("record.txt", "r");

    FILE *temp_file = fopen("temp.txt", "w");

    if (ptr)
    {
        if (choice >= 0)
        {
            while (!feof(ptr))
            {
                strcpy(read, "\0");

                if (line == choice)
                {
                    fgets(read, 30, ptr); //skipping unwanted lines....
                    fgets(read, 30, ptr);
                    fgets(read, 30, ptr);
                }
                else//copying only desire data into temp_file...
                {
                    fgets(read, 30, ptr);
                    printf("%s", read);
                    fputs(read, temp_file);

                    fgets(read, 30, ptr);
                    printf("%s", read);
                    fputs(read, temp_file);

                    fgets(read, 30, ptr);
                    printf("%s", read);
                    fputs(read, temp_file);
                }
                line++;
                printf("%s", read);
            }
            fclose(ptr);
            fclose(temp_file);
            remove("record.txt");
            rename("temp.txt", "record.txt");
        }
        else
            printf("Invalid Choice\n");
    }
    else
        printf("FIle Not found\n");
}

int main()
{
    char name[20], roll_no[20], email[30];
    FILE *file;
    int option;

    printf("Enter 1 to add record.\n");
    printf("Enter 2 to read specifc record.\n");
    printf("Enter 3 to delete specific record\n");
    scanf("%d", &option);
    if (option == 1)
    {
        printf("Enter Name  : ");
        scanf("%s", name);

        printf("Enter RollNo.  : ");
        scanf("%s", roll_no);

        printf("Enter Email  : ");
        scanf("%s", email);

        add_record(file, name, roll_no, email);
    }
    else if (option == 2)
    {
        read_record(file);
    }
    else if (option == 3)
    {
        delete_record(file);
    }
    
    return 0;
}