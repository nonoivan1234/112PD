#include<iostream>
using namespace std;

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

    // Find the unseen movie with the highest score sum for the given member
    int MovieIndex = 1, MovieRatedNum = 0;
    int maxScoreSum = -1, maxScoreSumMovie = -1, maxScoreSumMovieRatedNum = 0;
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
    

    cout << maxScoreSumMovie << "," << maxScoreSumMovieRatedNum << "," << maxScoreSum << "\n";
}