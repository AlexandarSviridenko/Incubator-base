#include <iostream>
#include <cmath>

using namespace std;

void count();
void countNM(int n, int m);
int getSum(int n, int m);
double getAverage(int n, int m);
void distance();

int main()
{
	int n = 0;
	int m = 0;
	
	cout << endl << "Input N" << endl;
	cin >> n;
	cout << "Input M" << endl;
	cin >> m;
	
	count();
	cout << endl;
	countNM(n, m);
	cout << endl;
	cout << "Sum = " << getSum(n, m) << endl;
	cout << "Average = " << getAverage(n, m);
	cout << endl;
	distance();
}

void count()
{                         
	int permanentIncrease = 1;
	int maxNumber = 10;
	int number = 0;
	while (number < maxNumber){
		number += permanentIncrease;
		cout << number;
	}
}

void countNM(int n, int m)
{
	int permanentIncrease = 1;
	int number = 0;
		
	cout << n;
	while(n < m){
		n += permanentIncrease;
		cout << n;
	}
}
	
int getSum(int n, int m)
{
	int permanentIncrease = 1;
	int Sum = 0;
		
	while(n <= m){
		Sum += n;
		n += permanentIncrease;
	}
	return Sum;
}
	
double getAverage(int n, int m)
{  
	double average = 0.0;
	average = (double)(m + n) / 2;
	return average;
}
	
void distance()
{ 
	double answer = 0.0;
	int x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;
		
	cout << "Input coordinates of 2 points." << endl << "Coordinates first point. Input X1: ";
	cin >> x1;
	cout << "Input Y1: ";
	cin >> y1;
	cout << "Coordinates second point. Input X2: ";
	cin >> x2;
	cout << "Input Y2: ";
	cin >> y2;
	
	answer = (double)sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	cout << answer;
}
	
	

