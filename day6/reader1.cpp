#include <bits/stdc++.h>
using namespace std;

int main () {
  
  ifstream file("input");

  if (!file.is_open()) {
    cerr << "error opening file";
    return 1;
  }
  
  vector<vector<string>> contents;
  string line;
  int numLines = 0;
  int numProblems = 0;
  while (getline(file, line)) {
    vector<string> line_vector;
    stringstream linestream(line);
    string token;
    while(getline(linestream, token, ' ')) {
      if (token.length() != 0) {
        line_vector.push_back(token);
      }
    }
    numProblems = line_vector.size();
    contents.push_back(line_vector);
  }
  numLines = contents.size();

  cout << numLines - 1 << " " << numProblems << endl;

  for(vector<string> line : contents) {
    for(string number : line) {
      cout << number << " ";
    }
    cout << "\n";
  }

  return 0;
}
