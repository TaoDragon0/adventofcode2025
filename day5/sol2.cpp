#include <bits/stdc++.h>
using namespace std;

int main () {
  
  int n;
  cin >> n;
  //cout << n << endl;

  vector<long long> lowers;
  vector<long long> uppers;

  for (int i = 0; i < n; i++) {
    long long lower;
    long long upper;
    cin >> lower >> upper;
    upper *= -1; // vro i have to do this bc the dash gets interpreted as a negative symbol
    //cout << "what " <<  lower << " and " << upper << endl;
    {
      int min_index = 0;
      int max_index = lowers.size() - 1;
      while (max_index - min_index > 1) {
        int new_index = (min_index + max_index) / 2;
        if (lowers[new_index] < lower) {
          min_index = new_index;
        } else {
          max_index = new_index;
        }
      }
      if (lowers.size() == 0 || lowers[max_index] < lower) {
        lowers.push_back(lower);
      } else if (lowers[min_index] < lower) {
        lowers.insert(lowers.begin() + max_index, lower);
      } else {
        lowers.insert(lowers.begin() + min_index, lower);
      }
    }
    
    {
      int min_index = 0;
      int max_index = uppers.size() - 1;
      while (max_index - min_index > 1) {
        int new_index = (min_index + max_index) / 2;
        if (uppers[new_index] < upper) {
          min_index = new_index;
        } else {
          max_index = new_index;
        }
      }
      if (uppers.size() == 0 || uppers[max_index] < upper) {
        uppers.push_back(upper);
      } else if (uppers[min_index] < upper) {
        uppers.insert(uppers.begin() + max_index, upper);
      } else {
        uppers.insert(uppers.begin() + min_index, upper);
      }
    }

  }

  long long res = 0;
  int lower_index = 1;
  int upper_index = 0;
  long long low_bound = lowers[0];
  while (lower_index < lowers.size()) {
    if (uppers[upper_index] < lowers[lower_index]) {
      res += uppers[upper_index] - low_bound + 1;
      low_bound = lowers[lower_index];
    }
    lower_index++;
    upper_index++;
  }
  res += uppers[upper_index] - low_bound + 1;

  cout << endl << res << endl;

  return 0;
}
