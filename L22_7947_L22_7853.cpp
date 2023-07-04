#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <windows.h>
#include <time.h>

using namespace std;

void welcome_screen();
void main_menu(char arr[9][9]);
void game_slot();
void game_slot2();
void game_mid(char arr[9][9], int valid);
void game_grid(char arr[9][9], int game);
void game_difficulty();
void game_mechanics(char arr[9][9], int game);
void setCord(int x, int y);
bool checksquare(char skudo[9][9], int row, int columun, char num);

char arr[9][9];
int main()
{
	char sudoku[9][9] = {};
	system("color 71");
	welcome_screen();
	main_menu(sudoku);

	system("pause");
	return 0;
}

void setCord(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void welcome_screen()
{
	system("cls");
	cout << "\t\t|*********************************************|" << endl;
	cout << "\t\t|          ____________________               |" << endl;
	cout << "\t\t|          |WELCOME TO SUDOKU!|               |" << endl;
	cout << "\t\t|          --------------------               |" << endl;
	cout << "\t\t|                                             |" << endl;
	cout << "\t\t| (1) Load Game                               |" << endl;
	cout << "\t\t|                                             |" << endl;
	cout << "\t\t| (2) New Game                                |" << endl;
	cout << "\t\t|                                             |" << endl;
	cout << "\t\t|*********************************************|" << endl << endl << endl;

	main_menu(arr);
}

void main_menu(char arr[9][9])
{
	char input;
	setCord(0, 13);
	cout << "Welcome to Sudoku! Enter [1] or [2] to proceed: ";
	cin >> input;
	bool status = true;
	while (status == true)
	{
		if ((input != '1' && input != '2'))
		{
			welcome_screen();
			setCord(0, 12);
			cout << "Invalid Input! Please Enter [1] or [2] to proceed: ";
			cin >> input;
			cout << "Enter Option again to confirm: ";
		}
		status = false;
	}
	cout << endl << "Choice [" << input << "] was chosen!. ";
	Sleep(1600);
	int valid = 0;
	if (input == '1')
	{
		valid = 1;
		game_slot();
		game_mid(arr, valid);

	}
	else if (input == '2')
	{
		valid = 2;
		game_slot2();
		game_mid(arr, valid);
	}
}
void game_slot()
{
	system("cls");
	cout << "\t    *CREATING NEW GAME MAY OVVERIDE PREVIOUS SAVED GAME!*   " << endl;
	cout << "\t\t             *PROCEED WITH CAUTION                  " << endl;
	cout << "\t\t|*********************************************|" << endl;
	cout << "\t\t|          ____________________               |" << endl;
	cout << "\t\t|          | Suduko Game Slots |              |" << endl;
	cout << "\t\t|          --------------------               |" << endl;
	cout << "\t\t|                                             |" << endl;
	cout << "\t\t| (*) Game [1]            (*) Game [3]        |" << endl;
	cout << "\t\t|                                             |" << endl;
	cout << "\t\t| (*) Game [2]            (*) Main Menu [m]   |" << endl;
	cout << "\t\t|                                             |" << endl;
	cout << "\t\t|*********************************************|" << endl << endl;

}
void game_slot2()
{
	system("cls");
	cout << "\t    *CREATING NEW GAME MAY OVVERIDE PREVIOUS SAVED GAME!*   " << endl;
	cout << "\t\t             *PROCEED WITH CAUTION                  " << endl;
	cout << "\t\t|*********************************************|" << endl;
	cout << "\t\t|          ____________________               |" << endl;
	cout << "\t\t|          | Suduko Game Slots |              |" << endl;
	cout << "\t\t|          --------------------               |" << endl;
	cout << "\t\t|                                             |" << endl;
	cout << "\t\t| (*) Game [1]            (*) Game [3]        |" << endl;
	cout << "\t\t|                                             |" << endl;
	cout << "\t\t| (*) Game [2]                                |" << endl;
	cout << "\t\t|                                             |" << endl;
	cout << "\t\t|*********************************************|" << endl << endl;

}

void game_mid(char arr[9][9], int valid)
{
	ifstream inData, game_1, game_2, game_3;
	ofstream outData, game_ONE, game_TWO, game_THREE;
	char option; int game;
	if (valid == 1)
	{
		setCord(0, 14);
		cout << "Enter Game Slot/ Option to Load Game: ";
		cin >> option;
		cout << "Confirm Option/ Slot: ";
		bool status = true;
		while (status == true)
		{
			if (option != '1' && option != '2' && option != '3' && option != 'm' && option != 'M' || !(cin >> option))
			{
				cin.clear();
				cin.ignore(123, '\n');
				game_slot();
				setCord(0, 13);
				cout << "ERROR: Enter valid option";
				game_mid(arr, valid);
				continue;
			}
			status = false;
		}
		if (option == 'm' || option == 'M')
		{
			setCord(0, 16); cout << "::[Main Menu]::";
			Sleep(1600);
			welcome_screen();
			main_menu(arr);
		}
		else if (option == '1')
		{
			game = 1;

			inData.open("game_1.txt");
			inData.seekg(0, ios::end);
			int length = inData.tellg();
			inData.close();

			if (length > 0)
			{
				inData.open("game_1.txt");
				if (inData.is_open())
				{
					while (!inData.eof())
					{
						for (int i = 0; i < 9; i++)
						{
							char num;
							for (int j = 0; j < 9 && inData >> num; j++)
							{
								arr[i][j] = num;
							}
						}

					}
				}
				inData.close();
				game_grid(arr, game);
			}
			else
			{
				game_slot();
				setCord(0, 13);
				cout << "GAME NOT FOUND! Return to Main Menu or Choose Saved Slot!";
				game_mid(arr, valid);
			}

		}
		else if (option == '2')
		{
			game = 2;

			inData.open("game_2.txt");
			inData.seekg(0, ios::end);
			int length = inData.tellg();
			inData.close();

			if (length > 0)
			{
				inData.open("game_2.txt");
				if (inData.is_open())
				{
					while (!inData.eof())
					{
						for (int i = 0; i < 9; i++)
						{
							char num;
							for (int j = 0; j < 9 && inData >> num; j++)
							{
								arr[i][j] = num;
							}
						}

					}
				}
				inData.close();
				game_grid(arr, game);
			}
			else
			{
				game_slot2();
				setCord(0, 13);
				cout << "GAME NOT FOUND! Return to Main Menu or Choose Saved Slot!";
				game_mid(arr, valid);
			}
		}
		else if (option == '3')
		{
			game = 3;

			inData.open("game_3.txt");
			inData.seekg(0, ios::end);
			int length = inData.tellg();
			inData.close();

			if (length > 0)
			{
				inData.open("game_3.txt");
				if (inData.is_open())
				{
					while (!inData.eof())
					{
						for (int i = 0; i < 9; i++)
						{
							char num;
							for (int j = 0; j < 9 && inData >> num; j++)
							{
								arr[i][j] = num;
							}
						}
					}
				}
				inData.close();
				game_grid(arr, game);
			}
			else
			{
				game_slot();
				setCord(0, 13);
				cout << "GAME NOT FOUND! Return to Main Menu or Choose Saved Slot!";
				game_mid(arr, valid);
			}
		}
	}
	else if (valid == 2)
	{
		char difficulty; int option_2;
		setCord(0, 14);
		cout << "Enter Game Slot/ Option to SAVE Game: ";
		cin >> option_2;
		cout << "Confirm SLOT/OPTION: ";
		bool status = true;
		while (status == true)
		{
			if (option_2 != 1 && option_2 != 2 && option_2 != 3 && option_2 != 'm' && option_2 != 'M' || !(cin >> option_2))
			{
				cin.clear();
				cin.ignore(123, '\n');
				game_slot2();
				setCord(0, 13);
				cout << "ERROR: Enter valid option";
				game_mid(arr, valid);
				continue;
			}
			status = false;
		}
		if (option_2 == 1)
		{
			game = 1;
			cout << "SAVING GAME 1!" << endl;
			Sleep(1700);
			game_difficulty();
			setCord(0, 14);
			cout << "Choose Difficulty Level [E -- Easy || M -- Medium || H -- Hard]: ";
			cin >> difficulty;
			cout << "Confirm [Level]: ";
			bool status_2 = true;
			while (status_2 == true)
			{
				if (difficulty != 'E' && difficulty != 'e' && difficulty != 'm' && difficulty != 'M' && difficulty != 'H' && difficulty != 'h' || !(cin >> difficulty))
				{
					cin.clear();
					cin.ignore(123, '\n');
					game_slot2();
					setCord(0, 13);
					cout << "ERROR: Enter valid option";
					game_mid(arr, valid);
				}
				status_2 = false;
			}

			if (difficulty == 'E' || difficulty == 'e') {
				setCord(0, 16);
				cout << "[EASY] TEMPLATE LOADING..." << endl;
				Sleep(1600);
				cout << "SETTING UP GRID..." << endl;
				Sleep(1650);
				cout << "RESHUFFLING NUMBERS..." << endl;
				Sleep(2000);
				cout << "GOOD LUCK!" << endl;
				Sleep(1700);

				char arr_temp[9][9];


				inData.open("template_e1.txt");
				game_ONE.open("game_1.txt"); string line; int count = 0;
				while (getline(inData, line))
				{
					++count;
					game_ONE << line;
					if (count != 9)
					{
						game_ONE << endl;
						continue;
					}
					break;
				}
				inData.close();
				game_ONE.close();

				inData.open("game_1.txt");
				if (inData.is_open())
				{
					while (!inData.eof())
					{
						for (int i = 0; i < 9; i++)
						{
							char num;
							for (int j = 0; j < 9 && inData >> num; j++)
							{
								arr_temp[i][j] = num;
							}
						}
					}
				}
				inData.close();


				srand(time(0));
				int random = rand() % 9 + 1;
				for (int k = 0; k < random; k++)
				{
					for (int i = 0; i < 9; i++)
					{
						char temp = arr_temp[i][0];
						for (int j = 0; j < 8; j++)
						{
							arr_temp[i][j] = arr_temp[i][j + 1];
						}
						arr_temp[i][8] = temp;
					}
				}

				int x = 6, y = 0;
				char temp;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						temp = arr_temp[i][j];
						arr_temp[i][j] = arr_temp[x][y];
						arr_temp[x][y] = temp;
						y++;
					}
					y = 0;
					x++;
				}

				int space1 = 0; int lines_1 = 0;
				outData.open("game_1_temp.txt");
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						++space1;
						outData << arr_temp[i][j];
						if (space1 != 9)
						{
							outData << " ";
						}
					}
					++lines_1;
					outData << endl;
					if (lines_1 == 9)
					{
						break;
					}
				}
				outData.close();

				int space2 = 0; int lines_2 = 0;
				outData.open("game_1.txt");
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						++space2;
						outData << arr_temp[i][j];
						if (space2 != 9)
						{
							outData << " ";
						}
					}
					++lines_2;
					outData << endl;
					if (lines_2 == 9)
					{
						break;
					}
				}
				outData.close();

				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						arr[i][j] = arr_temp[i][j];
					}
				}
				game_grid(arr, game);
			}
			else if (difficulty == 'm' || difficulty == 'M') {
				setCord(0, 16);
				cout << "[MEDIUM] TEMPLATE LOADING..." << endl;
				Sleep(1600);
				cout << "SETTING UP GRID..." << endl;
				Sleep(1650);
				cout << "RESHUFFLING NUMBERS..." << endl;
				Sleep(2000);
				cout << "GOOD LUCK!" << endl;
				Sleep(1700);

				char arr_temp[9][9];

				inData.open("template_m1.txt");
				game_ONE.open("game_1.txt"); string line;
				while (getline(inData, line))
				{
					game_ONE << line << "\n";
				}
				inData.close();
				game_ONE.close();


				inData.open("game_1.txt");
				if (inData.is_open())
				{
					while (!inData.eof())
					{
						for (int i = 0; i < 9; i++)
						{
							char num;
							for (int j = 0; j < 9 && inData >> num; j++)
							{
								arr_temp[i][j] = num;
							}
						}
					}
				}
				inData.close();

				srand(time(0));
				int random = rand() % 9 + 1;
				for (int k = 0; k < random; k++)
				{
					for (int i = 0; i < 9; i++)
					{
						char temp = arr_temp[i][0];
						for (int j = 0; j < 8; j++)
						{
							arr_temp[i][j] = arr_temp[i][j + 1];
						}
						arr_temp[i][8] = temp;
					}
				}

				int x = 6, y = 0;
				char temp;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						temp = arr_temp[i][j];
						arr_temp[i][j] = arr_temp[x][y];
						arr_temp[x][y] = temp;
						y++;
					}
					y = 0;
					x++;
				}

				int space3 = 0; int lines_3 = 0;
				outData.open("game_1_temp.txt");
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						++space3;
						outData << arr_temp[i][j];
						if (space3 != 9)
						{
							outData << " ";
						}
					}
					++lines_3;
					outData << endl;
					if (lines_3 == 9)
					{
						break;
					}
				}
				outData.close();

				int space4 = 0; int lines_4 = 0;
				outData.open("game_1.txt");
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						++space4;
						outData << arr_temp[i][j];
						if (space4 != 9)
						{
							outData << " ";
						}
					}
					++lines_4;
					outData << endl;
					if (lines_4 == 9)
					{
						break;
					}
				}
				outData.close();

				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						arr[i][j] = arr_temp[i][j];
					}
				}
				game_grid(arr, game);
			}
			else if (difficulty == 'H' || difficulty == 'h')
			{
				setCord(0, 16);
				cout << "[HARD] TEMPLATE LOADING..." << endl;
				Sleep(1600);
				cout << "SETTING UP GRID..." << endl;
				Sleep(1650);
				cout << "RESHUFFLING NUMBERS..." << endl;
				Sleep(2000);
				cout << "GOOD LUCK!" << endl;
				Sleep(1700);

				char arr_temp[9][9];

				inData.open("template_h1.txt");
				game_TWO.open("game_1.txt"); string line;
				while (getline(inData, line))
				{
					game_TWO << line << "\n";
				}
				inData.close();
				game_TWO.close();

				inData.open("game_1.txt");
				if (inData.is_open())
				{
					while (!inData.eof())
					{
						for (int i = 0; i < 9; i++)
						{
							char num;
							for (int j = 0; j < 9 && inData >> num; j++)
							{
								arr_temp[i][j] = num;
							}
						}
					}
				}
				inData.close();

				srand(time(0));
				int random = rand() % 9 + 1;
				for (int k = 0; k < random; k++)
				{
					for (int i = 0; i < 9; i++)
					{
						char temp = arr_temp[i][0];
						for (int j = 0; j < 8; j++)
						{
							arr_temp[i][j] = arr_temp[i][j + 1];
						}
						arr_temp[i][8] = temp;
					}
				}

				int x = 6, y = 0;
				char temp;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						temp = arr_temp[i][j];
						arr_temp[i][j] = arr_temp[x][y];
						arr_temp[x][y] = temp;
						y++;
					}
					y = 0;
					x++;
				}

				int space5 = 0; int lines_5 = 0;
				outData.open("game_1_temp.txt");
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						++space5;
						outData << arr_temp[i][j];
						if (space5 != 9)
						{
							outData << " ";
						}
					}
					++lines_5;
					outData << endl;
					if (lines_5 == 9)
					{
						break;
					}
				}
				outData.close();

				int space12 = 0; int lines_12 = 0;
				outData.open("game_1.txt");
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						++space12;
						outData << arr_temp[i][j];
						if (space12 != 9)
						{
							outData << " ";
						}
					}
					++lines_12;
					outData << endl;
					if (lines_12 == 9)
					{
						break;
					}
				}
				outData.close();

				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						arr[i][j] = arr_temp[i][j];
					}
				}
				game_grid(arr, game);
			}

		}
		else if (option_2 == 2)
		{
			game = 2;
			cout << "SAVING GAME 2!" << endl;
			Sleep(1700);
			game_difficulty();
			setCord(0, 14);
			cout << "Choose Difficulty [E -- Easy || M -- Medium || H -- Hard]: ";
			cin >> difficulty;
			bool status_2 = true;
			while (status_2 == true)
			{
				if (difficulty != 'E' && difficulty != 'e' && difficulty != 'm' && difficulty != 'M' && difficulty != 'H' && difficulty != 'h' || !(cin >> difficulty))
				{
					cin.clear();
					cin.ignore(123, '\n');
					game_slot();
					setCord(0, 13);
					cout << "ERROR: Enter valid option";
					game_mid(arr, valid);
					continue;
				}
				status_2 = false;
			}

			if (difficulty == 'E' || difficulty == 'e')
			{
				setCord(0, 16);
				cout << "[EASY] TEMPLATE LOADING..." << endl;
				Sleep(1600);
				cout << "SETTING UP GRID..." << endl;
				Sleep(1650);
				cout << "RESHUFFLING NUMBERS..." << endl;
				Sleep(2000);
				cout << "GOOD LUCK!" << endl;
				Sleep(1700);

				char arr_temp[9][9];

				inData.open("template_e1.txt");
				game_TWO.open("game_2.txt"); string line;
				while (getline(inData, line))
				{
					game_TWO << line << "\n";
				}
				inData.close();
				game_TWO.close();

				inData.open("game_2.txt");
				if (inData.is_open())
				{
					while (!inData.eof())
					{
						for (int i = 0; i < 9; i++)
						{
							char num;
							for (int j = 0; j < 9 && inData >> num; j++)
							{
								arr_temp[i][j] = num;
							}
						}
					}
				}
				inData.close();

				srand(time(0));
				int random = rand() % 9 + 1;
				for (int k = 0; k < random; k++)
				{
					for (int i = 0; i < 9; i++)
					{
						char temp = arr_temp[i][0];
						for (int j = 0; j < 8; j++)
						{
							arr_temp[i][j] = arr_temp[i][j + 1];
						}
						arr_temp[i][8] = temp;
					}
				}

				int x = 6, y = 0;
				char temp;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						temp = arr_temp[i][j];
						arr_temp[i][j] = arr_temp[x][y];
						arr_temp[x][y] = temp;
						y++;
					}
					y = 0;
					x++;
				}

				int space7 = 0; int lines_7 = 0;
				outData.open("game_2_temp.txt");
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						++space7;
						outData << arr_temp[i][j];
						if (space7 != 9)
						{
							outData << " ";
						}
					}
					++lines_7;
					outData << endl;
					if (lines_7 == 9)
					{
						break;
					}
				}
				outData.close();

				int space8 = 0; int lines_8 = 0;
				outData.open("game_2.txt");
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						++space8;
						outData << arr_temp[i][j];
						if (space8 != 9)
						{
							outData << " ";
						}
					}
					++lines_8;
					outData << endl;
					if (lines_8 == 9)
					{
						break;
					}
				}
				outData.close();

				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						arr[i][j] = arr_temp[i][j];
					}
				}
				game_grid(arr, game);
			}
			else if (difficulty == 'm' || difficulty == 'M') {
				setCord(0, 16);
				cout << "[MEDIUM] TEMPLATE LOADING..." << endl;
				Sleep(1600);
				cout << "SETTING UP GRID..." << endl;
				Sleep(1650);
				cout << "RESHUFFLING NUMBERS..." << endl;
				Sleep(2000);
				cout << "GOOD LUCK!" << endl;
				Sleep(1700);

				char arr_temp[9][9];

				inData.open("template_m1.txt");
				game_TWO.open("game_2.txt"); string line;
				while (getline(inData, line))
				{
					game_TWO << line << "\n";
				}
				inData.close();
				game_TWO.close();

				inData.open("game_2.txt");
				if (inData.is_open())
				{
					while (!inData.eof())
					{
						for (int i = 0; i < 9; i++)
						{
							char num;
							for (int j = 0; j < 9 && inData >> num; j++)
							{
								arr_temp[i][j] = num;
							}
						}
					}
				}
				inData.close();

				srand(time(0));
				int random = rand() % 9 + 1;
				for (int k = 0; k < random; k++)
				{
					for (int i = 0; i < 9; i++)
					{
						char temp = arr_temp[i][0];
						for (int j = 0; j < 8; j++)
						{
							arr_temp[i][j] = arr_temp[i][j + 1];
						}
						arr_temp[i][8] = temp;
					}
				}

				int x = 6, y = 0;
				char temp;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						temp = arr_temp[i][j];
						arr_temp[i][j] = arr_temp[x][y];
						arr_temp[x][y] = temp;
						y++;
					}
					y = 0;
					x++;
				}

				int space9 = 0; int lines_9 = 0;
				outData.open("game_2_temp.txt");
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						++space9;
						outData << arr_temp[i][j];
						if (space9 != 9)
						{
							outData << " ";
						}
					}
					++lines_9;
					outData << endl;
					if (lines_9 == 9)
					{
						break;
					}
				}
				outData.close();

				int space10 = 0; int lines_10 = 0;
				outData.open("game_2.txt");
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						++space10;
						outData << arr_temp[i][j];
						if (space10 != 9)
						{
							outData << " ";
						}
					}
					++lines_10;
					outData << endl;
					if (lines_10 == 9)
					{
						break;
					}
				}
				outData.close();

				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						arr[i][j] = arr_temp[i][j];
					}
				}
				game_grid(arr, game);
			}
			else if (difficulty == 'H' || difficulty == 'h') {
				setCord(0, 16);
				cout << "[HARD] TEMPLATE LOADING..." << endl;
				Sleep(1600);
				cout << "SETTING UP GRID..." << endl;
				Sleep(1650);
				cout << "RESHUFFLING NUMBERS..." << endl;
				Sleep(2000);
				cout << "GOOD LUCK!" << endl;
				Sleep(1700);

				char arr_temp[9][9];

				inData.open("template_h1.txt");
				game_TWO.open("game_2.txt"); string line;
				while (getline(inData, line))
				{
					game_TWO << line << "\n";
				}
				inData.close();
				game_TWO.close();

				inData.open("game_2.txt");
				if (inData.is_open())
				{
					while (!inData.eof())
					{
						for (int i = 0; i < 9; i++)
						{
							char num;
							for (int j = 0; j < 9 && inData >> num; j++)
							{
								arr_temp[i][j] = num;
							}
						}
					}
				}
				inData.close();

				srand(time(0));
				int random = rand() % 9 + 1;
				for (int k = 0; k < random; k++)
				{
					for (int i = 0; i < 9; i++)
					{
						char temp = arr_temp[i][0];
						for (int j = 0; j < 8; j++)
						{
							arr_temp[i][j] = arr_temp[i][j + 1];
						}
						arr_temp[i][8] = temp;
					}
				}

				int x = 6, y = 0;
				char temp;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						temp = arr_temp[i][j];
						arr_temp[i][j] = arr_temp[x][y];
						arr_temp[x][y] = temp;
						y++;
					}
					y = 0;
					x++;
				}

				int space11 = 0; int lines_11 = 0;
				outData.open("game_2_temp.txt");
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						++space11;
						outData << arr_temp[i][j];
						if (space11 != 9)
						{
							outData << " ";
						}
					}
					++lines_11;
					outData << endl;
					if (lines_11 == 9)
					{
						break;
					}
				}
				outData.close();

				int space12 = 0; int lines_12 = 0;
				outData.open("game_2.txt");
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						++space12;
						outData << arr_temp[i][j];
						if (space12 != 9)
						{
							outData << " ";
						}
					}
					++lines_12;
					outData << endl;
					if (lines_12 == 9)
					{
						break;
					}
				}
				outData.close();

				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						arr[i][j] = arr_temp[i][j];
					}
				}
				game_grid(arr, game);
			}
		}
		else if (option_2 == 3)
		{
			game = 3;
			cout << "SAVING GAME 3!" << endl;
			Sleep(1700);
			game_difficulty();
			setCord(0, 14);
			cout << "Choose Difficulty [E -- Easy || M -- Medium || H -- Hard]: ";
			cin >> difficulty;
			bool status_2 = true;
			while (status_2 == true)
			{
				if (difficulty != 'E' && difficulty != 'e' && difficulty != 'm' && difficulty != 'M' && difficulty != 'H' && difficulty != 'h' || !(cin >> difficulty))
				{
					cin.clear();
					cin.ignore(123, '\n');
					game_slot();
					setCord(0, 13);
					cout << "ERROR: Enter valid option";
					game_mid(arr, valid);
					continue;
				}
				status_2 = false;
			}

			if (difficulty == 'E' || difficulty == 'e') {
				setCord(0, 16);
				cout << "[EASY] TEMPLATE LOADING..." << endl;
				Sleep(1600);
				cout << "SETTING UP GRID..." << endl;
				Sleep(1650);
				cout << "RESHUFFLING NUMBERS..." << endl;
				Sleep(2000);
				cout << "GOOD LUCK!" << endl;
				Sleep(1700);

				char arr_temp[9][9];

				inData.open("template_e1.txt");
				game_THREE.open("game_3.txt"); string line;
				while (getline(inData, line))
				{
					game_THREE << line << "\n";
				}
				inData.close();
				game_THREE.close();

				inData.open("game_3.txt");
				if (inData.is_open())
				{
					while (!inData.eof())
					{
						for (int i = 0; i < 9; i++)
						{
							char num;
							for (int j = 0; j < 9 && inData >> num; j++)
							{
								arr_temp[i][j] = num;
							}
						}
					}
				}
				inData.close();

				srand(time(0));
				int random = rand() % 9 + 1;
				for (int k = 0; k < random; k++)
				{
					for (int i = 0; i < 9; i++)
					{
						char temp = arr_temp[i][0];
						for (int j = 0; j < 8; j++)
						{
							arr_temp[i][j] = arr_temp[i][j + 1];
						}
						arr_temp[i][8] = temp;
					}
				}

				int x = 6, y = 0;
				char temp;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						temp = arr_temp[i][j];
						arr_temp[i][j] = arr_temp[x][y];
						arr_temp[x][y] = temp;
						y++;
					}
					y = 0;
					x++;
				}

				int space13 = 0; int lines_13 = 0;
				outData.open("game_3_temp.txt");
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						++space13;
						outData << arr_temp[i][j];
						if (space13 != 9)
						{
							outData << " ";
						}
					}
					++lines_13;
					outData << endl;
					if (lines_13 == 9)
					{
						break;
					}
				}
				outData.close();

				int space14 = 0; int lines_14 = 0;
				outData.open("game_3.txt");
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						++space14;
						outData << arr_temp[i][j];
						if (space14 != 9)
						{
							outData << " ";
						}
					}
					++lines_14;
					outData << endl;
					if (lines_14 == 9)
					{
						break;
					}
				}
				outData.close();

				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						arr[i][j] = arr_temp[i][j];
					}
				}
				game_grid(arr, game);
			}
			else if (difficulty == 'm' || difficulty == 'M') {
				setCord(0, 16);
				cout << "[MEDIUM] TEMPLATE LOADING..." << endl;
				Sleep(1600);
				cout << "SETTING UP GRID..." << endl;
				Sleep(1650);
				cout << "RESHUFFLING NUMBERS..." << endl;
				Sleep(2000);
				cout << "GOOD LUCK!" << endl;
				Sleep(1700);

				char arr_temp[9][9];

				inData.open("template_m1.txt");
				game_THREE.open("game_3.txt"); string line;
				while (getline(inData, line))
				{
					game_THREE << line << "\n";
				}
				inData.close();
				game_THREE.close();

				inData.open("game_3.txt");
				if (inData.is_open())
				{
					while (!inData.eof())
					{
						for (int i = 0; i < 9; i++)
						{
							char num;
							for (int j = 0; j < 9 && inData >> num; j++)
							{
								arr_temp[i][j] = num;
							}
						}
					}
				}
				inData.close();

				srand(time(0));
				int random = rand() % 9 + 1;
				for (int k = 0; k < random; k++)
				{
					for (int i = 0; i < 9; i++)
					{
						char temp = arr_temp[i][0];
						for (int j = 0; j < 8; j++)
						{
							arr_temp[i][j] = arr_temp[i][j + 1];
						}
						arr_temp[i][8] = temp;
					}
				}

				int x = 6, y = 0;
				char temp;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						temp = arr_temp[i][j];
						arr_temp[i][j] = arr_temp[x][y];
						arr_temp[x][y] = temp;
						y++;
					}
					y = 0;
					x++;
				}

				int space15 = 0; int lines_15 = 0;
				outData.open("game_3_temp.txt");
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						++space15;
						outData << arr_temp[i][j];
						if (space15 != 9)
						{
							outData << " ";
						}
					}
					++lines_15;
					outData << endl;
					if (lines_15 == 9)
					{
						break;
					}
				}
				outData.close();

				int space16 = 0; int lines_16 = 0;
				outData.open("game_3.txt");
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						++space16;
						outData << arr_temp[i][j];
						if (space16 != 9)
						{
							outData << " ";
						}
					}
					++lines_16;
					outData << endl;
					if (lines_16 == 9)
					{
						break;
					}
				}
				outData.close();

				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						arr[i][j] = arr_temp[i][j];
					}
				}
				game_grid(arr, game);
			}
			else if (difficulty == 'H' || difficulty == 'h')
			{
				setCord(0, 16);
				cout << "[HARD] TEMPLATE LOADING..." << endl;
				Sleep(1600);
				cout << "SETTING UP GRID..." << endl;
				Sleep(1650);
				cout << "RESHUFFLING NUMBERS..." << endl;
				Sleep(2000);
				cout << "GOOD LUCK!" << endl;
				Sleep(1700);

				char arr_temp[9][9];

				inData.open("template_h1.txt");
				game_THREE.open("game_3.txt"); string line;
				while (getline(inData, line))
				{
					game_THREE << line << "\n";
				}
				inData.close();
				game_THREE.close();

				inData.open("game_3.txt");
				if (inData.is_open())
				{
					while (!inData.eof())
					{
						for (int i = 0; i < 9; i++)
						{
							char num;
							for (int j = 0; j < 9 && inData >> num; j++)
							{
								arr_temp[i][j] = num;
							}
						}
					}
				}
				inData.close();

				srand(time(0));
				int random = rand() % 9 + 1;
				for (int k = 0; k < random; k++)
				{
					for (int i = 0; i < 9; i++)
					{
						char temp = arr_temp[i][0];
						for (int j = 0; j < 8; j++)
						{
							arr_temp[i][j] = arr_temp[i][j + 1];
						}
						arr_temp[i][8] = temp;
					}
				}

				int x = 6, y = 0;
				char temp;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						temp = arr_temp[i][j];
						arr_temp[i][j] = arr_temp[x][y];
						arr_temp[x][y] = temp;
						y++;
					}
					y = 0;
					x++;
				}

				int space17 = 0; int lines_17 = 0;
				outData.open("game_3_temp.txt");
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						++space17;
						outData << arr_temp[i][j];
						if (space17 != 9)
						{
							outData << " ";
						}
					}
					++lines_17;
					outData << endl;
					if (lines_17 == 9)
					{
						break;
					}
				}
				outData.close();

				int space18 = 0; int lines_18 = 0;
				outData.open("game_3.txt");
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						++space18;
						outData << arr_temp[i][j];
						if (space18 != 9)
						{
							outData << " ";
						}
					}
					++lines_18;
					outData << endl;
					if (lines_18 == 9)
					{
						break;
					}
				}
				outData.close();

				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						arr[i][j] = arr_temp[i][j];
					}
				}
				game_grid(arr, game);

			}

		}
		else if (option_2 == 'm' || option_2 == 'M')
		{
			setCord(0, 16); cout << "::[Main Menu]::";
			Sleep(1600);
			welcome_screen();
			main_menu(arr);
		}
	}

}
void game_difficulty()
{
	system("cls");
	cout << "\t\t|*********************************************|" << endl;
	cout << "\t\t|          ____________________               |" << endl;
	cout << "\t\t|        | Suduko Game Difficulty |           |" << endl;
	cout << "\t\t|          --------------------               |" << endl;
	cout << "\t\t|                                             |" << endl;
	cout << "\t\t| (*) Easy            (*) Hard                |" << endl;
	cout << "\t\t|                                             |" << endl;
	cout << "\t\t| (*) Medium                                  |" << endl;
	cout << "\t\t|                                             |" << endl;
	cout << "\t\t|*********************************************|" << endl << endl << endl;
}

