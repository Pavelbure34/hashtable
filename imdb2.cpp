/*
    katie / Alistaire - CS 271 - Fall 2019
*/
#include <iostream>
#include <fstream>
#include <string>
#include "dict.h"
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
            hashNode<string, string> *temp = new hashNode<string, string>(movieKey, adjustedValue);
            movies.insert(temp);
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
    string s = "";
    string g;
    dictionary<hashNode<string, string>> movies;
    readFile("data.tsv", movies);
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
