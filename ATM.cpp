
#include <iostream>
#include <string>

using namespace std;


void checkBalance(int balance);
void depositMoney(int &balance, string history[], int &count);
void withdrawMoney(int &balance, string history[], int &count);
void showTransactions(string history[], int count);

int main() {

    int defaultPIN = 1234;
    int pin;
    int attempts = 3;

    int balance = 0;
    int choice;

    string transactionHistory[100];
    int transCount = 0;

    
    while (attempts > 0) {

        cout << "\nEnter PIN: ";
        cin >> pin;

        if (pin == defaultPIN) {
            cout << "\nLogin Successful!\n";

            do {
                cout << "\n===== ATM MENU =====\n";
                cout << "1. Check Balance\n";
                cout << "2. Deposit Money\n";
                cout << "3. Withdraw Money\n";
                cout << "4. Transaction History\n";
                cout << "5. Exit\n";
                cout << "Choose: ";
                cin >> choice;

                switch (choice) {

                case 1:
                    checkBalance(balance);
                    break;

                case 2:
                    depositMoney(balance, transactionHistory, transCount);
                    break;

                case 3:
                    withdrawMoney(balance, transactionHistory, transCount);
                    break;

                case 4:
                    showTransactions(transactionHistory, transCount);
                    break;

                case 5:
                    cout << "\nThank you for using ATM.\n";
                    break;

                default:
                    cout << "\nInvalid choice!\n";
                }

            } while (choice != 5);

            break;
        }
        else {
            attempts--;
            cout << "\nWrong PIN!\n";
            cout << "Remaining attempts: " << attempts << endl;
        }
    }

    if (attempts == 0) {
        cout << "\nATM BLOCKED!\n";
    }

    return 0;
}



void checkBalance(int balance) {
    cout << "\nCurrent Balance: " << balance << " FRW\n";
}

void depositMoney(int &balance, string history[], int &count) {

    int amount;

    cout << "\nEnter amount to deposit: ";
    cin >> amount;

    balance += amount;

    history[count] = "Deposited: " + to_string(amount) + " FRW";
    count++;

    cout << "\nDeposit Successful!\n";
}

void withdrawMoney(int &balance, string history[], int &count) {

    int amount;

    cout << "\nEnter amount to withdraw: ";
    cin >> amount;

    if (amount > balance) {
        cout << "\nInsufficient Funds!\n";
    }
    else {
        balance -= amount;

        history[count] = "Withdrawn: " + to_string(amount) + " FRW";
        count++;

        cout << "\nWithdrawal Successful!\n";
    }
}

void showTransactions(string history[], int count) {

    if (count == 0) {
        cout << "\nNo Transactions Found!\n";
    }
    else {

        cout << "\n===== TRANSACTION HISTORY =====\n";

        for (int i = 0; i < count; i++) {
            cout << i + 1 << ". " << history[i] << endl;
        }
    }
}