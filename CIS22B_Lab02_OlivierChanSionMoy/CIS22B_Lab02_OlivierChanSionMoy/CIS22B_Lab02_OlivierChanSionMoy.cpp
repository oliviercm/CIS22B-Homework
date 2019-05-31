/*
CIS 22B
Lab 02: Implement and demonstate recreated versions of strlen(), strncpy(), strncat(), and strncmp().
Name: Olivier Chan Sion Moy

Pseudocode:

[START]

Enter main function
	Declare/initialize variables
	Loop while option is not "Exit"
		Display menu options
		Get user option
		Switch user option
			stringLength
				length equals 0
				While *ptr is not null-character
					Increase ptr and length by one
				Return length
			stringNCopy
				Work with a temporary ptr to destination in order to save destination's address
				While num characters haven't been copied yet
					If "End of source" flag is false
						Copy source into destination
						Move source and destination ptrs forward by one
					Else
						Pad destination with null-character
						Move destination ptr forward by one
					If source is a null-character
						Change "End of source" flag to true
				Return destination
			stringNAdd
				Work with a temporary ptr to destination in order to save destination's address
				While ptr is not pointing to a null-character
					Move forward until ptr is pointing to a null-character
				While num characters haven't been copied yet and source hasn't terminated yet
					Append source to destination one character at once
					Move source and destination ptrs forward by one
				End destination with a null-character
				Return destination
			stringNCompare
				If num is 0
					Return 0 (mimics strncmp() behavior)
				While str1 equals str2, neither str is a null-character, and num characters haven't been compared yet
					If it is not the last loop dictated by num
						Move str1 and str2 ptrs forward by one
				Calculate result
				If result isn't 0
					Clamp result to 1 or -1 (mimics strncmp() behavior)
				Return result
			Exit
				Exit on next loop

[END]

*/

#include <iostream>

using namespace std;

size_t stringLength(const char* str); //strlen()
char* stringNCopy(char* destination, const char* source, size_t num); //strncpy()
char* stringNAdd(char* destination, const char* source, size_t num); //strncat()
int stringNCompare(const char* str1, const char* str2, size_t num); //strncmp()

enum mainMenuOptions
{
	NONE,
	STRING_LENGTH,
	STRING_COPY,
	STRING_ADD,
	STRING_COMPARE,
	EXIT
};

int main(void)
{
	const int SIZE = 100;
	char cstring1[SIZE], cstring2[SIZE];
	size_t number;
	int option = NONE;

	while (option != EXIT)
	{
		cout << "[" << STRING_LENGTH << "] stringLength" << endl
			<< "[" << STRING_COPY << "] stringNCopy" << endl
			<< "[" << STRING_ADD << "] stringNAdd" << endl
			<< "[" << STRING_COMPARE << "] stringNCompare" << endl
			<< "[" << EXIT << "] Exit" << endl << endl
			<< "Choose an option [1-5]: ";

		while (!(cin >> option))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cin.ignore();
		cout << endl;

		switch (option)
		{
			case STRING_LENGTH:
				cout << "Enter a string: ";
				cin.getline(cstring1, SIZE);
				cout << cstring1 << " is " << stringLength(cstring1) << " characters long." << endl << endl;
				break;
			case STRING_COPY:
				cout << "Enter destination string: ";
				cin.getline(cstring1, SIZE);
				cout << "Enter source string: ";
				cin.getline(cstring2, SIZE);
				cout << "Enter max number of characters to copy: ";
				while (!(cin >> number))
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				cin.ignore();
				cout << "Resulting string is: " << stringNCopy(cstring1, cstring2, number) << endl << endl;
				break;
			case STRING_ADD:
				cout << "Enter destination string: ";
				cin.getline(cstring1, SIZE);
				cout << "Enter source string: ";
				cin.getline(cstring2, SIZE);
				cout << "Enter max number of characters to add: ";
				while (!(cin >> number))
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				cin.ignore();
				cout << "Resulting string is: " << stringNAdd(cstring1, cstring2, number) << endl << endl;
				break;
			case STRING_COMPARE:
				cout << "Enter first string: ";
				cin.getline(cstring1, SIZE);
				cout << "Enter second string: ";
				cin.getline(cstring2, SIZE);
				cout << "Enter max number of characters to compare: ";
				while (!(cin >> number))
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				cin.ignore();
				cout << "Result is: " << stringNCompare(cstring1, cstring2, number) << endl << endl;
				break;
			case EXIT:
				break;
			default:
				break;
		}
	}
	
	return 0;
}

/**
 * stringLength
 *
 * @brief Returns the length of the C string str.
 *
 * @details http://www.cplusplus.com/reference/cstring/strlen/
 *
 * @param str C string.
 *
 * @return Length of str.
 */

size_t stringLength(const char* str)
{
	size_t len = 0;

	while (*str++ != '\0')
	{
		len++;
	}

	return len;
}

/**
 * stringNCopy
 *
 * @brief Copies the first num characters of source to destination.
 *
 * @details http://www.cplusplus.com/reference/cstring/strncpy/
 *
 * @param destination Pointer to the destination array where the content is to be copied.
 *
 * @param source C string to be copied.
 *
 * @param num Maximum number of characters to be copied from source.
 *
 * @return destination is returned.
 */

char* stringNCopy(char* destination, const char* source, size_t num)
{
	char* ptr = destination;

	size_t i = 0;
	bool endOfSource = false;
	
	while (i++ < num)
	{
		//"If the end of the source C string is found before num characters have been copied, destination is padded with zeros until a total of num characters have been written to it."
		if (!endOfSource)
		{
			*ptr++ = *source++;
		}
		else
		{
			*ptr++ = '\0';
		}

		if (*source == '\0')
		{
			endOfSource = true;
		}
	};
	
	return destination;
}

/**
 * stringNAdd
 *
 * @brief Appends the first num characters of source to destination, plus a terminating null-character.
 *
 * @details http://www.cplusplus.com/reference/cstring/strncat/
 *
 * @param destination Pointer to the destination array, which should contain a C string, and be large enough to contain the concatenated resulting string, including the additional null-character.
 *
 * @param source C string to be appended.
 *
 * @param num Maximum number of characters to be appended.
 *
 * @return destination is returned.
 */

char* stringNAdd(char* destination, const char* source, size_t num)
{
	char* ptr = destination;

	size_t i = 0;
	
	while (*ptr != '\0')
	{
		ptr++;
	};

	while (i++ < num && *source != '\0')
	{
		*ptr++ = *source++;
	}

	*ptr = '\0';
	
	return destination;
}

/**
 * stringNCompare
 *
 * @brief Compares up to num characters of the C string str1 to those of the C string str2.
 *
 * @details http://www.cplusplus.com/reference/cstring/strncmp/
 *
 * @param str1 C string to be compared.
 *
 * @param str2 C string to be compared.
 *
 * @param num Maximum number of characters to compare.
 *
 * @return Returns an integral value indicating the relationship between the strings: <0 = the first character that does not match has a lower value in str1 than in str2, 0 = the contents of both strings are equal, >0 = the first character that does not match has a greater value in str1 than in str2.
 */

int stringNCompare(const char* str1, const char* str2, size_t num)
{
	int result;
	size_t i = 0;

	//strncmp(s1, s2, 0) returns 0
	if (num == 0)
	{
		return 0;
	}

	while (*str1 == *str2 && *str1 != '\0' && *str2 != '\0' && i++ < num)
	{
		if (i < num)
		{
			str1++;
			str2++;
		}
	}

	result = *str1 - *str2;

	if (result != 0)
	{
		result = result / abs(result);
	}

	return result;
}