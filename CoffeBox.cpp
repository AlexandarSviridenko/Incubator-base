#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <string>
#include <iomanip>
#define COST_CAPPUCCINO 2.0
#define COST_LATTE 2.5
#define COST_ESPRESSO 1.9
#define MONEY_2 2
#define MONEY_1 1
#define MONEY_05 0.5
#define MONEY_02 0.2
#define MONEY_01 0.1
#define CAPPUCCINO "Cappuccino"
#define ESPRESSO "Espresso"
#define LATTE "Latte"
#define PIN 1111
#define MAX_CUPS 700
#define COFFE_BOX_NAME "LEI700"

using namespace std;

double depositMoney2();
double depositMoney1();
double depositMoney05();
double depositMoney02();
double depositMoney01();
void showMenu();
void showDepositMenu();
int functionalShowMenu ();
void functionDeposit ();
void takeCoffee(int choice);
void enterServiceMenu();
void printServiceMenu();
void serviceMenuSelectionProcessing(int choose);
void setCups();
void getEarnings();

bool serviceMenuBlocked = false;
double earnings = 0.0;
double balance = 0.0;
int cup = 0;


int main()
{
	cup = 7;
	functionalShowMenu ();
	return 0;
}


void showMenu (){	
	cout << endl << " Welcome to Coffeebox" << endl;
		
	if(cup <= 5 and cup >= 0){
		cout <<	endl << " WARNING! Cup left: " << cup << endl;
	}
	if (cup == 0) {
		cout << endl << " Sorry, Cup is over." << endl;
	}
	if(cup >= 0) {
		cout << endl << " Balance:   " << balance << endl;
		cout << "_________________________________" << endl;
	
		cout << endl << endl << " 1 - Deposit Money" << endl;
		cout << " 2 - Espresso             " << COST_ESPRESSO << " BYN" << endl;
		cout << " 3 - Cappuccino           " << COST_CAPPUCCINO << "   BYN" << endl;
		cout << " 4 - Latte                " << COST_LATTE << " BYN" <<endl;
		cout << " 5 - Service Menu" << endl;
	}
}

void showDepositMenu() {
	
	cout << endl << " Balance:   " << balance << endl;
	cout << "_________________________________" << endl;
	
	cout << endl << endl << " 1 - 2 BYN" << endl;
	cout << " 2 - 1 BYN" << endl;
	cout << " 3 - 50 penny" << endl;
	cout << " 4 - 20 penny" << endl;
	cout << " 5 - 10 penny" << endl;
	cout << " 6 - Back" << endl;
}

double depositMoney2() {
	balance += MONEY_2;
	earnings += MONEY_2;
	return balance; 
}

double depositMoney1() {
	balance += MONEY_1;
	earnings += MONEY_1;
	return balance;
}

double depositMoney05() {
	balance += MONEY_05;
	earnings += MONEY_05;
	return balance;
}

double depositMoney02() {
	balance += MONEY_02;
	earnings += MONEY_02;
	return balance;
}

double depositMoney01() {
	balance += MONEY_01;
	earnings += MONEY_01;
	return balance;
}

int functionalShowMenu () {
	int choice = 0;
	while (true) {
		std::system("cls");
		choice = 0;
		showMenu();
		cout << endl << " Your choice? ";
		cin >> choice;
		if (cup == 0) {
			if (choice == 5) {			
				enterServiceMenu();		
				return functionalShowMenu ();							
			}
			else {
				std::system("cls");	
				cout << endl << " Input [5], please " << endl;
				Sleep(2000);
			}
		}
		else {
			std::system("cls");
			if (choice == 1) {                                                                  
				functionDeposit ();
			}
			else if (choice >= 2 and choice	<= 4) {
				takeCoffee(choice);
			}
			else if (choice == 5) { 
				enterServiceMenu();	
			}
			else {	
				cout << endl << " Exception.Input [1..5], please " << endl;	
				Sleep(2000);
			}
		}	
	}
}


void functionDeposit () {
	int choiceDeposit = 0;	
	while(true) {			
		showDepositMenu();			

		cout << endl << " Your choice? ";
		cin >> choiceDeposit;
			
		if (choiceDeposit == 1) {
			std::system("cls");
			balance = depositMoney2();
		}
		else if (choiceDeposit == 2) {
				std::system("cls");
				balance = depositMoney1();
		}
		else if (choiceDeposit == 3) {
				std::system("cls");
				balance = depositMoney05();
		}
		else if (choiceDeposit == 4) {
				std::system("cls");
				balance = depositMoney02();
		}
		else if (choiceDeposit == 5) {
				std::system("cls");
				balance = depositMoney01();
		}
		else if (choiceDeposit == 6) {														
				std::system("cls");	
				break;
		}
		else{
			std::system("cls");	
			cout << endl << " Exception. Input [1..6], please " << endl;
			choiceDeposit = 0;
			functionDeposit();
			break;			
		}	
 	}
}

