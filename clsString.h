#pragma once
 
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;
class clsString
{
private:
	string _value;
public:
	clsString(string value)
	{
		_value = value;
	}

	void Print()
	{
		cout << _value;
	}

	static int Length(string value)
	{
		int count = 0;
		for (int i = 0; value[i] != '\0'; i++)
		{
			count++;
		}
		return count;
	}

	int Length()
	{
		return Length(_value);
	}

	bool empty()
	{
		return (Length(_value) == 0);
	}

	static char at(string value, short index)
	{
		if (index >= value.length())
		{
			throw out_of_range(" index Out Of range");

		}
		return value[index];

	}

	char at(short index)
	{
		return at(_value, index);
	}

	static char front(string value)
	{
		if (!value.empty())
		{
			return value[0];
		}
		else
		{
			throw out_of_range("string is empty");
		}
	}

	char front()
	{
		return front(_value);
	}

	static char back(string value)
	{
		if (!value.empty())
		{
			return (value[value.length() - 1]);
		}
		else
		{
			throw out_of_range("string is empty");
		}
	}
	char back()
	{
		return back(_value);
	}

	static void clear(string value)
	{
		value = "";
	}

	void clear()
	{
		clear(_value);
	}

	static void push_back(string& value, char ch)
	{
		//string variableName(numberOfCharacters, character);   constructor of type string
		size_t count = value.length();
		string NewString(count + 1, ' ');

		for (int i = 0; i < count; i++)
		{
			NewString[i] = value[i];
		}

		NewString[count] = ch;

		value = NewString;
	}

	void push_back(char ch)
	{
		push_back(_value, ch);
	}

	static void push_front(string& value, char ch)
	{
		size_t count = value.length();

		string NewString(count + 1, ' ');

		NewString[0] = ch;

		for (int i = 0; i < count; i++)
		{
			NewString[i + 1] = value[i];
		}

		value = NewString;
	}

	void push_front(char ch)
	{
		push_front(_value, ch);
	}

	static void append(string& value, string added_str)
	{
		string NewString = value + added_str;
		value = NewString;
	}

	void append(string added_str)
	{
		append(_value, added_str);
	}

	static string substr(string value, short pos)
	{
		size_t count = value.length();

		if (pos > count)
		{
			throw out_of_range("std::pos is greater than the length");
		}
		if (pos == count)
		{
			return "";

		}

		string NewString((count - pos), ' ');
		int j = 0;

		for (short i = pos; value[i] != '\0'; i++)
		{
			NewString[j++] = value[i];
		}
		return NewString;
	}

	string substr(short pos)
	{
		return substr(_value, pos);
	}

	static string substr(string value, short start, short count)
	{

		short _count = value.length();

		if (start > _count)
		{
			throw out_of_range("std::pos is greater than the length");
		}

		if (start == _count)
		{
			return "";
		}

		if (count > _count - start)
		{
			count = _count - start;
		}

		string NewString(count, ' ');

		int j = 0;
		for (int i = start; value[i] != '\0'; i++)
		{
			NewString[j] = value[i];

			j++;

			if (j == count)
			{
				break;
			}
		}
		return NewString;
	}

	string substr(short start, short count)
	{
		return substr(_value, start, count);
	}

	static size_t find(string value, string search)
	{
		size_t valueLength = value.length();
		size_t searchLength = search.length();

		if (searchLength == 0)
		{
			return 0;
		}


		if (searchLength > valueLength)
		{
			return string::npos;
		}


		for (size_t i = 0; i <= valueLength - searchLength; i++)
		{
			size_t j = 0;

			while (j < searchLength && value[i + j] == search[j])
			{
				j++;
			}

			if (j == searchLength)
				return i;
		}

		return string::npos;
	}

	size_t find(string search)
	{
		return find(_value, search);
	}

	static size_t find(string value, char ch)
	{
		for (size_t i = 0; value[i] != '\0'; i++)
		{
			if (value[i] == ch)
			{
				return i;
			}
		}
		return string::npos;
	}

	size_t find(char ch)
	{
		return find(_value, ch);
	}

	static size_t find(string value, char ch, short start)
	{
		for (size_t i = start; value[i] != '\0'; i++)
		{
			if (value[i] == ch)
			{
				return i;
			}
		}
		return string::npos;
	}

