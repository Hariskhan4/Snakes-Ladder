#include <iostream>
#include<cstdlib>
#include<ctime>
#include <iomanip>
using namespace std;
int diceroll(int dice)
{
	srand(time(0));
	dice = (rand() % 6) + 1;
	return dice;
}
int main()
{
	int dice = 0;
	int dicenum = 0;
	int board[10][10] = {};
	int redpos = 1;
	int bluepos = 1;
	int counter = 0;
	int first = 9;
	int second = 8;
	int x = 0;
	bool turn = false;


	while (redpos < 100 && bluepos < 100)
	{
		first = 9;
		second = 8;
		counter = 0;

		for (int i = 0; i < 5; i++)
		{

			for (int j = 9; j >= 0; j--)
			{
				board[first][j] = (100 - x) - counter;
				if (redpos == board[first][j])
					cout << "\033[31mR\033[0m";
				if (bluepos == board[first][j])
					cout << "\033[34mB\033[0m";

				cout << setw(2);

				//Ladder
				if (board[first][j] == 99)
					cout << "\033[31mH\033[0m" << "       ";

				else if (board[first][j] == 80)
					cout << "\033[31mH\033[0m" << "       ";

				else if (board[first][j] == 92)
					cout << "\033[34mH\033[0m" << "       ";

				else if (board[first][j] == 71)
					cout << "\033[34mH\033[0m" << "       ";

				else if (board[first][j] == 76)
					cout << "\033[32mH\033[0m" << "       ";

				//Snake
				else if (board[first][j] == 98)
					cout << "\033[33m\\\033[0m" << "       ";

				else if (board[first][j] == 38)
					cout << "\033[31m/\033[0m" << "       ";

				else if (board[first][j] == 16)
					cout << "\033[35mH\033[0m" << "       ";

				else
					cout << board[first][j] << "      ";
				x++;
			}
			cout << endl << endl << endl;
			x = 0;

			first -= 2;

			for (int k = 0; k <= 9; k++)
			{
				board[second][k] = (81 + x) - counter;
				if (redpos == board[second][k])
					cout << "\033[31mR\033[0m";
				if (bluepos == board[second][k])
					cout << "\033[34mB\033[0m";
				
				cout << setw(2);
				//Ladder
				if (board[second][k] == 28)
					cout << "\033[32mH\033[0m" << "       ";

				else if (board[second][k] == 21)
					cout << "\033[33mH\033[0m" << "       ";

				else if (board[second][k] == 42)
					cout << "\033[33mH\033[0m" << "       ";

				else if (board[second][k] == 4)
					cout << "\033[35mH\033[0m" << "       ";
				//Snake
				else if (board[second][k] == 7)
					 cout << "\033[33m\\\033[0m" << "       ";

				else if (board[second][k] == 48)
					cout << "\033[34m/\033[0m" << "       ";

				else if (board[second][k] == 26)
					cout << "\033[34m/\033[0m" << "       ";

				else if (board[second][k] == 64)
					cout << "\033[31m/\033[0m" << "       ";

				else
					cout << board[second][k] << "      ";
				x++;
			}
			cout << endl << endl << endl;
			x = 0;
			second -= 2;
			counter += 20;

		}
		cout << "                                                                                                           " <<  "\033[31m Red Position : \033[0m" << redpos << endl << endl;
		cout << "                                                                                                           " <<  "\033[34m Blue Position : \033[0m"  << bluepos << endl << endl;




		cout << " Red's Turn " << endl;
		turn = false;
		cout << " Press any key to roll the dice " << endl;
		system("pause>null");
		dicenum = diceroll(dice);
		cout << " Red rolled a dice of " << dicenum << endl << endl;



		if (turn == false)
		{
			redpos += dicenum;
			if (redpos == 28)
				redpos = 76;
			if (redpos == 71)
				redpos = 92;
			if (redpos == 80)
				redpos = 99;
			if (redpos == 21)
				redpos = 42;
			if (redpos == 98)
				redpos = 7;
			if (redpos == 64)
				redpos = 38;
			if (redpos == 48)
				redpos = 26;
			if (redpos == 4)
				redpos = 16;

			if (redpos >= 100)
				redpos = 100;
			/*cout << " Red Position: " << redpos << endl << endl;*/
			if (redpos >= 100)
			{
				system("pause>null");
				system("cls");
				cout << "\033[31m Red Wins! \033[0m";
				break;

			}

		}

		cout << " Blue's Turn " << endl;;
		turn = true;
		cout << " Press any key to roll the dice " << endl;
		system("pause>null");
		dicenum = diceroll(dice);

		cout << " Blue rolled a dice of " << dicenum << endl << endl;
		if (turn == true)
		{
			bluepos += dicenum;
			if (bluepos == 28)
				bluepos = 76;
			if (bluepos == 71)
				bluepos = 92;
			if (bluepos == 80)
				bluepos = 99;
			if (bluepos == 21)
				bluepos = 42;
			if (bluepos == 98)
				bluepos = 7;
			if (bluepos == 64)
				bluepos = 38;
			if (bluepos == 48)
				bluepos = 26;
			if (bluepos == 4)
				bluepos = 16;


			if (bluepos >= 100)
				bluepos = 100;

			
			if (bluepos >= 100)
			{
				system("pause>null");
				system("cls");
				cout <<  "\033[34m Blue Wins! \033[0m";
				break;

			}
		}
		cout << " Press any key for the next turn ";
		system("pause>null");
		system("cls");






	}





	return 0;
}




