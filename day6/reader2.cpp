#include <bits/stdc++.h>
using namespace std;

int main () {
  
  ifstream file("input");

  if (!file.is_open()) {
    cerr << "error opening file";
    return 1;
  }
  
  vector<string> contents;
  string line;
  int numLines = 0;
  while (getline(file, line)) {
    contents.push_back(line);
  }
  numLines = contents.size();

  cout << numLines - 1 << endl;

  for(string line : contents) {
    cout << line << "\n";
  }

  return 0;
}
