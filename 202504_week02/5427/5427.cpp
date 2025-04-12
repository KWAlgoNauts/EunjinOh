#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs( vector<vector<int>> &vec, vector<vector<bool>> &canMove, pair<int, int> &currentLoc, queue<pair<int, pair<int, int>>> &fireLoc,int w, int h){
  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};

  queue<pair<int,pair<int, int>>> q;
  int cnt = 1;

  if(currentLoc.first == 0 || currentLoc.first == h-1 || currentLoc.second == 0 || currentLoc.second == w-1){
    return 1;
  }

  q.push({0,currentLoc});
  



  while(!q.empty()){
    while(!fireLoc.empty() && fireLoc.front().first == cnt-1){
      pair<int, int> fire = fireLoc.front().second;
      fireLoc.pop();

      for(int i = 0; i < 4; i++){
        int nx = fire.first + dx[i];
        int ny = fire.second + dy[i];        

        if(nx >= 0 && nx < h && ny >= 0 && ny < w){
          
          if(vec[nx][ny] == 1){
            vec[nx][ny] = 9;
            canMove[nx][ny] = false;
            fireLoc.push({cnt,{nx, ny}});
          }
        }
      }
    }

    while(!q.empty() && q.front().first == cnt-1){
      int x = q.front().second.first;
      int y = q.front().second.second;

      q.pop();

      for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && nx < h && ny >= 0 && ny < w){
          if((nx == 0 || nx == h-1 || ny == 0 || ny == w-1) && vec[nx][ny] == 1){
            return cnt +1;
          }

          if(vec[nx][ny] == 1 && canMove[nx][ny]){
            currentLoc = {nx, ny};
            canMove[nx][ny] = false;
            q.push({cnt, currentLoc});
          }
        }
        
      }
    }
    cnt++;
  }
  
  return -1;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout.tie(0);

  int n;

  cin >> n;

  while(n--){
    int w,h;
    int second = 0;
    cin >> w >> h;

    pair<int, int> currentLoc;
    queue<pair<int, pair<int, int>>> fireLoc;

    vector<vector<int>> vec(h, vector<int>(w, 0));
    vector<vector<bool>> canMove(h, vector<bool>(w, true));


    for(int i = 0; i < h; i++){
      for(int j = 0; j < w; j++){
        char a;
        cin >> a;
        
        switch(a){
          case '#':
            vec[i][j] = -1;
            canMove[i][j] = false;
            break;
          case '@':
            vec[i][j] = 1;
            currentLoc = {i, j};
            canMove[i][j] = false;
            break;
          case '*':
            vec[i][j] = 9;
            fireLoc.push({0,{i, j}});
            canMove[i][j] = false;
            break;
          default:
            vec[i][j] = 1;
            canMove[i][j] = true;
        }
      }
    }

    second = bfs(vec, canMove, currentLoc, fireLoc, w, h);

    if(second == -1){
      cout << "IMPOSSIBLE" << '\n';
    }else{
      cout << second << '\n';
    }

  }


  return 0;
}