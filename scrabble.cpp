#include "hash_table.h"
#include <fstream>
#include <map>

/*
  This is scrabble.
*/

int hashFun(string &s){
  int sum;
  for (int i = 0; i < s.length(); i++)
      sum += s[i];
  sum = sum / s.length();
  double A = (sqrt(5) - 1) / 2;
  return 1000 * (fmod(A * double(sum), 1));
}

void readFile(std::string file,  map<int, int> &hashNumLengths){
  std::ifstream inputFile(file);
  string s;
  if (inputFile.fail()){
    std::cerr << "Error opening file";
    return;
  }
  int hashNum;
  while(inputFile >> s){
    hashNum = hashFun(s);
    if(hashNumLengths.count(hashNum))
      hashNumLengths[hashNum] ++;
    else
      hashNumLengths[hashNum] = 1;
   }

  inputFile.close();
}

int main(int argc, char const *argv[]) {
  map<int, int> hashNumLengths;
  readFile("scrabble.txt", hashNumLengths);
  ofstream o;
  o.open("scrabble.csv");
  o << "key, value\n";
  for (auto pair: hashNumLengths){
    o << pair.first << ", " << pair.second << endl;
  }
  o.close();
  return 0;
}
