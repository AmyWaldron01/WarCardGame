#include <stdio.h>
#include <time.h>   


//funtions
void NewGame();
void PlayGame();

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
		printf("new game");
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

	printf("How many players are there (2-4): ");
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


}//end of newGame

//playing the game
void PlayGame()
{



}//end of play game