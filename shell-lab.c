#include <stdio.h>
#include <string.h>

#define MAX 50

char *nullReplace(char *str, char locate)
{
    char *current = strchr(str, locate);
    while (current)
    {
        *current = '\0';
        current = strchr(current, locate);
    }
    return str;
}

int main()
{
    char str[MAX];
    while (strcmp(str, "bye") != 0)
    {
        // read command line arguments
        fgets(str, MAX, stdin);
        str[strlen(str) - 1] = '\0';

        // TYPE ONE COMMANDS
        // hello command
        if (strcmp(str, "hello") == 0)
        {
            printf("Hello! I hope you have a lovely day!\n");
        }

        // assignment command
        if (strcmp(str, "assignment") == 0)
        {
            printf("202 lab #1 (Spring 2022)\n");
        }

        // author command
        if (strcmp(str, "author") == 0)
        {
            printf("Megan Nicius, N10169642, mhn274\n");
        }

        // section command
        if (strcmp(str, "section") == 0)
        {
            printf("003\n");
        }

        //TYPE TWO COMMANDS
        if (strcmp(str, "fork()") == 0)
        {
            int status;

            if (fork() == 0)
            {
                char forkStr[MAX];
                fgets(forkStr, MAX, stdin);
                forkStr[strlen(forkStr) - 1] = '\0';
                char *env[] = {forkStr, NULL};
                char bin[MAX] = "/bin/";
                strcat(bin, forkStr);
                printf("%s", forkStr);
                if (execve(bin, env, NULL) == -1)
                {
                    printf("Your input is invalid. Cannot fork.\n");
                    exit(1);
                }
                else
                {
                    execve(bin, env, NULL);
                    printf("Thank you. Please say 'bye' now!");
                }
                exit(0);
            }
            else
            {
                printf("Enter command such as 'dir', 'echo' or 'date'.\n");
                wait(&status);
            }
        }
    }


    // bye command
    if (strcmp(str, "bye") == 0)
    {
        printf("Goodbye! I hope you have a lovely day!\n");
        return 0;
    }

    return 0;
}
