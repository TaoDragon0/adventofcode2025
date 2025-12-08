#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int noLines;
  int noProblems;
  cin >> noLines >> noProblems;
  
  vector<pair<long long, long long>> problems;
  for (int j = 0; j < noProblems; j++) {
    problems.push_back(make_pair(0, 1));
  }

  for (int i = 0; i < noLines; i++) {
    for (int j = 0; j < noProblems; j++) {
      int number;
      cin >> number;
      problems.at(j).first += number;
      problems.at(j).second *= number;
    }
  }

  long long res = 0;
  for (int j = 0; j < noProblems; j++) {
    string operation;
    cin >> operation;
    if (operation == "*") {
      //cout << "* ";
      res += problems.at(j).second;
    } else if (operation == "+") {
      //cout << "+ ";
      res += problems.at(j).first;
    } else {
      cerr << "encountered unknown operation [" << operation << "].";
      return 1;
    }
  }
  
  cout << res << "\n";

  return 0;
}
