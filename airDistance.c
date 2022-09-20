/**
 * Author: Carsten Graves
 * Date: 9/1/2022
 *
 * This program takes in user input of latitude and longitude, and computes the distance between the two locations.
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main(int argc, char **argv) {

    double latOfA;
    double longOfA;
    double latOfB;
    double longOfB;

    printf("What is the latitude of location A: ");
    scanf("%lf", &latOfA);

    printf("What is the longitude of location A: ");
    scanf("%lf", &longOfA);

    printf("What is the latitude of location B: ");
    scanf("%lf", &latOfB);

    printf("What is the longitude of location B: ");
    scanf("%lf", &longOfB);

// Convert degrees to radians
    double radLatA;
    radLatA = (latOfA / 180) * M_PI;


    double radLongA;
    radLongA = (longOfA / 180) * M_PI;


    double radLatB;
    radLatB = (latOfB / 180) * M_PI;


    double radLongB;
    radLongB = (longOfB / 180) * M_PI;


    double longDist;
    longDist = radLongB - radLongA;


    double distance;
    distance =  acos((sin(radLatA) * sin(radLatB)) + (cos(radLatA) * cos(radLatB) * cos(longDist))) * 6371;


    printf("        Location Distance\n");
    printf("=================================\n");
    printf("Origin:      (%lf, %lf)\n", latOfA, longOfA);
    printf("Destination: (%lf, %lf)\n", latOfB, longOfB);
    printf("Air distance is %lf kms\n", distance);

    return 0;
}