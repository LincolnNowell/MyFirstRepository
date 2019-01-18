#include <iostream>
#include <random>
#include <chrono>
#include <thread>

using std::cout; using std::cin; using std::endl;

void tic_tac_toe();
void print_board(char board[][3]);
bool tie(char board[3][3]);
bool win(char board[][3]);
void validate_input(int&);
void tic_tac_toe_with_computer();
void ai_choice(int &);
void ai_face_off();


int main()
{
	int choice;
	std::cout << "1. Play against computer.\n";
	std::cout << "2. Play against another person.\n";
	std::cout << "3. Watch AI Match.\n";
	std::cin >> choice;
	while (choice > 3 || choice < 0)
	{
		std::cout << "Choose option 1 or 2.\n";
		std::cin >> choice;
	}

	switch (choice)
	{
		case 1:
			tic_tac_toe_with_computer();
			break;

		case 2:
			tic_tac_toe();
			break;

		case 3:
			ai_face_off();
			break;

	default:
		break;
	}
}

void print_board(char board[][3])
{
	system("cls");
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			cout << board[row][col];
		}
		cout << endl;
	}
}

void tic_tac_toe()
{
	bool Is_Game_Won; 
	bool is_tie = false;

	struct Player
	{
		int player_row_choice, player_col_choice;
	};

	Player player_1, player_2;

	char board[3][3] = { '*','*', '*',
						'*', '*', '*',
						'*', '*', '*' };

	while (is_tie != true)
	{
		print_board(board);

		cout << " Player 1 Enter your the row\n";
		cin >> player_1.player_row_choice;
		validate_input(player_1.player_row_choice);

		cout << " Player 1 Enter your the col\n";
		cin >> player_1.player_col_choice;

		validate_input(player_1.player_col_choice);

		if (board[player_1.player_row_choice - 1][player_1.player_col_choice - 1] == '*')
		{
			board[player_1.player_row_choice - 1][player_1.player_col_choice - 1] = 'X';
		}
		else
		{
			while (board[player_1.player_row_choice - 1][player_1.player_col_choice - 1] != '*')
			{
				cout << "That space is taken chose another place.\n";
				cout << " Player 1 Enter your the row\n";
				cin >> player_1.player_row_choice;
				validate_input(player_1.player_row_choice);

				cout << " Player 1 Enter your the col\n";
				cin >> player_1.player_col_choice;
				validate_input(player_1.player_col_choice);
			}

			board[player_1.player_row_choice - 1][player_1.player_col_choice - 1] = 'X';

		}


		print_board(board);


		Is_Game_Won = win(board);

		is_tie = tie(board);

		if (is_tie == true)
		{
			cout << "Tied Good Game!\n";
			system("pause");
			break;
		}

		else if (Is_Game_Won == true)
		{
			cout << "Player 1 wins!\n";
			system("pause");
			break;
		}
		
		cout << " Player 2 Enter your the row\n";
		cin >> player_2.player_row_choice;
		validate_input(player_2.player_row_choice);

		cout << " Player 2 Enter your the col\n";
		cin >> player_2.player_col_choice;

		validate_input(player_2.player_col_choice);

		if (board[player_2.player_row_choice - 1][player_2.player_col_choice - 1] == '*')
		{
			board[player_2.player_row_choice - 1][player_2.player_col_choice - 1] = 'O';
		}
		else
		{
			while (board[player_2.player_row_choice - 1][player_2.player_col_choice - 1] != '*')
			{
				cout << "That space is taken chose another place.\n";
				cout << " Player 2 Enter your the row\n";
				cin >> player_2.player_row_choice;
				validate_input(player_2.player_row_choice);

				cout << " Player 2 Enter your the col\n";
				cin >> player_2.player_col_choice;
				validate_input(player_2.player_col_choice);
			}

			board[player_2.player_row_choice - 1][player_2.player_col_choice - 1] = 'O';

		}


		Is_Game_Won = win(board);

		is_tie = tie(board);

		if (is_tie == true)
		{
			cout << "Tied Good Game!\n";
			system("pause");
			break;
		}


		else if (Is_Game_Won == true)
		{
			cout << "Player 2 wins!\n";
			system("pause");
			break;
		}
	}
}

bool tie(char board[3][3])
{
	bool tie = true;

	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if (board[row][col] != '*')
			{

			}
			else
			{
				tie = false;
				break;
			}
		}

		if (tie == false)
		{
			break;
		}
	}

	return tie;
}

void validate_input(int& Player_Choice)
{
	while (Player_Choice > 3 || Player_Choice < 0)
	{
		std::cout << "Enter a number between 1 and 3\n";
		std::cin >> Player_Choice;
	}
}

bool win(char board[][3])
{
	if (board[0][0] == board[0][1] and board[0][1] == board[0][2] and board[0][0] != '*')
	{
		return true;
	}

	else if (board[1][0] == board[1][1] and board[1][1] == board[1][2] and board[1][0] != '*')
	{
		return true;
	}

	else if (board[2][0] == board[2][1] and board[2][1] == board[2][2] and board[2][0] != '*')
	{
		return true;
	}

	else if (board[0][0] == board[1][0] and board[1][0] == board[2][0] and board[0][0] != '*')
	{
		return true;
	}

	else if (board[0][1] == board[1][1] and board[1][1] == board[2][1] and board[0][1] != '*')
	{
		return true;
	}

	else if (board[0][2] == board[1][2] and board[1][2] == board[2][2] and board[0][2] != '*')
	{
		return true;
	}

	else if (board[0][0] == board[2][2] and board[1][1] == board[2][2] and board[0][0] != '*')
	{
		return true;
	}
	else if (board[2][0] == board[1][1] and board[1][1] == board[0][2] and board[2][0] != '*')
	{
		return true;
	}
}

