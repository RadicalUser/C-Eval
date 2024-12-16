#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int accNum;
    char name[50];
    float balance;
    char type[10];
}BankAcc;

void createAcc(BankAcc *acc , float balance , char *name , int num , char *type){
        acc->accNum =num;
        acc->balance= balance;
        strcpy(acc->name , name);
        strcpy(acc->type , type);
}
void displayAcc (BankAcc acc){
    printf("Account Number: %d\n", acc.accNum);
    printf("Balance: %.2f\n", acc.balance);
    printf("Name: %s\n", acc.name);
    printf("Type: %s\n" , acc.type);
}

void depositMoney (BankAcc *acc , int  amount){
    acc->balance +=  amount;
}

void withMoney(BankAcc *acc , int amount ){
    if(acc->balance >= amount){
        acc->balance -= amount;
    }else{
        printf("Insufficient balance\n");
    }

}





int main(){
    BankAcc acc;
    int accNum;
    float balance;
    char name[50];
    char type[10];

    printf("Enter  account number: ");
    scanf("%d", &accNum);

    printf("Enter balance: ");
    scanf("%f", &balance);

    printf("Enter  name: ");
    scanf("%s", name);

    printf("Enter Type Of Account: ");
    scanf("%s", type);

    createAcc(&acc , balance , name , accNum , type);

    int choice;
    float Amount;

    do
    { 
        printf("Choose Operation :\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &choice);   

        switch (choice)
        {
        case 1:
        printf("Enter amount to deposit: ");
        scanf("%f", &Amount);
        depositMoney(&acc, Amount);
        break;

        case 2:
        printf("Enter amount to withdraw: ");
        scanf("%f", &Amount);
        withMoney(&acc, Amount);
        break;

        case 3:
        displayAcc(acc);
        break;

        case 4:
        printf("Exiting...");
        break;
        
        default:
        printf("Invalid choice");
            break;
        }

    } while (choice !=4);

    return 0;
    
}
