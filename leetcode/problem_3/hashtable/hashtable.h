#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

struct nlist;

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE]; /* pointer table */

/* hash: form hash value for string s */
unsigned hash(char *s);

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s);

// char *strdup(char *);
/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn);

#endif // __HASHTABLE_H__
