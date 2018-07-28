#include "WordInfo.h"
using namespace std;
typedef unsigned int uint;

void WordInfo::ReadWordsFromFile(const char * filename)
{
	// Set filepath
	string filePath = "SAMPLE_file.txt";
	ifstream file(filePath);

	if (file.is_open())
	{

		string line;
		while (getline(file, line))
		{
			// break line apart by space delim
			istringstream str(line);
			string word;

			while (getline(str, word, ' '))
			{
				// String manipulation
				for (uint i = 0; i < word.length(); i++)
				{
					// Covert to lower case
					word[i] = tolower(word[i]);

				}

				// Remove period in the words
				if (word.find(".") != string::npos)
				{
					word.erase(word.find("."), 1);
				}

				// Remove comma in the words
				if (word.find(",") != string::npos)
				{
					word.erase(word.find(","), 1);
				}

				// Remove : in the words
				if (word.find(":") != string::npos)
				{
					word.erase(word.find(":"), 1);
				}

				// Remove apostrophes if they are at the ends
				if (word.find("'") == 0 || word.find("'") == (word.length() - 1))
				{
					word.erase(word.find("'"),1);
				}

				// TODO: Remove other possible weird stuff from string

				// Store words in the unordered map and increment any similar ones
				wordMap[word]++;
			}
			
		}

		file.close();
	}
}


void WordInfo::DisplayStats() const
{
	int avgWordLength = 0;
	int numOfUniques = 0;
	int totalWords = 0;
	// Create an iterator to traverse
	auto iter = wordMap.begin();

	while (iter != wordMap.end())
	{
		if (iter->second == 1)
			numOfUniques++;

		avgWordLength += iter->first.length();
		totalWords += iter->second;
		iter++;
	}

	// Calculate average word len
	avgWordLength = avgWordLength / totalWords;

	cout << "Number of Words: " << totalWords << endl;
	cout << "Number of Unique words: " << numOfUniques << endl;
	cout << "Average word length: " << avgWordLength << endl;

}

void WordInfo::MostCommonWords(int count, bool ignoreCommonFile) const
{
	multimap<int, string> sortedWords;
	int freqNum;
	string word;
	// Sort wordMap based on word frequency via emplacing in a multimap
	auto iter = wordMap.begin();
	while (iter != wordMap.end())
	{
		freqNum = iter->second;
		word = iter->first;
		sortedWords.emplace(freqNum, word);
		iter++;
	}

	cout << count << " most common words found in the file:" << endl;
	auto sortedIter = sortedWords.end();
	sortedIter--; // Start at the last entry
	for (int i = 0; i < count; i++)
	{
		cout << sortedIter->second << endl;
		sortedIter--;
	}

}
