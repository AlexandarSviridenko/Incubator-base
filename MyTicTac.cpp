#include <iostream>
#include <cstdlib>
#include <cstdlib> 
#define ARR_SIZE 3
#include <ctime>

using namespace std;

void inputXandO();
void showField();
void instructionChoice();
void whoGoes();
void whoGoesNext();
void AI();
int win();
void winOrDefanse();
void winOrAttack();

int counter = 0;
bool firstGoes = false;
char ticTac[ARR_SIZE][ARR_SIZE] = {{' ',' ',' '}, {' ',' ',' '},{' ',' ',' '}};
char player1 = ' ';
char player2 = ' ';
char choiceValue = ' ';
int choice = 0;
int choice1 = 0;
int choice2 = 0;

int main(){	
	inputXandO();
	showField();
	whoGoes();
	instructionChoice();		
	while(true){	
		showField();
		whoGoesNext();
		instructionChoice();
		if(win() == 1){
			return 2;
		}
	}
	return 0;
}

void inputXandO(){
	bool wrongValue = true;
	while(wrongValue){
		cout << "Select X or O" << endl;
		cout << "Input your choice: " << endl;
		cout << "Your choice Player 1:  " ;
		cin >> player1;
		while (true){
			if (player1 == 'X'){
				cout << " Computer select O." << endl;
				cout << " Player 1 goes first." << endl;
				wrongValue = false;
				player1 = 'X';
				player2 = 'O';
				firstGoes = true;   
				break;
			}
			else if (player1 == 'O'){
				cout << " Computer select X." << endl;
				cout << " Computer goes first." << endl;
				wrongValue = false;
				player1 = 'O';
				player2 = 'X';
				break;
			}
			else {
				cout << "Wrong Input. Again select X or O" << endl;
				break;
			}
		}
	}
}

void showField(){		
	int count = 1;
	cout << endl << "Field." << endl;
	for (int i = 0; i < ARR_SIZE; i++) {
		for (int j = 0; j < ARR_SIZE; j++) {
			cout << ticTac[i][j];
			if(j != 2){
				cout << " | ";
			}
		}
		if (i != 2){
			cout << endl;
			cout << "----------" << endl;
		}
	}
	cout << endl << endl;
	cout << "Note help you."<< endl;
	for (int i = 0; i < ARR_SIZE; i++) {
		for (int j = 0; j < ARR_SIZE; j++) {
			cout << count;
			if(j != 2){
				cout << " | ";
			}
			count++;
		}
		if (i != 2){
			cout << endl;
			cout << "----------" << endl;
		}
	}
	cout << endl;
}

void whoGoes(){
	if(firstGoes){
		choiceValue = player1;
	}
	else {
		choiceValue = player2;
	}
}

void whoGoesNext(){
	if (choiceValue == player1){
		choiceValue = player2;	
	}
	else {
		choiceValue = player1;
		cout << endl << "Goes Player 1." << endl;
	}
}

