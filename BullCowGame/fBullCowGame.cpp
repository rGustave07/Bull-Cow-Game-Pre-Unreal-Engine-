#include "stdafx.h"
#include "fBullCowGame.h"

using INT32 = int;

void fBullCowGame::Reset()
{
	const Fstring HIDDEN_WORD = "planet";
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
			if (UserGuess[i] == MyHiddenWord[j] && UserGuess[j] != MyHiddenWord[i])
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

bool fBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}
