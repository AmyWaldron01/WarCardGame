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
	int CurrentUser = 0;


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
		PlayGame(CurrentUser,UsersCard, UsersSuit, NumPlayers, KeepScore, 1, Cards_CLICKED);

		//Redoing for new games
		//printing out the cards 
		//dont need this
		//put in play game
		//int suit = " ";
		//for (int i = 0; i < 14; i++)
		//{
		//	suit = UsersSuit[CurrentUser][i];

		//	switch (suit)
		//		//do this with every suit
		//	case 1: suit = "Hearts";
		//	break;

		//	printf("%d %d of %s", i, UsersCard[CurrentUser][i], suit);

		//}

		////At the end of the round loop
		//for (int j = 0; j < NumPlayers; j++)
		//{
		//	CurrentUser++;
		//}
}


//playing the game
void PlayGame(int CurrentUser, int UsersCard[players][cards], int UsersSuit[players][suits], int NumPlayers, int KeepScore[players], int TheRound, int Cards_Clicked[players][cards])
{
	//Assign variables
	int player = 1;
	int ChosenCard;
	int numSuits = 13;

	int CardPicked;

	//Scoring
	int Score = 0;
	int Winner = 0;
	int WiningCard = 0;

	//Users picked 
	int UserSelectedCard[4][4];
	int UserSelectedSuit[4][4];
	char exit = 'E', round = 'R';////

	do {

		do {
			//There is 13 rounds
			printf("\nRound %d", TheRound);

			//Player __ cards
			printf("\nPlayer %d's Cards \n", player);

			//TRYING TO GET THIS TO WORK---------------------------------------
			//printing out the cards 
			int suit = 0;
			for (int i = 1; i < 14; i++)
			{
				//printf("%d", UsersCard[0][i]);
				suit = UsersSuit[CurrentUser][i];

				switch (suit)
				{
					//do this with every suit
				case 1: printf("\n%d. %d of Hearts", i, UsersCard[CurrentUser][i]);
					break;

				case 2: printf("\n%d. %d of Diamonds", i, UsersCard[CurrentUser][i]);
					break;

				case 3: printf("\n%d. %d of Spades", i, UsersCard[CurrentUser][i]);
					break;

				case 4: printf("\n%d. %d of Clubs", i, UsersCard[CurrentUser][i]);
					break;


				}//switch

			}

			// ask user to pick card
			printf("\nplease pick a card (or 0 to exit) : ");
			scanf("%d", &ChosenCard);

			/*if (ChosenCard==0)
			{
				printf("GOODBYE");
			}*/

			//IF user trying to play a used card
			while (UsersCard[CurrentUser][(ChosenCard - 1)] == 1)
			{
				printf("\nCard has been used");

				// ask user to pick card
				printf("\nplease pick a card (or 0 to exit) : ");
				scanf("%d", &ChosenCard);
			}

			//Saving user card
			switch (ChosenCard)
			{
			case 1:
				//Save Selected Card Details
				UserSelectedCard[CurrentUser][CurrentUser] = UsersCard[CurrentUser][0];
				UserSelectedSuit[CurrentUser][CurrentUser] = UsersCard[CurrentUser][0];

				//card set to played
				UsersCard[CurrentUser][0] = 0;
				UsersSuit[CurrentUser][0] = 0;

				break;

			case 2:
				//Save Selected Card Details
				UserSelectedCard[CurrentUser][CurrentUser] = UsersCard[CurrentUser][1];
				UserSelectedSuit[CurrentUser][CurrentUser] = UsersCard[CurrentUser][1];

				//card set to played
				UsersCard[CurrentUser][1] = 0;
				UsersSuit[CurrentUser][1] = 0;

				break;

			case 3:
				//Save Selected Card Details
				UserSelectedCard[CurrentUser][CurrentUser] = UsersCard[CurrentUser][2];
				UserSelectedSuit[CurrentUser][CurrentUser] = UsersCard[CurrentUser][2];

				//card set to played
				UsersCard[CurrentUser][2] = 0;
				UsersSuit[CurrentUser][2] = 0;

				break;

			case 4:
				//Save Selected Card Details
				UserSelectedCard[CurrentUser][CurrentUser] = UsersCard[CurrentUser][3];
				UserSelectedSuit[CurrentUser][CurrentUser] = UsersCard[CurrentUser][3];

				//card set to played
				UsersCard[CurrentUser][3] = 0;
				UsersSuit[CurrentUser][3] = 0;

				break;

			case 5:
				//Save Selected Card Details
				UserSelectedCard[CurrentUser][CurrentUser] = UsersCard[CurrentUser][4];
				UserSelectedSuit[CurrentUser][CurrentUser] = UsersCard[CurrentUser][4];

				//card set to played
				UsersCard[CurrentUser][4] = 0;
				UsersSuit[CurrentUser][4] = 0;

				break;

			case 6:
				//Save Selected Card Details
				UserSelectedCard[CurrentUser][CurrentUser] = UsersCard[CurrentUser][5];
				UserSelectedSuit[CurrentUser][CurrentUser] = UsersCard[CurrentUser][5];

				//card set to played
				UsersCard[CurrentUser][5] = 0;
				UsersSuit[CurrentUser][5] = 0;

				break;

			case 7:
				//Save Selected Card Details
				UserSelectedCard[CurrentUser][CurrentUser] = UsersCard[CurrentUser][6];
				UserSelectedSuit[CurrentUser][CurrentUser] = UsersCard[CurrentUser][6];

				//card set to played
				UsersCard[CurrentUser][6] = 0;
				UsersSuit[CurrentUser][6] = 0;

				break;

			case 8:
				//Save Selected Card Details
				UserSelectedCard[CurrentUser][CurrentUser] = UsersCard[CurrentUser][7];
				UserSelectedSuit[CurrentUser][CurrentUser] = UsersCard[CurrentUser][7];

				//card set to played
				UsersCard[CurrentUser][7] = 0;
				UsersSuit[CurrentUser][7] = 0;

				break;

			case 9:
				//Save Selected Card Details
				UserSelectedCard[CurrentUser][CurrentUser] = UsersCard[CurrentUser][8];
				UserSelectedSuit[CurrentUser][CurrentUser] = UsersCard[CurrentUser][8];

				//card set to played
				UsersCard[CurrentUser][8] = 0;
				UsersSuit[CurrentUser][8] = 0;

				break;

			case 10:
				//Save Selected Card Details
				UserSelectedCard[CurrentUser][CurrentUser] = UsersCard[CurrentUser][9];
				UserSelectedSuit[CurrentUser][CurrentUser] = UsersCard[CurrentUser][9];

				//card set to played
				UsersCard[CurrentUser][9] = 0;
				UsersSuit[CurrentUser][9] = 0;

				break;

			case 11:
				//Save Selected Card Details
				UserSelectedCard[CurrentUser][CurrentUser] = UsersCard[CurrentUser][10];
				UserSelectedSuit[CurrentUser][CurrentUser] = UsersCard[CurrentUser][10];

				//card set to played
				UsersCard[CurrentUser][10] = 0;
				UsersSuit[CurrentUser][10] = 0;

				break;

			case 12:
				//Save Selected Card Details
				UserSelectedCard[CurrentUser][CurrentUser] = UsersCard[CurrentUser][11];
				UserSelectedSuit[CurrentUser][CurrentUser] = UsersCard[CurrentUser][11];

				//card set to played
				UsersCard[CurrentUser][11] = 0;
				UsersSuit[CurrentUser][11] = 0;

				break;

			case 13:
				//Save Selected Card Details
				UserSelectedCard[CurrentUser][CurrentUser] = UsersCard[CurrentUser][12];
				UserSelectedSuit[CurrentUser][CurrentUser] = UsersCard[CurrentUser][12];

				//card set to played
				UsersCard[CurrentUser][12] = 0;
				UsersSuit[CurrentUser][12] = 0;

				break;
			}//end of switch

			//saving the choice to varible ----------------------------------------------
			ChosenCard = UserSelectedCard[CurrentUser][CurrentUser];

			//Set point decide by Card Choice
			switch (ChosenCard)
			{
			case 1:
				Score += 14;
				break;

			case 2:
				Score += 2;
				break;

			case 3:
				Score += 3;
				break;

			case 4:
				Score += 4;
				break;

			case 5:
				Score += 5;
				break;

			case 6:
				Score += 6;
				break;

			case 7:
				Score += 7;
				break;

			case 8:
				Score += 8;
				break;

			case 9:
				Score += 9;
				break;

			case 10:
				Score += 10;
				break;

			case 11:
				Score += 11;
				break;

			case 12:
				Score += 12;
				break;

			case 13:
				Score += 13;
				break;
			}

			//when minus number is entered
			if (ChosenCard == 0)
			{
				//exit round
				round = 'R';

				//exit - ente menu
				exit = 'E';


			}

			//OVER PLAYEr COUNT
			if (player > NumPlayers)
			{
				//RESETING
				player = 0;

				//EXIT LOOP
				round = 'R';
			}
			//updates players  
			player++;

		} while (round != 'R');


	}while (exit!="E");


			//	//At the end of the round loop
		//for (int j = 0; j < NumPlayers; j++)
		//{
		//	CurrentUser;
		//}

		////Update Player Counter
		//player++;
	//} while (up to 13 rounds)



	//} while (exit !=)

		//Open menu to decide what to do 


	} //end of play game


//the menu options
void Menu()
{
	printf("\n\t--------------------------------MENU--------------------------------");
	printf("\n\t\t CHOOSE AN OPTION BELOW!");
	printf("\n\t\t 1-complete Turn 2-Save and Exit 3-Exit 4-Game Status");
	printf("\n\t--------------------------------------------------------------------");
	
}