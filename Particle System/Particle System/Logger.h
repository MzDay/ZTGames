#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <ctime>
#include <iomanip>

class Logger {
public:
	void logError(const std::string& msg) {
		printMsg("ERROR: " + msg, RED, true);
	}

	void logInfo(const std::string& msg) {
		printMsg("Info: " + msg, CYAN, true);
	}
	
	void logWarning(const std::string& msg) {
		printMsg("WARNING: " + msg, YELLOW, true);
	}

	void logSuccess(const std::string& msg) {
		printMsg("SUCCESS: " + msg, LIGHTGREEN, true);
	}

	void logSimple(const std::string& msg) {
		printMsg(msg, WHITE, true);
	}

private:
	void printMsg(const std::string& msg, int color, bool isError)
	{
		setColor(color);
		printTime();
		if (isError)
			std::cerr << " " << msg << '\n';
		else
			std::cout << " " << msg << '\n';
	}

	void setColor(int c) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;

		GetConsoleScreenBufferInfo(hConsole, &csbi);

		SetConsoleTextAttribute(hConsole, (csbi.wAttributes & 0xFFF0) | (WORD)c);
	}

	void printTime() {
		auto now = std::chrono::system_clock::now();
		auto now_c = std::chrono::system_clock::to_time_t(now);
		std::cout << '[' << std::put_time(std::localtime(&now_c), "%c") << ']';
	}

	enum {
		BLACK,
		BLUE,
		GREEN,
		CYAN,
		RED,
		MAGENTA,
		BROWN,
		GREY,
		DARKGREY,
		LIGHTBLUE,
		LIGHTGREEN,
		LIGHTCYAN,
		LIGHTRED,
		LIGHTMAGENTA,
		YELLOW,
		WHITE
	};
};

#endif