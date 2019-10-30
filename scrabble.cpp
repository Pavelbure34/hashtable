#include "hash_table.h"
#include <fstream>
#include <vector>
#include <map>

/*
  This is scrabble.
*/

int hashFun(string &s){
    double sum = 0.0;
    for (int i = 0; i < s.length(); i++)
        sum += (int(s[i]) * (i + 1));
    sum = sum / double(s.length());
    double A = (sqrt(5) - 1) / 2; 
    return 1000 * (fmod(A * double(sum), 1));
}

void readFile(std::string file,  map<int, int> &hashNumLengths){
  ifstream inputFile(file);
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

void outFile(map<int, int> hashNums){
  ofstream o;
  o.open("scrabble.csv");
  o << "key, value\n";
  for (auto pair: hashNums){
    o << pair.first << ", " << pair.second << endl;
  }
  o.close();
}

void getNums(string file, int &min, int& max, double& std){
  ifstream inputFile(file);
  string s;
  string num;
  if (inputFile.fail()){
    std::cerr << "Error opening file";
    return;
  }
  vector<int> allValues;
  inputFile >> s >> num;
  while (inputFile >> s >> num){
    allValues.push_back(stoi(num));
  }
  min = allValues[0];
  max = allValues[0];
  int sum = 0;
  for (int i = 0; i < allValues.size(); i++){
    if (allValues[i] < min)
      min = allValues[i];
    if (allValues[i] > max)
      max = allValues[i];
    sum += allValues[i];
  }
  double mean = sum / allValues.size();
  double total = 0.0;
  for (int i = 0; i < allValues.size(); i++){
    total += pow((allValues[i] - mean), 2);
  }
  std = sqrt(total/allValues.size());
}

int main(int argc, char const *argv[]) {
  map<int, int> hashNumLengths;
  readFile("scrabble.txt", hashNumLengths);
  outFile(hashNumLengths);
  int min, max = 0;
  double std = 0;
  getNums("scrabble.csv", min, max, std);
  cout << std << endl;
  return 0;
}
