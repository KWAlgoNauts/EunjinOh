#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<bool>> &visit, pair<int, int> d, pair<int, int> a){ 
  int dx[] = {2,-2,2,-2,1,-1,1,-1};
  int dy[] = {1,1,-1,-1,2,2,-2,-2};

  int cnt = 0;

  queue<pair<int, int>> q1;
  queue<pair<int, int>> q2;

  q1.push(d);

  while(!q1.empty()||!q2.empty()){
    while(!q1.empty()){
      pair<int, int> w = q1.front();
      q1.pop();

      for(int i = 0;i<8;i++){
        int nx = w.first + dx[i];
        int ny = w.second + dy[i];

        if(nx == a.first && ny == a.second){
          cout << cnt + 1 << '\n';
          return 0;
        }

        if(nx >= 0 && nx < visit.size() && ny >= 0 && ny < visit[0].size()){
          if(!visit[nx][ny]){
            visit[nx][ny]=true;
            q2.push({nx, ny});
          }
        }
      }
      
    }
    cnt++;
    while(!q2.empty()){
      pair<int, int> d = q2.front();
      q2.pop();

      for(int i = 0;i<8;i++){
        int nx = d.first + dx[i];
        int ny = d.second + dy[i];

        if(nx == a.first && ny == a.second){
          cout << cnt + 1 << '\n';
          return 0;
        }

        if(nx >= 0 && nx < visit.size() && ny >= 0 && ny < visit[0].size()){
          if(!visit[nx][ny]){
            visit[nx][ny]=true;
            q1.push({nx, ny});
          }
        }
      }
    }
  
    cnt++;
  }
  return 0;
}

int main(){
  int n;

  cin >> n;



  for(int i = 0; i < n; i++){
    int l;
    cin >> l;

    vector<vector<bool>> visit(l, vector<bool>(l, false));

    pair<int, int> d;
    pair<int, int> a;

    cin >> d.first >> d.second;
    cin >> a.first >> a.second;

    if(d.first == a.first && d.second == a.second){
      cout << 0 << '\n';
      continue;
    }

    visit[d.first][d.second] = true;

    bfs(visit, d, a);
  }
  
  return 0;
}