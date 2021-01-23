#include <iostream>
#include "constants.h"
#include "filereader.h"
#include "dictionary.h"
using namespace std;
int main() {

	cout << "Welcome to your personal dictionary " << endl;
	string file_path = "words.txt";
	FileReader*file_reader = new FileReader(".",file_path);
	auto words = file_reader->getWords();
	Dictionary* dictonary = new Dictionary(words);

}
