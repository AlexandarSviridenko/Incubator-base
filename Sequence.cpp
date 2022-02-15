#include <iostream>

using namespace std;

int getNumberDischarge(int number);

int main(){
	int number = 0;
	int index = 1;
	int k = 0;
	int testnumber = 0;
	int counter = 0;
	int discharge = 0;
	int digit = 0;
	
	cout << "Introduced sequence 14916253649 " << endl << "The program will display the number corresponding to the given index and the sequence itself." << endl;
	cout << "Specify the index K of the given sequence." << endl;
	cin >> k;
	
	if(k <= 0){
		cout << "Wrong index K. K need more 0";
		return 1;	
	}
	
	while (k >= index){
		number = index * index;	
		testnumber = number;
		discharge = getNumberDischarge(number);
		cout << number;
		index++;
		while (discharge >= 1){
			digit = (testnumber / discharge) % 10;
			discharge /= 10;
			counter++;
			if (counter == k){
				cout << endl <<"Sequence digit is " << digit;
				return 0;
			}
		}	
	}
}
	
	int getNumberDischarge(int number) {
    	int counter = 0;
    	int tens = 1;
    	int discharge = 0;
   		while (number > 0) {
        	number /= 10;
        	counter++;
        	if (counter > 1)
        	tens *= 10;
    	}
    	discharge += tens;
    	return discharge;
	}

	
	

	
	

