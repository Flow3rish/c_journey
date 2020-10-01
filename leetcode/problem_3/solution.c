#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable/hashtable.h"

int length_until_repeat(char *s)
{
    for (; *s != '\0'; s++)
    {
        printf("%c", *s);
    }

    return 0;
}

char *solution(char *s)
{
    char **e = malloc(strlen(s));
    for (int i = 0; i < strlen(s); i++)
    {
        /* create string of one character strings */
        *(e + i) = malloc(sizeof(char) * 2); /* * 2 for the \0 character */
        strncpy(*(e + i), s + i, 1);
        // printf("%s\n", *(e + i));
    }

    for (int i = 0; i < strlen(s); i++)
    {
        printf("got here.");
        if (lookup(*(e + i)) != NULL)
        {
            /* character is repeated */
            printf("not found\n");
            // break;
        }
        else
        {
            printf("found\n");
            // install(*(e + i), "e");
        }
    }

    for (int i = 0; i < strlen(s); i++)
    {
        /* clean up */
        free(*(e + i));
    }

    free(e);
}

int main(int argc, char const *argv[])
{
    solution("qwertyuiqopasdfghjklzxcvm");
    // solution("qwertyuiopasdfghjklzxcvmq");

    for (int i = 0; i < HASHSIZE; i++) /* clean the hash table */
    {
        free(hashtab[i]);
    }

    return 0;
}
