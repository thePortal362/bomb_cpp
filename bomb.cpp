#include <iostream>
#include <string>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <cstdlib>

using namespace std;

void typeEffect(const string& text, int delayMs = 50) {
	for (char c : text) {
		cout << c << flush;
		this_thread::sleep_for(std::chrono::milliseconds(delayMs));
	}
}

void codecorrect() {
	system("clear");
	typeEffect("\033[32mBomb armed!\n", 50);
	this_thread::sleep_for(chrono::milliseconds(205));
	typeEffect("To dearm type dearm: \n", 50);
	string dearmChoice;
	typeEffect(">", 50);
	cin >> dearmChoice;
	if (dearmChoice == "dearm") {
		system("clear");
		this_thread::sleep_for(chrono::milliseconds(100));
		typeEffect("Bomb dearmed!\n");
	} else {
		codecorrect();
	}
}

void codefalse() {
	system("clear");
	typeEffect("\033[31mFailed to arm bomb\n", 50);
}

void askcode() {
	system("clear");
	typeEffect("Bomb Version 0.0.1\n", 100);
	cout << flush;
	this_thread::sleep_for(chrono::milliseconds(1000));
	typeEffect("Provide Code to arm Bomb: \n", 50);
	typeEffect(">", 50);
	string code;
	cin >> code;
	if (code == "734567") {
		codecorrect();
	} else {
		codefalse();
	}
}


int main() {
	cout << "\033[31m";
	askcode();
	cout << "\033[0m";
	return 0;
}
