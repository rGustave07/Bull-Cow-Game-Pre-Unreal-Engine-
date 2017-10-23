#include "stdafx.h"
#include "fBullCowGame.h"

using INT32 = int;

void fBullCowGame::Reset()
{
	const Fstring HIDDEN_WORD = "puck";
	MyHiddenWord = HIDDEN_WORD;

	constexpr INT32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	MyCurrentTry = 1;
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

fBullCowCount fBullCowGame::SubmitGuess(Fstring UserGuess)
{
	//Increment the turn number
	MyCurrentTry++;
	//setup a return variable
	fBullCowCount BullCowCount;
	//Loop through all letters in guess
		//compare letters against hidden word
			//if theyy match then
				// increment bulls if they're in the same place
				// increment cows if not
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

	return BullCowCount;
}

bool fBullCowGame::IsGameWon() const
{
	return false;
}

EGuessStatus fBullCowGame::CheckGuessValidity(std::string Guess) const
{
	// If the guess isn't an isogram, return an error
	if (false)
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false) //if the guess isn't all lower case
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
