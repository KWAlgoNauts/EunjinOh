#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int n, m;
  deque<int> dq;
  vector<int> v;
  int rst=0;

  cin >> n;
  cin >> m;

  for(int i = 1; i <= n; i++){
    dq.push_back(i);
  }

  for(int i = 0; i < m; i++){
    int x;
    cin >> x;
    v.push_back(x);
  }

  for(int i=0;i<m;i++){
    int idx = find(dq.begin(), dq.end(), v[i]) - dq.begin();
    
    if(idx <= dq.size()/2){
      while(dq.front() != v[i]){
        dq.push_back(dq.front());
        dq.pop_front();
        rst++;
      }
      dq.pop_front();
  }else{
      while(dq.front() != v[i]){
        dq.push_front(dq.back());
        dq.pop_back();
        rst++;
      }
      dq.pop_front();
    }
  }

  cout << rst << '\n';

  return 0;
}