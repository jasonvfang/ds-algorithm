#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double init_height = 0;
    int n = 0;
    double distance = 0.0, height_n = 0.0;

    scanf("%lf %d", &init_height, &n);

    while (n > 0)
    {
        if(init_height <= 0)
            break;
        height_n = (init_height) / 2.0;
        distance = distance + init_height + height_n;
        init_height /= 2.0;
        //printf("distance:%.1lf height_n:%.1lf n:%d init_height:%lf\n", distance, height_n, n, init_height);
        n --;
    }
    
    distance = distance - height_n;
    
    printf("%.1lf %.1lf\n", distance, height_n);

    return 0;
}