void game_grid(char arr[9][9], int game)
{
	system("cls"); cin.clear();
	int counter = 0;
	cout << endl;
	cout << "\t\t          GAME [" << game << "]" << endl << endl;
	cout << "\t\t    0  1  2  3  4  5  6  7  8 " << endl;
	cout << "\t\t  |**************************|" << endl;
	for (int i = 0; i < 9; i++)
	{
		if (i == 3 || i == 6)
		{
			cout <<"\t\t" <<"  |--------------------------|" << endl;
		}
		cout << "\t\t" << i << " ";
		for (int j = 0; j < 9; j++)
		{
			counter++;
			cout << "| ";
			if (arr[i][j] == '#')
			{
				cout << " ";
			}
			else
			{
				cout << arr[i][j];
			}
		}
		cout << "|" << endl;
	}
	cout << "\t\t  |**************************|" << endl;

	game_mechanics(arr, game);
}

void game_mechanics(char arr[9][9], int game)
{
	ifstream inData; ofstream outData;
	int temp[9][9];
	bool status = true;
	char check = arr[6][0];
	char arr_temp[9][9];
	int cord_x, cord_y, index_x, index_y;

	
	if (game == 1)
	{
		inData.open("game_1_temp.txt");
		while (!inData.eof())
		{
			for (int i = 0; i < 9; i++)
			{
				char num;
				for (int j = 0; j < 9 && inData >> num; j++)
				{
					arr_temp[i][j] = num;
				}
			}
		}
		inData.close();
	}
	else if (game == 2)
	{
		inData.open("game_2_temp.txt");
		if (inData.is_open())
		{
			while (!inData.eof())
			{
				for (int i = 0; i < 9; i++)
				{
					char num;
					for (int j = 0; j < 9 && inData >> num; j++)
					{
						arr_temp[i][j] = num;
					}
				}
			}
		}
		inData.close();
	}
	else if (game == 3)
	{
		inData.open("game_3_temp.txt");
		if (inData.is_open())
		{
			while (!inData.eof())
			{
				for (int i = 0; i < 9; i++)
				{
					char num;
					for (int j = 0; j < 9 && inData >> num; j++)
					{
						arr_temp[i][j] = num;
					}
				}
			}
		}
		inData.close();
	}
	
	char quit;
	setCord(0, 18);
	cout << "DO YOU WISH TO PROCEED? " << endl;
	cout << "[Enter Q to exist OR Enter ANY Character to continue]: ";
	cin >> quit;
	if (quit == 'q' || quit == 'Q')
	{
		cout << "EXISTING GAME..." << endl;
		Sleep(1750);
		cout << "SAVING CHANGES..." << endl;
		Sleep(1750);
		cout << "RETURNING TO MAIN MENU";
		Sleep(1750);
		welcome_screen();
		;
	}
	cout << endl;
	cout << "Enter [ROW] coordinates to enter values in [0 - 8]: ";
	cin >> cord_x;
	cout << "Enter [COLUMN] coordinates to enter values in [0 - 8]: ";
	cin >> cord_y;

	char number;
	cout << "Enter number ranging from [1 - 9]: ";
	cin >> number;
	cout << endl;
	cin.clear();

	if (cord_x < 0 || cord_x > 9)
	{
		cin.clear();
		cin.ignore(123, '\n');
		setCord(0, 24); cout << "|| ERROR! || Enter VALID COORDINATES/ Values!";
		Sleep(1700);
		game_grid(arr, game);
	}
	if (cord_y < 0 || cord_y > 9)
	{
		cin.clear();
		cin.ignore(123, '\n');
		setCord(0, 24); cout << "|| ERROR! || Enter VALID COORDINATES/ Values!";
		Sleep(1700);
		game_grid(arr, game);
	}
	if ((int)number < (int)'0' || (int)number > (int)'9')
	{
		/*cin.clear();
		cin.ignore(123, '\n');*/
		setCord(0, 24); cout << "|| ERROR! || Enter VALID COORDINATES/ Values!";
		Sleep(1700);
		game_grid(arr, game);
	}

	index_x = cord_x;
	index_y = cord_y;

	if (arr_temp[index_x][index_y] != '#')
	{
		cout << "Number at index [" << index_x << ", " << index_y << " ] is hardcoded!" << endl;
		cout << "CANNOT BE CHANGED TRY A DIFFERENT  INDEX!";
		Sleep(1700);
		game_grid(arr, game);
	}
	else
	{
		for (int i = 0; i < 9; i++)
		{
			if (arr[index_x][i] == number)
			{
				cout << "Invalid! " << number << " detected in Row [" << index_x << "," << i << "] of grid";
				Sleep(1750);
				game_grid(arr, game);
			}
		}
		for (int j = 0; j < 9; j++)
		{
			if (arr[j][index_y] == number)
			{
				cout << "Invalid! " << number << " detected in Row[" << j << ", " << index_y << "] of grid";
				Sleep(1750);
				game_grid(arr, game);
			}
		}

		bool status = checksquare(arr, index_x, index_y, number);
		if (status == false)
		{
			cout << "Invalid! " << number << " detected in 3 x 3 box of grid";
			Sleep(1750);
			game_grid(arr, game);
		}


		cout << "Valid Input! Adding Value" << endl;
		Sleep(1750);
		arr[index_x][index_y] = number;

		if (game == 1)
		{
			int space = 0; int line = 0;
			outData.open("game_1.txt");
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					++space;
					outData << arr[i][j];
					if (space != 9)
					{
						outData << " ";
					}
				}
				++line;
				outData << endl;
				if (line == 9)
				{
					break;
				}
			}
			outData.close();
		}
		else if (game == 2)
		{
			int space = 0; int line = 0;
			outData.open("game_2.txt");
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					++space;
					outData << arr[i][j];
					if (space != 9)
					{
						outData << " ";
					}
				}
				++line;
				outData << endl;
				if (line == 9)
				{
					break;
				}
			}
			outData.close();
		}
		else if (game == 3)
		{
			int space = 0; int line = 0;
			outData.open("game_3.txt");
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					++space;
					outData << arr[i][j];
					if (space != 9)
					{
						outData << " ";
					}
				}
				++line;
				outData << endl;
				if (line == 9)
				{
					break;
				}
			}
			outData.close();
		}
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j] == '#')
			{
				game_grid(arr, game);
			}
		}
	}
	system("cls"); cin.clear();
	int counter = 0;
	cout << endl << endl;
	cout << "\t\t          GAME [" << game << "]" << endl << endl;
	cout << "\t\t    0  1  2  3  4  5  6  7  8 " << endl;
	cout << "\t\t  |**************************|" << endl;
	for (int i = 0; i < 9; i++)
	{
		cout << "\t\t" << i << " ";
		for (int j = 0; j < 9; j++)
		{
			counter++;
			cout << "| ";
			if (arr[i][j] == '#')
			{
				cout << " ";
			}
			else
			{
				cout << arr[i][j];
			}
		}
		cout << "|" << endl;
	}
	cout << "\t\t  |**************************|" << endl << endl;
	Sleep(1765);
	cout << "\t\tYOU WIN!!!!" << endl;
	Sleep(1750);
	main();
}

