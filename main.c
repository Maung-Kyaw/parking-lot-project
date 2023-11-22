#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CAR 20

struct parking{

} ;

int main()
{

    int input_num;


    do{
        printf("1. Park a car\n2. Remove a car\n3. Show parking lot\n4. Exit the program");
        printf("\nChoose one :");
        scanf("%d",&input_num);

        switch(input_num){
        case 1:
            printf("Park a car\n\n");
            break;
        case 2:
            printf("Remove a car\n\n");
            break;
        case 3:
            printf("Show parking lot\n\n");
            break;
        case 4:
            printf("You have parked ur car successfully\n\n");
            exit(1);
        }
    }while(input_num<=4 && input_num>0);



}
// 4 functions
/*
void Park_Car(){
}

void Remove_Car(){

}
void Show_Parking(){

}
void exit(){

}
*/
