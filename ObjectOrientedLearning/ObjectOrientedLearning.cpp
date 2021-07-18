#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <exception>
#include <list>
#include <vector>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <windows.h>
#include <numeric>
#include <fstream>

int main();
class dice
{
public:
	// This is to check which dice will be used and rolled based off the amount of times they want to rule it
	int rolling(int rolls_dSix = 0, int rolls_dTen = 0, int rolls_dTwenty = 0)
	{
		std::string d_Six = "dSix:: ";
		std::string d_Ten = "dTen:: ";
		std::string d_Twenty = "dTwenty:: ";
		std::vector<int> dSix;
		std::vector<int> dTen;
		std::vector<int> dTwenty;
		//DSix Config
		if (rolls_dSix != 0) {
			int rolls = 0;
			while (rolls_dSix > rolls) {
				dSix.push_back(rolldSix());
				rolls++;
				int sleep_t = rolls_dSix * 2;
				Sleep(sleep_t);
			}
			std::cout << "dSix Rolls: ";
			int sum = 0;
			sum = std::accumulate(dSix.begin(), dSix.end(), sum);
			std::cout << sum << std::endl;
		}
		else
		{
			std::cout << "dSix was not rolled." << std::endl;
		}
		//DTen Config
		if (rolls_dTen != 0) {
			int rolls = 0;
			while (rolls_dTen > rolls) {
				dTen.push_back(rolldTen());
				rolls++;
				int sleep_t = rolls_dTen * 2;
				Sleep(sleep_t);
			}
			std::cout << "dTen Rolls: ";
			int sum = 0;
			sum = std::accumulate(dTen.begin(), dTen.end(), sum);
			std::cout << sum << std::endl;
		}
		else
		{
			std::cout << "dTen was not rolled." << std::endl;
		}
		//DTwenty Config
		if (rolls_dTwenty != 0) {
			int rolls = 0;
			while (rolls_dTwenty > rolls) {
				dTwenty.push_back(rolldTwenty());
				rolls++;
				int sleep_t = rolls_dTwenty * 2;
				Sleep(sleep_t);
			}
			std::cout << "dTwenty Rolls: ";
			int sum = 0;
			sum = std::accumulate(dTwenty.begin(), dTwenty.end(), sum);
			std::cout << sum << std::endl;
		}
		else
		{
			std::cout << "dTwenty was not rolled." << std::endl;
		}
		return 0;
	}
private:
	//Random dSix Roll
	int rolldSix() {
		srand(GetTickCount64());
		int val1 = (rand() % 6) + 1;
		return(val1);
	}
	//Random dTen Roll
	int rolldTen() {
		srand(GetTickCount64());
		int dTen = (rand() % 10) + 1;
		return dTen;
	}
	//Random dTwenty Roll
	int rolldTwenty() {
		srand(GetTickCount64());
		int dTwenty = (rand() % 20) + 1;
		return dTwenty;
	}
};
//Die out of range exception
struct dieException : public std::exception {
	const char* what() const throw () {
		return "Invalid amount of die, the limit is 10";
	}
};
//User Input not char exception
struct usrIput : public std::exception {
	const char* what() const throw () {
		return "Invalid Input, Type CHAR required 'A' 'B' 'C' ";
	}
};
struct usrIputCont : public std::exception {
	const char* what() const throw () {
		return "Invalid Input, Type (y or n) required";
	}
};
// Main Function
void user_select() {
	dice diceObj;
	int dSix;
	int dTen;
	int dTwenty;
	char choice;
	std::string choices[] = { "A:) D6\n", "B:) D10\n", "C:) D20\n", "D:) D6 & D10\n","E:) D6 & D20\n","F:) D10 & D20\n", "G:) All\n" }; //List of dice choices
	for (auto i : choices) { //List out all choices for the user
		std::cout << i;
	}
	std::cin >> choice;
	choice = toupper(choice);// nullifying lowecase charicters
	//std::cout << choice << std::endl;
	std::cin.clear();
	do {
		try {
			if (choice != 'A' && choice != 'B' && choice != 'C' && choice != 'D' && choice != 'E' && choice != 'F' && choice != 'G') {
				throw usrIput();
			}
			switch (choice)
			{
			case 'A': //DSix Instance
				std::cout << "How many instances of this die would you like to roll?" << std::endl;
				std::cin >> dSix;
				if (dSix > 10) {
					throw dieException(); // throw range exception
				}
				diceObj.rolling(dSix, 0, 0);
				break;
			case 'B': //DTen Instance
				std::cout << "How many instances of this die would you like to roll?" << std::endl;
				std::cin >> dTen;
				if (dTen > 10) {
					throw dieException(); // throw range exception
				}
				diceObj.rolling(0, dTen, 0);
				break;
			case 'C': //DTwenty Instance
				std::cout << "How many instances of this die would you like to roll?" << std::endl;
				std::cin >> dTwenty;
				if (dTwenty > 10) {
					throw dieException(); // throw range exception
				}
				diceObj.rolling(0, 0, dTwenty);
				break;
			case 'D': //DSix and DTen Instances
				std::cout << "How many instances of these dice would you like to roll?" << std::endl;
				std::cout << "dSix: ";
				std::cin >> dSix;
				std::cin.clear();
				std::cout << "dTen: ";
				std::cin >> dTen;
				std::cin.clear();
				if (dSix > 10 || dTen > 10) {
					throw dieException(); // throw range exception
				}
				diceObj.rolling(dSix, dTen, 0);
				break;
			case 'E': //DSix and DTwenty Instances
				std::cout << "How many instances of these dice would you like to roll?" << std::endl;
				std::cout << "dSix: ";
				std::cin >> dSix;
				std::cin.clear();
				std::cout << "dTwenty: ";
				std::cin >> dTwenty;
				std::cin.clear();
				if (dSix > 10 || dTwenty > 10) {
					throw dieException(); // throw range exception
				}
				diceObj.rolling(dSix, 0, dTwenty);
				break;
			case 'F'://DTen and DTwenty Instances
				std::cout << "How many instances of these dice would you like to roll?" << std::endl;
				std::cout << "dTen: ";
				std::cin >> dTen;
				std::cin.clear();
				std::cout << "dTwenty: ";
				std::cin >> dTwenty;
				std::cin.clear();
				if (dTen > 10 || dTwenty > 10) {
					throw dieException(); // throw range exception
				}
				diceObj.rolling(0, dTen, dTwenty);
				break;
			case 'G': //All Dice Instances
				std::cout << "How many instances of this die would you like to roll?" << std::endl;
				std::cout << "dSix";
				std::cin >> dSix;
				std::cin.clear();
				std::cout << "dTen: ";
				std::cin >> dTen;
				std::cin.clear();
				std::cout << "dTwenty: ";
				std::cin >> dTwenty;
				std::cin.clear();
				if (dSix > 10 || dTen > 10 || dTwenty > 10) {
					throw dieException(); // throw range exception
				}
				diceObj.rolling(dSix, dTen, dTwenty);
				break;
			default:
				std::cout << "If you trigger this you royally screwed something up...." << std::endl;
				main();
			}
		}
		catch (usrIput& e)
		{
			std::cout << e.what() << std::endl;
			user_select(); // rerun user_select if invalid values
		}
		catch (dieException& e)
		{
			std::cout << e.what() << std::endl;
			continue;
		}
		break;
	} while (true);
	do
	{
		try {
			std::cout << "Would you like to rerun this program? (y/n): ";
			std::cin.clear();
			char cont;
			std::cin >> cont;
			cont = tolower(cont);
			if (cont != 'y' && cont != 'n') {
				throw usrIputCont();
			}
			else if (cont == 'y')
			{
				main();
			}
			else
			{
				break;
			}
		}
		catch (usrIputCont& e) {
			std::cout << e.what() << std::endl;
			continue;
		}
		break;
	} while (true);
	system("pause");
}

std::string getFileContents(std::ifstream& File)
{
	std::string Lines = "";        //All lines

	if (File)                      //Check if everything is good
	{
		while (File.good())
		{
			std::string TempLine;                  //Temp line
			std::getline(File, TempLine);        //Get temp line
			TempLine += "\n";                      //Add newline character

			Lines += TempLine;                     //Add newline
		}
		return Lines;
	}
	else                           //Return error
	{
		return "ERROR File does not exist.";
	}
}

int main() {
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);

	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 800, 600, TRUE);

	std::ifstream Reader("banner.txt");             //Open file

	std::string Art = getFileContents(Reader);       //Get file

	std::cout << Art << std::endl;               //Print it to the screen

	Reader.close();                           //Close file

	std::cout << "Please enter the dice combination you would like to use: " << std::endl;
	user_select();
}