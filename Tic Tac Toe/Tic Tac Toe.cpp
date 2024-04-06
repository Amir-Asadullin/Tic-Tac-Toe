#include <iostream>
#include <random>

char table[3][3];

void PrintTable()
{
	std::cout << "\nyx 1  2  3\n";
	std::cout << "1 " << table[0][0] << " | " << table[1][0] << " | " << table[2][0] << std::endl;
	std::cout << "  --+---+---\n";
	std::cout << "2 " << table[0][1] << " | " << table[1][1] << " | " << table[2][1] << std::endl;
	std::cout << "  --+---+---\n";
	std::cout << "3 " << table[0][2] << " | " << table[1][2] << " | " << table[2][2] << std::endl;
}

int CheckWin()
{
	if (table[0][0] == 'X' && table[1][0] == 'X' && table[2][0] == 'X') {
		return 1;
	}
	else if (table[0][1] == 'X' && table[1][1] == 'X' && table[2][1] == 'X') {
		return 1;
	}
	else if (table[0][2] == 'X' && table[1][2] == 'X' && table[2][2] == 'X') {
		return 1;
	}
	else if (table[0][0] == 'X' && table[0][1] == 'X' && table[0][2] == 'X') {
		return 1;
	}
	else if (table[1][0] == 'X' && table[1][1] == 'X' && table[1][2] == 'X') {
		return 1;
	}
	else if (table[2][0] == 'X' && table[2][1] == 'X' && table[2][2] == 'X') {
		return 1;
	}
	else if (table[0][0] == 'X' && table[1][1] == 'X' && table[2][2] == 'X') {
		return 1;
	}
	else if (table[2][0] == 'X' && table[1][1] == 'X' && table[0][2] == 'X') {
		return 1;
	}
	else if (table[0][0] == 'O' && table[1][0] == 'O' && table[2][0] == 'O') {
		return 2;
	}
	else if (table[0][1] == 'O' && table[1][1] == 'O' && table[2][1] == 'O') {
		return 2;
	}
	else if (table[0][2] == 'O' && table[1][2] == 'O' && table[2][2] == 'O') {
		return 2;
	}
	else if (table[0][0] == 'O' && table[0][1] == 'O' && table[0][2] == 'O') {
		return 2;
	}
	else if (table[1][0] == 'O' && table[1][1] == 'O' && table[1][2] == 'O') {
		return 2;
	}
	else if (table[2][0] == 'O' && table[2][1] == 'O' && table[2][2] == 'O') {
		return 2;
	}
	else if (table[0][0] == 'O' && table[1][1] == 'O' && table[2][2] == 'O') {
		return 2;
	}
	else if (table[2][0] == 'O' && table[1][1] == 'O' && table[0][2] == 'O') {
		return 2;
	}
	else if (table[0][0] != ' ' && table[1][0] != ' ' && table[2][0] != ' ' && table[0][1] != ' ' && table[1][1] != ' ' && table[2][1] != ' ' && table[0][2] != ' ' && table[1][2] != ' ' && table[2][2] != ' ') {
		return 3;
	}
	else {
		return 0;
	}
}

void Player()
{
	while (1) {
		int x;
		int y;
		std::cout << "Enter the x: ";
		std::cin >> x;
		std::cout << "Enter the y: ";
		std::cin >> y;
		if (x < 4 && x > 0 && y < 4 && y > 0 && table[x-1][y-1] == ' ') {
			table[x-1][y-1] = 'X';
			break;
		}
		else {
			std::cout << "Error!";
		}
	}

	PrintTable();
}

