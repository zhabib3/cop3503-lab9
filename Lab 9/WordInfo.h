#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <conio.h>
using namespace std;

class WordInfo {
	public:
	// Open and read word from file
	void ReadWordsFromFile(const char* filename);

	// Display the stats of words in map
	void DisplayStats() const;

	// Find most common words based on count passed
	void MostCommonWords(int count, bool ignoreCommonFile = false) const;


	unordered_map<string, int> wordMap;
};

