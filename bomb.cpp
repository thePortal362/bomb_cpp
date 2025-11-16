#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>

using namespace std;

#ifdef _WIN32
    string clr = "cls";
#elif __linux__
    string clr = "clear";
#endif

void typeEffect(const string& text, int delayMs = 50) {
	for (char c : text) {
		cout << c << flush;
		this_thread::sleep_for(std::chrono::milliseconds(delayMs));
	}
}

void codecorrect() {
	system(clr.c_str());
	typeEffect("\033[32mBomb armed!\n", 50);
	this_thread::sleep_for(chrono::milliseconds(205));
	system(clr.c_str());
    for (int countdown = 15; countdown > 0; countdown--) {
        typeEffect("Bomb exploding in ");
        typeEffect(to_string(countdown));
        this_thread::sleep_for(chrono::milliseconds(900));
        system(clr.c_str());
    }
    system(clr.c_str());
    typeEffect("\033[0mBomb exploded!\n", 200);
    this_thread::sleep_for(chrono::milliseconds(2000));
}

void codefalse() {
	system(clr.c_str());
	typeEffect("\033[31mFailed to arm bomb\n", 50);
}

void askcode() {
	system(clr.c_str());
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
