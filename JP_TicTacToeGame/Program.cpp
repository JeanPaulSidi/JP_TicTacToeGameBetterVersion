#include <iostream>
#include <conio.h>
using namespace std;


void setUpGameBoard(char* arrayPointer, int numberOfElements) 
{
	int counter;

	counter = 1;

	for (int i = 0; i < numberOfElements; i++)
	{
		*(arrayPointer + i) = counter + '0';
		counter++;
	}


}

void displayGameRules(char* arrayPointer, int numberOfElements) 
{
	cout << "********************" << endl;
	cout << "* Tic Tac Toe Game *" << endl;
	cout << "********************" << endl;
	cout << endl;

	for (int i = 0; i < numberOfElements; i++)
	{
		if ( (i % 3) == 0 ) 
		{
			cout << endl;
		}

		cout << "[ " << *(arrayPointer + i) << " ]";
	}

	cout << endl;
	cout << endl;
	cout << endl;
	cout << "********** Rules ********** " << endl;
	cout << "1. The game is played on a 3x3 grid." << endl;
	cout << "2. Players take turns putting their marks(X or O) in empty squares labeled from '1' to '9'." << endl;
	cout << "3. The first player to get 3 of their marks in a row (vertically, horizontally, or diagonally) is the winner." << endl;
	cout << "4. If all 9 squares are full and no player has won, the game is over." << endl;
	cout << endl;
	cout << "Player 1's mark: X.  Player 2's mark: O" << endl;
		
}

void resetGameBoard(char* arrayPointer, int numberOfElements) 
{
	for (int i = 0; i < numberOfElements; i++)
	{
		*(arrayPointer + i) = ' ';
	}
}

void displayGameBoard(char* arrayPointer, int numberOfElements) 
{
	cout << endl;

	for (int i = 0; i < numberOfElements; i++)
	{
		if ((i % 3) == 0)
		{
			cout << endl;
		}
		
		if ( *(arrayPointer + i) != 'X' && *(arrayPointer + i) != 'O') 
		{
			cout << "[   ]";
		}
		else
		{
			cout << "[ " << *(arrayPointer + i) << " ]";
		}
	}

	cout << endl;
}

void displayEmptyBoardPositions(char* arrayPointer, int numberOfElements) 
{
	int counter;

	counter = 1;

	for (int i = 0; i < numberOfElements; i++)
	{
		if ( *(arrayPointer + i) == ' ') 
		{
			cout << counter << ",  ";
		}

		counter++;
	}
}

bool checkPositionAvailability(char* arrayPointer, int numberOfElements, char boardPosition)
{
	int positionIndex;

	positionIndex = (boardPosition - '0') - 1;

	if (*(arrayPointer + positionIndex) == ' ')
	{
		return true;
	}
	else
	{
		return false;
	}


}

int getBoardPositionInput(char* arrayPointer, int numberOfElements) 
{
	bool positionAvailable;
	int positionInput;

	cin >> positionInput;

	while (cin.fail())
	{
		cout << endl;
		cout << "Invalid input. Please try again..." << endl;

		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Your choice: ";
		cin >> positionInput;
	}

	if (positionInput != 1 && positionInput != 2 && positionInput != 3 && positionInput != 4 && positionInput != 5 
		   && positionInput != 6 && positionInput != 7 && positionInput != 8 && positionInput != 9)
	{
		cout << endl;
		cout << "Please choose a number between: ";
		displayEmptyBoardPositions(arrayPointer, numberOfElements);
		cout << ": ";

		cin.clear();
		cin.ignore(INT_MAX, '\n');

		return -1;
	}
	else
	{
		positionAvailable = checkPositionAvailability(arrayPointer, numberOfElements, positionInput + '0');

		if (!positionAvailable) 
		{
			cout << endl;
			cout << "This position is occupied.";
			cout << endl;
			cout << "Please choose a number between: ";
			displayEmptyBoardPositions(arrayPointer, numberOfElements);
			cout << ": ";

			cin.clear();
			cin.ignore(INT_MAX, '\n');

			return -1;
		}
		else
		{
			return positionInput;
		}
	}

}


void updateGameBoard(char* arrayPointer, char PlayerNumber, char boardPosition) 
{
	int positionIndex;

	positionIndex = (boardPosition - '0') - 1;

	if (PlayerNumber == '1') 
	{
		*(arrayPointer + positionIndex) = 'X';
	}
	else
	{
		*(arrayPointer + positionIndex) = 'O';
	}
}

