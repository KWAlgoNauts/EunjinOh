#include<iostream>
#include<queue>
#include<vector>

using namespace std;

queue<pair<int,int>> q;

void bfs(vector<vector<bool>>& vec){
  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;

    q.pop();

    if(x > 0 && vec[x-1][y]){
      q.push({x-1, y});
      vec[x-1][y] = false;
    }
    if(x < vec.size()-1 && vec[x+1][y]){
      q.push({x+1, y});
      vec[x+1][y] = false;
    }
    if(y > 0 && vec[x][y-1]){
      q.push({x, y-1});
      vec[x][y-1] = false;
    }
    if(y < vec[0].size()-1 && vec[x][y+1]){
      q.push({x, y+1});
      vec[x][y+1] = false;
    }
  }
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;


    for(int i=0; i<n; i++){
        int m, n, k;
        vector<vector<bool>> vec;
        int rst = 0;

        cin >> m >> n >> k;

        vec.resize(m, vector<bool>(n, false));

        for(int j=0; j<k; j++){
            int x, y;

            cin >> x >> y;
            vec[x][y] = true;
        }

        for(int x=0; x<m; x++){
          for(int y=0; y<n; y++){
            if(vec[x][y]){
              q.push({x, y});
              vec[x][y] = false;
              rst++;
              bfs(vec);
            }
          }
        }
        
        cout << rst << "\n";
    }

    return 0;
}