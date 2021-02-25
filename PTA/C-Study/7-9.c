#include<stdio.h>  

int main()
{  
    int year, month, day, i, dayOfTheYear = 0;
    int monthDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    scanf("%d/%d/%d", &year, &month, &day);

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        monthDays[2] = 29;

    for (i = 1; i < month; i ++)
    {
        dayOfTheYear += monthDays[i];
    }

    dayOfTheYear += day;

    printf("%d\n", dayOfTheYear);

    return 0;   
}


