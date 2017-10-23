#include "stdafx.h"
#include "fBullCowGame.h"
#include <map>
#define TMap std::map

using INT32 = int;

void fBullCowGame::Reset()
{
	const Fstring HIDDEN_WORD = "puck";
	MyHiddenWord = HIDDEN_WORD;

	constexpr INT32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}

fBullCowGame::fBullCowGame()
{
	Reset();
}

INT32 fBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

INT32 fBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

INT32 fBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

fBullCowCount fBullCowGame::SubmitValidGuess(Fstring UserGuess)
{
	MyCurrentTry++;
	fBullCowCount BullCowCount;

	//loop through all letters in hidden word and guess
	for (INT32 i = 0; i < UserGuess.length(); i++)
	{
		if (UserGuess[i] == MyHiddenWord[i])
		{
				BullCowCount.bulls++;
		}
		for (INT32 j = 0; j < UserGuess.length(); j++)
		{
			if (UserGuess[i] == MyHiddenWord[j] && i != j)
			{
				BullCowCount.cows++;
			}
		}
	}
	if (BullCowCount.bulls == MyHiddenWord.length())
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}

	return BullCowCount;
}

bool fBullCowGame::IsIsogram(Fstring Guess) const
{
	if (Guess.length() <= 1)
	{
		return true;
	}
	//Create hashtable
	//compare letter to table
	TMap<char, bool> LetterSeen;
	for (auto Letter : Guess)
	{
		Letter = tolower(Letter);
		if (LetterSeen[Letter]){
			return false;
		} else {
			// add The letter to the map as seen
			LetterSeen[Letter] = true;
		}
	}
	// if letter matches mark it
	// if letter gets two matches return false
	return true;
}

bool fBullCowGame::IsLowerCase(Fstring Guess) const
{
	for (auto Letter : Guess)
	{
		if (islower(Letter))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool fBullCowGame::IsGameWon() const
{
	return bGameIsWon;
}

EGuessStatus fBullCowGame::CheckGuessValidity(std::string Guess) const
{
	// If the guess isn't an isogram, return an error
	if (!IsIsogram(Guess))
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowerCase(Guess)) //if the guess isn't all lower case
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}

	return EGuessStatus::OK; //TODO make actual error;
}
