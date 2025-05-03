#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int>> &vec, int n, int m, pair<int, int> &first_ice_pos, int &ice_cnt){
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  int day=0;

  queue<pair<int, int>> q;


  while(1){
    if(ice_cnt<=0) return 0; // 빙하가 모두 녹았을 경우

    vector<vector<int>> vec_original = vec;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int current_ice_cnt = 1;
    int original_ice_cnt = ice_cnt;
    bool first_ice = false;

    q.push(first_ice_pos);

    while(!q.empty()){
      if(ice_cnt<=0) return 0; // 빙하가 모두 녹았을 경우

      pair<int, int> current = q.front();
      q.pop();
      visited[current.first][current.second] = true;
      

      int sea_cnt = 0;

      for(int i=0;i<4;i++){
        int nx = current.first + dx[i];
        int ny = current.second + dy[i];

        if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
        
        if(vec_original[nx][ny]==0){
          sea_cnt++;
      }else if(!visited[nx][ny]&& vec_original[nx][ny]>0){
          visited[nx][ny] = true;
          q.push({nx, ny});
          current_ice_cnt++;
          
        }
      }
      if(sea_cnt>0){
        vec[current.first][current.second] -= sea_cnt;
        if(vec[current.first][current.second]<=0 ) {
          vec[current.first][current.second] = 0;
          ice_cnt--;
        }
      }

      if(!first_ice&&vec[current.first][current.second]!=0){
        first_ice = true;
        first_ice_pos = {current.first, current.second};
      }
      }
    

    if(original_ice_cnt>=2&&current_ice_cnt==1) return day;
    
    if(q.empty()&&original_ice_cnt>current_ice_cnt) return day;
day++;
  
  }
  
}

int main(){
  int n,m;
  cin>>n>>m;

  vector<vector<int>> vec(n, vector<int>(m));

  bool first_ice = true;
  pair<int, int> first_ice_pos;
  int ice_cnt = 0;

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>vec[i][j];
      if(vec[i][j]!=0){
        if(first_ice){
          first_ice = false;
          first_ice_pos = {i, j}; 
        }
        ice_cnt++;
      }
    }
  }

  cout<<bfs(vec, n, m, first_ice_pos, ice_cnt);
  
  return 0;
}