void tic_tac_toe_with_computer()
{
	bool Is_Game_Won;
	bool is_tie = false;

	struct Player
	{
		int player_row_choice, player_col_choice;
	};

	Player player_1, player_2;

	char board[3][3] = { '*','*', '*',
						'*', '*', '*',
						'*', '*', '*' };

	while (is_tie != true)
	{
		print_board(board);

		cout << " Player 1 Enter your the row\n";
		cin >> player_1.player_row_choice;
		validate_input(player_1.player_row_choice);

		cout << " Player 1 Enter your the col\n";
		cin >> player_1.player_col_choice;

		validate_input(player_1.player_col_choice);

		if (board[player_1.player_row_choice - 1][player_1.player_col_choice - 1] == '*')
		{
			board[player_1.player_row_choice - 1][player_1.player_col_choice - 1] = 'X';
		}
		else
		{
			while (board[player_1.player_row_choice - 1][player_1.player_col_choice - 1] != '*')
			{
				cout << "That space is taken chose another place.\n";
				cout << " Player 1 Enter your the row\n";
				cin >> player_1.player_row_choice;
				validate_input(player_1.player_row_choice);

				cout << " Player 1 Enter your the col\n";
				cin >> player_1.player_col_choice;
				validate_input(player_1.player_col_choice);
			}

			board[player_1.player_row_choice - 1][player_1.player_col_choice - 1] = 'X';

		}


		print_board(board);


		Is_Game_Won = win(board);

		is_tie = tie(board);

		if (is_tie == true)
		{
			cout << "Tied Good Game!\n";
			system("pause");
			break;
		}

		else if (Is_Game_Won == true)
		{
			cout << "Player 1 wins!\n";
			system("pause");
			break;
		}


		ai_choice(player_2.player_row_choice);

		ai_choice(player_2.player_col_choice);

		if (board[player_2.player_row_choice - 1][player_2.player_col_choice - 1] == '*')
		{
			board[player_2.player_row_choice - 1][player_2.player_col_choice - 1] = 'O';
		}
		else
		{
			while (board[player_2.player_row_choice - 1][player_2.player_col_choice - 1] != '*')
			{
				ai_choice(player_2.player_row_choice);

				ai_choice(player_2.player_col_choice);
			}

			board[player_2.player_row_choice - 1][player_2.player_col_choice - 1] = 'O';

		}


		Is_Game_Won = win(board);

		is_tie = tie(board);

		if (is_tie == true)
		{
			cout << "Tied Good Game!\n";
			system("pause");
			break;
		}


		else if (Is_Game_Won == true)
		{
			cout << "Player 2 wins!\n";
			system("pause");
			break;
		}
	}
}

void ai_face_off()
{
	bool Is_Game_Won;
	bool is_tie = false;

	struct Player
	{
		int player_row_choice, player_col_choice;
	};

	Player player_1, player_2;

	char board[3][3] = { '*','*', '*',
						'*', '*', '*',
						'*', '*', '*' };

	while (is_tie != true)
	{
		print_board(board);

		ai_choice(player_1.player_row_choice);

		ai_choice(player_1.player_col_choice);

		if (board[player_1.player_row_choice - 1][player_1.player_col_choice - 1] == '*')
		{
			board[player_1.player_row_choice - 1][player_1.player_col_choice - 1] = 'X';
		}
		else
		{
			while (board[player_1.player_row_choice - 1][player_1.player_col_choice - 1] != '*')
			{
				ai_choice(player_1.player_row_choice);

				ai_choice(player_1.player_col_choice);
			}

			board[player_1.player_row_choice - 1][player_1.player_col_choice - 1] = 'X';

		}


		Is_Game_Won = win(board);

		print_board(board);
		std::this_thread::sleep_for(std::chrono::seconds(1));

		is_tie = tie(board);

		if (is_tie == true)
		{
			system("cls");
			print_board(board);
			cout << "Tied Good Game!\n";
			system("pause");
			break;
		}


		else if (Is_Game_Won == true)
		{
			system("cls");
			print_board(board);
			cout << "Player 2 wins!\n";
			system("pause");
			break;
		}


		ai_choice(player_2.player_row_choice);

		ai_choice(player_2.player_col_choice);

		if (board[player_2.player_row_choice - 1][player_2.player_col_choice - 1] == '*')
		{
			board[player_2.player_row_choice - 1][player_2.player_col_choice - 1] = 'O';
		}
		else
		{
			while (board[player_2.player_row_choice - 1][player_2.player_col_choice - 1] != '*')
			{
				ai_choice(player_2.player_row_choice);

				ai_choice(player_2.player_col_choice);
			}

			board[player_2.player_row_choice - 1][player_2.player_col_choice - 1] = 'O';

		}


		Is_Game_Won = win(board);

		print_board(board);
		std::this_thread::sleep_for(std::chrono::seconds(1));

		is_tie = tie(board);

		if (is_tie == true)
		{
			system("cls");
			print_board(board);
			cout << "Tied Good Game!\n";
			system("pause");
			break;
		}


		else if (Is_Game_Won == true)
		{
			system("cls");
			print_board(board);
			cout << "Player 2 wins!\n";
			system("pause");
			break;
		}
	}
}

void ai_choice(int & comp_choice)
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine random_choice(seed);

	std::uniform_int_distribution<int> nums(1, 3);

	comp_choice = nums(random_choice);
}