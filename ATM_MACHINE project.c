#include<stdio.h>

int main(){
//Age Calculator: Calculate age based on birthdate.

    // data types
    int date,day,month,year,current_year;
    printf("Enter your Date of Birth (8-digit): ");
    scanf("%d",&date);

    // 8 digit verify
    if ((date >= 10000000 && date <= 99999999)) {
        printf("valid date\n");
    } else 
    {
        printf("Invalid date");
        return 0;
    }

    // for day
    day = date / 1000000;
    if (day < 1 || day > 31)
    {
        printf("Invalid date");
        return 0;
    }

    // for month
    month = (date / 10000) % 100;

    // confrimation
    if (month > 12 || month < 1)
    {
        printf("Invalid Month\n");
        return 0;
    }

    // for year
    year = date % 10000;
    
    printf("Enter current year: ");
    scanf("%d",&current_year);

    // for age
    int age = current_year - year; 
    
    printf("Your age is %d\n",age);


    return 0;
}