/*
    katie / Alistaire - CS 271 - Fall 2019

    this is imdb2.
*/
#include <iostream>
#include <fstream>
#include <string>
#include "dict.h"
#include <sys/time.h>
using namespace std;

void readFile(string file, dictionary<hashNode<string, string>>& movies){
    ifstream imdbFile;
    imdbFile.open(file);
    string line;
    int howMany = 0;
    string movieKey, movieValue;
    int i = 0;
    while(getline(imdbFile, line, '\t')){
        if(howMany == 2)
            movieKey = line;
        if(howMany == 8){
            movieValue = line;
            howMany = 0;
            string adjustedValue = "";
            int i = 0;
            while(movieValue[i] != '\n'){
                adjustedValue = adjustedValue + movieValue[i];
                i++;
            }
            if(adjustedValue == "\\N") { //check for movies without a genre
                adjustedValue = "No Genre Available";
            }
            hashNode<string, string> *newNode = new hashNode<string, string>(movieKey, adjustedValue);
            // hashNode<string, string> newNode(movieKey, adjustedValue);
            // cout << temp->toString() << endl;
            // movies.insert(new hashNode<string, string>(movieKey, adjustedValue));
            // movies.insert(&newNode);
            movies.insert(newNode);
            delete newNode;
            cout << movies.itemNum() << endl;
          }
        howMany ++;
    }
    imdbFile.close();
}

string getMovieGenre(dictionary<hashNode<string, string>> movies, string s){
    try{
      string get;
      hashNode<string, string> targetNode(s, "");
      hashNode<string, string> moviegen = *(movies.get(targetNode));
      get = moviegen.value;
      return get;
    }catch(noKeyException *e){
      throw new noKeyException;
    }
}

int main(int argc, char const *argv[]){
    ofstream o;
    o.open("hashtableTime.txt");
    timeval timeBefore, timeAfter;          //time variables
    long diffSeconds, diffUSeconds;

    string s = "";
    string g;
    dictionary<hashNode<string, string>> movies(100000000);

    gettimeofday(&timeBefore, NULL);     //time count init
    readFile("data.tsv", movies);
    gettimeofday(&timeAfter, NULL);       //time count done

    //calculating run time of encoding under hashTable based dictionary
    diffSeconds = timeAfter.tv_sec - timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec - timeBefore.tv_usec;
    o << "data.tsv with hashtable:" << diffSeconds + (diffUSeconds/1000000.0) << "\n";//writing on csv
    o.close();
    //time calculated complete

    cout << "Welcome to our movie collection" << endl;
    cout << "----------------------------------" << endl;
    cout << "Type a movie that you are interested in:  ";
    while(true){
        cout << "//type exit program to quit program//" << endl;
        cout << "Movie title >> ";
        getline(cin, s);
        if (s == "exit program")
          return false;
        cout << endl;
        try{
          g = getMovieGenre(movies, s);
          cout << s << " : " << g << endl;;
        }catch(noKeyException *e){
          cout << "no movie found" << endl;
        }
    }
    return 0;
}
