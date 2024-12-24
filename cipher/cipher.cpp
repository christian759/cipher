
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

string choice;
string keyword_key;
int caesar_key;
string word_to_cipher;
string ciphered_word;

string alphabet = "abcdefghijklmnopqrstuvwxyz";

void caesar_cipher();

void caesar_cipher() {
	cout << "Enter the word you wish to cipher: " << endl;
	cin >> word_to_cipher;
	for (int i = 0; i < word_to_cipher.length(); i++) {
		ciphered_word += word_to_cipher[i] + caesar_key;
	}
	cout << "The ciphered word is: " << ciphered_word << endl;
}

string createSubstitutionAlphabet(const string& keyword) {
	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string substitutionAlphabet = keyword;
	unordered_set<char> usedChars(keyword.begin(), keyword.end());

	for (char c : alphabet) {
		if (usedChars.find(c) == usedChars.end()) {
			substitutionAlphabet += c;
		}
	}

	return substitutionAlphabet;
}

void keyword_cipher() {
	cout << "Enter the word you wish to cipher: " << endl;
	cin >> word_to_cipher;
	string substitutionAlphabet = createSubstitutionAlphabet(keyword_key);
	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	ciphered_word.clear();

	for (size_t i = 0; i < word_to_cipher.size(); ++i) {
		if (isalpha(word_to_cipher[i])) {
			char upperChar = toupper(word_to_cipher[i]);
			size_t index = alphabet.find(upperChar);
			ciphered_word += isupper(word_to_cipher[i]) ? substitutionAlphabet[index] : tolower(substitutionAlphabet[index]);
		}
		else {
			ciphered_word += word_to_cipher[i];
		}
	}

	cout << "The ciphered word is: " << ciphered_word << endl;
}

void ask() {
	cout << "which cipher method do you which to use: " << endl;
	cout << "1. Caesar Cipher" << endl;
	cout << "2. Keyword Cipher" << endl;
	cin >> choice;

	if (choice == "1") {
		cout << "Enter the key for the Caesar Cipher: " << endl;
		cin >> caesar_key;
		caesar_cipher();
	}
	else if (choice == "2") {
		cout << "Enter the key for the Keyword Cipher: " << endl;
		cin >> keyword_key;
	}
	else {
		cout << "Invalid choice, please try again" << endl;
		ask();
	}
}


int main()
{
	ask();
}

