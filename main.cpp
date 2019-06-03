#include <bits/stdc++.h>
#include <fstream>
#include <windows.h>
#include <conio.h>
using namespace std;
const int csize= 26;
string a="                                                                                              ";
vector < string > v;
struct TrieNode{
    TrieNode *children[csize];
    bool eow;
};
int count1=0;
TrieNode* newnode(){
    TrieNode * temp= new  TrieNode;
    temp->eow =false;
    for(int i=0;i<csize;i++){
        temp->children[i]=NULL;
    }
    return temp;
}
bool islastnode(TrieNode* root)
{
    for(int i = 0; i < csize; i++)
        if (root->children[i])
            return 0;
    return 1;
}
void insert(TrieNode* root , string s){
    TrieNode* temp=root;
    for(int i=0;i<s.length();i++){
        int index=s[i]-'a';
        if(!temp->children[index]){
            TrieNode* temp1=newnode();
            temp->children[index]=temp1;
        }
        temp=temp->children[index];
    }
    temp->eow=true;
    return ;
}
bool search(TrieNode* root, string s){
    TrieNode* temp=root;
    for(int i=0;i<s.length();i++){
        int index=s[i]-'a';
        if(temp->children[index]){
            temp=temp->children[index];
        }
        else {
            return false;
        }
    }
    if(temp && temp->eow){
        return true;
    }
    else
    {
        return false;
    }

}

void suggestions(TrieNode* root, string s)
{
    if(count1<5)
    {
    if (root->eow)
    {
        v.push_back(s);
        count1++;
        //cout <<s<<'\n';
    }

    }
    else
    {
        return ;
    }
    if (islastnode(root))
        return;
    for (int i = 0; i <csize; i++)
    {
        if (root->children[i])
        {
            s.push_back(97 + i);
            suggestions(root->children[i],s);
        }
    }
}
int getsuggestions(TrieNode* root,string query)
{
    TrieNode* temp = root;

    int n = query.length();
    for (int level = 0; level < n; level++)
    {
        int index = query[level]-'a';
        if (!temp->children[index])
            return 0;
        temp= temp->children[index];
    }
    bool isword =temp->eow;
    bool islast = islastnode(temp);
    if (isword && islast)
    {
        v.push_back(query);
        return -1;
    }
    if (!islast)
    {
        suggestions(temp, query);
        return 1;
    }
}

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos1 = {1, 10};
    COORD pos2;
    TrieNode* root=newnode();
    ifstream fin;
    fin.open("words2.txt");
    string s1;
    int i=1;
    while (fin) {
        getline(fin,s1);
        transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
        insert(root,s1);
        i++;
    }
    fin.close();
    char c;
    i=0;
    string temp="";
    count1=0;
    char s[300];
    do{
        count1=0;
        pos2={i,0};
        SetConsoleCursorPosition(hConsole, pos2);
        c=getch();
        putc(c,stdout);
        i++;
        cout<<"\n\n\n\n\n\n\n"<<a<<flush;
        SetConsoleCursorPosition(hConsole, pos2);

      if(c!=' '){
        temp+=c;
      }
      else
      {
          temp="";
          continue;
      }
      putc(c,stdout);
      v.clear();
      int x=0;
      getsuggestions(root,temp);
      int n=v.size();
      string t="";
      for(int i=0;i<min(5,n);i++){
        t+=v[i];
        t+=" ";
      }
      cout<<"\n\n\n\n\n\n\n"<<t;
        /*strcpy(s, t.c_str());
        pos1 = {x,12};
        SetConsoleCursorPosition(hConsole, pos1);
        WriteConsole(hConsole,s,5,NULL,NULL);
        */
      v.clear();

    }while(c!='\n');

    return 0;
}