void instructionChoice(){		
	bool wrongValue = true;
	while(wrongValue){
		choice = 0;
		cout << "Your choice: ";	
		if (player1 == 'X'){        //логика описывающая кто ходит в зависимости от выбора Х или О
			if (counter % 2 == 0){
				cin >> choice;	
			}
			else {
				std::system("cls");
				cout << endl << "Goes Computer." << endl;
				winOrDefanse();
				if (choice1 !=0){
					choice = choice1;
				}
				winOrAttack();
					if (choice2 != 0){
						choice = choice2;
					}
					if(choice == 0) {
						AI();	
					}
			}
		}
		else if (player1 == 'O'){
			if (counter % 2 == 1){
				cin >> choice;
			}
			else{
				std::system("cls");
				cout << endl << "Goes Computer." << endl;
				winOrAttack();
				if (choice2 != 0){
					choice = choice2;
				}				
				winOrDefanse();	
				if (choice1 !=0){
					choice = choice1;
				}
				if(choice == 0) {
					AI();	
				}	
			}
		}	
		while(true){		
			if(choice >=1 and choice <=9){
				wrongValue = false;
			}
			if (choice == 1){
				if (ticTac[0][0] == player1 or ticTac[0][0] == player2 ){
					wrongValue = true;
					cout << "This cell is occupied, choose another one." << endl;
				}
				else{
					ticTac[0][0] = choiceValue ;
				}
				break;
			}
			else if (choice == 2){
				if (ticTac[0][1] == player1 or ticTac[0][1] == player2 ){
					wrongValue = true;
					cout << "This cell is occupied, choose another one." << endl;
				}
				else{
					ticTac[0][1] = choiceValue;
				}
				break;
			}
			else if (choice == 3){
				if (ticTac[0][2] == player1 or ticTac[0][2] == player2 ){
					wrongValue = true;
					cout << "This cell is occupied, choose another one." << endl;
				}
				else{				
					ticTac[0][2] = choiceValue;
				}
				break;
			}
			else if (choice == 4){
				if (ticTac[1][0] == player1 or ticTac[1][0] == player2 ){
					wrongValue = true;
					cout << "This cell is occupied, choose another one." << endl;
				}
				else{
					ticTac[1][0] = choiceValue;
				}
				break;
			}
			else if (choice == 5){
				if (ticTac[1][1] == player1 or ticTac[1][1] == player2 ){
					wrongValue = true;
					cout << "This cell is occupied, choose another one." << endl;
				}				
				else{
					ticTac[1][1] = choiceValue;
				}
				break;
			}
			else if (choice == 6){
				if (ticTac[1][2] == player1 or ticTac[1][2] == player2 ){
					wrongValue = true;
					cout << "This cell is occupied, choose another one." << endl;
				}
				else{			
					ticTac[1][2] = choiceValue;
				}
				break;
			}
			else if (choice == 7){
				if (ticTac[2][0] == player1 or ticTac[2][0] == player2 ){
					wrongValue = true;
					cout << "This cell is occupied, choose another one." << endl;
				}
				else {				
					ticTac[2][0] = choiceValue;
				}
				break;
			}
			else if (choice == 8){
				if (ticTac[2][1] == player1 or ticTac[2][1] == player2 ){
					wrongValue = true;
					cout << "This cell is occupied, choose another one." << endl;
				}				
				else{
					ticTac[2][1] = choiceValue;
				}
				break;
			}
			else if (choice == 9){
				if (ticTac[2][2] == player1 or ticTac[2][2] == player2 ){
					wrongValue = true;
					cout << "This cell is occupied, choose another one." << endl;
				}
				else{				
					ticTac[2][2] = choiceValue;
				}
				break;
			}
			else {
				cout << "Wrong choice. Inpur number 1..9." << endl;
				break;
			}	
		}
		cout << endl << "Choice = " << choice << endl;
	}
	counter+=1;
}

void AI(){
	choice = 0;
	srand(time(0));
	choice = 1 + rand() % 9;
}

