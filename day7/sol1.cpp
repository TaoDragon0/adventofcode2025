#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n;
  int k;
  cin >> n >> k;

  bool state[k];
  for(int i = 0; i < k; i++) {
    state[i] = false;
  }

  int res = 0;
  for(int i = 0; i < n; i++) {
    // no occurence of something like .^^. so we can mutate the state as we iterate through it.
    string space;
    cin >> space;
    for(int j = 0; j < k; j++) {
      if (space[j] == 'S') {
        state[j] = true;
      } else if (space[j] == '^' && state[j]) {
        // there are no ^ on the borders
        state[j-1] = true;
        state[j+1] = true;
        state[j] = false;
        res++;
      }
    }
  }

  cout << res;
  return 0;
}
