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
    if (line.at(0) == 'L') {
      contents.append("-");
    }
    contents.append(line.substr(1,line.length()-1) + "\n");
    numLines++;
  }

  cout << numLines << endl;

  istringstream contentstream(contents);
  while (getline(contentstream, line)) {
    cout << line << endl;
  }

  return 0;
}
