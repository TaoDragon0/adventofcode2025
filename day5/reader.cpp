#include <bits/stdc++.h>
using namespace std;

int main () {
  
  ifstream file("example");

  if (!file.is_open()) {
    cerr << "error opening file";
    return 1;
  }
  
  string contents = "";
  string line;
  int numLines = 0;
  while (getline(file, line)) {
    if (line.length() == 0) {
      cout << numLines << endl;
      istringstream contentstream(contents);
      while (getline(contentstream, line)) {
        cout << line << endl;
     }

      numLines = 0;
      contents = "";
    } else {

      contents.append(line + "\n");
      numLines++;
    }
  }

  cout << numLines << endl;

  istringstream contentstream(contents);
  while (getline(contentstream, line)) {
    cout << line << endl;
  }

  return 0;
}
