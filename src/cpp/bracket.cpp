/*
 * bracket.cpp
 *
 *  Created on: 17 Oct 2017
 *      Author: micha
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "bracket.h"

using namespace std;

struct Bracket {
	Bracket(int position, int priority) :
			position(position), priority(priority) {
	}
	int position;
	int priority;
};

Bracket* findByPriority(int priority, vector<Bracket>* brackets);

int bracket() {
	int currentPriority = 0;
	string text;
	vector<Bracket> brackets;
	vector<char> preChars = { '(', '[', '{' };
	vector<char> postChars = { ')', ']', '}' };

	cout << "Type text to transform" << endl;
	while (getline(cin, text)) {
		if (!text.compare("exit")) {
			break;
		}

		for (int i = 0; i < text.size(); i++) {
			if (text[i] == '(') {
				Bracket br = Bracket(i, currentPriority++);
				brackets.push_back(br);
			}

			if (text[i] == ')') {
				Bracket* br = findByPriority(--currentPriority, &brackets);
				if (br == nullptr) {
					cout << "incorrect brackets" << endl;
					return EXIT_FAILURE;
				}

				text.at(i) = postChars[
						currentPriority <= 2 ? currentPriority : 2];
				text.at(br->position) = preChars[
						br->priority <= 2 ? br->priority : 2];
				brackets.pop_back();
			}
		}

		if (!brackets.empty()) {
			cout << "incorrect brackets" << endl;
			return EXIT_FAILURE;
		}
		cout << text << endl;
	}

	return EXIT_SUCCESS;
}

Bracket* findByPriority(int priority, vector<Bracket>* brackets) {
	for (int i = 0; i < brackets->size(); i++) {
		if (brackets->at(i).priority == priority) {
			return &brackets->at(i);
		}
	}
	return nullptr;
}

