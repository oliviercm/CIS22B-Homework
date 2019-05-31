/*
CIS 22B
Lab 01: Read up to 1024 words from a text file, sort the words, search the words for user-defined words, then output all results to a file.
Name: Olivier Chan Sion Moy

Pseudocode:

[START]

Enter main function
	Declare filepaths, word array, array size
	Get user filepaths
		Get input filepath, try again if invalid
		Get output filepath
		Write filepaths to output file
	Read from text file into word array
		Loop through the file word by word, ignoring single-character words
			Stop when 1024 words have been read in or end of file
	Selection sort
		Loop through the word array word by word
			Store the current word in x
			Loop through all the following words
					If a following word is smaller than x, store it in x
			Swap x and the current word.
		Resulting array is sorted in ascending order.
	Search for user-defined words
		While the user doesn't enter a blank word (just pressing enter)
			Get user-defined word
			Binary search for defined word
				While the word isn't found and the entire array hasn't been searched,
					If the midpoint is the defined word
						Return its position
					Else
						Adjust the search range to the remaining half of the array that may contain the defined word
				Return -1 to signify the word doesn't exist in the array
			If a valid position is returned
				Print the word and its position
				Write the word and its position to output file
			Else
				Print that the word wasn't found
				Write that the word wasn't found to output file
	Write the array into the output file
		Write a small header into the output file
		Loop through the array word by word
			Write the contents of the array into the output file
	Display completion message
	Wait for Enter key

[END]

*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void inputUserPaths(string &inputPath, string &outputPath);
void inputUserSearch(string array[], int size, string outputPath);
void readFromFileIntoArray(string path, string array[], int size);
void writeIntoFileFromArray(string path, string array[], int size);
void selectionSort(string array[], int size);
int binarySearch(string array[], int size, string value);

int main(void)
{
	const int ARRAY_SIZE = 1024;
	string words[ARRAY_SIZE];
	string inputPath, outputPath;

	inputUserPaths(inputPath, outputPath);

	readFromFileIntoArray(inputPath, words, ARRAY_SIZE);

	selectionSort(words, ARRAY_SIZE);

	inputUserSearch(words, ARRAY_SIZE, outputPath);

	writeIntoFileFromArray(outputPath, words, ARRAY_SIZE);

	cout << "Complete. Press Enter to exit." << endl;
	cin.get();

	return 0;
}

/**
 * inputUserPaths
 * 
 * @brief Prompt the user for an input and output file path and save it to referenced variables.
 *
 * @param &inputPath,&outputPath User inputted filepaths will be saved to these variables.
 *
 * @return void
 */

void inputUserPaths(string &inputPath, string &outputPath)
{
	ifstream testInput;
	ofstream output;

	do
	{
		cout << "Enter path to input file (.txt must be included): ";
		getline(cin, inputPath);

		testInput.open(inputPath);

		if (!testInput)
		{
			cerr << "ERROR: Invalid path. Make sure to include .txt after the file name." << endl << endl;
		}
	}
	while (!testInput);

	testInput.close();

	cout << "Enter path to output file: ";
	getline(cin, outputPath);
	cout << endl;

	output.open(outputPath);
	output << "Input file: " << inputPath << endl;
	output << "Output file: " << outputPath << endl << endl;
	output.close();

	return;
}

/**
 * inputUserSearch
 *
 * @brief Prompt the user for a word to search for in an array. An empty input breaks the loop. Uses binary search, displays and writes results to screen and output.
 *
 * @param array,size Array to search and its size.
 *
 * @param outputPath File to write results into.
 *
 * @return void
 */

void inputUserSearch(string array[], int size, string outputPath)
{
	string search;
	int foundPosition;

	ofstream output;
	output.open(outputPath, ios_base::app);

	do
	{
		cout << "Enter a word to search (Pressing Enter without typing anything will exit): ";
		getline(cin, search);

		if (search != "")
		{
			foundPosition = binarySearch(array, size, search);

			if (foundPosition == -1)
			{
				cout << search << " not found." << endl << endl;
				output << search << " not found." << endl << endl;
			}
			else
			{
				cout << search << " found at array position: " << foundPosition << endl << endl;
				output << search << " found at array position: " << foundPosition << endl << endl;
			}
		}
	}
	while (search != "");

	output.close();

	return;
}

/**
 * readFromFileIntoArray
 *
 * @brief Read through file at the passed filepath, writing its contents into an array word by word, ignoring single-character words.
 *
 * @param path File to read from.
 *
 * @param array,size Array to write into and its size.
 *
 * @return void
 */

void readFromFileIntoArray(string path, string array[], int size)
{
	ifstream input;
	input.open(path);

	if (!input)
		return;

	int i = 0;
	string word;
	const int WORD_MIN_SIZE = 1;

	while (i < size && input >> word)
	{
		if (word.length() > WORD_MIN_SIZE)
		{
			array[i] = word;
			i++;
		}
	}

	input.close();

	return;
}

/**
 * writeIntoFileFromArray
 *
 * @brief Write into a file the contents of an array one by one, headed as a list of sorted words.
 *
 * @param path File to write into.
 *
 * @param array,size Array to read from and its size.
 *
 * @return void
 */

void writeIntoFileFromArray(string path, string array[], int size)
{
	ofstream output;
	output.open(path, ios_base::app);

	output << "Sorted word list:" << endl;

	for (int i = 0; i < size; i++)
	{
		output << "[" << i << "] " << array[i] << endl;
	}

	output.close();
}

/**
 * selectionSort
 *
 * @brief Sort an array of strings in ascending order using a Selection Sort algorithm.
 *
 * @param array,size Array to sort and its size.
 *
 * @return void
 */

void selectionSort(string array[], int size)
{
	int startIndex, minIndex, index;
	string minValue;

	for (startIndex = 0; startIndex < size - 1; startIndex++)
	{
		minIndex = startIndex;
		minValue = array[startIndex];

		for (index = startIndex + 1; index < size; index++)
		{
			if (array[index] < minValue)
			{
				minIndex = index;
				minValue = array[index];
			}
		}

		array[minIndex] = array[startIndex];
		array[startIndex] = minValue;
	}
	
	return;
}

/**
 * binarySearch
 *
 * @brief Search an array of strings for a specific string using a Binary Search algorithm.
 *
 * @param array,size Array to search and its size.
 *
 * @return The position of the searched word, or -1 if the word wasn't found
 */

int binarySearch(string array[], int size, string value)
{
	int first = 0,
		last = size - 1,
		middle,
		position = -1;
	bool found = false;
	
	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (array[middle] == value)
		{
			position = middle;
			found = true;
		}
		else if (array[middle] > value)
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}
	}

	return position;
}