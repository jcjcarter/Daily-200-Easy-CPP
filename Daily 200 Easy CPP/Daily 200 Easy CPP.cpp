// Daily 200 Easy CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <string.h>

int w;
int h;
char **ascii;

void convert(int x, int y, int c) {
	char old = ascii[x][y];
	ascii[x][y] = c;
	if (x - 1 >= 0 && ascii[x - 1][y] == old) {
		convert(x - 1, y, c);
	}
	if (y - 1 >= 0 && ascii[x][y - 1] == old) {
		convert(x, y - 1, c);
	}
	if (x + 1 < h && ascii[x + 1][y] == old) {
		convert(x + 1, y, c);
	}
	if (y + 1 < w && ascii[x][y + 1] == old) {
		convert(x, y + 1, c);
	}
}

void display() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			std::cout << ascii[i][j];
		}
		std::cout << std::endl;
	}
}

int main() {
	std::cout << "Enter size:" << std::endl;
	std::cin >> h >> w;

	ascii = new char*[h];
	for (int i = 0; i < h; i++) {
		std::string buff;
		std::cin >> buff;
		ascii[i] = strdup(buff.c_str());
	}
	int x;
	int y;
	char c;

	std::cout << "Enter replacement:" << std::endl;
	std::cin >> x >> y >> c;

	convert(x, y, c);

	display();

	for (int i = 0; i < h; i++) {
		delete[] ascii[i];
	}
	delete[] ascii;
	ascii = 0;
}