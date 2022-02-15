#include <iostream>

using namespace std;

//const int A = 1;
//const int B = 2;

int main(){
	int whiteHorseX = 0;
	int blackHorseX = 0;
	int whiteHorseY = 0;
	int blackHorseY = 0;
	
	cout << "Input X  horizontal coordinate white horse" << endl;
	cin >> whiteHorseX;
	cout << "Input Y  vertical coordinate white horse" << endl;
	cin >> whiteHorseY;
	cout << "Input X  horizontal coordinate black horse" << endl;
	cin >> blackHorseX;
	cout << "Input Y  vertical coordinate black horse" << endl;
	cin >> blackHorseY;
	
	if (whiteHorseX == blackHorseX and whiteHorseY == blackHorseY){
		cout << "It's impossible, wrong coordinates. Chess piece cannot stand in one place.";
		return 1;
	} 
	
	if (!((whiteHorseX > 0 and whiteHorseX <= 8) and(blackHorseX > 0 and blackHorseX <= 8) and (whiteHorseY > 0 and whiteHorseY <= 8) and (blackHorseY > 0 and blackHorseY <= 8))){
		cout << "Wrong coordinates. Your chess piece is off the chessboard";
		return 2;
	} 
	
	if (whiteHorseX + 1 == blackHorseX and whiteHorseY + 2 == blackHorseY){
		cout << " Chess pieces hit each other";
		if (whiteHorseX - 1 == blackHorseX and whiteHorseY + 2 == blackHorseY){
			cout << " Chess pieces hit each other";	
			if (whiteHorseX + 2 == blackHorseX and whiteHorseY + 1 == blackHorseY){
				cout << " Chess pieces hit each other";
				if (whiteHorseX - 2 == blackHorseX and whiteHorseY +1 == blackHorseY){
					cout << " Chess pieces hit each other";
					if (whiteHorseX + 1 == blackHorseX and whiteHorseY - 2 == blackHorseY){
						cout << " Chess pieces hit each other";
						if (whiteHorseX - 1 == blackHorseX and whiteHorseY - 2 == blackHorseY){
							cout << " Chess pieces hit each other";
							if (whiteHorseX + 2 == blackHorseX and whiteHorseY - 1 == blackHorseY){
								cout << " Chess pieces hit each other";
								if (whiteHorseX - 2 == blackHorseX and whiteHorseY - 1 == blackHorseY){
									cout << " Chess pieces hit each other";
								}
							}
						}
					}
				}
			}
		}
	}
	else {
		cout << "Chess pieces don't hit each other"; 
	}
	return 0;	
}
	





