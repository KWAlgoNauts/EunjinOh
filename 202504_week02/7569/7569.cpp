#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int cnt = 0;
queue<pair<int, pair<int, int>>> q1;
queue<pair<int, pair<int, int>>> q2;

int bfs(int h, int n, int m, vector<vector<vector<int>>>& vec, vector<vector<vector<bool>>>& ripe){
  int day = 0;

  int dx[6] = {0, 0, 0, -1, 1, 0};
  int dy[6] = {0, 0, -1, 0, 0, 1};
  int dz[6] = {-1, 1, 0, 0, 0, 0};
  
  while(!q2.empty()||!q1.empty()){
    while (!q2.empty()){
      int x = q2.front().first;
      int y = q2.front().second.first;
      int z = q2.front().second.second;

      q2.pop();

      for(int i = 0; i < 6; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        int nz = z + dz[i];

        if(nx >= 0 && nx < h && ny >= 0 && ny < n && nz >= 0 && nz < m){
          if(vec[nx][ny][nz] == 0 && !ripe[nx][ny][nz]){
            ripe[nx][ny][nz] = true;
            vec[nx][ny][nz] =  1;
            q1.push({nx, {ny, nz}});
            cnt++;
          }
        }
      }
      if(q2.empty()&&!q1.empty()){
        day++;
      }
  }
  while(!q1.empty()){
    int x = q1.front().first;
    int y = q1.front().second.first;
    int z = q1.front().second.second;

    q1.pop();

    for(int i = 0; i < 6; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      int nz = z + dz[i];

      if(nx >= 0 && nx < h && ny >= 0 && ny < n && nz >= 0 && nz < m){
        if(vec[nx][ny][nz] == 0 && !ripe[nx][ny][nz]){
          ripe[nx][ny][nz] = true;
          vec[nx][ny][nz] = 1;
          q2.push({nx, {ny, nz}});
          cnt++;
        }
      }
    }
    if(q1.empty()&&!q2.empty()){
      day++;
    }
  }}


  return day;
}

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n,m,h;


  cin >> n >> m >> h;

  vector<vector<vector<int>>> vec(h, vector<vector<int>>(m, vector<int>(n)));
  vector<vector<vector<bool>>> ripe(h, vector<vector<bool>>(m, vector<bool>(n, false)));

  for(int i = 0; i < h; i++){
    for(int j = 0; j < m; j++){
      for(int k = 0; k < n; k++){
        cin >> vec[i][j][k];
        if(vec[i][j][k] == 1){
          ripe[i][j][k] = true;
          q1.push({i, {j, k}});
          cnt++;
        }else if(vec[i][j][k] == -1){
          ripe[i][j][k] = true;
          cnt++; 
        }
      }
    }
  }

  if(cnt == m*n*h){
    cout << 0 << "\n";
    return 0;
  }

  int day = bfs(h, m, n, vec, ripe);

  if(cnt != m*n*h){
    cout << -1 << "\n";
    return 0;
  }

  cout << day << "\n";

  return 0;
}