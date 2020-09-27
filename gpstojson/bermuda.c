#include <stdio.h>

int main(int argc, char const *argv[])
{
    float latitude, longitude;
    char info[80];
    while (scanf("%f,%f,%79[^\n]", &latitude, &longitude, info) == 3)
    {
        if ((26 <= latitude) && (latitude <= 34))
        {
            if ((-76 <= longitude) && (longitude <= -64))
            {
                printf("%f,%f,%s\n", latitude, longitude, info);
            }
        }
    }
    return 0;
}
