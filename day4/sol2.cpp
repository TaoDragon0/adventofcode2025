#include <bits/stdc++.h>
using namespace std;

int main () {
  
  int rows;
  int columns;
  cin >> rows >> columns;

  int when_the[rows+2][columns+2];
  for (int i = 0; i < rows+2; i++) {
    when_the[i][0] = 0;
    when_the[i][columns+1] = 0;
  }
  for (int i = 0; i < columns+2; i++) {
    when_the[0][i] = 0;
    when_the[rows+1][i] = 0;
  }

  for (int row = 0; row < rows; row++) {
    string str_row;
    cin >> str_row;
    for (int column = 0; column < columns; column++) {
      if (str_row.at(column) == '@') {
        when_the[row+1][column+1] = 1;
      } else {
        when_the[row+1][column+1] = 0;
      }
    }
  }
  
  int finalres = 0;
  int new_when_the[rows+2][columns+2];
  


  for (int row = 0; row < rows + 2; row++) {
    for (int column = 0; column < columns + 2; column++) {
      new_when_the[row][column] = when_the[row][column];
    }
  }

  int res = 1;
  while (res > 0) {
    res = 0;
    for (int row = 0; row < rows; row++) {
      for (int column = 0; column < columns; column++) {
        if (when_the[row+1][column+1] == 1) {
          int sum = 0;
          for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
              sum += when_the[row+i][column+j];
            }
          }
          if (sum < 5) {
            res++;
            new_when_the[row+1][column+1] = 0;
          }
        } 
      }
    } 
    for (int row = 0; row < rows + 2; row++) {
      for (int column = 0; column < columns + 2; column++) {
        when_the[row][column] = new_when_the[row][column];
      }
    }

    finalres += res;
  }

  cout << finalres;

  return 0;
}
