#include <iostream>
#include <fstream>
#include "mersenne-twister.h"
#include <vector>
#include <algorithm>


using namespace std;
//PROJECT 2: WORD GAME:


int chooseRandomNumber(int min, int max);
string fullSetOfVowels();
string fullSetOfConsonants();

vector<string> loadWordsFromFile(const string& fileName);

bool isValidWord (string availableLetters, const string& word, const vector<string>& words);

void toUppercase(string &word);

string findLongestWord(const string& availableLetters, const vector<string>& words);

int main() 
{
	//seed generator
	int randSeed=0;
	cout << "Enter random seed: " << endl;
	cin >> randSeed;
	seed(randSeed);

	string playAgain;
	vector<string> words = loadWordsFromFile("words.txt");

	cout << "Let's play Countdown!" << endl;
	do {
		int numVowels;
		do {
			

			//asking for the number of vowels
			cout << "How many vowels would you like (3-5)? " << endl;
			cin >> numVowels;
			if (numVowels < 3 || numVowels > 5){
				cout << "Invalid number of vowels." << endl;
			}
		} while (numVowels < 3 || numVowels > 5);


		//get the rest of the available letters

			//getting the vowels
		string availableLetters;
		string vowels = fullSetOfVowels();
		for (int i = 0; i < numVowels; ++i) {
			int index = chooseRandomNumber(0,vowels.size()-1);
			char vowel = vowels[index];
			availableLetters += vowel;
			vowels.replace(index, 1, "");
	
		}
			//getting the consonants
		string consonants = fullSetOfConsonants();
		for (int i =0; i < (9-numVowels); ++i){
			int index = chooseRandomNumber(0,consonants.size()-1);
			char consonant = consonants[index];
			availableLetters += consonant;
			consonants.replace(index,1,"");
			
		}

		cout << "The letters are: " << availableLetters << endl;

		//get the player words
		string player1Word, player2Word;
		cout << "Player 1, enter your word: " << endl;
		cin >> player1Word;
		toUppercase(player1Word);
		cout << "Player 2, enter your word: " << endl;
		cin >> player2Word;
		toUppercase(player2Word);
		


		//check if valid

		bool player1Valid = isValidWord(availableLetters, player1Word, words);
		bool player2Valid = isValidWord(availableLetters, player2Word, words);


		//check for winner
		if (player1Valid && player2Valid){
			if(player1Word.length() > player2Word.length()){
				cout << "Player 1 wins!" << endl;
			}
			else if(player2Word.length() > player1Word.length()){
				cout << "Player 2 wins!" << endl;
			}
			else if(player1Word.length() == player2Word.length()){
				cout << "Tie game." << endl;
			}
		}
		else if (!player2Valid && player1Valid){
			cout << "Player 2's word is not valid." << endl;
			cout << "Player 1 wins!" << endl;
		}
		else if (!player1Valid && player2Valid){
			cout << "Player 1's word is not valid." << endl;
			cout << "Player 2 wins!" << endl;
		}
		else {
			cout << "Player 1's word is not valid." << endl;
			cout << "Player 2's word is not valid." << endl;
			cout << "Tie game." << endl;
		}
		
		
		//longest possible word
		string longestWord = findLongestWord(availableLetters, words);
		if(!longestWord.empty()) {
			cout << "The longest possible word is: " << findLongestWord(availableLetters,words) << endl;
		}

		
		//play again
		cout << "Do you want to play again (y/n)? " << endl;
		cin >> playAgain;
	} while(playAgain == "y" || playAgain == "Y");
}

int chooseRandomNumber(int min, int max) {
	return rand_u32() % (max + 1 - min) + min;
}

string fullSetOfVowels() {
	return 
		string(15, 'A') + 
		string(21, 'E') + 
		string(13, 'I') + 
		string(13, 'O') + 
		string(5, 'U');
}

string fullSetOfConsonants() {
	return
		string(2, 'B') +
		string(3, 'C') +
		string(6, 'D') +
		string(2, 'F') +
		string(3, 'G') +
		string(2, 'H') +
		string(1, 'J') +
		string(1, 'K') +
		string(5, 'L') +
		string(4, 'M') +
		string(8, 'N') +
		string(4, 'P') +
		string(1, 'Q') +
		string(9, 'R') +
		string(9, 'S') +
		string(9, 'T') +
		string(1, 'V') +
		string(1, 'W') +
		string(1, 'X') +
		string(1, 'Y') +
		string(1, 'Z');
}


vector<string> loadWordsFromFile(const string& fileName){
	vector<string> words;
	ifstream file(fileName);
	string word;

	if(file.is_open()) {
		while(file>>word) {
			toUppercase(word);
			words.push_back(word);
		}
		file.close();
	}
	else {
		cerr << "Unable to open file: " << fileName << endl;
	}
	return words;
}

bool isValidWord (string availableLetters, const string& word, const vector<string>& words) {
	string available = availableLetters;
	for(char letter : word) {
		size_t index = available.find(letter);
		if (index == string::npos) {
			return false;
		}
		available.replace(index,1," ");
	}
	return find(words.begin(),words.end(),word) !=words.end();
}

void toUppercase(string &word) {
	std::transform(word.begin(),word.end(), word.begin(),  [](unsigned char c) {return std::toupper(c);});
}

string findLongestWord(const string& availableLetters, const vector<string>& words){
	string longestWord = "";
	for(const string& word:words){
		if(isValidWord(availableLetters, word, words)){
			if(word.length() > longestWord.length()){
				longestWord = word;
			}
		}
	}
	return longestWord;
}