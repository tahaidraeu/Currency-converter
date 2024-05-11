#include <stdio.h>

float convertToTRY(float amount) {
    return amount * 6.66; // 1 Libyan Dinar = 6.66 Turkish Lira
}

float convertToLYD(float amount) {
    return amount / 6.66; // 1 Turkish Lira = 1 / 6.66 Libyan Dinar
}

void displayError() {
    printf("Invalid input. Please enter a valid choice.\n");
}

void convertCurrency(int choice) {
    float amount;

    printf("Enter the amount: ");
    if (scanf("%f", &amount) != 1) {
        displayError();
        return;
    }

    float convertedAmount;
    if (choice == 1) {
        convertedAmount = convertToTRY(amount);
        printf("%.2f Libyan Dinar is equal to %.2f Turkish Lira\n", amount, convertedAmount);
    } else if (choice == 2) {
        convertedAmount = convertToLYD(amount);
        printf("%.2f Turkish Lira is equal to %.2f Libyan Dinar\n", amount, convertedAmount);
    } else {
        displayError();
        return;
    }
}

int main() {
    int choice;

    printf("Currency Converter\n");
    while (1) {
        printf("1. Libyan Dinar to Turkish Lira\n");
        printf("2. Turkish Lira to Libyan Dinar\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            displayError();
            // Clear input buffer
            while (getchar() != '\n');
            continue;
        }

        if (choice == 3) {
            printf("Exiting...\n");
            break;
        } else if (choice == 1 || choice == 2) {
            convertCurrency(choice);
        } else {
            displayError();
        }
    }

    return 0;
}
