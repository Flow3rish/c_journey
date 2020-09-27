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
        "Space diver",
        "Irresitible"};
    char searched_text[80];
    puts("What song are you looking for?");
    scanf("%79s", searched_text);
    for (int i = 0; i < sizeof(songs) / sizeof(songs[0]); i++)
    {
        if (strstr(songs[i], searched_text))
            printf("I found \"%s\" in \"%s\".", searched_text, songs[i]);
    }

    return 0;
}
