#include <iostream>

using namespace std;

void sequence();
void repitSequence();

int main(){
	sequence();
	repitSequence();
}
	void sequence(){
		int number = 0;
		int m = 0;
		
		cout << "Input m" << endl; //���������
		cin >> m;
		
		while(number != m){
			number++;
			cout << number;	
		}
	}

	void repitSequence(){
		int number = 0;
		int m = 0;
		int testNumber = 0;
		int binarNumber = 0;
		int translate = 0;
		int tens = 10;
		int nextBinarNumber=0;
		int counter = 1;
		bool oneNull = true;
		
		cout << "Input m" << endl; //���������
		cin >> m;
		
		while(number != m){ // ���� ����������� ������.
			number++;
			testNumber = number;
			
			while(testNumber != 0){ //���� �� �������� � �������� �����
				binarNumber = testNumber % 2;
				testNumber/=2;              
				nextBinarNumber = nextBinarNumber   + binarNumber * counter ;
				counter*= tens ;	
			}
			//cout << nextBinarNumber << endl;
				while(nextBinarNumber > 0 or oneNull == true ){	 //������ �����
					if(nextBinarNumber % 10 == 0){
					return false;
				}
				if(oneNull == true){
					cout << number << endl;
				}
				
			oneNull = true;
			counter = 1;
			nextBinarNumber = 0;	
		}
	}
