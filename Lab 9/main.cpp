// Lexer.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "WordInfo.h"
#include <map>
#include <conio.h>
#include <unordered_map>
using namespace std;

int main()
{
	// TODO: Load words_to_ignore.txt, store those in a vector of strings to pass to your class objects
	WordInfo wordInfo;
	cout << "1-4: Which file to open?" << endl;
	int option;
	cin >> option;

	// TODO: Create a WordList object and set the list of words to ignore
	switch (option)
	{
	case 1:
		wordInfo.ReadWordsFromFile("1");
		break;
	default:
		break;
	}

	_getch();
	// Read the words from the file
	// Show the stats
	// Show the most frequent words, NOT using the ignore list
	// Show the most frequent words, using the ignore list (to ignore the universally common words)

	// (Show a number of common words based on the selected file + 1. First file shows 2 common words, second shows 3, 4th shows 5, etc)

	// Get and then show the longest words
	vector<string> longestWords;

	// Get input for a word, and do an exact match search for that word. (Convert input to lowercase first!)
	cout << "Enter a word for an exact search: ";

	//cout << '\'' << searchTerm << "' was found " << count << " times in the list.\n";

	// Ditto for partial search...
	//cout << "Enter a word for a partial search: ";

	//if (no matches found)
	//	cout << "\nNo entries match '" << searchTerm << '\'' << endl;
	//else
	//{
	//	cout << "\nWords containing '" << thesearchterm << '\'' << endl;

	//	// print list o' matches
	//}

	_getch();

	return 0;
}

