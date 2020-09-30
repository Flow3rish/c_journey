#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char card_name[3];
    puts("Enter card");
    scanf("%2s", card_name);
    int val = 0;
    switch (card_name[0])
    {
    case 'K':
        // val = 10;
        // break;
    case 'Q':
        // val = 10;
        // break;
    case 'J':
        val = 10;
        break;
    case 'A':
        val = 11;
        break;
    default:
        val = atoi(card_name);
        break;
    }
    printf("the value is %d\n", val);
    return 0;
}
