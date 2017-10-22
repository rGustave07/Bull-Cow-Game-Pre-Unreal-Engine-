#pragma once
#include <string>

using Fstring = std::string;
using INT32 = int;

struct fBullCowCount 
{
	INT32 bulls = 0;
	INT32 cows = 0;
};

class fBullCowGame {
public:
	fBullCowGame(); //constructor
	INT32 GetMaxTries() const;
	INT32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); //Make a more rich return value
	bool CheckGuessValidity(Fstring); //TODO Make more rich return value
	//provide a method for counting bulls and cows and incrementing turn number
	//Counts bull & cows assuming valid guess
	fBullCowCount SubmitGuess(Fstring);

private:	
	INT32 MyCurrentTry;
	INT32 MyMaxTries;
	Fstring MyHiddenWord;
};