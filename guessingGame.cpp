/*
 * File Name: guessingGame.cpp
 * Purpose: Just c++ practice after intro to programing ended, first project using git
 *
 * [X] Intro program and prompt user for high and low bounds bounds
 * [X] gen rand int
 * [X] prompt for guess
 * [X] save guess and num guesses
 * [X] tell user if high or low guess
 * [X] loop guessing untill correct
 * [X] print number of guesses ask if they want guess history
 * [X] if y display rand num, then guesses with guess number below
 * [X] loop guessing untill user prompts n
 */

#include <iostream> // cin cout
#include <cstdlib> // rand()
#include <vector> // vector class
#include <iomanip> // setw()

int main(void)
{
	int highBound;
	int lowBound;
	int ans;
	int guess;
	char prompt;

	std::cout << "\nHello, this is a number guessing game.";

	do {
		char histPrompt;
		std::vector<int> guesses;

		std::cout << "\nWhat two integers would you like to guess between? (seperate them with a space and hit enter)\n";
		std::cin >> lowBound;
		std::cin >> highBound;

		if (lowBound > highBound) { // if user enters highBound first they will be swapped
			lowBound = lowBound + highBound;
			highBound = lowBound - highBound;
			lowBound = lowBound - highBound;
		}

		ans = rand() % (highBound - lowBound) + lowBound; // generates a rand int in bounds

		///*TESTING*/std::cout << "\nlowbound: " << lowBound << "       highbound: " << highBound << "        rand num: " << ans << std::endl;

		std::cout << "Please enter a guess in integer form: ";

		do {
			std::cin >> guess;
			guesses.push_back(guess);

			if (guess < ans)
				std::cout << "Thats too low! Make another guess: ";
			else if (guess > ans)
				std::cout << "Thats too high! Make another guess: ";
		}
		while (guess != ans);

		std::cout << "Congratulations, it was " << ans << ", and it only took " << guesses.size() << " guesses!\n";

		std::cout << "Would you like to see your guess history? (y/n): ";
		std::cin >> histPrompt;
		if (histPrompt == 'y' || histPrompt == 'Y') {

			std::cout << "Guess:      | ";
			for (unsigned int i = 0; i < guesses.size(); i ++)
				std::cout << std::setw(6) << guesses[i] << " | ";

			std::cout << "\n";

			std::cout << "Num. Tries: | ";
			for (unsigned int j = 1; j <= guesses.size(); j++)
				std::cout << std::setw(6) << j << " | ";
		}

		std::cout << "\nWould you like to play again? (y/n): ";
		std::cin >> prompt;
	}
	while (prompt == 'Y' || prompt == 'y');

	std::cout << "Goodbye." << std::endl;

	return 0;
}
