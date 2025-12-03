#include <bits/stdc++.h>
using namespace std;

int main () {
  
  ifstream file("input");

  if (!file.is_open()) {
    cerr << "error opening file";
    return 1;
  }
  
  string contents;
  string line;
  int numLines = 0;
  while (getline(file, line)) {
    contents.append(line + "\n");
    numLines++;
  }

  cout << numLines << endl;

  istringstream contentstream(contents);
  while (getline(contentstream, line)) {
    cout << line << endl;
  }

  return 0;
}