	size_t find(char ch, short start)
	{
		return find(_value, ch, start);
	}

	static void insert(string& value, short position, string inserted_str)
	{
		size_t origin_str_count = value.length();
		size_t Inserted_str_count = inserted_str.length();

		if (position > origin_str_count)
		{
			throw out_of_range("Position is out of range");
		}

		string Newstring(origin_str_count + Inserted_str_count, ' ');

		for (size_t i = 0; i < position; i++)
		{
			Newstring[i] = value[i];
		}

		for (size_t i = 0; i < Inserted_str_count; i++)
		{
			Newstring[position + i] = inserted_str[i];
		}

		for (size_t i = position; i < origin_str_count; i++)
		{
			Newstring[Inserted_str_count + i] = value[i];
		}

		value = Newstring;
	}

	void insert(short position, string inserted_str)
	{
		insert(_value, position, inserted_str);
	}


	static void replace(string& value, size_t position, size_t count, string new_str)
	{
		size_t origin_count = value.length();
		size_t new_count = new_str.length();

		if (position > origin_count)
		{
			throw out_of_range("Position is out of range");
		}

		// How many characters will actually be removed
		if (count > origin_count - position)
		{
			count = origin_count - position;
		}

		size_t final_count = origin_count - count + new_count;

		string NewString(final_count, ' ');

		size_t index = 0;

		// 1. Copy characters before position
		for (size_t i = 0; i < position; i++)
		{
			NewString[index] = value[i];
			index++;
		}

		// 2. Copy the new string
		for (size_t i = 0; i < new_count; i++)
		{
			NewString[index] = new_str[i];
			index++;
		}

		// 3. Copy characters after the removed part
		for (size_t i = position + count; i < origin_count; i++)
		{
			NewString[index] = value[i];
			index++;
		}

		value = NewString;
	}

	void replace(size_t position, size_t count, string new_str)
	{
		replace(_value, position, count, new_str);
	}

