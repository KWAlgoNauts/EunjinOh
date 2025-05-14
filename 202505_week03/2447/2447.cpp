#include<iostream>
#include<vector>

using namespace std;
char MAP[6561][6561];
void space(int x, int y, int n);


void recusive(int x, int y, int n){
  if(n == 3){
    MAP[x][y]= '*';
    MAP[x][y+1]= '*';
    MAP[x][y+2]= '*';
    MAP[x+1][y]= '*';
    MAP[x+1][y+1]= ' ';
    MAP[x+1][y+2]= '*';
    MAP[x+2][y]= '*';
    MAP[x+2][y+1]= '*';
    MAP[x+2][y+2]= '*';
  }else{
    recusive(x, y, n/3);
    recusive(x, y + n/3, n/3);
    recusive(x, y + 2*n/3, n/3);
    recusive(x + n/3, y, n/3);
    space(x + n/3, y + n/3, n/3);
    recusive(x + n/3, y + 2*n/3, n/3);
    recusive(x + 2*n/3, y, n/3);
    recusive(x + 2*n/3, y + n/3, n/3);
    recusive(x + 2*n/3, y + 2*n/3, n/3);
  }
}
void space(int x, int y, int n){
  for(int i = x; i < x + n; i++){
    for(int j = y; j < y + n; j++){
      MAP[i][j] = ' ';
    }
  }
}

int main(){
  int n;
  cin >> n;

  recusive(0, 0, n);

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << MAP[i][j];
    }
    cout << '\n';
  }

  return 0;
}