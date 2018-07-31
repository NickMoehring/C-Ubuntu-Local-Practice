/*
 * [X] Intro program and prompt user for high and low bounds bounds
 * [] gen rand int
 * [] prompt for guess
 * [] save guess and num guesses
 * [] tell user if high or low guess
 * [] loop guessing untill correct
 * [] print number of guesses ask if they want guess history
 * [] if y display rand num, then guesses with guess number below
 * [] loop guessing untill user prompts n
 */

#include <iostream>
#include <cstdlib>

int main(void)
{
	int highBound;
	int lowBound;
	int ans;

	std::cout << "Hello, this is a number guessing game. What two integers would you like to guess between? (low then high, sperate with a space and hit enter)\n";

	std::cin >> lowBound;
	std::cin >> highBound;

	ans = rand() % (highBound - lowBound) + lowBound; // generates a rand num in bounds

	/*TESTING*/std::cout << "\nlowbound: " << lowBound << "       highbound: " << highBound << "        rand num: " << ans << std::endl;


	return 0;
}