bool checksquare(char skudo[9][9], int row, int columun, char num)
{
	row++;
	columun++;
	if (row > 0 && row <= 3 && columun > 0 && columun <= 3)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (num == skudo[i][j])
				{
					return false;
				}

			}
		}
		return true;
	}
	else if (row > 0 && row <= 3 && columun > 3 && columun <= 6)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 3; j < 6; j++)
			{
				if (num == skudo[i][j])
				{
					return false;
				}

			}
		}
		return true;
	}
	else if (row > 0 && row <= 3 && columun > 6 && columun <= 9)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 6; j < 9; j++)
			{
				if (num == skudo[i][j])
				{
					return false;
				}

			}
		}
		return true;
	}
	else if (row > 3 && row <= 6 && columun > 0 && columun <= 3)
	{
		for (int i = 3; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (num == skudo[i][j])
				{
					return false;
				}

			}
		}
		return true;
	}
	else if (row > 3 && row <= 6 && columun > 3 && columun <= 6)
	{
		for (int i = 3; i < 6; i++)
		{
			for (int j = 3; j < 6; j++)
			{
				if (num == skudo[i][j])
				{
					return false;
				}

			}
		}
		return true;
	}
	else if (row > 3 && row <= 6 && columun > 6 && columun <= 9)
	{
		for (int i = 3; i < 6; i++)
		{
			for (int j = 6; j < 9; j++)
			{
				if (num == skudo[i][j])
				{
					return false;
				}

			}
		}
		return true;
	}
	else if (row > 6 && row <= 9 && columun > 0 && columun <= 3)
	{
		for (int i = 6; i < 9; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (num == skudo[i][j])
				{
					return false;
				}

			}
		}
		return true;
	}
	else if (row > 6 && row <= 9 && columun > 3 && columun <= 6)
	{
		for (int i = 6; i < 9; i++)
		{
			for (int j = 3; j < 6; j++)
			{
				if (num == skudo[i][j])
				{

					return false;
				}

			}
		}
		return true;
	}
	else if (row > 6 && row <= 9 && columun > 6 && columun <= 9)
	{
		for (int i = 6; i < 9; i++)
		{
			for (int j = 6; j < 9; j++)
			{
				if (num == skudo[i][j])
				{
					return false;
				}

			}
		}
		return true;
	}
}