#include <stdio.h>

int main(void)
{
    int hour, minutes, seconds, fowardSeconds;

    scanf("%d:%d:%d", &hour, &minutes, &seconds);
    scanf("%d", &fowardSeconds);

    seconds += fowardSeconds;

    if (seconds >= 60)
    {
        seconds = seconds - 60;
        minutes ++;
    }

    if (minutes >= 60)
    {
        hour ++;
        minutes = minutes - 60;   
    }

    if (hour >= 24)
    {
        hour = hour - 24;
    }

    printf("%02d:%02d:%02d\n", hour, minutes, seconds);

    return 0;
}
