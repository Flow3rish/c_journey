#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// HASHTABLE //
struct nlist
{                       /* table entry: */
    struct nlist *next; /* next entry in chain */
    char *name;         /* defined name */
    char *defn;         /* replacement text */
};

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE]; /* pointer table */

/* hash: form hash value for string s */
unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np; /* found */
    return NULL;       /* not found */
}

// char *strdup(char *);
/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;
    if ((np = lookup(name)) == NULL)
    { /* not found */
        np = (struct nlist *)malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    else                        /* already there */
        free((void *)np->defn); /*free previous defn */
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

// char *strdup(char *s) /* make a duplicate of s */
// {
//     char *p;
//     p = (char *)malloc(strlen(s) + 1); /* +1 for ’\0’ */
//     if (p != NULL)
//         strcpy(p, s);
//     return p;
// }
// /HASHTABLE //

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
