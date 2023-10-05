#include<iostream>
#include<cstring>
using namespace std;

// The length of modified string won't exceed two times of the original one
const int N = 2005; 

int isMark(char c){
    if(c == '.' || c == ',' || c == '!' || c == ')' || c == '('){
        return 1;
    }
    return 0;
}

int main(){
    char s[N];
    cin.getline(s, N);

    int len = strlen(s);

    for(int i = 0; i < len; i++){
        if(s[i] == '.' || s[i] == ',' || s[i] == '!' || s[i] == ')'){
            if(i > 0 && s[i-1] == ' '){
                for(int j = i-1; j < len; j++){
                    s[j] = s[j+1];
                }
                
                len--;
                
                // The former char is deleted, so the index should be decreased by 1
                i--;
            }

            if(i < len-1 && s[i+1] != ' '){
                for(int j = len; j > i+1; j--){
                    s[j] = s[j-1];
                }

                s[i+1] = ' ';
                len++;
            }
            
            if(i < len-2 && s[i] == ')' && isMark(s[i+2]) && s[i+1] == ' '){
                for(int j = i+1; j < len; j++){
                    s[j] = s[j+1];
                }

                len--;
            }
        }
        else if(s[i] == '('){
            if(i < len-1 && s[i+1] == ' '){
                for(int j = i+1; j < len; j++){
                    s[j] = s[j+1];
                }

                len--;
            }
            
            if(i != 0 && s[i-1] != ' '){
                for(int j = len; j > i; j--){
                    s[j] = s[j-1];
                }

                s[i] = ' ';
                len++;
            }
        }

        if(i == len-1 && s[i] == ' ') len--;
    }

    for(int i = 0; i < len; i++){
        cout << s[i];
    }
    cout << "\n";

    return 0;
}