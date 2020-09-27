#include <stdio.h>
#include <string.h>

// Ask the user for the text she's looking for.
// Loop through all of the track names.
// If a track name contains the search text, display the track name.

int main(int argc, char const *argv[])
{
    char songs[][80] = {
        "Smoke on the water",
        "Master of puppets",
        "Laskyplni",
        "Brdokoky",
        "Irresitible"};
    char searched_text[80];
    puts("What song are you looking for?");
    scanf("%80s", searched_text);
    // printf("%ld", (sizeof(songs) / sizeof(char)));
    printf(sizeof(char));
    // // for (int i = 0; i < sizeof(songs) / sizeof(char); i++)
    // {
    //     if (strcmp(searched_text, songs[i]))
    //         printf("%s80", songs[i]);
    // }

    return 0;
}
