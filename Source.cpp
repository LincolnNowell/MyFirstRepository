#include <iostream>

using std::cout; using std::cin; using std::endl;

void tic_tac_toe();
bool tie(char board[3][3]);
bool win(char board[][3]);


int main()
{
	tic_tac_toe();

	cin.get();
}

void tic_tac_toe()
{
	bool huh;
	bool is_tie = false;

	struct choices
	{
		int player1_choice_x, player1_choice_y,
			player2_choice_x, player2_choice_y;

	};

	choices choice;

	char board[3][3] = { '*','*', '*',
						'*', '*', '*',
						'*', '*', '*' };

	while (is_tie != true)
	{
		char winner;
		for (int row = 0; row < 3; row++)
		{
			for (int col = 0; col < 3; col++)
			{
				cout << board[row][col];
			}
			cout << endl;
		}

		cout << " Player 1 Enter your the row\n";
		cin >> choice.player1_choice_x;
		cout << " Player 1 Enter your the col\n";
		cin >> choice.player1_choice_y;
		if (board[choice.player1_choice_x - 1][choice.player1_choice_y - 1] == '*')
		{
			board[choice.player1_choice_x - 1][choice.player1_choice_y - 1] = 'X';
		}
		else
		{
			cout << "That space is taken chose another place.\n";
			cout << " Player 1 Enter your the row\n";
			cin >> choice.player1_choice_x;
			cout << " Player 1 Enter your the col\n";
			cin >> choice.player1_choice_y;

		}


		for (int row = 0; row < 3; row++)
		{
			for (int col = 0; col < 3; col++)
			{
				cout << board[row][col];
			}
			cout << endl;
		}


		huh = win(board);
		is_tie = tie(board);
		if (is_tie == true)
		{
			cout << "Tied Good Game!\n";
		}

		else if (huh == true)
		{
			cout << "Player 1 wins!\n";
			break;
		}

		cout << " Player 2 Enter your the row\n";
		cin >> choice.player2_choice_x;
		cout << " Player 2 Enter your the col\n";
		cin >> choice.player2_choice_y;

		if (board[choice.player2_choice_x - 1][choice.player2_choice_y - 1] == '*')
		{
			board[choice.player2_choice_x - 1][choice.player2_choice_y - 1] = 'O';
		}
		else
		{
			cout << "That space is taken chose another place.\n";
			cout << " Player 2 Enter your the row\n";
			cin >> choice.player2_choice_x;
			cout << " Player 2 Enter your the col\n";
			cin >> choice.player2_choice_y;

		}


		huh = win(board);
		is_tie = tie(board);
		if (is_tie == true)
		{
			cout << "Tied Good Game!\n";
		}


		else if (huh == true)
		{
			cout << "Player 2 wins!\n";
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