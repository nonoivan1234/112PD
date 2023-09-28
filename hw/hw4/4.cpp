#include<iostream>
using namespace std;
const int INF = 1e9+5;

int d1(int* movieListSizes, int** movieLists, int** scoreLists, int MovieNum,int r, int p){
    int ret = 0;
    for(int i = 1; i <= MovieNum; i++){
        int x1 = 0, x2 = 0;
        for(int j = 0; j < movieListSizes[r]; j++){
            if(movieLists[r][j] == i){
                x1 = scoreLists[r][j];
                break;
            }
        }
        for(int j = 0; j < movieListSizes[p]; j++){
            if(movieLists[p][j] == i){
                x2 = scoreLists[p][j];
                break;
            }
        }

        if(x1 > x2) ret += x1 - x2;
        else ret += x2 - x1;
    }

    return ret;
}

int d2(int* movieListSizes, int** movieLists, int** scoreLists, int MovieNum,int r, int p){
    int ret = 0;
    for(int i = 1; i <= MovieNum; i++){
        bool ok1 = 0, ok2 = 0;
        for(int j = 0; j < movieListSizes[r]; j++){
            if(movieLists[r][j] == i){
                ok1 = 1;
                break;
            }
        }
        for(int j = 0; j < movieListSizes[p]; j++){
            if(movieLists[p][j] == i){
                ok2 = 1;
                break;
            }
        }

        if(ok1 != ok2) ret++;
    }

    return ret;
}

int ScoreSum(int* movieListSizes, int** movieLists, int** scoreLists, int MemberNum, int Movie, int &MovieRatedNum){
    int sum = 0;
    for(int i = 0; i < MemberNum; i++){
        for(int j = 0; j < movieListSizes[i]; j++){
            if(movieLists[i][j] == Movie){
                sum += scoreLists[i][j];
                MovieRatedNum++;
            }
        }
    }
    return sum;
}

int main(){
    int MemberNum = 0, MovieNum = 0, Member = 0;
    cin >> MemberNum >> MovieNum >> Member;

    int* movieListSizes = new int[MemberNum];
    int** movieLists = new int*[MemberNum];
    int** scoreLists = new int*[MemberNum];

    // Create adjacency list for each member and score
    for(int i = 0; i < MemberNum; i++){
        cin >> movieListSizes[i];
        movieLists[i] = new int[movieListSizes[i]];
        scoreLists[i] = new int[movieListSizes[i]];
        for(int j = 0; j < movieListSizes[i]; j++){
            cin >> movieLists[i][j] >> scoreLists[i][j];
        }
    }
    
    int min = INF, minIndex = -1;
    for(int i = 0; i < MemberNum; i++){
        if(i == Member - 1) continue;
        int temp = d1(movieListSizes, movieLists, scoreLists, MovieNum, Member - 1, i);
        if(temp < min){
            min = temp;
            minIndex = i;
        }
        else if(temp == min){
            if(d2(movieListSizes, movieLists, scoreLists, MovieNum, Member - 1, i) < d2(movieListSizes, movieLists, scoreLists, MovieNum, Member - 1, minIndex)){
                min = temp;
                minIndex = i;
            }
        }
    }

    int mx = -1, ind = -1;

    for(int i = 0; i < movieListSizes[minIndex]; i++){
        bool ok = 0;
        for(int j = 0; j < movieListSizes[Member - 1]; j++){
            if(movieLists[minIndex][i] == movieLists[Member - 1][j]){
                ok = 1;
                break;
            }
        }
        if(!ok){
            if(scoreLists[minIndex][i] > mx){
                mx = scoreLists[minIndex][i];
                ind = movieLists[minIndex][i];
            }
        }
    }

    int maxScoreSum = -1, maxScoreSumMovie = -1, maxScoreSumMovieRatedNum = 0;
    if(mx != -1){
        maxScoreSum = ScoreSum(movieListSizes, movieLists, scoreLists, MemberNum, ind, maxScoreSumMovieRatedNum);
        maxScoreSumMovie = ind;
    }
    else{
        int MovieIndex = 1, MovieRatedNum = 0;
        maxScoreSum = -1, maxScoreSumMovie = -1, maxScoreSumMovieRatedNum = 0;

        for(int i = 0; i < movieListSizes[Member - 1]; i++){
            for(int j = MovieIndex; j < movieLists[Member - 1][i]; j++){
                int tempScoreSum = ScoreSum(movieListSizes, movieLists, scoreLists, MemberNum, j, MovieRatedNum);
                if(tempScoreSum > maxScoreSum){
                    maxScoreSum = tempScoreSum;
                    maxScoreSumMovie = j;
                    maxScoreSumMovieRatedNum = MovieRatedNum;
                }
                else if(tempScoreSum == maxScoreSum && MovieRatedNum > maxScoreSumMovieRatedNum){
                    maxScoreSum = tempScoreSum;
                    maxScoreSumMovie = j;
                    maxScoreSumMovieRatedNum = MovieRatedNum;
                }
                MovieRatedNum = 0;
            }
            MovieIndex = movieLists[Member - 1][i] + 1;
        }

        // Check the last unseen movie
        for(int i = MovieIndex; i <= MovieNum; i++){
            int tempScoreSum = ScoreSum(movieListSizes, movieLists, scoreLists, MemberNum, i, MovieRatedNum);
            if(tempScoreSum > maxScoreSum){
                maxScoreSum = tempScoreSum;
                maxScoreSumMovie = i;
                maxScoreSumMovieRatedNum = MovieRatedNum;
            }
            else if(tempScoreSum == maxScoreSum && MovieRatedNum > maxScoreSumMovieRatedNum){
                maxScoreSum = tempScoreSum;
                maxScoreSumMovie = i;
                maxScoreSumMovieRatedNum = MovieRatedNum;
            }
            MovieRatedNum = 0;
        }
    }

    cout << maxScoreSumMovie << "," << maxScoreSumMovieRatedNum << "," << maxScoreSum << "\n";
}