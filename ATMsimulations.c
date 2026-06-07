#include <stdio.h>
#include <stdlib.h>
#define CORRECT_PIN 7620

float Balance =10000.0;

void checkBalance()
{
    printf("\n*** WELCOME***\n");
    printf("\nYour current balance is: $%.2f\n", Balance);

}
void depositMoney() {
    float amount ;
    printf ("\nEnter amount to deposit: $");
    scanf ("%f",&amount);
    if (amount <0) {
        printf("Invalid amount.\n");
        return;
    }
    int b=100000;
    if (amount>b) {
        printf ("YOU CAN ONLY DEPOSITE %d Rs. \n please try again\n",b);
        return;
    }
    Balance += amount ;
    printf("Successfully deposited $%.2f\n" ,amount);
    printf("current available balance is: $%.2f\n",Balance);


}
void withdrawMoney() {
    float amount ;
    printf ("Enter amount to withdraw : $");
    scanf("%f",&amount);
    if (amount <=0) {
        printf("Invalid amount.\n");
        return;
    }
    if (amount > Balance) {
        printf("Insufficient balance.\n");
        return;
    }
        int a= 20000;
        if(amount >=a) {
            printf ("withdraw limit is only %d\n please try again\n ",a);
            return;

        }


    Balance -=amount;
    printf("Successfully withdrawn $%.2f\n" ,amount);
    printf("current available balance is: $%.2f\n ", Balance);
}
int verifyPin() {
    int pin,attempts = 5;
    while (attempts>0) {
        printf (" Enter your 4-digit pin:");
        scanf ("%d",&pin);

        if (pin ==  CORRECT_PIN) {
            return 1;

        } else {
            attempts--;
            printf(" Please Enter a Valide PIN \n you have only :%d attempts\n\n",attempts);

        }
    }
    return 0;
}
int main () {
    int choice;

    printf ("===Welcome to Simple ATM Project===\n");
    if (!verifyPin()) {
        printf("Access denied. Exiting...\n");
        exit(0);
    }
    while (1) {
        printf ("\n ==== Main Menu====\n");
        printf ( "1.Check Balance\n");
        printf ("2.Deposit Money\n");
        printf ("3.Withdraw Money\n");
        printf ("4.Exit\n");
        printf ("Chooce an option:");
        scanf ("%d",&choice);

        switch (choice) {
            case 1: checkBalance() ;break;
            case 2: depositMoney();break;
            case 3: withdrawMoney();break;
            case 4:
                printf ("Thank you for using ATM. Good by \nRam Ram");
                exit(0);
            default:printf("invalid choice.Try again.\n");

        }
    }
    return 0;
}