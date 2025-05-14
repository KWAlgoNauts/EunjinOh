#include <iostream>

using namespace std;

char MAP[3072][6144];

void star(int x, int y, int n) {
  if(n==3){
    MAP[x][y] = '*';
    MAP[x+1][y-1]= '*';
    MAP[x+1][y+1]= '*';
    MAP[x+2][y-2]= '*';
    MAP[x+2][y-1]= '*';
    MAP[x+2][y]= '*';
    MAP[x+2][y+1]= '*';
    MAP[x+2][y+2]= '*';
    MAP[x+2][y+2]= '*';
  }
  else{
    star(x, y, n/2);
    star(x+n/2, y-n/2, n/2);
    star(x+n/2, y+n/2, n/2);
  }
}

int main(){
  fill(&MAP[0][0], &MAP[3071][6144], ' ');

  int n;
  cin >> n;

  star(0, n-1, n);

  for(int i = 0; i < n; i++){
    for(int j = 0; j < 2*n; j++){
      cout << MAP[i][j];
    }
    cout << '\n';
  }

  return 0;
}