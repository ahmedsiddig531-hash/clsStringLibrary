 # C++ String Library

A custom C++ string library implemented using a `clsString` class.

This project provides a collection of string manipulation and utility
functions implemented from scratch for learning and practicing C++.

## Features

### Basic String Operations
- `Length()`
- `empty()`
- `at()`
- `front()`
- `back()`
- `clear()`
- `push_back()`
- `push_front()`
- `append()`

### Substring and Search Operations
- `substr()`
- `find()`
- `insert()`
- `replace()`

### Character and Letter Operations
- `CountVowels()`
- `IsVowel()`
- `CountLetters()`
- `CountCapitalLetters()`
- `CountSmallLetters()`
- `CountSpecificLetter()`
- `InvertLettercase()`

### Case Conversion
- `UpperFirstLetterOfEachWord()`
- `LowerFirstLetterOfEachWord()`
- `UpperAllString()`
- `LowerAllString()`
- `InvertStringLettersCase()`

### Word and String Operations
- `CountWords()`
- `Split()`
- `JoinString()`
- `ReverseWordsInString()`
- `TrimLeft()`
- `TrimRight()`
- `Trim()`
- `RemovePunctuations()`

## Implementation

The library is implemented as a C++ class called `clsString`.

It stores the string internally using:

```cpp
string _value;