int win(){  
	if (ticTac[0][0] == player1 and ticTac[0][1]==player1 and ticTac[0][2]==player1){
		cout << "Win Player 1";
		return 1;
	}
	else if (ticTac[1][0] == player1 and ticTac[1][1]==player1 and ticTac[1][2]==player1){
		cout << "Win Player 1";	
		return 1;
	}
	else if(ticTac[2][0] == player1 and ticTac[2][1]==player1 and ticTac[2][2]==player1){
		cout << "Win Player 1";
		return 1;
	}
	else if (ticTac[0][1] == player1 and ticTac[1][1]==player1 and ticTac[2][1]==player1){
		cout << "Win Player 1";
		return 1;
	}
	else if (ticTac[0][0] == player1 and ticTac[1][0]==player1 and ticTac[2][0]==player1){
		cout << "Win Player 1";
		return 1;
	}
	else if (ticTac[0][2] == player1 and ticTac[1][2]==player1 and ticTac[2][2]==player1){
		cout << "Win Player 1";
		return 1;
	}
	else if (ticTac[0][0] == player1 and ticTac[1][1]==player1 and ticTac[2][2]==player1){
		cout << "Win Player 1";
		return 1;
	}
	else if (ticTac[2][0] == player1 and ticTac[1][1]==player1 and ticTac[0][2]==player1){
		cout << "Win Player 1";
		return 1;
	}
	else if(ticTac[0][0] == player2 and ticTac[0][1]==player2 and ticTac[0][2]==player2){
		cout << "Win Computer";
		return 1;
	}
	else if(ticTac[1][0] == player2 and ticTac[1][1]==player2 and ticTac[1][2]==player2){
		cout << "Win Computer";	
		return 1;
	}
	else if (ticTac[2][0] == player2 and ticTac[2][1]==player2 and ticTac[2][2]==player2){
		cout << "Win Computer";
		return 1;
	}
	else if (ticTac[0][1] == player2 and ticTac[1][1]==player2 and ticTac[2][1]==player2){
		cout << "Win Computer";	
		return 1;
	}
	else if (ticTac[0][0] == player2 and ticTac[1][0]==player2 and ticTac[2][0]==player2){
		cout << "Win Computer";
		return 1;
	}
	else if (ticTac[0][2] == player2 and ticTac[1][2]==player2 and ticTac[2][2]==player2){
		cout << "Win Computer";
		return 1;
	}
	else if (ticTac[0][0] == player2 and ticTac[1][1]==player2 and ticTac[2][2]==player2){
		cout << "Win Computer";
		return 1;
	}
	else if (ticTac[2][0] == player2 and ticTac[1][1]==player2 and ticTac[0][2]==player2){
		cout << "Win Computer";
		return 1;
	}
	else if (ticTac[0][0] != ' ' and ticTac[0][1] != ' 'and ticTac[0][2] != ' ' and ticTac[1][0] != ' ' and ticTac[1][1] != ' ' and ticTac[1][2] != ' ' and ticTac[2][0] != ' ' and ticTac[2][1] != ' ' and ticTac[2][2] != ' '){
		cout << "Draw.";
		return 1;
	}
}
 
 void winOrDefanse(){
	choice1 = 0;
	if((ticTac[0][0] == 'X' and ticTac[0][1] == 'X') and (ticTac[0][2] != 'O' and ticTac[0][2] != 'X')){
		choice1 = 3;
	}
	else if ((ticTac[0][0] == 'X' and ticTac[0][2] == 'X') and (ticTac[0][1] != 'O' and ticTac[0][1] != 'X')){
		choice1 = 2;
	}
	else if ((ticTac[0][1] == 'X' and ticTac[0][2] == 'X') and (ticTac[0][0] != 'O' and ticTac[0][0] != 'X')){
	choice1 = 1;
	}	
	else if((ticTac[1][0] == 'X' and ticTac[1][1] == 'X') and (ticTac[1][2] != 'O' and ticTac[1][2] != 'X')){
		choice1 = 6;
	}
	else if ((ticTac[1][0] == 'X' and ticTac[1][2] == 'X') and (ticTac[1][1] != 'O' and ticTac[1][1] != 'X')){
		choice1 = 5;
	}
	else if ((ticTac[1][1] == 'X' and ticTac[1][2] == 'X') and (ticTac[1][0] != 'O' and ticTac[1][0] != 'X')){
		choice1 = 4;
	}
	else if ((ticTac[2][1] == 'X' and ticTac[2][2] == 'X') and (ticTac[2][0] != 'O' and ticTac[2][0] != 'X')){
		choice1 = 7;
	}	
	else if ((ticTac[2][0] == 'X' and ticTac[2][2] == 'X') and (ticTac[2][1] != 'O' and ticTac[2][1] != 'X')){
		choice1 = 8;
	}	
	else if ((ticTac[2][0] == 'X' and ticTac[2][1] == 'X') and (ticTac[2][2] != 'O' and ticTac[2][2] != 'X')){
		choice1 = 9;
	}
	else if ((ticTac[0][0] == 'X' and ticTac[1][0] == 'X') and (ticTac[2][0] != 'O' and ticTac[2][0] != 'X')){
		choice1 = 7;
	}
	else if ((ticTac[0][0] == 'X' and ticTac[2][0] == 'X') and (ticTac[1][0] != 'O' and ticTac[1][0] != 'X')){
		choice1 = 4;
	}	
	else if ((ticTac[1][0] == 'X' and ticTac[2][0] == 'X') and (ticTac[0][0] != 'O' and ticTac[0][0] != 'X')){
		choice1 = 1;
	}
	else if ((ticTac[0][1] == 'X' and ticTac[1][1] == 'X') and (ticTac[2][1] != 'O' and ticTac[2][1] != 'X')){
		choice1 = 8;
	}
	else if ((ticTac[0][1] == 'X' and ticTac[2][1] == 'X') and (ticTac[1][1] != 'O' and ticTac[1][1] != 'X')){
		choice1 = 5;
	}	
	else if ((ticTac[1][1] == 'X' and ticTac[2][1] == 'X') and (ticTac[0][1] != 'O' and ticTac[0][1] != 'X')){
		choice1 = 2;
	}
	else if ((ticTac[0][2] == 'X' and ticTac[1][2] == 'X') and (ticTac[2][2] != 'O' and ticTac[2][2] != 'X')){
		choice1 = 9;
	}
	else if ((ticTac[0][2] == 'X' and ticTac[2][2] == 'X') and (ticTac[1][2] != 'O' and ticTac[1][2] != 'X')){
		choice1 = 6;
	}	
	else if ((ticTac[1][2] == 'X' and ticTac[2][2] == 'X') and (ticTac[0][2] != 'O' and ticTac[0][2] != 'X')){
		choice1 = 3;
	}	
	else if ((ticTac[0][0] == 'X' and ticTac[1][1] == 'X') and (ticTac[2][2] != 'O' and ticTac[2][2] != 'X')){
		choice1 = 9;
	}
	else if ((ticTac[2][2] == 'X' and ticTac[1][1] == 'X') and (ticTac[0][0] != 'O' and ticTac[0][0] != 'X')){
		choice1 = 1;
	}
	else if ((ticTac[2][2] == 'X' and ticTac[0][0] == 'X') and (ticTac[1][1] != 'O' and ticTac[1][1] != 'X')){
		choice1 = 5;
	}
	else if ((ticTac[0][2] == 'X' and ticTac[1][1] == 'X') and (ticTac[2][0] != 'O' and ticTac[2][0] != 'X')){
		choice1 = 7;
	}
	else if ((ticTac[2][0] == 'X' and ticTac[1][1] == 'X') and (ticTac[0][2] != 'O' and ticTac[0][2] != 'X')){
		choice1 = 3;
	}
	else if ((ticTac[0][2] == 'X' and ticTac[2][0] == 'X') and (ticTac[1][1] != 'O' and ticTac[1][1] != 'X')){
		choice1 = 5;
	}		
	else {
		choice1 = 0;
	}
}

