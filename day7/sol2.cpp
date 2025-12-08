#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n;
  int k;
  cin >> n >> k;

  long long state[k];
  for(int i = 0; i < k; i++) {
    state[i] = 0;
  }

  for(int i = 0; i < n; i++) {
    // no occurence of something like .^^. so we can mutate the state as we iterate through it.
    string space;
    cin >> space;
    for(int j = 0; j < k; j++) {
      if (space[j] == 'S') {
        state[j] += 1;
      } else if (space[j] == '^' && state[j]) {
        // there are no ^ on the borders
        state[j-1] += state[j];
        state[j+1] += state[j];
        state[j] = 0;
      }
    }
  }
  
  long long res = 0;
  for(int i = 0; i < k; i++) {
    res += state[i];
  }
  cout << res;
  return 0;
}
