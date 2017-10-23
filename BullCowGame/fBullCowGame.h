#pragma once
#include <string>

using Fstring = std::string;
using INT32 = int;

struct fBullCowCount 
{
	INT32 bulls = 0;
	INT32 cows = 0;
};

enum EGuessStatus {
	Invalid_Status,
	OK,
	Not_Isogram,
	Valid,
	Invalid_Input,
	Wrong_Length,
	Not_Lowercase,

};

class fBullCowGame {
public:
	fBullCowGame();
	INT32 GetMaxTries() const;
	INT32 GetCurrentTry() const;
	INT32 GetHiddenWordLength() const;

	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(Fstring) const;

	void Reset();
	fBullCowCount SubmitValidGuess(Fstring);

private:	
	INT32 MyCurrentTry;
	INT32 MyMaxTries;
	Fstring MyHiddenWord;
	bool bGameIsWon;
	bool IsIsogram(Fstring) const;
	bool IsLowerCase(Fstring) const;
};