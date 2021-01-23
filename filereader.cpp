#include "filereader.h"
#include <filesystem>
#include <iostream>
using namespace std;

FileReader::FileReader(const string& directory, const string& file_name){
    string word;
    d_words.clear();
    string file_path = directory + '/' + file_name;
    cout << file_path <<endl;
    freopen(file_path.c_str(), "r", stdin);
    while(cin>>word){
        d_words.push_back(word);
    }
    fclose (stdout);
}

vector < string>  FileReader::getWords() const{
    return d_words;
}

void FileReader::addWord(const string& word){
    d_words.push_back(word);
}

void FileReader::addWords(vector < string > & words){
    d_words.insert(d_words.end(),words.begin(),words.end());
}


