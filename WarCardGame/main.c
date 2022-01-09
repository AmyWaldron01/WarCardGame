#include <stdio.h>
#include <time.h>   //for random numbers 

//Set Vairbles
#define cards 13
#define suits 13

#define players 4

//trial and error
//const char suits[4] = { 'D', 'C', 'H', 'S' };
//const char values[13] = { '2', '3', '4', '5', '6', '7', '8', '9', 'X', 'J', 'Q', 'K', 'A' };

//funtions
void NewGame();
void PlayGame();
void Menu();

 
void main()
{
	//Varibles
	int startgame;

	//Welcome open screen
	printf("\t---------------------Welcome To The Card Game War---------------------");
	printf("\n\tEnter 0 to start a new game or enter 1 to load a saved game: ");
	scanf("%d",&startgame);

	if (startgame ==0)
	{
		NewGame();
	}
	else if(startgame == 1)
	{
		printf("saved game");
	}
	else
	{
		//gets the user to re enter the numbers
		printf("\n\tWrong number entered Try again");
		printf("\n\t---------------------Welcome To The Card Game War---------------------");
		printf("\n\tEnter 0 to start a new game or enter 1 to load a saved game: ");
		scanf("%d", &startgame);
	}


}//end of main

//Creating a new game
void NewGame()
{
	//Varibles
	int NumPlayers;
	int cardNum;
	int cardSuit;


	printf("\tHow many players are there (2-4): ");
	scanf("%d",&NumPlayers);

	//if the players are greater than 4
	if (NumPlayers > 4)
	{
		printf("Too many players are entered");
		printf("Players have been set to the max (4)");
		//changing it to the max
		NumPlayers = 4;
	}
	//if the players are less than 2
	else if (NumPlayers < 2)
	{
		printf("Too little players are entered");
		printf("Players have been set to the min (2)");
		//changing it to the min
		NumPlayers = 2;
	}

		//////////////////////////////
		// u get 13 cards 1-13 for array
		// repeat ir 4 times
		int TheCards[52] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,    1,2,3,4,5,6,7,8,9,10,11,12,13,    1,2,3,4,5,6,7,8,9,10,11,12,13,    1,2,3,4,5,6,7,8,9,10,11,12,13 };

		//suit array is to assign the cards to the suits
		//For the suits
		//hearts, spades clubs diamonds
		int TheSuits[52] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,          2,2,2,2,2,2,2,2,2,2,2,2,2,      3,3,3,3,3,3,3,3,3,3,3,3,3,          4,4,4,4,4,4,4,4,4,4,4,4,4 };

		//Max player is 4 (2-4)
		//User gets 13 cards
		int UsersCard[players][cards];
		int UsersSuit[players][suits];

		//Cards that have been used
		int Cards_CLICKED[players][cards];

		//Stores the score of the user
		int KeepScore[players] = { 0,0,0,0 };

		//reset used cards back to 0
		for (int i = 0; i < NumPlayers; i++)
		{
			for (int j = 0; j < cards; j++)
			{
				//Make sure each is reset for new game
				Cards_CLICKED[i][j] = 0;
			}
		}

		//Assign player cards in player array
		for (int i = 0; i < NumPlayers; i++)
		{
			//Generate Random cards
			for (int j = 0; j < 13; j++)
			{
				//using random class to get random card and suit
				cardNum = TheCards[rand() % 52];
				cardSuit = TheSuits[rand() % 52];

				//Assign the random cards and suit 
				UsersCard[i][j] = cardNum;
				UsersSuit[i][j] = cardSuit;
			}
		}

		//Play the game
		PlayGame(UsersCard, UsersSuit, NumPlayers, KeepScore, 1, Cards_CLICKED);
}


//playing the game
void PlayGame(int UsersCard[players][cards], int UsersSuit[players][suits], int NumPlayers, int KeepScore[players], int TheRound, int Cards_Clicked[players][cards])
{
	//Assign variables
	int player = 1;
	int ChosenCard;

	int CurrentUser;
	int CardPicked;
	
	//Scoring
	int Score = 0;
	int Winner = 0; 
	int WiningCard = 0;
	
	//Users picked 
	int playerSelectedCard[4][4];
	int playerSelectedSuit[4][4];
	char exit = 'X', round = 'X';////


	//There is 13 rounds
	printf("\nRound %d", TheRound);

	//Players
	CurrentUser = (player - 1);

	//Player __ cards
	printf("\nPlayer %d's Cards \n", player);

	//options of cards in numbers
	for (int i = 0; i < 13; i++)
	{
		if (i < 9)
		{
			printf("    %d:   ", (i + 1));
		}
		//doesnt align correctly unless u do this
		else
		{
			printf("   %d:   ", (i + 1));
		}
	}
	printf("\n");
	 
	//printing out the cards 
	int suit = " ";
	for (int i = 0; i < 14; i++)
	{
		//numSuits = UsersSuit[CurrentUser][i];

		switch (suit)

			case 1: suit = "Hearts";
			break;

			printf("%d %d of %s", i ,UsersCard[CurrentUser][i]);

	}
	
	//At the end of the round loop
	for (int j = 0; j < NumPlayers; j++) 
	{
		CurrentUser;
	}

	////Update Player Counter
	//player++;
//} while (up to 13 rounds)
	


//} while (exit !=)

	//Open menu to decide what to do 


}//end of play game

//the menu options
void Menu()
{
	printf("\n\t--------------------------------MENU--------------------------------");
	printf("\n\t\t CHOOSE AN OPTION BELOW!");
	printf("\n\t\t 1-complete Turn 2-Save and Exit 3-Exit 4-Game Status");
	printf("\n\t--------------------------------------------------------------------");
	
}