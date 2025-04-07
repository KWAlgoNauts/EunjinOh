#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<string> vec, vector<vector<pair<bool,bool>>>& visit, int i, int j, char color){
  queue<pair<int,int>> q;
  q.push({i,j});

  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;

    q.pop();

    if(x > 0 && vec[x-1][y] == color && !visit[x-1][y].first){
      q.push({x-1, y});
      visit[x-1][y].first = true;
    }
    if(x < vec.size()-1 && vec[x+1][y] == color && !visit[x+1][y].first){
      q.push({x+1, y});
      visit[x+1][y].first = true;
    }
    if(y > 0 && vec[x][y-1] == color && !visit[x][y-1].first){
      q.push({x, y-1});
      visit[x][y-1].first = true;
    }
    if(y < vec[0].size()-1 && vec[x][y+1] == color && !visit[x][y+1].first){
      q.push({x, y+1});
      visit[x][y+1].first = true;
    }
  }
}
void bfs_d(vector<string> vec, vector<vector<pair<bool,bool>>>& visit, int i, int j, char color){
  queue<pair<int,int>> q;
  q.push({i,j});

  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;

    q.pop();

    if(color == 'R' || color == 'G') {
      // 정상적인 색상 방문 외에 색약 처리 (R과 G는 동일한 색으로 취급)
      if(x > 0 && (vec[x-1][y] == 'R' || vec[x-1][y] == 'G') && !visit[x-1][y].second){
        q.push({x-1, y});
        visit[x-1][y].second = true;
      }
      if(x < vec.size()-1 && (vec[x+1][y] == 'R' || vec[x+1][y] == 'G') && !visit[x+1][y].second){
        q.push({x+1, y});
        visit[x+1][y].second = true;
      }
      if(y > 0 && (vec[x][y-1] == 'R' || vec[x][y-1] == 'G') && !visit[x][y-1].second){
        q.push({x, y-1});
        visit[x][y-1].second = true;
      }
      if(y < vec[0].size()-1 && (vec[x][y+1] == 'R' || vec[x][y+1] == 'G') && !visit[x][y+1].second){
        q.push({x, y+1});
        visit[x][y+1].second = true;
      }
    }else{
      if(x > 0 && vec[x-1][y] == color && !visit[x-1][y].first){
        q.push({x-1, y});
        visit[x-1][y].first = true;
      }
      if(x < vec.size()-1 && vec[x+1][y] == color && !visit[x+1][y].first){
        q.push({x+1, y});
        visit[x+1][y].first = true;
      }
      if(y > 0 && vec[x][y-1] == color && !visit[x][y-1].first){
        q.push({x, y-1});
        visit[x][y-1].first = true;
      }
      if(y < vec[0].size()-1 && vec[x][y+1] == color && !visit[x][y+1].first){
        q.push({x, y+1});
        visit[x][y+1].first = true;
      }
    }
  }
}
int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n;
  vector<string> vec;
  vector<vector<pair<bool,bool>>> visit;
  int rst = 0;
  int doltanism = 0;

  cin >> n;
  
  vec.resize(n);
  visit.resize(n, vector<pair<bool,bool>>(n,{false, false}));

  for(int i=0; i<n; i++){
    cin >> vec[i];
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(visit[i][j].first) continue;
      if(vec[i][j] == 'B'){
        rst++;
        doltanism++;
        visit[i][j] = {true, true};
        
        bfs(vec, visit, i, j, 'B');
        bfs_d(vec, visit, i, j, 'B');
      }
      else if(vec[i][j]=='R' || vec[i][j]=='G'){
        if(!visit[i][j].second){
          doltanism++;
          bfs_d(vec, visit, i, j, vec[i][j]);
        } 
        rst++;
        visit[i][j] = {true, true};

        bfs(vec, visit, i, j, vec[i][j]);
      }
    }
  }

  cout << rst << " " << doltanism;
  return 0;
}