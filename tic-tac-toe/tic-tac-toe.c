#include <stdio.h>

#define rows 3
#define cols 3
int main() {
	int board[rows][cols];
	int player = 1;
	int win = 0;
	int playerRow;
	int playerCol;
	extern int print_board(board);
	extern int check_win(board);

	for (int i = 0, j; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = 0;
		}
	}

	while (win == 0) {
		print_board(board);

		printf("Player %d's turn\n", player);
		while(1)
		{
			printf("Enter the position where you would like to go as Row then Column\n");
			scanf("%d", &playerRow);
			scanf("%d", &playerCol);
			printf("%d, %d\n\n", playerRow, playerCol);
			if (board[playerRow][playerCol] == 0)
			{
				board[playerRow][playerCol] = player;
				break;
			}
			else
			{
				printf("Invalid position, Try again");
			}
		}

		win = check_win(board, player);
		if(win == 0)
			player = player == 1 ? 2 : 1;
	}
	printf("Player %d Won!\n\n", player);
	print_board(board);
	return 0;
}

int check_win(int board[3][3], int player) {
	int count = 0;
	//horizontal check
	for (int i = 0, j; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			if (board[i][j] == player)
				count++;
			else
				count = 0;
		}
	}
	if(count == 3)
		return 1;
	count = 0;

	////vertical check
	for (int i = 0, j; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			if (board[j][i] == player)
				count++;
			else
				count = 0;
		}
	}
	if (count == 3)
		return 1;
	count = 0;

	//diagonal check 1
	for (int i = 0, j = 0; i < rows && j < cols; i++, j++)
	{
		if (board[i][j] == player)
			count++;
		else
			count = 0;
	}
	if (count == 3)
		return 1;
	count = 0;

	//diagonal check 2
	for (int i = rows - 1, j = 0; i >= 0 && j < cols; i--, j++)
	{
		printf("%d, %d\n\n", i, j);
		if (board[i][j] == player)
			count++;
		else
			count = 0;
	}
	if (count == 3)
		return 1;
	count = 0;

	return 0;
}

int print_board(int board[3][3]) {
	for (int i = 0, j; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			printf("%d  ", board[i][j]);
		}
		printf("\n");
	}
	return 0;
}