void takeCoffee (int choice) {
	string name = " ";
	std::system("cls");
	if ((choice == 2 and balance < COST_ESPRESSO) or
			(choice == 3 and balance < COST_CAPPUCCINO) or
			(choice == 4 and balance < COST_LATTE)) {
				cout << endl << " Insufficient funds. Go back menu and replenish the deposit." << endl;
				Sleep(2000);
	} else {
		if(choice == 2) {
			name = ESPRESSO;
			balance -= COST_ESPRESSO;
		}
		else if (choice == 3) {
			name = CAPPUCCINO;
			balance -= COST_CAPPUCCINO;
		}
		else if (choice == 4) {
			name = LATTE;
			balance -= COST_LATTE;
		}
		cout << endl << " Your " << name << " is being prepared, please wait. " <<  endl;
		Sleep(2000);
		cout << endl << " Finish. Good day." << endl;
		cup--;
		Sleep(2000);
		std::system("cls");
		}	
}

void enterServiceMenu() {
    int pin = 0;
    int counter = 0;
    const int MAX_ATTEMPTS = 3;

    if (serviceMenuBlocked) {
        cout << endl << " ERROR: Service menu was blocked." << endl;
        cout << endl << " Contact Support." << endl;
        Sleep(3000);
        return;
    }

    while(pin != PIN) {
        std::system("cls");
        cout << endl << " Warning, this menu is only for staff" << endl;
        cout << endl << " For exit type - '0'." << endl;
        cout << endl << " Enter service PIN code: ";
        cin >> pin;
        
        if (pin == 0) {
        	return;
        }

        if (pin == PIN) {
            break;
        }
        std::system("cls");
        cout << endl << " ERROR: Wrong PIN-code!" << endl;
        counter++;
        if (counter == MAX_ATTEMPTS) {
            std::system("cls");
            cout << endl << " ERROR:You exceeded number of entry attempts." << endl;
            cout << endl << " The Service menu was blocked!" << endl;
            serviceMenuBlocked = true;
            Sleep(2000);
            return;
        }
        cout << MAX_ATTEMPTS - counter << " attempts left" << endl;
        Sleep(2000);
    }
    std::system("cls");
    cout << endl << " SUCCES: You have entered in service menu " << endl;
    Sleep(2000);
    printServiceMenu();
}

void printServiceMenu() {
    int choose = 0;

    while(true) {
        std::system("cls");
        cout << endl << COFFE_BOX_NAME << " Service menu" << endl;
        cout << "--------------------" << endl << endl;
        cout << " 1. Accumulated cash" << endl;
        cout << " 2. Show Cup" << endl;
        cout << " 3. Take Money" << endl;
        cout << endl << " 4. Back" << endl;

        cout << endl << " Please choose the option [1 - 4]: ";
        cin >> choose;

        if (choose == 4)
        {
            std::system("cls");
            cout << endl << " Exit from service menu" << endl;
            Sleep(2000);
            std::system("cls");
            return;
        }
        serviceMenuSelectionProcessing(choose);
    }
}

void serviceMenuSelectionProcessing(int choose) {
    if (choose == 1) {
        cout << endl << " Earnings" << setw(10) << earnings << " BYN" << endl << endl;
        Sleep(5000);
    }
    else if (choose == 2) {
        setCups();
    }
    else if (choose == 3) {
        std::system("cls");
        getEarnings();
    }
    else {
        cout << endl << " ERROR: No such option." << endl;
        Sleep(2000);
        std::system("cls");
    }
}


void setCups() {
    int cupsAmount = 0;


        cout << endl << " Cups in the " << COFFE_BOX_NAME << " " << cup << " pcs." << endl;
        cout << " You can set up " << MAX_CUPS - cup << " pcs." << endl;
        cout << " How many cups do you want to set up? ";
        cin >> cupsAmount;

        std::system("cls");
        if (cupsAmount < 0 or cup + cupsAmount > MAX_CUPS) {
            cout << endl <<  "ERROR: The number of cups in  cannot be greater than " << MAX_CUPS << endl;
        }
        else {
            cup += cupsAmount;
            cout << endl << " SUCCESS: You have set up " << cupsAmount << " cups." << endl;
            cout << " Cups in the " << COFFE_BOX_NAME << " " << cup << " pcs." << endl;   
        }
    Sleep(2000);
}

void getEarnings() {
    std::system("cls");

        if (earnings == 0.0) {
            cout << endl << " There is no earnings in the Coffee Box." << endl;
        }
        else {
            cout << endl << " SUCCESS: You have picked up " << earnings << " BYN" << endl;
            earnings = 0.0;
            balance = 0.0;
        }
    
    Sleep(2000);
}




