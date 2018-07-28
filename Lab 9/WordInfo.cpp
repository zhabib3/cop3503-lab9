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
		vector<string> stringVect;
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
				stringVect.push_back(word);
			}
			
		}

		file.close();
	}
}
