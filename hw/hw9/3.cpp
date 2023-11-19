#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
using namespace std;

char* ToLower(char *str){
    for(int i = 0; i < strlen(str); i++){
        if(isupper(str[i])) str[i] = tolower(str[i]);
    }
    return str;
}

class Dictionary{
public:
    Dictionary(string path);
    int GetSize() {return size;};
    char* GetWord(int index)    {return words[index];};
    ~Dictionary();
private:
    ifstream dict;
    string path;
    char **words;
    int size;
};

Dictionary::Dictionary(string path){
    this->path = path;
    dict.open(path);
    dict >> size;
    words = new char*[size];
    for(int i = 0; i < size; i++){
        words[i] = new char[10005];
        dict >> words[i];
        words[i] = ToLower(words[i]);
    }
}

Dictionary::~Dictionary(){
    for(int i = 0; i < size; i++){
        delete [] words[i];
        words[i] = nullptr;
    }
    delete [] words;
    words = nullptr;
    dict.close();
}

class Article{
public:
    Article(string path);
    int CntWord(Dictionary &dict);
    ~Article();
private:
    ifstream article;
    string path;
    char text[10005];
};

Article::Article(string path){
    this->path = path;
    article.open(path);
    article.getline(text, 10005);
}

int Article::CntWord(Dictionary &dict){
    int cnt = 0;

    char *now;
    now = strtok(text, " ,.?!;:\"\'");
    while(now != nullptr){
        now = ToLower(now);
        for(int i = 0; i < dict.GetSize(); i++){
            if(strcmp(now, dict.GetWord(i)) == 0){
                cnt++;
                break;
            }
        }
        now = strtok(NULL, " ,.?!;:\"\'");
    }

    return cnt;
}

Article::~Article(){
    article.close();
}

int main(){
    string ArticlePath, DictionaryPath;
    getline(cin, ArticlePath);
    getline(cin, DictionaryPath);

    // For Linux Debug
    // ArticlePath.insert(0, ".");
    // DictionaryPath.insert(0, ".");

    Dictionary dict(DictionaryPath);
    Article article(ArticlePath);

    cout << article.CntWord(dict) << "\n";

    return 0;
}