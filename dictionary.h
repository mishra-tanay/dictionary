#include <string.h>
#include <map>
#include <vector>
using namespace std;
struct TrieNode
{
    map <char,TrieNode*> children;
    bool is_end_of_word;
    TrieNode(){
        is_end_of_word = false;
    }
};

class Dictionary {
public:
	Dictionary(vector <string> &words);

	void addWord(const string& word);

	void deleteWord(const string& word);

	int countWords();

	bool isWordPresent(const string& word);

protected:
    TrieNode* getNewNode();

private:
    TrieNode* d_root = nullptr;
};
