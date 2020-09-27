#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char card_name[3];
    int lower;
    int upper;
    puts("Enter the card name: ");
    scanf("%2s", card_name);
    puts("Enter lower bound: ");
    scanf("%d", &lower);
    puts("Enter upper bound: ");
    scanf("%i", &upper);
    int val = 0;
    if (card_name[0] == 'K')
        val = 10;
    else if (card_name[0] == 'Q')
        val = 10;
    else if (card_name[0] == 'J')
        val = 10;
    else if (card_name[0] == 'A')
        val = 11;
    else
        val = atoi(card_name);
    printf("The card value is: %i\n", val);
    if (lower <= val <= upper)
        printf("The card value is in your selected range");
    else
        printf("The card value is NOT in your selected range");
    return 0;
}
