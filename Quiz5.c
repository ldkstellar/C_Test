#include <stdio.h>

# define PI 3.1415926

void main(){

    float road;
    float radius;
    float wheel;

    printf("1.이동할 거리(m):");
    scanf("%f",&road);
    printf("2.바퀴의 지름 :");
    scanf("%f",&radius);
    
    wheel =  road / (radius * PI);
    float rpm = wheel * 360;
    
    printf("%.2f",wheel);
    printf("바퀴이다\t");
    printf("%.2f",rpm);
    printf("도");

}