void winOrAttack(){
	choice2 = 0;
	if((ticTac[0][0] == 'O' and ticTac[0][1] == 'O') and (ticTac[0][2] != 'O' and ticTac[0][2] != 'X')){
		choice2 = 3;
	}
	else if ((ticTac[0][0] == 'O' and ticTac[0][2] == 'O') and (ticTac[0][1] != 'O' and ticTac[0][1] != 'X')){
		choice2 = 2;
	}
	else if ((ticTac[0][1] == 'O' and ticTac[0][2] == 'O') and (ticTac[0][0] != 'O' and ticTac[0][0] != 'X')){
	choice2 = 1;
	}	
	else if((ticTac[1][0] == 'O' and ticTac[1][1] == 'O') and (ticTac[1][2] != 'O' and ticTac[1][2] != 'X')){
		choice2 = 6;
	}
	else if ((ticTac[1][0] == 'O' and ticTac[1][2] == 'O') and (ticTac[1][1] != 'O' and ticTac[1][1] != 'X')){
		choice2 = 5;
	}
	else if ((ticTac[1][1] == 'O' and ticTac[1][2] == 'O') and (ticTac[1][0] != 'O' and ticTac[1][0] != 'X')){
		choice2 = 4;
	}
	else if ((ticTac[2][1] == 'O' and ticTac[2][2] == 'O') and (ticTac[2][0] != 'O' and ticTac[2][0] != 'X')){
		choice2 = 7;
	}	
	else if ((ticTac[2][0] == 'O' and ticTac[2][2] == 'O') and (ticTac[2][1] != 'O' and ticTac[2][1] != 'X')){
		choice2 = 8;
	}	
	else if ((ticTac[2][0] == 'O' and ticTac[2][1] == 'O') and (ticTac[2][2] != 'O' and ticTac[2][2] != 'X')){
		choice2 = 9;
	}
	else if ((ticTac[0][0] == 'O' and ticTac[1][0] == 'O') and (ticTac[2][0] != 'O' and ticTac[2][0] != 'X')){
		choice2 = 7;
	}
	else if ((ticTac[0][0] == 'O' and ticTac[2][0] == 'O') and (ticTac[1][0] != 'O' and ticTac[1][0] != 'X')){
		choice2 = 4;
	}	
	else if ((ticTac[1][0] == 'O' and ticTac[2][0] == 'O') and (ticTac[0][0] != 'O' and ticTac[0][0] != 'X')){
		choice2 = 1;
	}
	else if ((ticTac[0][1] == 'O' and ticTac[1][1] == 'O') and (ticTac[2][1] != 'O' and ticTac[2][1] != 'X')){
		choice2 = 8;
	}
	else if ((ticTac[0][1] == 'O' and ticTac[2][1] == 'O') and (ticTac[1][1] != 'O' and ticTac[1][1] != 'X')){
		choice2 = 5;
	}	
	else if ((ticTac[1][1] == 'O' and ticTac[2][1] == 'O') and (ticTac[0][1] != 'O' and ticTac[0][1] != 'X')){
		choice2 = 2;
	}
	else if ((ticTac[0][2] == 'O' and ticTac[1][2] == 'O') and (ticTac[2][2] != 'O' and ticTac[2][2] != 'X')){
		choice2 = 9;
	}
	else if ((ticTac[0][2] == 'O' and ticTac[2][2] == 'O') and (ticTac[1][2] != 'O' and ticTac[1][2] != 'X')){
		choice2 = 6;
	}	
	else if ((ticTac[1][2] == 'O' and ticTac[2][2] == 'O') and (ticTac[0][2] != 'O' and ticTac[0][2] != 'X')){
		choice2 = 3;
	}	
	else if ((ticTac[0][0] == 'O' and ticTac[1][1] == 'O') and (ticTac[2][2] != 'O' and ticTac[2][2] != 'X')){
		choice2 = 9;
	}
	else if ((ticTac[2][2] == 'O' and ticTac[1][1] == 'O') and (ticTac[0][0] != 'O' and ticTac[0][0] != 'X')){
		choice2 = 1;
	}
	else if ((ticTac[2][2] == 'O' and ticTac[0][0] == 'O') and (ticTac[1][1] != 'O' and ticTac[1][1] != 'X')){
		choice2 = 5;
	}
	else if ((ticTac[0][2] == 'O' and ticTac[1][1] == 'O') and (ticTac[2][0] != 'O' and ticTac[2][0] != 'X')){
		choice2 = 7;
	}
	else if ((ticTac[2][0] == 'O' and ticTac[1][1] == 'O') and (ticTac[0][2] != 'O' and ticTac[0][2] != 'X')){
		choice2 = 3;
	}
	else if ((ticTac[0][2] == 'O' and ticTac[2][0] == 'O') and (ticTac[1][1] != 'O' and ticTac[1][1] != 'X')){
		choice2 = 5;
	}	
	else {	
		choice2 = 0;
	}
}



