#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <conio.h>
#include <stdio.h>
using namespace std;

int x = 10;
int y = 10;
int tailx[100] = {-1};
int taily[100] = {-1};
int Fx;
int Fy;
char doing = 'q';
long score;
int boof = 0;

void tail(){
	
}

void Draw(){
	system("cls");
	for (int i = 0; i < 20; i++){      //y
		for (int j = 0; j < 20; j++){  //x
			if (j == 0 || j == 19 || i == 0 || i == 19) cout << "#";
			
			else if ((x == j) && (y == i)) cout << "0";
			
			else if((Fx == j) && (Fy == i)) cout << "F";
			
			else {
				bool right = true;
				for (int q = 0; q < boof; q++){
					if ((tailx[q] == j) && (taily[q] == i)){
						cout << "o";
						right = false;
					}
				}
				if (right == true) cout << " ";
			}
		}
		cout << endl;
	}
	cout << endl << endl << "Score: " << score << endl;
}

void Logic(){
	if (kbhit()){
		switch (getch()){
			case 'a':
				if (doing != 'd') doing = 'a';
				break;
			case 'w':
				if (doing != 's') doing = 'w';
				break;
			case 'd':
				if (doing != 'a') doing = 'd';
				break;
			case 's':
				if (doing != 'w') doing = 's';
				break;
		}
	}
	
	if ((x == Fx) && (y == Fy)){
		score += 10;
		boof = (score+10) / 10;
		Fx = rand()%18 + 1;
		Fy = rand()%18 + 1;
	}
	
	if (x == 19) x = 1;
	
	if (y == 19) y = 1;
	
	if (x == 0) x = 19;
	
	if (y == 0) y = 19;
	
	int lastx = tailx[0];
	int lasty = taily[0];
	int glastx, glasty;
	tailx[0] = x;
	taily[0] = y;
	for (int i = 0; i < boof+1; i++){
		glastx = tailx[i];
		glasty = taily[i];
		tailx[i] = lastx;
		taily[i] = lasty;
		lastx = glastx;
		lasty = glasty;
	}
	
	switch (doing){
		case 'a':
			x--;
			break;
		case 'w':
			y--;
			break;
		case 'd':
			x++;
			break;
		case 's':
			y++;
			break;
	}
	
	for (int i = 0; i < boof; i++){
		if ((tailx[i] == x) && (taily[i] == y)){
			cout << endl << "Вы проиграли, попробуйте ещё раз" << endl;
			getch();
			exit(0);
		}
	}
}

int main(){
	setlocale(LC_ALL, "rus");
	srand(time(0));
	cout << "Здравствуйте, вас приветствует игра \"Змейка\"" << endl << endl << endl;
	cout << "Когда вы будете готовы играть, нажмите любую кнопку на клавиатуре" << endl << endl;
	cout << "Напомню, что раскладка клавиатуры должна быть английской, в противном случае,   игра не запустится" << endl << endl;
	getch();
	system("cls");
	Fx = rand()%18 + 1;
	Fy = rand()%18 + 1;
	
	while(true){
		Logic();
		Draw();
	}
return 0;
}
