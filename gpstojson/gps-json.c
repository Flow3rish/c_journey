#include <stdio.h>

int main(int argc, char const *argv[])
{
    float latitude, longitude;
    char info[80];
    int started = 0;

    puts("data=[");
    while (scanf("%f,%f,%79[^\n]", &latitude, &longitude, info) == 3)
    {
        if (started)
            printf(",\n");
        else
            started = 1;
        if (!(-90.0 <= latitude && latitude <= 90.0))
        {
            fprintf(stderr, "Invalid latitude: %f\n", latitude);
            return 2;
        }
        if (!(-180.0 <= longitude && longitude <= 180.0))
        {
            fprintf(stderr, "Invalid longitude: %f\n", longitude);
            return 2;
        }
        printf("{latitude: %f, longitude: %f, info: \"%s\"", latitude, longitude, info);
    }
    puts("\n]");

    return 0;
}