bool checkWinningGame(char* arrayPointer, int numberOfElements) 
{
	if (*(arrayPointer + 0) != ' ' && *(arrayPointer + 0) == *(arrayPointer + 1) && *(arrayPointer + 1) == *(arrayPointer + 2))
	{
		return true;
	}
	else if (*(arrayPointer + 3) != ' ' && *(arrayPointer + 3) == *(arrayPointer + 4) && *(arrayPointer + 4) == *(arrayPointer + 5))
	{
		return true;
	}
	else if (*(arrayPointer + 6) != ' ' && * (arrayPointer + 6) == *(arrayPointer + 7) && *(arrayPointer + 7) == *(arrayPointer + 8))
	{
		return true;
	}
	else if (*(arrayPointer + 0) != ' ' && * (arrayPointer + 0) == *(arrayPointer + 3) && *(arrayPointer + 3) == *(arrayPointer + 6))
	{
		return true;
	}
	else if (*(arrayPointer + 1) != ' ' && * (arrayPointer + 1) == *(arrayPointer + 4) && *(arrayPointer + 4) == *(arrayPointer + 7))
	{
		return true;
	}
	else if (*(arrayPointer + 2) != ' ' && * (arrayPointer + 2) == *(arrayPointer + 5) && *(arrayPointer + 5) == *(arrayPointer + 8))
	{
		return true;
	}
	else if (*(arrayPointer + 0) != ' ' && * (arrayPointer + 0) == *(arrayPointer + 4) && *(arrayPointer + 4) == *(arrayPointer + 8))
	{
		return true;
	}
	else if (*(arrayPointer + 2) != ' ' && *(arrayPointer + 2) == *(arrayPointer + 4) && *(arrayPointer + 4) == *(arrayPointer + 6))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool checkDrawGame(char* arrayPointer, int numberOfElements) 
{
	for (int i = 0; i < numberOfElements; i++)
	{
		if ( *(arrayPointer + i) == ' ' ) 
		{
			return false;
		}
	}

	return true;
}

char managePlayerTurns(char currentPlayerNumber) 
{
	char nextPlayerNumber;

	if (currentPlayerNumber == '1') 
	{
		nextPlayerNumber = '2';
	}
	else
	{
		nextPlayerNumber = '1';
	}

	return nextPlayerNumber;
}


int main() 
{
	char board[3][3];
	int numberOfElements = 9;
	char* boardPointer;
	boardPointer = &board[0][0];

	bool winningGame;
	bool drawGame;
	bool keepPlaying;

	char currentPlayerNumber;
	int playerPositionChoice;
	string playerInput;

	while (true)
	{
		system("cls");

		setUpGameBoard(boardPointer, numberOfElements);
		displayGameRules(boardPointer, numberOfElements);
		cout << endl;
		cout << endl;
		cout << "Press any key to start a new game...";
		_getch();

		do
		{
			system("cls");

			currentPlayerNumber = '1';
			winningGame = false;
			drawGame = false;
			keepPlaying = false;

			resetGameBoard(boardPointer, numberOfElements);
			cout << endl;
			cout << endl;

			while (!winningGame && !drawGame)
			{
				system("cls");
				cout << "Player " << currentPlayerNumber << "'s turn..." << endl;
				cout << endl;
				displayGameBoard(boardPointer, numberOfElements);
				cout << endl;
				playerPositionChoice = -1;
				cout << "Empty positions on the board: ";
				displayEmptyBoardPositions(boardPointer, numberOfElements);
				cout << endl;
				cout << "Choose an empty position: ";

				while (playerPositionChoice == -1)
				{
					playerPositionChoice = getBoardPositionInput(boardPointer, numberOfElements);
				}

				updateGameBoard(boardPointer, currentPlayerNumber, playerPositionChoice + '0');
				cout << endl;

				winningGame = checkWinningGame(boardPointer, numberOfElements);

				if (!winningGame)
				{
					drawGame = checkDrawGame(boardPointer, numberOfElements);

					if (!drawGame)
					{
						currentPlayerNumber = managePlayerTurns(currentPlayerNumber);
					}
				}
			}

			if (winningGame)
			{
				system("cls");

				displayGameBoard(boardPointer, numberOfElements);
				cout << endl;
				cout << "Congratulations player " << currentPlayerNumber << ". You won!" << endl;
			}
			else if (drawGame)
			{
				system("cls");

				displayGameBoard(boardPointer, numberOfElements);
				cout << endl;
				cout << "All positions on the board are filled and no player has achieved a win." << endl;
				cout << "The game is over." << endl;
			}

			cout << endl;
			cout << endl;
			cout << "Would you like to start a new game? " << endl;
			cout << "Enter 'y' for yes or 'n' for no: ";

			cin >> playerInput;

			while (playerInput != "Y" && playerInput != "y" && playerInput != "N" && playerInput != "n")
			{
				cout << endl;
				cout << "Please enter 'y' or 'n': ";

				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cin >> playerInput;
			}

			if (playerInput == "Y" || playerInput == "y")
			{
				keepPlaying = true;
			}

		} while (keepPlaying);
		
	}

	return 0;
}