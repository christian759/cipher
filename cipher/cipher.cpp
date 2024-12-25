
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int caesar_key;
string word_to_cipher;
string ciphered_word;

string alphabet = "abcdefghijklmnopqrstuvwxyz";

void caesar_cipher();

void caesar_cipher() {
	for (int i = 0; i < word_to_cipher.length(); i++) {
		char letter = word_to_cipher[i];
		int index = alphabet.find(letter);
		int new_index = (index + caesar_key) % 26;
		ciphered_word += alphabet[new_index];
	}

	cout << "The ciphered word is: " << ciphered_word << endl;
}

void ask() {
	cout << "Enter the key for the Caesar Cipher: " << endl;
	cin >> caesar_key;
	cout << "Enter the word to be encrypted: " << endl;
	cin >> word_to_cipher;
	caesar_cipher();

	word_to_cipher.clear();
	ciphered_word.clear();
}


int main()
{
	ask();
}

