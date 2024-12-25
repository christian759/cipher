
#include <iostream>
#include <string>

using namespace std;

int caesar_key;
string word_to_cipher;
string ciphered_word;
size_t index;

string alphabet = "abcdefghijklmnopqrstuvwxyz";

void caesar_cipher();
bool check(char letter);

void caesar_cipher() {
	cout << "The word to be encrypted is: " << word_to_cipher << endl;
	for (int i = 0; i < word_to_cipher.length(); i++) {
		char letter = word_to_cipher[i];
		if (letter == ' ') {
			ciphered_word += ' ';
			continue;
		}
		if (!check(letter)) {
			ciphered_word += letter;
			continue;
		}
		size_t index = alphabet.find(tolower(letter));
		int new_index = (index + caesar_key) % 26;
		ciphered_word += alphabet[new_index];
	}

	cout << "The ciphered word is: " << ciphered_word << endl;
}

bool check(char letter) {
	for (int i = 0; i < alphabet.length(); i++) {
		if (letter == alphabet[i]) {
			return true;
		}
	}
	return false;
}

void ask() {
	cout << "Enter the key for the Caesar Cipher: " << endl;
	cin >> caesar_key;
	cout << "Enter the word to be encrypted: " << endl;
	cin.ignore();
	getline(cin, word_to_cipher);
	caesar_cipher();

	word_to_cipher.clear();
	ciphered_word.clear();
}


int main()
{
	ask();
}