void Bot()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, 2);

	if (table[0][0] == ' ' && table[1][0] == 'O' && table[2][0] == 'O') {
		table[0][0] = 'O';
	}
	else if (table[0][0] == ' ' && table[1][1] == 'O' && table[2][2] == 'O') {
		table[0][0] = 'O';
	}
	else if (table[0][0] == ' ' && table[0][1] == 'O' && table[0][2] == 'O') {
		table[0][0] = 'O';
	}
	else if (table[0][0] == 'O' && table[1][0] == ' ' && table[2][0] == 'O') {
		table[1][0] = 'O';
	}
	else if (table[1][0] == ' ' && table[1][1] == 'O' && table[1][2] == 'O') {
		table[1][0] = 'O';
	}
	else if (table[0][0] == 'O' && table[1][0] == 'O' && table[2][0] == ' ') {
		table[2][0] = 'O';
	}
	else if (table[2][0] == ' ' && table[1][1] == 'O' && table[0][2] == 'O') {
		table[2][0] = 'O';
	}
	else if (table[2][0] == ' ' && table[2][1] == 'O' && table[2][2] == 'O') {
		table[2][0] = 'O';
	}
	else if (table[0][0] == 'O' && table[0][1] == ' ' && table[0][2] == 'O') {
		table[0][1] = 'O';
	}
	else if (table[0][1] == ' ' && table[1][1] == 'O' && table[2][1] == 'O') {
		table[0][1] = 'O';
	}
	else if (table[0][0] == 'O' && table[1][1] == ' ' && table[2][2] == 'O') {
		table[1][1] = 'O';
	}
	else if (table[1][0] == 'O' && table[1][1] == ' ' && table[1][2] == 'O') {
		table[1][1] = 'O';
	}
	else if (table[2][0] == 'O' && table[1][1] == ' ' && table[0][2] == 'O') {
		table[1][1] = 'O';
	}
	else if (table[0][1] == 'O' && table[1][1] == ' ' && table[2][1] == 'O') {
		table[1][1] = 'O';
	}
	else if (table[2][0] == 'O' && table[2][1] == ' ' && table[2][2] == 'O') {
		table[2][1] = 'O';
	}
	else if (table[0][1] == 'O' && table[1][1] == 'O' && table[2][1] == ' ') {
		table[2][1] = 'O';
	}
	else if (table[0][0] == 'O' && table[0][1] == 'O' && table[0][2] == ' ') {
		table[0][2] = 'O';
	}
	else if (table[2][0] == 'O' && table[1][1] == 'O' && table[0][2] == ' ') {
		table[0][2] = 'O';
	}
	else if (table[0][2] == ' ' && table[1][2] == 'O' && table[2][2] == 'O') {
		table[0][2] = 'O';
	}
	else if (table[1][0] == 'O' && table[1][1] == 'O' && table[1][2] == ' ') {
		table[1][2] = 'O';
	}
	else if (table[0][2] == 'O' && table[1][2] == ' ' && table[2][2] == 'O') {
		table[1][2] = 'O';
	}
	else if (table[0][0] == 'O' && table[1][1] == 'O' && table[2][2] == ' ') {
		table[2][2] = 'O';
	}
	else if (table[2][0] == 'O' && table[2][1] == 'O' && table[2][2] == ' ') {
		table[2][2] = 'O';
	}
	else if (table[0][2] == 'O' && table[1][2] == 'O' && table[2][2] == ' ') {
		table[2][2] = 'O';
	}
	else if (table[0][0] == ' ' && table[1][0] == 'X' && table[2][0] == 'X') {
		table[0][0] = 'O';
	}
	else if (table[0][0] == ' ' && table[1][1] == 'X' && table[2][2] == 'X') {
		table[0][0] = 'O';
	}
	else if (table[0][0] == ' ' && table[0][1] == 'X' && table[0][2] == 'X') {
		table[0][0] = 'O';
	}
	else if (table[0][0] == 'X' && table[1][0] == ' ' && table[2][0] == 'X') {
		table[1][0] = 'O';
	}
	else if (table[1][0] == ' ' && table[1][1] == 'X' && table[1][2] == 'X') {
		table[1][0] = 'O';
	}
	else if (table[0][0] == 'X' && table[1][0] == 'X' && table[2][0] == ' ') {
		table[2][0] = 'O';
	}
	else if (table[2][0] == ' ' && table[1][1] == 'X' && table[0][2] == 'X') {
		table[2][0] = 'O';
	}
	else if (table[2][0] == ' ' && table[2][1] == 'X' && table[2][2] == 'X') {
		table[2][0] = 'O';
	}
	else if (table[0][0] == 'X' && table[0][1] == ' ' && table[0][2] == 'X') {
		table[0][1] = 'O';
	}
	else if (table[0][1] == ' ' && table[1][1] == 'X' && table[2][1] == 'X') {
		table[0][1] = 'O';
	}
	else if (table[0][0] == 'X' && table[1][1] == ' ' && table[2][2] == 'X') {
		table[1][1] = 'O';
	}
	else if (table[1][0] == 'X' && table[1][1] == ' ' && table[1][2] == 'X') {
		table[1][1] = 'O';
	}
	else if (table[2][0] == 'X' && table[1][1] == ' ' && table[0][2] == 'X') {
		table[1][1] = 'O';
	}
	else if (table[0][1] == 'X' && table[1][1] == ' ' && table[2][1] == 'X') {
		table[1][1] = 'O';
	}
	else if (table[2][0] == 'X' && table[2][1] == ' ' && table[2][2] == 'X') {
		table[2][1] = 'O';
	}
	else if (table[0][1] == 'X' && table[1][1] == 'X' && table[2][1] == ' ') {
		table[2][1] = 'O';
	}
	else if (table[0][0] == 'X' && table[0][1] == 'X' && table[0][2] == ' ') {
		table[0][2] = 'O';
	}
	else if (table[2][0] == 'X' && table[1][1] == 'X' && table[0][2] == ' ') {
		table[0][2] = 'O';
	}
	else if (table[0][2] == ' ' && table[1][2] == 'X' && table[2][2] == 'X') {
		table[0][2] = 'O';
	}
	else if (table[1][0] == 'X' && table[1][1] == 'X' && table[1][2] == ' ') {
		table[1][2] = 'O';
	}
	else if (table[0][2] == 'X' && table[1][2] == ' ' && table[2][2] == 'X') {
		table[1][2] = 'O';
	}
	else if (table[0][0] == 'X' && table[1][1] == 'X' && table[2][2] == ' ') {
		table[2][2] = 'O';
	}
	else if (table[2][0] == 'X' && table[2][1] == 'X' && table[2][2] == ' ') {
		table[2][2] = 'O';
	}
	else if (table[0][2] == 'X' && table[1][2] == 'X' && table[2][2] == ' ') {
		table[2][2] = 'O';
	}
	else {
		while (1) {
			int x = dist(gen);
			int y = dist(gen);
			if (table[x][y] == ' ') {
				table[x][y] = 'O';
				break;
			}
		}
	}
	PrintTable();
}

int main()
{
	int w;

	table[0][0] = ' ';
	table[1][0] = ' ';
	table[2][0] = ' ';
	table[0][1] = ' ';
	table[1][1] = ' ';
	table[2][1] = ' ';
	table[0][2] = ' ';
	table[1][2] = ' ';
	table[2][2] = ' ';
	
	std::cout << "Tic Tac Toe! You start!\n";
	PrintTable();

	while (1) {
		if (CheckWin() == 0) {
			Player();
		}
		else {
			w = CheckWin();
			break;
		}

		if (CheckWin() == 0) {
			Bot();
		}
		else {
			w = CheckWin();
			break;
		}
	}

	if (w == 1) {
		std::cout << "You win!";
	}
	else if (w == 2) {
		std::cout << "You lost!";
	}
	else {
		std::cout << "Draw!";
	}
}