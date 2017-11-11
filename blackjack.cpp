#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//set global variables
int runningtotal = 0;
int card1;
int card2; 
char lettercard1;
char lettercard2;

//start defining the functions to be overloaded
int blackJack (int card1, int card2)
{
	runningtotal = card1 + card2;
	cout << "Total:" << runningtotal << endl;
}

//define a function for each type of argument
int blackJack (int card1, char lettercard2)
{
	if (lettercard2 == 'K' || lettercard2 == 'Q' || lettercard2 == 'J')
	{
		card2 = 10;
	}
	else
	{
		card2 = 11;
	}
	runningtotal = card1 + card2;
	cout << "Total:" << runningtotal << endl;
}

int blackJack (char lettercard1, int card2)
{
	if (lettercard1 == 'K' || lettercard1 == 'Q' || lettercard1 == 'J')
	{
		card1 = 10;
	}
	else
	{
		card1 = 11;
	}
	runningtotal = card1 + card2;
	cout << "Total:" << runningtotal << endl;
}

int blackJack (char lettercard1, char lettercard2)
{		
	if (lettercard1 == 'K' || lettercard1 == 'Q' || lettercard1 == 'J')
	{
		card1 = 10;
	}
	else
	{
		card1 = 11;
	}
	if (lettercard2 == 'K' || lettercard2 == 'Q' || lettercard2 == 'J')
	{
		card2 = 10;
	}
	else
	{
		card2 = 11;
	}
		runningtotal = card1 + card2;
		cout << "Total:" << runningtotal << endl;
}
//these are the functions for when we draw single cards
int blackJack (int card1)
{
	runningtotal = runningtotal + card1;
	cout << "Total:" << runningtotal << endl;
}

int blackJack (char lettercard1)
{
	if (lettercard1 == 'K' || lettercard1 == 'Q' || lettercard1 == 'J')
	{
		card1 = 10;
	}
	else
	{
		card1 = 11;
	}
	runningtotal = runningtotal + card1;
	cout << "Total:" << runningtotal << endl;
}

int main()
{
	char user_response;

	//generate random number
	srand(time(0));
	//generate card 1, from a range of 2-14
	int card1 = rand() % 13 + 2;
	if (card1 > 9)
	{
		//identifying my face cards
		if (card1 == 10)
		{
			lettercard1 = 'A';
		}
		else if (card1 == 11)
		{
			lettercard1 = 'K';
		}
		else if (card1 == 12)
		{
			lettercard1 = 'Q';
		}
		else
		{
			lettercard1 = 'J';
		}
	}
	//generate card 2
	int card2 = rand() % 13 + 2;
	if (card2 > 9)
	{
		if (card2 == 10)
		{
			lettercard2 = 'A';
		}
		else if (card2 == 11)
		{
			lettercard2 = 'K';
		}
		else if (card2 == 12)
		{
			lettercard2 = 'Q';
		}
		else
		{
			lettercard2 = 'J';
		}
	}
		//choose the function based on the type of card given
		if (card1 <= 13, card1 > 9 && card2 <= 13, card2 > 9)
		{
			blackJack(char (lettercard1), char (lettercard2));
		}
		else if (card1 <= 13, card1 > 9 && card2 <= 9)
		{
			blackJack(char (lettercard1), int (card2));
		}
		else if (card2 <= 13, card2 > 9 && card1 <= 9)
		{
			blackJack(int (card1), char (lettercard2));
		}
		else
		{
			blackJack( int (card1), int (card2));
		}
	//starting a loop to continuously ask to draw cards until end conditions are met
	while (runningtotal < 21 && runningtotal > 0)
	{
		cout << "Draw Again (y/n):" << endl;
		cin >> user_response;
		if (user_response == 'n')
		{
			cout << "YOU QUIT WITH " << runningtotal << endl;
			break;
		}
		else if (user_response != 'n' && user_response != 'y')
		{
			cout << "ERROR OCCURED" << endl;
			break;
		}
		else
		{
			int card1 = rand() % 13 + 2;
				if (card1 > 9)
				{
					if (card1 == 10)
					{
						lettercard1 = 'A';
					}
					else if (card1 == 11)
					{
						lettercard1 = 'K';
					}
					else if (card1 == 12)
					{
						lettercard1 = 'Q';
					}
					else
					{
						lettercard1 = 'J';
					}
				}
			if (card1 <= 13 && card1 > 9 )
			{
				blackJack(char (lettercard1));
			}
			else
			{
				blackJack(int (card1));
			}
		}
	}

	if(runningtotal == 21)
		{
			cout << "WON BLACKJACK" << endl;
			return 0;
		}
	else if (runningtotal > 21)
		{
		cout << "FAILED BLACKJACK" << endl;
			return -1;
		}
}
