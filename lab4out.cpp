//Zach Brown
//Lab 4 Out
//Write a C++ program that simulates The Price is Right clock game.

//including necessary libraries
#include <iostream>
#include <cstdlib>
#include "graph1.h"

using namespace std;

int main() {

	//Delcaring varibales
	int start_time = 0;
	int current_time = 0;
	int no_secs = 0;
	int timer = current_time - start_time;
	int picture = 0;
	int i = 0;
	double price = 0;
	double guess = 0;
	char choice = ' ';

	
	//Graphics window
	displayGraphics();

	//Initiating random
	srand(time(0));

	//Main loop for program
	do {
		//start time
		start_time = 0;

		// random selection of BMP pictures
		picture = rand() % 10 + 1;

		//random price
		price = rand() % 500 + 500;

		//random selection of prizes based off of random number generation
		if (picture == 1) {

			displayBMP("chair.bmp", 155, 90);
			gout << setPos(155, 345) << "Chair" << endg;
		}
		else if (picture == 2) {

			displayBMP("couch.bmp", 155, 90);
			gout << setPos(155, 345) << "Couch" << endg;
		}
		else if (picture == 3) {

			displayBMP("dodgers.bmp", 155, 90);
			gout << setPos(155, 345) << "Dogder's Tickets for 1 week" << endg;
		}
		else if (picture == 4) {

			displayBMP("freezer.bmp", 155, 90);
			gout << setPos(155, 345) << "Freezer" << endg;
		}
		else if (picture == 5) {

			displayBMP("jukebox.bmp", 155, 90);
			gout << setPos(155, 345) << "Juke Box full of LPs" << endg;
		}
		else if (picture == 6) {

			displayBMP("piano.bmp", 155, 90);
			gout << setPos(155, 345) << "Piano" << endg;
		}
		else if (picture == 7) {

			displayBMP("pooltable.bmp", 155, 90);
			gout << setPos(155, 345) << "Pooltable" << endg;
		}
		else if (picture == 8) {

			displayBMP("powertools.bmp", 155, 90);
			gout << setPos(155, 345) << "Power Tools" << endg;
		}
		else if (picture == 9) {

			displayBMP("recliner.bmp", 155, 90);
			gout << setPos(155, 345) << "Recliner" << endg;
		}
		else if (picture == 10) {

			displayBMP("lawnmowers.bmp", 155, 90);
			gout << setPos(155, 345) << "Lawn Mowers" << endg;
		}

		//30 second timer
		no_secs = 30;

		//main loop for guess
		do {
			cout << "Enter value for prize: ";
			cin >> guess;

			//current time
			current_time = time(0);

			//start timer after the first guess
			if (start_time == 0) {
				start_time = time(0);
			}
			//if prices is higher than guess prints "Higher"
			if (guess < price) {
				gout << setPos(155, 357) << "HIGHER" << endg;
			}
			//if price is lower than guess prints "Lower"
			else if (guess > price) {
				gout << setPos(155, 357) << "LOWER" << endg;
			}
			//if guess = price prints "Winner" and break loop
			else {
				gout << setPos(155, 357) << "WINNER" << endg;

				price = guess;
				break;
			}

			//calculation for time
			timer = current_time - start_time;

			//prints remaining time to graphics window
			gout << setPos(155, 367) << "Time Remaining: " << no_secs - timer << "secs" << endg;

			//if timer runs out prints game over and the correct price of the item.
			if (timer >= no_secs) {
				gout << setPos(155, 357) << "!!!GAME OVER!!!" << endg;
				gout << setPos(155, 377) << "Correct Price: " << price << endg;
				break;
			}
		
		// continue loop as long as guess does not equal price and timer is not less than # of seconds
		} while (guess != price && timer < no_secs);

		//allows the user to play again
		cout << "Would you like to play again? (y/n)";
		cin >> choice;

		//clears system and graphics if y or Y is selected
		if (choice == 'y' || choice == 'Y') {
			//Clear all graphics
			clearGraphics();
			system("cls");
		}
		else {
			choice = ' ';
			clearGraphics();
		}

		//if user selects y or Y then the loop game repeats
	} while (choice == 'y' || choice == 'Y');

return 0;
	
}

