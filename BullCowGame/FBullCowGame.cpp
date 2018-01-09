#pragma once
#include "FBullCowGame.h"
#include <map>


int32 FBullCowGame::GetMaxTries() const 
{ 
	TMap<int32, int32> WordLengthToMaxTries{ {3,2},{4,5},{5,5},{6,5} };
	return WordLengthToMaxTries[MyHiddenWord.length()]; 
}
int32 FBullCowGame::GetCurrentGameTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bIsGameWon; }

void FBullCowGame::Reset()
{
	MyCurrentTry = 1;

	const FString MY_HIDDEN_WORD = "ant";

	MyHiddenWord = MY_HIDDEN_WORD;

	bIsGameWon = false;

	return;
}

FString FBullCowGame::PrintGameSummary()
{
	if (IsGameWon())
	{
		return "You have won";
	}
	else
	{
		return "Better luck next time";
	}
}


// Receives a valid guess
EGuessStatus FBullCowGame::CheckGuessVaildity(FString Guess) const
{
	if (!IsIsogram(Guess))// not isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowerCase(Guess))// Now lower
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length()!=GetHiddenWordLength())// wrong length
	{
		return EGuessStatus::Wrong_length;
	}
	else 
	{
		return EGuessStatus::OK;
	}
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	// MyCurrentTry Increment
	MyCurrentTry++;

	// setup return variable
	// loop through all the letters as guess
	// compare letter against hidden word
	FBullCowCount bullCowCount;
	int32 HiddenWordLength = MyHiddenWord.length();

	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
	{
		for (int32 GWChar = 0; GWChar < HiddenWordLength; GWChar++)
		{
			if (Guess[GWChar] == MyHiddenWord[MHWChar])
			{
				if (MHWChar == GWChar)
				{
					bullCowCount.Bulls++;
				}
				else
				{
					bullCowCount.Cows++;
				}
				
			}
			else
			{
				
			}
		}
	}
	if (bullCowCount.Bulls == HiddenWordLength)
	{
		bIsGameWon = true;
	}
	else
	{
		bIsGameWon = false;
	}
	return bullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	if (Word.length() <= 1)	{ return true;	}

	TMap<char, bool> LetterSeen;
	for (char letter : Word)
	{
		letter = tolower(letter);

		if (LetterSeen[letter]) { return false; } // if the letter is in the map
		else
		{
			LetterSeen[letter] = true; // add letter to map
		}
	}


	return true;
}

bool FBullCowGame::IsLowerCase(FString Word) const
{
	for (char letter : Word)
	{
		if (!islower(letter))
		{
			return false;
		}
	}
	return true;
}

FBullCowGame::FBullCowGame()
{
	Reset();
}




