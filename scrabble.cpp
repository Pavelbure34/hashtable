#include "hash_table.h"
#include <fstream>
#include <vector>
#include <map>

/*
  This is scrabble file calculating standard deviation
  for our custom hash functions

  coded by Alistaire Suh and Katie Masell.
*/

int hashFun(string &key, int slots = 1000){
    double sum = 0.0;
    for (int i = 0; i < key.length(); i++)
        sum += pow((int(key[i]) * (i + 1)),2);
    sum = sqrt(sum);
    return int(slots * (fmodl(KA * double(sum), 1)));
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
  std = sqrt(total / allValues.size());
}

int main(int argc, char const *argv[]) {
  map<int, int> hashNumLengths;
  readFile("scrabble.txt", hashNumLengths);
  outFile(hashNumLengths);
  int min, max = 0;
  double std = 0;
  getNums("scrabble.csv", min, max, std);

  cout << "<---------<Result>-------->" << endl;
  cout << "  std : " << std << endl;
  cout << "  min : " << min << endl;
  cout << "  max : " << max << endl;
  cout << "<------------------------->" << endl;
  return 0;
}
