#include <iostream>
#define ARR_SIZE 10

using namespace std;

void initializationField();
void workWithFigur ();
void choiceFirstFigur();
void safeOldArr();
int end();
void showField();
int compareArr();

int arr[10][10];
int arr2[10][10];

int main(){
	int a =0;
	
	initializationField();
	choiceFirstFigur();	
	cout << endl << "FIELD START" << endl;
	showField();
	while (true){
		safeOldArr();
		cout << endl << "FIELD CHANGE" << endl;
		workWithFigur();
		end();
		if (compareArr() == 0){
			cout << "The End";
			return 2;
		}
	}
	return 0;	
}

int compareArr(){
	int counter = 0;
	for (int i = 0; i < ARR_SIZE; i++) {
		for (int j = 0; j < ARR_SIZE; j++) {
			if (arr2[i][j] != arr[i][j]){
				counter +=1;
			}
			
		}
	}
	return counter;		
}

void initializationField(){
	for (int i = 0; i < ARR_SIZE; i++) {
		for (int j = 0; j < ARR_SIZE; j++) {
			arr[i][j] = 0;
		}
		cout << endl;
	}
	cout << endl << endl;		
}

void showField(){
	for (int i = 0; i < ARR_SIZE; i++) {
		for (int j = 0; j < ARR_SIZE; j++) {
			cout << " " << arr[i][j];
		}
		cout << endl;
	}
	cout << endl << endl;		
}

void workWithFigur (){
	int sum = 0;
	for (int i = 0; i < ARR_SIZE; i++) {
		for (int j = 0; j < ARR_SIZE; j++) {
			sum = arr[i-1][j-1] + arr[i-1][j] + arr[i-1][j+1] + arr[i][j-1] + arr[i][j+1] + arr[i+1][j-1] + arr[i+1][j] + arr[i+1][j+1];
				if (arr[i][j] == 0){		
					if ( sum == 3){
						arr[i][j] = 1;
					}
				}
				else {
					if (arr[i][j] == 1){
						if (sum < 2 or sum > 3){
							arr[i][j] = 0;
						}		
					}
				}
			cout << " " << arr[i][j];
		}
		cout << endl;
	}
}

void choiceFirstFigur(){
	arr[1][1] = 1 ;
	arr[2][1] = 1;
	arr[3][1] = 1;
	arr[2][2] = 1;
	arr[1][3] = 1;
	arr[3][3] = 1;
	arr[2][4] = 1;
}

void safeOldArr(){
	for (int i = 0; i < ARR_SIZE; i++) {
		for (int j = 0; j < ARR_SIZE; j++) {
			arr2[i][j] = arr[i][j];
		}
	}		
}

int end(){
	int counter =0;
	for (int i = 0; i < ARR_SIZE; i++) {
		for (int j = 0; j < ARR_SIZE; j++) {	
			if(arr[i][j] == 1){
				counter += 1;
			}
		}
	}
	if( counter == 0){
		return 1;
	}
}
