#include <bits/stdc++.h>
using namespace std;

int main () {
  
  int n;
  cin >> n;
  string dummy;
  getline(cin, dummy);

  vector<vector<char>> contents;
  for (int i = 0; i < n+1; i++) {
    string line;
    getline(cin, line);
    vector<char> line_vector(line.begin(), line.end());
    contents.push_back(line_vector);
  }

  int numColumns = contents.at(0).size();
  //cout << n << " ";
  //cout << numColumns << " ";

  vector<vector<char>> contents_rotated;
  for (int i = 0; i < numColumns; i++) {
    vector<char> v;
    contents_rotated.push_back(v);
  }
  for (int i = 0; i < n+1; i++) {
    vector<char> row = contents.at(i);
    for (int j = 0; j < numColumns; j++) {
      contents_rotated.at(numColumns - j - 1).push_back(row.at(j));
    }
  }
  
  for (int i = 0; i < numColumns; i++) {
    for (int j = 0; j < n+1; j++) {
      cout << contents_rotated.at(i).at(j);
      cout << " ";
    }
    cout << endl;
  }
  //cout << contents_rotated.size();

  long long res = 0;
  vector<long long> numbers;
  for(vector<char> line : contents_rotated) {
    long long number;
    string number_string(line.begin(), line.end() - 1);
    if (number_string.find_first_not_of(' ') != string::npos) {
      //number_string.erase(remove_if(number_string.begin(), number_string.end(), isspace), number_string.end());
      number = stoll(number_string);
      numbers.push_back(number);
      if (line.back() == '+') {
        long long addres = 0;
        for(long long number : numbers) {
          addres += number;
        }
        res += addres;
        numbers.clear();
  
      } else if (line.back() == '*') {
        long long multres = 1;
        for(long long number : numbers) {
          multres *= number;
        }
        res += multres;
        numbers.clear();
      }
    }
  }

  cout << res << endl;

  return 0;
}
