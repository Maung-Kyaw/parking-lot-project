#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX_ROWS 5
#define MAX_COLS 5

//Build a struct for Car informations
struct Car {
    int number;
};

// Function prototypes
void Park_Car(struct Car *parked_car, int parking_slot[MAX_ROWS][MAX_COLS]);
void Remove_Car(int parking_slot[MAX_ROWS][MAX_COLS],struct Car *parked_car);
void show_parking(int parking_slot[MAX_ROWS][MAX_COLS]);
void show_ParkedCar_Information(int parking_slot[MAX_ROWS][MAX_COLS]);
void save_data(int parking_slot[MAX_ROWS][MAX_COLS]);
void load_data(int parking_slot[MAX_ROWS][MAX_COLS]);

int main() {

    struct Car parked_car;
    int parking_slot[MAX_ROWS][MAX_COLS]={};
    int input_num;
    load_data(parking_slot);

    do {
        printf("\033[1;35m1. Park a car\n2. Remove a car\n3. Show parking lot\n4. Show parked car informations\n5. Exit the program\033[0m\n");
        printf("\033[1;35m-----------------------------------------------------------------------\033[0m\n");
        printf("Choose one :");
        scanf("%d", &input_num);
        printf("\n");

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
                show_ParkedCar_Information(parking_slot);
                break;
            case 5:
                save_data(parking_slot);
                printf("Thank you for using the parking!\n");
                exit(1);
        }
    } while (input_num <= 5 && input_num > 0);
    return 0;
}

// Function for saving data into the file
void save_data(int parking_slot[MAX_ROWS][MAX_COLS]) {
    FILE *file = fopen("F:/MUIC 2nd term/Fundamental Programming/parking_lot/parking_data.txt", "w");

    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            fprintf(file, "%d ", parking_slot[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}


// Function for loading data from the file
void load_data(int parking_slot[MAX_ROWS][MAX_COLS]) {
    FILE *file = fopen("F:/MUIC 2nd term/Fundamental Programming/parking_lot/parking_data.txt", "r");
    if (file == NULL) {
        printf("No previous data found.\n");
        return;
    }

    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (fscanf(file, "%d", &parking_slot[i][j]) != 1) {
                printf("Error reading data from the file.\n");
                fclose(file);
                return;
            }
        }
    }

    fclose(file);
}



// Function for parking car ( Option 1 )

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
                printf("\n\033[1;31m\"Parked car number is %d\"\033[0m\n\n", parked_car->number);
            } else {
                printf("This parking slot is full. Choose another Col & Row\n");
            }
        } else {
            printf("Invalid row or column. Please enter values between 1 and 5.\n\n");
            printf("----------------------------------------------------------------");
        }

    } while (parking_slot[x - 1][y - 1] == 0);
}

//Function for removing car ( Option 2 )

void Remove_Car(int parking_slot[MAX_ROWS][MAX_COLS],struct Car *parked_car)
{
    int i,j;
    int x=0;
    do{
        printf("Enter your car number to remove:");
        scanf("%d",&parked_car->number);
        for(i=0;i<MAX_ROWS;i++){
            for(j=0;j<MAX_COLS;j++){
                if(parked_car->number==parking_slot[i][j]){
                    printf("Successfully removed your car %d\n\n",parked_car->number);
                    parking_slot[i][j]=0;
                    x=1;
                }
            }
        }
     if(x!=1) printf("Cannot find this car number in the parking!\n\n");

    }while(x!=1);

}

//Function for show parking lot ( Option 3 )

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

//Function to show all parked informations ( Option 4 )

void show_ParkedCar_Information(int parking_slot[MAX_ROWS][MAX_COLS]){
    int i,j;
    int x=0;

    for(i=0;i<MAX_ROWS;i++){
        for(j=0;j<MAX_COLS;j++){
            if(parking_slot[i][j]!=0){
                printf("Parking Slot [%d][%d] : %5d\n\n",i+1,j+1,parking_slot[i][j]);
                int x=1;
            }
        }
    }
    if(x==0){
        printf("\033[1;31mThere is no car parked!\033[0m\n\n");
    }
}




