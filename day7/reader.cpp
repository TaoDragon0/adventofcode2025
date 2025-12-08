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
  int lineLength;
  while (getline(file, line)) {
    contents.append(line + "\n");
    numLines++;
    lineLength = line.length();
  }

  cout << numLines << " " << lineLength << endl;

  istringstream contentstream(contents);
  while (getline(contentstream, line)) {
    cout << line << endl;
  }

  return 0;
}
