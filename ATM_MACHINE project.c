#include <stdio.h>
#include<unistd.h>

int main() {
    // Primitive data types
    int debit_card_number, pin_code, deposit_amount,withdraw_amount = 0,balance;
    char ch, choose_withdraw_or_deposit,yes_no;
    
    // Start ATM machine
    printf("Press s to Start the ATM Machine: ");
    scanf(" %c",&ch);

    // if enter s will start mach.
    if (ch =='s' || ch == 'S')
    {
        sleep(1.7); // welcome will pop after 1.7s(Added by importing unistd.h library)

        printf("#### WELCOME TO THE ATM MACHINE ####\n\n");

        sleep(0.7);

        printf("Enter 4-digit PIN CODE:  ");
        scanf("%d",&pin_code);

       // verify pin code is 4 digit
       if (pin_code >= 1000 && pin_code <= 9999) {
            printf("Valid PIN code\n\n");
        } else {
            printf("Wrong PIN code\n");
            return 0; // if wrong exit 
        }

        start: // goto start will take me to here (added at false statment below)
        printf("********   CHOOSE  *********\n1. w = Withdraw Money\n2. d = Deposit Money  ");
        scanf(" %c", &choose_withdraw_or_deposit);

        // prompt user to choose deposit or withdraw
        switch (choose_withdraw_or_deposit)
        {
            // for deposit
            case 'd':
            printf("Enter Amount: ");
            scanf("%d",&deposit_amount);
            
            //show current balance
            printf("Balance = %d\n",deposit_amount);

            // prompt user to withdraw yes or no            
            printf("Do You want to withdraw money Y or N:  ");
            scanf(" %c",&yes_no);
            
            // if yes then
            if (yes_no == 'y' || yes_no == 'Y')
            {
                printf("Enter Amount to withdraw (UPTO 5000): \n");
                scanf("%d",&withdraw_amount);
                
                // ternary conditional statement
                (withdraw_amount >= 0 && withdraw_amount <= 5000) ? /*nothing*/ : printf("Sorry, You have to withdraw within this range");
                
                printf("New Balance = %d\n", deposit_amount - withdraw_amount);
                printf("Withdrawl Amount = %d", withdraw_amount);
                return 0;
            } else if (yes_no == 'N' || yes_no == 'n')
            { 
                // nothing
            }
            break;
            
            // for withdrawl
            case 'w':
            printf("Firstly Deposit Amount\n\n");
            goto start; // will take to top at start

            // if invalid input then again will take to up
            default: printf("Invalid Input");
            goto start;
            break;
        }
        
    } else 
    {
        printf("Error");
        return 0;
    }
    
    printf("Balance = %d\n",deposit_amount);
    printf("Withdraw Amount = %d\n",withdraw_amount);

    printf("####   THANK YOU   ####");

return 0;
}