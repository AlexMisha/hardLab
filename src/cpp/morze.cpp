/*
 * morze.cpp
 *
 *  Created on: 29 Sep 2017
 *      Author: micha
 */

#include <iostream>
#include <map>
#include <string>
#include <cctype>

#include "morze.h"

using namespace std;

int morze() {
	map<char, string> morze = { { 'a', ".-" }, { 'b', "-..." }, { 'w', ".--" },
			{ 'g', "--." }, { 'd', "-.." }, { 'e', "." }, { 'v', "...-" }, {
					'z', "--.." }, { 'i', ".." }, { 'j', ".---" },
			{ 'k', "-.-" }, { 'l', ".-.." }, { 'm', "--" }, { 'n', "-." }, {
					'o', "---" }, { 'p', ".--." }, { 'r', ".-." },
			{ 's', "..." }, { 't', "-" }, { 'u', "..-" }, { 'f', "..-." }, {
					'h', "...." }, { 'c', "-.-." }, { 'q', "--.-" }, { 'y',
					"-.--" }, { 'x', "-..-" }, { '1', ".----" },
			{ '2', "..---" }, { '3', "...--" }, { '4', "....-" },
			{ '5', "....." }, { '6', "-...." }, { '7', "--..." },
			{ '8', "---.." }, { '9', "----." }, { '0', "-----" }, { '.',
					"......" }, { ',', ".-.-.-" }, { ':', "---..." }, { ';',
					"-.-.-." }, { '(', "-.--.-" }, { ')', "-.--.-" }, { '"',
					".-..-." }, { '-', "-....-" }, { '/', "-..-." }, { '?',
					"..--.." }, { '!', "--..--" }, { '@', ".--.-." }, };
	string text;

	cout << "Type text to transform" << endl;
	while (cin >> text) {
		if (!text.compare("exit")) {
			break;
		}

		for (int i = 0; i < text.length(); i++) {
			text[i] = tolower(text[i]);
			cout << morze.find(text[i])->second << "  ";
		}
		//cout << morze.find(' ')->second << "  ";
	}

	return EXIT_SUCCESS;
}

