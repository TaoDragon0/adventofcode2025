#include <bits/stdc++.h>
using namespace std;

int main () {
  
  long long res = 0;
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {

    string batteries;
    cin >> batteries;
    
    int joltage_digits[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 

    int length = batteries.length();
    //cout << length << endl;
    for (int j = 0; j < length; j++) {
      int joltage_digit = stoi(batteries.substr(j, 1));
      for (int k = 0; k < 12; k++) {
        if ((joltage_digit > joltage_digits[k]) && (j < length - 11 + k)) {
          joltage_digits[k] = joltage_digit;
          for (int k2 = k+1; k2 < 12; k2++) {
            joltage_digits[k2] = 0;
          }
          break;
        }
      }
    }
    
    long long addthis = 0;
    for (int j = 0; j < 12; j++) {
      addthis *= 10;
      addthis += joltage_digits[j];
    }
    res += addthis;
    cout << res << endl;

  }
  
  cout << endl << res << endl;
  return 0;
}
