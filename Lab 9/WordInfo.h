#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <conio.h>
using namespace std;

class WordInfo {
	public:
	// Open and read word from file
	void ReadWordsFromFile(const char* filename);


	unordered_map<string, int> wordMap;
};

