#include "dictionary.h"
#include "constants.h"
using namespace std;
Dictionary::Dictionary( vector <string>& words)
{
	d_root = new TrieNode();
	for(auto word:words){
        addWord(word);
	}
}

TrieNode* Dictionary::getNewNode(){
    TrieNode* new_node = new TrieNode();
    return new_node;
}

void Dictionary::addWord(const string& word){
    TrieNode *current = d_root;
    for (auto character:word)
    {
        if (current->children[character]==nullptr)
        {
            current->children[character] = getNewNode();
        }
        current = current->children[character];
    }
    current->is_end_of_word = true;
}

bool Dictionary::isWordPresent(const string& word){
    TrieNode *current = d_root;
    for (auto character:word)
    {
        if (current->children[character]!=nullptr) {
            current = current->children[character];
        } else {
            return false;
        }
    }
    return  (current != nullptr && current->is_end_of_word );
}

