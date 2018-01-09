#pragma once
#include <string>
using FString = std::string;
using int32 = int;
#define TMap std::map

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_length,
	Not_Lowercase
};




class FBullCowGame
{
public :	
	FBullCowGame(); // Constructor


	int32 GetMaxTries() const;
	int32 GetCurrentGameTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;


	void Reset();
	FString PrintGameSummary();

	EGuessStatus CheckGuessVaildity(FString) const;


	FBullCowCount SubmitValidGuess(FString);


private :
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bIsGameWon;
	bool IsIsogram(FString) const;
	bool IsLowerCase(FString) const;
};