	static short CountVowels(string value)
	{
		size_t str_length = value.length();
		short VowelsCount = 0;
		char ch;
		for (int i = 0; i < str_length; i++)
		{
			ch = tolower(value[i]);
			if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'u' || ch == 'o')
				VowelsCount++;
		}
		return VowelsCount;
	}

	short CountVowels()
	{
		return CountVowels(_value);
	}

	static short CountWords(string S1)
	{

		string delim = " "; // delimiter  
		short Counter = 0;
		short pos = 0;
		string sWord; // define a string variable  

		// use find() function to get the position of the delimiters  
		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word   
			if (sWord != "")
			{
				Counter++;
			}

			//erase() until positon and move to next word.
			S1.erase(0, pos + delim.length());
		}

		if (S1 != "")
		{
			Counter++; // it counts the last word of the string.
		}

		return Counter;

	}

	short CountWords()
	{
		return  CountWords(_value);
	}

	static string  UpperFirstLetterOfEachWord(string S1)
	{

		bool isFirstLetter = true;

		for (short i = 0; i < S1.length(); i++)
		{

			if (S1[i] != ' ' && isFirstLetter)
			{
				S1[i] = toupper(S1[i]);

			}

			isFirstLetter = (S1[i] == ' ' ? true : false);

		}

		return S1;
	}

	void UpperFirstLetterOfEachWord()
	{
		_value = UpperFirstLetterOfEachWord(_value);
	}

	static string  LowerFirstLetterOfEachWord(string S1)
	{

		bool isFirstLetter = true;

		for (short i = 0; i < S1.length(); i++)
		{

			if (S1[i] != ' ' && isFirstLetter)
			{
				S1[i] = tolower(S1[i]);

			}

			isFirstLetter = (S1[i] == ' ' ? true : false);

		}

		return S1;
	}

	void LowerFirstLetterOfEachWord()
	{
		_value = LowerFirstLetterOfEachWord(_value);
	}


	static string UpperAllString(string S1)
	{

		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
			{
				S1[i] = toupper(S1[i]);
			}
		}
		return S1;
	}


	void UpperAllString()
	{
		_value = UpperAllString(_value);
	}

	static string LowerAllString(string S1)
	{

		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
			{
				S1[i] = tolower(S1[i]);
			}
		}
		return S1;
	}

	void  LowerAllString()
	{
		_value = LowerAllString(_value);
	}

	static char InvertLettercase(char ch)
	{
		return isupper(ch) ? tolower(ch) : toupper(ch);
	}

	static string InvertStringLettersCase(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = InvertLettercase(S1[i]);
		}

		return S1;
	}

	void InvertStringLettersCase()
	{
		_value = InvertStringLettersCase(_value);
	}

	enum enWhatToCount { smallLetters = 1, capitalLetters = 2, All = 3 };

	static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
	{
		short counter = 0;
		if (WhatToCount == All)
			return S1.length();


		else if (WhatToCount == smallLetters)
		{
			for (int i = 0; i < S1.length(); i++)
				islower(S1[i]) ? counter++ : counter;
		}
		else
		{
			for (int i = 0; i < S1.length(); i++)
				isupper(S1[i]) ? counter++ : counter;
		}

		return counter;
	}

	short CountLetters()
	{
		_value = CountLetters(_value);
	}

	static short  CountCapitalLetters(string S1)
	{

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{

			if (isupper(S1[i]))
				Counter++;

		}

		return Counter;
	}

	short  CountCapitalLetters()
	{
		return CountCapitalLetters(_value);
	}

	static short  CountSmallLetters(string S1)
	{

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{

			if (islower(S1[i]))
				Counter++;

		}
	};

	short CountSmallLetters()
	{
		return CountSmallLetters(_value);
	}

	static short  CountSpecificLetter(string S1, char Letter, bool MatchCase = true)
	{

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{

			if (MatchCase)
			{
				if (S1[i] == Letter)
					Counter++;
			}
			else
			{
				if (tolower(S1[i]) == tolower(Letter))
					Counter++;
			}

		}

		return Counter;
	}

	short  CountSpecificLetter(char Letter, bool MatchCase = true)
	{
		return CountSpecificLetter(_value, Letter, MatchCase);
	}

	static bool IsVowel(char Ch1)
	{
		Ch1 = tolower(Ch1);

		return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));

	}

	static short  CountVowels(string S1)
	{

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{

			if (IsVowel(S1[i]))
				Counter++;

		}

		return Counter;
	}

	short  CountVowels()
	{
		return CountVowels(_value);
	}

	static vector<string> Split(string S1, string Delim)
	{

		vector<string> vString;

		short pos = 0;
		string sWord; // define a string variable  

		// use find() function to get the position of the delimiters  
		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word   
			if (sWord != "")
			{
				vString.push_back(sWord);
			}

			S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
		}

		if (S1 != "")
		{
			vString.push_back(S1); // it adds last word of the string.
		}

		return vString;

	}

	vector<string> Split(string Delim)
	{
		return Split(_value, Delim);
	}

	static string TrimLeft(string S1)
	{


		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(i, S1.length() - i);
			}
		}
		return "";
	}

	string TrimLeft()
	{
		return TrimLeft(_value);
	}

	static string TrimRight(string S1)
	{


		for (short i = S1.length() - 1; i >= 0; i--)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(0, i + 1);
			}
		}
		return "";
	}

	void TrimRight()
	{
		_value = TrimRight(_value);
	}

	static string Trim(string S1)
	{
		return (TrimLeft(TrimRight(S1)));

	}

	void Trim()
	{
		_value = Trim(_value);
	}

	static string JoinString(vector<string> vString, string Delim)
	{

		string S1 = "";

		for (string& s : vString)
		{
			S1 = S1 + s + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());


	}
	
	static string JoinString(string arrString[], short Length, string Delim)
	{

		string S1 = "";

		for (short i = 0; i < Length; i++)
		{
			S1 = S1 + arrString[i] + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());

	}

	static string ReverseWordsInString(string S1)
	{

		vector<string> vString;
		string S2 = "";

		vString = Split(S1, " ");

		// declare iterator
		vector<string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{

			--iter;

			S2 += *iter + " ";

		}

		S2 = S2.substr(0, S2.length() - 1); //remove last space.

		return S2;
	}

	string ReverseWordsInString()
	{
		return ReverseWordsInString(_value);
}

	static string RemovePunctuations(string S1)
	{

		string S2 = "";

		for (short i = 0; i < S1.length(); i++)
		{
			if (!ispunct(S1[i]))
			{
				S2 += S1[i];
			}
		}

		return S2;

	}

	void RemovePunctuations()
	{
		_value = RemovePunctuations(_value);
	}


};