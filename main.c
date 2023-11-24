#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 5
#define MAX_COLS 5

struct Car {
    int number;
};

// Function prototypes
void Park_Car(struct Car *parked_car, int parking_slot[MAX_ROWS][MAX_COLS]);
void Remove_Car(int parking_slot[MAX_ROWS][MAX_COLS],struct Car *parked_car);
void show_parking(int parking_slot[MAX_ROWS][MAX_COLS]);

int main() {
    struct Car parked_car;
    int parking_slot[MAX_ROWS][MAX_COLS]={};
    int input_num;

    do {
        printf("\033[1;35m1. Park a car\n2. Remove a car\n3. Show parking lot\n4. Exit the program\033[0m");
        printf("\nChoose one :");
        scanf("%d", &input_num);

        switch (input_num) {
            case 1:
                Park_Car(&parked_car, parking_slot);
                break;
            case 2:
                Remove_Car(parking_slot,&parked_car);
                break;
            case 3:
                show_parking(parking_slot);
                break;
            case 4:
                printf("Thank you for using the parking!\n");
                exit(1);
        }
    } while (input_num <= 4 && input_num > 0);

    return 0;
}

// Function definition
void Park_Car(struct Car *parked_car, int parking_slot[MAX_ROWS][MAX_COLS]) {
    int x, y;

    do {
        printf("Enter a row (1-5):");
        scanf("%d", &x);
        printf("Enter a column (1-5):");
        scanf("%d", &y);

        if (x >= 1 && x <= MAX_ROWS && y >= 1 && y <= MAX_COLS) {
            if (parking_slot[x - 1][y - 1] == 0) {
                printf("The parking slot is available!\n");
                printf("Enter your car number:");
                scanf("%d", &parked_car->number);
                parking_slot[x - 1][y - 1] = parked_car->number;
                printf("Parked car number is %d\n", parked_car->number);
            } else {
                printf("This parking slot is full. Choose another Col & Row\n");
            }
        } else {
            printf("Invalid row or column. Please enter values between 1 and 5.\n");
        }

    } while (parking_slot[x - 1][y - 1] == 0);
}
void Remove_Car(int parking_slot[MAX_ROWS][MAX_COLS],struct Car *parked_car)
{
    int i,j;
    int x=0;
        do{
            printf("Enter the car number to remove: ");
            scanf("%d",&parked_car->number);
        
            for(i=0;i<MAX_ROWS;i++){
                for(j=0;j<MAX_COLS;j++){
                    if(parked_car->number==parking_slot[i][j]){
                        parking_slot[i][j]=0;
                        x=1;
                        printf("Your row is %d and column is %d. Successfully removed!",i+1,j+1);
                }
            }
            printf("\n");
            }
            if(x!=1) printf("Cannot find this car number in the parking!\n\n");
        }while(x!=1);

}
void show_parking(int parking_slot[MAX_ROWS][MAX_COLS]){
    int i,j;
    for(i=0;i<MAX_ROWS;i++){
        for(j=0;j<MAX_COLS;j++){
            if(parking_slot[i][j]==0){
                printf("\033[0;32m"); //green shows the available slots
                printf("%5s","*");
            }
            else{
                printf("\033[0;31m");
                printf("%5s","*");
            }
        }
    printf("\n");
    }}

/*
void Remove_Car(){

}
void Show_Parking(){

}
void exit(){

}

*/
