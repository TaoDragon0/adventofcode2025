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
    if (lowers.size() == 0 || lower > lowers[lowers.size() - 1]) {
      lowers.push_back(lower);
    } else if (lower < lowers[0]) {
      lowers.insert(lowers.begin(), lower);
    } else {
      int min_index = 0;
      int max_index = lowers.size();
      while (max_index - min_index > 1) {
        int new_index = (min_index + max_index) / 2;
        if (lowers[new_index] < lower) {
          min_index = new_index;
        } else {
          max_index = new_index;
        }
      }
      lowers.insert(lowers.begin() + max_index, lower);
    }

    if (uppers.size() == 0 || upper > uppers[uppers.size() - 1]) {
      uppers.push_back(upper);
    } else if (upper < uppers[0]) {
      uppers.insert(uppers.begin(), upper);
    } else {
      int min_index = 0;
      int max_index = uppers.size();
      while (max_index - min_index > 1) {
        int new_index = (min_index + max_index) / 2;
        if (uppers[new_index] < upper) {
          min_index = new_index;
        } else {
          max_index = new_index;
        }
      }
      uppers.insert(uppers.begin() + max_index, upper);
    }

  }

  cout << lowers[0] << endl;
  cout << uppers[0] << endl;
  
  cout << "cool" << endl;
  int n2;
  cin >> n2;
  
  int res = 0;

  for (int i = 0; i < n2; i++) {
    long long id;
    cin >> id;
    
    // binary search lower

    // binary search upper

    if (upper_index < lower_index) {
      cout << id << " is fresh: " << upper_index << "less than" << lower_index << endl;
      res++;
    } else {
      cout << id << " is spoiled: " << upper_index << "not less than"
    }

  }

  cout << res;

  return 0;
}
