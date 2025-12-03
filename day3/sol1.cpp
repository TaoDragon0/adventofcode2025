#include <bits/stdc++.h>
using namespace std;

int main () {
  
  int res = 0;
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {

    string batteries;
    cin >> batteries;
    
    int max = 0;
    int maxafter = 0;

    int length = batteries.length();
    //cout << length << endl;
    for (int j = 0; j < length; j++) {
      int joltage_digit = stoi(batteries.substr(j, 1));
      if ((joltage_digit > max) && (j < length - 1)) {
        max = joltage_digit;
        maxafter = 0;
      } else if (joltage_digit > maxafter) {
        maxafter = joltage_digit;
      }
    }

    res += 10*max + maxafter;
    cout << res << endl;

  }
  
  cout << endl << res << endl;
  return 0;
}
