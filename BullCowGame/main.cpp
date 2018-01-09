#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using Ftext = std::string;
using int32 = int;

int32 double_num()
{
	return 0;
}

void PrintIntro();

void PlayGame();
Ftext GetValidGuess();
bool AskToPlayAgain();

// Instantiate a new game
FBullCowGame BCGame;



int main()
{
	PrintIntro();
	do
	{
		PlayGame();
	} while (AskToPlayAgain());

	double_num();
}


void PrintIntro()
{
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << std::endl;
	std::cout << "          }   {         ___ " << std::endl;
	std::cout << "          (o o)        (o o) " << std::endl;
	std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
	std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
	std::cout << " *  |-,--- |              |------|  * " << std::endl;
	std::cout << "    ^      ^              ^      ^ " << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;	
}

void PlayGame()
{
	BCGame.Reset();

	int32 MaxTries = BCGame.GetMaxTries();

	while (!BCGame.IsGameWon() && BCGame.GetCurrentGameTry()<=BCGame.GetMaxTries())
	{
		
		FString Guess = "";

		Guess = GetValidGuess();




		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls Count :" << BullCowCount.Bulls;
		std::cout << "   Cows Count :" << BullCowCount.Cows << std::endl;

		//std::cout << "Now you have entered " << Guess << std::endl;
	}

	// TODO Add game details
	std::cout << BCGame.PrintGameSummary() << "\n";
	return;
}

// loop till u get valid guess
Ftext GetValidGuess()
{
	int32 CurrentTry = BCGame.GetCurrentGameTry();
	Ftext Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do
	{
		std::cout << "TRy No. " << CurrentTry <<" of "<< BCGame.GetMaxTries() << "..............Enter text:" << std::endl;
		getline(std::cin, Guess);
		Status = BCGame.CheckGuessVaildity(Guess);

		switch (Status)
		{
		case EGuessStatus::OK:
			return Guess;
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "PLease enter word without repeating letter" << "\n";
			break;
		case EGuessStatus::Wrong_length:
			std::cout << "PLease enter word of length :" << BCGame.GetHiddenWordLength() << "\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "PLease enter word with lower case letter only" << "\n";
			break;
		default:			
			break;
		}
	} while (Status != EGuessStatus::OK);
	
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do u want 2 play again (y/n)?" ;
	Ftext response = "";
	std::getline(std::cin, response);
	return ((response[0] == 'y') || (response[0] == 'Y'));
}
