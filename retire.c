/**
 * Author: Carsten Graves
 * Date: 9/15/2022
 *
 * This program produces a amortization table for a 401k account taking input from the command line: initail balance, monthly contribution,
 * average annual rate of return, average annual rate of inflation, number of years untill retirement.
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main(int argc, char **argv) {

    double startB = atof(argv[1]);
    double monthlyInput = atof(argv[2]);
    double annualReturn = atof(argv[3]);
    double annualInflation = atof(argv[4]);
    int years = atoi(argv[5]);
    double infAnnualRate;
    int month = 1;
    int months = years * 12;
    double annualInput = monthlyInput * 12;
    if(annualInput > 18500){
        printf("Illegal: monthly contributions exceed $18,500 annual limit\n");
        return (0);
    }
    if(monthlyInput<=0 || annualReturn<=0 || annualInflation<=0 || years<=0){
        printf("Illegal: illegal input\n");
        return (0);
    }


    infAnnualRate = ((1 + annualReturn) / (1 + annualInflation)) - 1;
    double perMonth = infAnnualRate / 12;
    float interest = perMonth * startB;
    float balance = startB + monthlyInput + interest;
    printf("Month     Interest     Balance\n");
    printf("%5.2d $ %10.2f $ %9.2f\n", month, interest, balance);
    float totalInterest = interest;

    for(month = 2; month <= months; ++month){
        infAnnualRate = ((1 + annualReturn) / (1 + annualInflation)) - 1;
        perMonth = infAnnualRate / 12;
        interest = perMonth * balance;
        balance = balance + monthlyInput + interest;
        printf("%5.2d $ %10.2f $ %9.2f\n", month, interest, balance);
        totalInterest = totalInterest + interest;
    }
    printf("Total Interest Earned: $ %4.2f\n", totalInterest);
    printf("Total Nest Egg: $ %4.2f\n", balance);




}