#include <stdio.h>
#include <stdlib.h>

#define MON_JAN 0
#define MON_FEB 1
#define MON_MAR 2
#define MON_APR 3
#define MON_MAY 4
#define MON_JUN 5
#define MON_JUL 6
#define MON_AUG 7
#define MON_SEP 8
#define MON_OCT 9
#define MON_NOV 10
#define MON_DEC 11

#define YEARS 5
#define MONTHS 12

void averageYearTemp(const float temps[YEARS][MONTHS], const char monthName[YEARS][MONTHS - 2], const int yearNums[]);

int main()
{
    float temps[YEARS][MONTHS];
    char monthName[MONTHS][10] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    int yearNums[] = { 2018, 2019, 2020, 2021, 2022 };

    for(int year = 0; year < YEARS; year++)
    {
        printf("%d\n", yearNums[year]);
        for(int month = 0; month < MONTHS; month++)
        {
            printf("%s: ", monthName[month]);
            scanf(" %f", &temps[year][month]);
        }
    }

    averageYearTemp(temps, monthName, yearNums);

    return 0;
}

void averageYearTemp(const float temps[YEARS][MONTHS], const char monthName[YEARS][MONTHS - 2], const int yearNums[])
{
    float average = 0;
    float totalAverage = 0;
    float highestPerYear = 0;
    float highestTotal = 0;
    float lowestPerYear = 0;
    float lowestTotal = 0;

    for(int year = 0; year < YEARS; year++)
    {
        if(year == 0)
        {
            highestTotal = temps[year][MON_JAN];
            lowestTotal = temps[year][MON_JAN];
        }
        printf("%d: \n", yearNums[year]);
        for(int month = MON_JAN; month < MONTHS; month++)
        {
            if(month == MON_JAN)
            {
                highestPerYear = temps[year][MON_JAN];
                lowestPerYear = temps[year][MON_JAN];
            }
            average += temps[year][month];
            if(temps[year][month] > highestPerYear)
            {
                highestPerYear = temps[year][month];
            }
            if(temps[year][month] < lowestPerYear)
            {
                lowestPerYear = temps[year][month];
            }
        }
        printf("Average temperature of %d: %.2f\n", yearNums[year], average / MONTHS);
        printf("Highest temperature of %d: %.2f\n", yearNums[year], highestPerYear);
        printf("Lowest temperature of %d: %.2f\n", yearNums[year], lowestPerYear);
        totalAverage += average;
        if(highestPerYear > highestTotal)
        {
            highestTotal = highestPerYear;
        }
        if(lowestPerYear < lowestTotal)
        {
            lowestTotal = lowestPerYear;
        }
    }
    printf("\nAverage temperature over %d years: %.2f\n", YEARS, totalAverage / (YEARS * MONTHS));
    printf("Highest temperature recorded: %.2f\n", highestTotal);
    printf("Lowest temperature recorded: %.2f\n", lowestTotal);
    return;
}


/*
Övning:
Skriv ett program där lagrar år och månader i en tvådimensionell array: 
2018,2019,2020,2021,2022 
samt  alla månader såklart
Skriv ett program där du kan mata in medeltemperaturen för alla dessa, år för år, månad för månad

Räkna sedan ut medeltemperatur PER ÅR
Medeltemperatur totalt
Varmaste och kallaste temperatur PER ÅR
Varmaste och kallaste temperatur  totalt
*/