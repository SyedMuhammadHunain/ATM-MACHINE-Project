#include <stdio.h>

int main() {
    int pin_code, deposit_amount = 0, withdraw_amount = 0, balance = 0;
    char ch, choose_withdraw_or_deposit, yes_no;

    printf("Press 's' to Start the ATM Machine: ");
    ch = getchar();

    if (ch == 's' || ch == 'S') {
        printf("-----------------------WELCOME TO THE ATM MACHINE------------------------\n\n");

        // Get 4-digit pin code
        printf("Enter 4-digit PIN CODE: ");
        scanf("%d", &pin_code);

        // Verify pin code is 4 digit
        if (pin_code >= 1000 && pin_code <= 9999) {
            printf("Valid PIN code\n\n");
        } else {
            printf("Wrong PIN code\n");
            return 0; // If wrong exit 
        }

        // Main loop for ATM interaction
        while (1) {
            printf("********   CHOOSE  *********\n1. w = Withdraw Money\n2. d = Deposit Money\n3. e = Exit\n");
            printf("Choose an option: ");
            scanf(" %c", &choose_withdraw_or_deposit);

            // Prompt user to choose deposit or withdraw
            switch (choose_withdraw_or_deposit) {
                case 'd': // Deposit money
                    printf("Enter Amount to Deposit: ");
                    scanf("%d", &deposit_amount);

                    // Add deposit amount to the balance
                    balance += deposit_amount;
                    printf("Balance = %d\n", balance);

                    // Ask if the user wants to withdraw money
                    printf("Do You want to withdraw money (Y/N): ");
                    scanf(" %c", &yes_no);

                    if (yes_no == 'y' || yes_no == 'Y') {
                        printf("Enter Amount to withdraw (Up to %d): ", balance);
                        scanf("%d", &withdraw_amount);

                        // Check if withdraw amount is valid
                        if (withdraw_amount >= 0 && withdraw_amount <= balance) {
                            balance -= withdraw_amount;
                            printf("Withdrawn Amount = %d\n", withdraw_amount);
                            printf("New Balance = %d\n", balance);
                        } else {
                            printf("Sorry, You have insufficient balance or entered an invalid amount.\n");
                        }
                    }
                    break;

                case 'w': // Withdraw money
                    printf("Firstly, you must deposit money first.\n");
                    break;

                case 'e': // Exit the ATM
                    printf("Exiting the ATM. Thank you!\n");
                    return 0;

                default: // Invalid input
                    printf("Invalid Input. Please choose again.\n");
                    break;
            }
        }
    } else {
        printf("Error. You must press 's' to start.\n");
        return 0;
    }

    return 0;
}
