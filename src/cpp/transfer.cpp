/*
 * transfer.cpp
 *
 *  Created on: 2 Oct 2017
 *      Author: micha
 */

#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

#include "transfer.h"
#include "hyphenator.h"
#include "patterns.h"
#include "hyphenator.cpp"

using namespace std;

int isdigit_func(unichar c);
int ismarker_func(unichar c);
unsigned char char2digit_func(unichar c);

const unichar marker = '.';

int transfer() {
	string text;

	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	struct pattern_list_t* plist = create_pattern_list();
	size_t i = 0;
	while (patterns[i]) {
		struct pattern_t* p = create_pattern(patterns[i], isdigit_func,
				ismarker_func, char2digit_func);
		add_patern(plist, p);
		++i;
	}
	sort_pattern_list(plist);

	cout << "Type text to transfer" << endl;
	cin >> text;

	int word_index = 0;
	while (cin >> text) {
		if (!text.compare("exit")) {
			break;
		}

		struct word_hyphenation_t* wh = hyphenate_word(text.c_str(), plist,
				marker);
		i = 0;
		while (text[i]) {
			if (wh->mask[i])
				printf("-");
			printf("%c", text[i]);
			++i;
		}
		printf("\n");
		destroy_word_hyphenation(wh);

		++word_index;
	}

	destroy_pattern_list(plist);
	return EXIT_SUCCESS;
}

int isdigit_func(unichar c) {
	return c >= '0' && c <= '9';
}

int ismarker_func(unichar c) {
	return c == marker;
}

unsigned char char2digit_func(unichar c) {
	return c - '0';
}
