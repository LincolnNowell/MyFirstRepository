#include <iostream>

using std::cout; using std::cin; using std::endl;

void tic_tac_toe();
void print_board(char board[][3]);
bool tie(char board[3][3]);
bool win(char board[][3]);
void validate_input(int&);


int main()
{
	tic_tac_toe();
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