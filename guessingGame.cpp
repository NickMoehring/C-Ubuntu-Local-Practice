/*
 * [X] Intro program and prompt user for high and low bounds bounds
 * [X] gen rand int
 * [X] prompt for guess
 * [] save guess and num guesses
 * [X] tell user if high or low guess
 * [X] loop guessing untill correct
 * [] print number of guesses ask if they want guess history
 * [] if y display rand num, then guesses with guess number below
 * [X] loop guessing untill user prompts n
 */

#include <iostream>
#include <cstdlib>

int main(void)
{
	int highBound;
	int lowBound;
	int ans;
	int guess;
	char prompt;

	std::cout << "\nHello, this is a number guessing game.";

	do {
		std::cout << "\nWhat two integers would you like to guess between?\n";
		std::cout << "(low then high, sperate with a space and hit enter)\n";
		std::cin >> lowBound;
		std::cin >> highBound;

		ans = rand() % (highBound - lowBound) + lowBound; // generates a rand num in bounds

		/*TESTING*/std::cout << "\nlowbound: " << lowBound << "       highbound: " << highBound << "        rand num: " << ans << std::endl;

		std::cout << "Please enter a guess in integer form: ";

		do {
			std::cin >> guess;

			if (guess < ans)
				std::cout << "Thats too low! Make another guess: ";
			else if (guess > ans)
				std::cout << "Thats too high! Make another guess: ";
		}
		while (guess != ans);

		std::cout << "Congratulations, it was " << ans << "! Would you like to play again? (y/n): ";
		std::cin >> prompt;
	}
	while (prompt == 'Y' || prompt == 'y');

	std::cout << "Goodbye." << std::endl;

	return 0;
}
