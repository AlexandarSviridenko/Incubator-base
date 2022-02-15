#include <iostream>
#define MAX_DATE 31    
#define MAX_MONTH 12

using namespace std;


int main(){
	int date = 0;  
	int month = 0;
	int year = 0;
	int dateNumber1 = 0;
	int dateNumber2 = 0;
	int monthNumber1 = 0;
	int monthNumber2 = 0;
	int rememberLastNumber = 0;
	int sumNumberYear = 0;
	int firstSum = 0;
	int destinyNumber = 0;
	int firstSumNumber1 = 0;
	int firstSumNumber2 = 0;
	
	cout << "Input Date of Birth(3 numbers)" << endl << "Date:";
	cin >> date;
	cout << "Month:";
	cin >> month;
	cout << "Year:";
	cin >> year;
	
	if (date <= 0 or date > MAX_DATE) {
		cout << "Wrong date";
		return 1;
	}
	if (month <= 0 or month > MAX_MONTH) {
		cout << "Wrong month";
		return 2;
	}	
	
	dateNumber1 = date / 10;
	dateNumber2 = date % 10;
	
	monthNumber1 = month / 10;
	monthNumber2 = month % 10;
	
	while (year > 0) {
		rememberLastNumber = year % 10;
		sumNumberYear = sumNumberYear + rememberLastNumber;
		year = year / 10;
	}
	firstSum = dateNumber1 + dateNumber2 + monthNumber1 + monthNumber2 + sumNumberYear;
	firstSumNumber1 = firstSum / 10;
	firstSumNumber2 = firstSum % 10;
	 
	 if (firstSumNumber1+firstSumNumber2>=10){
	 	int finalNumber1 = 0;
	 	int finalNumber2 = 0;
	 	finalNumber1 = (firstSumNumber1 + firstSumNumber2) / 10;
	 	finalNumber2 = (firstSumNumber1 + firstSumNumber2) % 10;
	 	destinyNumber = finalNumber1 + finalNumber2;
	 }
	 else{
	 	destinyNumber = firstSumNumber1 + firstSumNumber2;
	 }
	 cout << "Destiny Number: " << destinyNumber;	
	 return 0;  
}
