#include <string>
#include <vector>
using namespace std;

class FileReader {
public:
    FileReader(const string& directory,const string& path_name);

    vector <string> getWords() const;

    void addWord(const string& word);

    void addWords(vector < string > & words);

    int countWords() const{ return d_words.size();}

private:
    vector <string> d_words;
};
