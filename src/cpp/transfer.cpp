/*
 * transfer.cpp
 *
 *  Created on: 2 Oct 2017
 *      Author: micha
 */

#include <iostream>
#include <list>
#include <string>

#include "transfer.h"

using namespace std;

int transfer() {
	setlocale(LC_ALL, "Russian");

	list<string> vowels = { "А" };
	list<string> consonants = { "Б", "В", "Г", "Д" };
	list<string>::iterator findVowels;
	list<string>::iterator findConsonants;

	static int ONCE_STRING_LENGTH = 20;
	string text;

	cin >> text;
	//findVowels = find(vowels, vowels.end(), text[0]);

	return EXIT_SUCCESS;
}
