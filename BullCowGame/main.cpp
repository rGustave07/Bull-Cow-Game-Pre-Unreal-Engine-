// main.cpp : Defines the entry point for the console application.
//
/* This is the console executable that makes use of the BullCow Class
this acts as the view in an MVC pattern and is responsible for all user interaction.
for game logic see the FBullCowGame Class.
*/

#pragma once
#include "stdafx.h"
#include "fBullCowGame.h"
#include <iostream>
#include <string>

//To make syntax unreal friendly
using FText = std::string;
using INT32 = INT32;

void printIntro();
void PlayGame();
void PrintGameSummary();
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

//Plays game instance
void PlayGame()
{
	BCGame.Reset();
	INT32 MaxTries = BCGame.GetMaxTries();
	while ( !BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		INT32 TryIndex = BCGame.GetCurrentTry();
		FText Guess = ObtainValidGuess();
		//Submit valid guess to the game
		fBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		std::cout << "Bulls: " << BullCowCount.bulls << std::endl;
		std::cout << "Cows: " << BullCowCount.cows << std::endl;
		std::cout << "try " << TryIndex << " of " << BCGame.GetMaxTries() << "\nYou've guessed: " << Guess << std::endl;
	}

	// TODO Summarise game
	return;
}

void printIntro() {
	std::cout << "_________                                          .___ __________      .__  .__          " << std::endl;
	std::cout << "\\_   ___ \\  ______  _  ________ _____    ____    __| _/ \\______   \\__ __|  | |  |   ______" << std::endl;
	std::cout << "/    \\  \\/ /  _ \\ \\/ \\/ /  ___/ \\__  \\  /    \\  / __ |   |    |  _/  |  \\  | |  |  /  ___/" << std::endl;
	std::cout << "\\     \\___(  <_> )     /\\___ \\   / __ \\|   |  \\/ /_/ |   |    |   \\  |  /  |_|  |__\___ \\ " << std::endl;
	std::cout << " \\______  /\\____/ \\/\\_//____  > (____  /___|  /\\____ |   |______  /____/|____/____/____  >" << std::endl;
	std::cout << "        \\/                  \\/       \\/     \\/      \\/          \\/                     \\/ " << std::endl;

	std::cout << "Hello, welcome to Cows and Bulls!\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letters I'm thinking of in the isogram?\n";
	
	return;
}

FText ObtainValidGuess() {
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FText Guess = "";
	do
	{
		//Get a guess from the user
		INT32 TryIndex = BCGame.GetCurrentTry();
		std::cout << "\nEnter your guess: ";
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
			//Assume the guess is valid
			break;
		}
	} while (Status != EGuessStatus::OK); // Loop until valid input
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Would you like to play again? (Y/N)\n";
	FText Response = "";
	std::getline(std::cin, Response);
	
	if (Response[0] == 'y' || Response[0] == 'Y') {
		std::cout << "\n\n" << std::endl;
		return true;
	}
	else {
		std::cout << "\n\n" << std::endl;
		return false;
	}
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "Well done! Congratulations.\n";
	}
	else
	{
		std::cout << "Better luck next time\n";
	}
}
