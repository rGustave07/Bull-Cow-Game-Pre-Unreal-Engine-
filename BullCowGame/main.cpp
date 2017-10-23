// main.cpp : Defines the entry point for the console application.
//
/* This is the console executable that makes use of the BullCow Class
this acts as the view in an MVC pattern and is responsible for all user interaction.
for game logic see the FBullCowGame Class.
*/

#include "stdafx.h"
#include "fBullCowGame.h"
#include <iostream>
#include <string>

using FText = std::string;
using INT32 = INT32;

void printIntro();
void PlayGame();
FText ObtainValidGuess();
bool AskToPlayAgain();

fBullCowGame BCGame; //instantiated a new game

INT32 main()
{
	do {
		printIntro();
		PlayGame();
	} while (AskToPlayAgain());

    return 0;
}

void PlayGame()
{
	BCGame.Reset();
	INT32 MaxTries = BCGame.GetMaxTries();
	//Loop for the number of turns asking for guesses
	//TODO change from for to while loop once we are validating tries
	for (INT32 i = 0; i < MaxTries; i++)
	{
		INT32 TryIndex = BCGame.GetCurrentTry();
		//TODO make loop check for valid guesses
		FText Guess = ObtainValidGuess();
		//Submit valid guess to the game
		fBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		//Print number of bulls and cows
		std::cout << "Bulls: " << BullCowCount.bulls << std::endl;
		std::cout << "Cows: " << BullCowCount.cows << std::endl;
		std::cout << "try " << TryIndex << "\nYou've guessed: " << Guess << std::endl;
	}

	// TODO Summarise game
}

void printIntro() {
	//Introduce game
	std::cout << "Hello, welcome to Bulls and Cows!\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letters I'm thinking of in the isogram?\n";
	
	return;
}

FText ObtainValidGuess() {
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do
	{
		//Get a guess from the user
		INT32 TryIndex = BCGame.GetCurrentTry();
		std::cout << "\nEnter your guess: ";
		FText Guess = "";
		getline(std::cin, Guess);

		//Check Status and give feedback
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case Not_Isogram:
			std::cout << "There are no repeating letters in the answer.\n";
			break;

		case Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;

		case Not_Lowercase:
			std::cout << "Please enter the word in all lowercase.\n";
			break;

		default:
			return Guess;
			break;
		}
	} while (Status != EGuessStatus::OK); // Loop until valid input
}

bool AskToPlayAgain()
{
	std::cout << "Would you like to play again? (Y/N)\n";
	FText Response = "";
	std::getline(std::cin, Response);
	
	if (Response[0] == 'y' || Response[0] == 'Y') {
		std::cout << "True" << std::endl;
		return true;
	}
	else {
		std::cout << "False" << std::endl;
		return false;
	}
}
