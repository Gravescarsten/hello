/**
 * Author: Carsten Graves
 * Date: 9/8/2022
 *
 * This program calculated whether someone is using their data plan correctly and informs them of how they can better use it.
 */

#include <stdlib.h>
#include <stdio.h>
int main(int argc, char **argv) {

    double numGB = atof(argv[1]);
    int day = atoi(argv[2]);
    double GBused = atof(argv[3]);
    double avg = GBused / day;
    int dayRemain = 30 - day;
    double numGBremain = numGB - GBused;
    double actualAvg = numGB / 30;
    double newAvg = numGBremain / dayRemain;
    double extraGB = (numGB - (avg * 30));
    if(numGBremain < 0){
        numGBremain = 0;
    }

    printf("%d days used, %d days remaining.\n", day, dayRemain);
    printf("%.2lf GB used, %.2lf GB remaining.\n", GBused, numGBremain);
    printf("Average daily use: %.2lf GB per day.\n", avg);

    if(numGB <= GBused){

        printf("You are out of Data\n");
    }else if(avg > actualAvg){
        printf("You are exceeding the average daily usage limit.\n");
        printf("In order to not exceed your monthly data limit you must use a maximum of %.2lf GB per day.\n", newAvg);
        extraGB = extraGB * -1;
        printf("If you continue this high usage you will exceed your data plan by %.2lf GB.\n", extraGB);
    } else{
        printf("You are using an acceptable amount of %.2lf GB per day.\nHowever if you continue to use %.2lf GB per day you will have %.2lf unused GB at the end of the month.\n", avg, avg, extraGB);
    }




    return (0);
}
