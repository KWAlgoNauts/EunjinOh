#include <iostream>
#include <queue>

using namespace std;

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int n;
  queue<int> q;

  cin >> n;
  cin.ignore();

  for(int i = 0; i < n; i++){
    string s;

    getline(cin, s);

    if(s == "back"){
      if(q.empty()){
        cout << -1 << '\n';
      }else{
      cout << q.back() << '\n';
      }
      
    }else if(s=="pop"){
      if(q.empty()){
        cout << -1 << '\n';
      }else{
        cout << q.front() << '\n';
        q.pop();
      }
    }
    else if(s =="size"){
      cout << q.size() << '\n';
    }else if(s=="empty"){
      cout << q.empty() << '\n';
    }else if(s=="front"){
      if(q.empty()){
        cout << -1 << '\n';
      }else{
      cout << q.front() << '\n';
      }
    }else{
      
      int x = stoi(s.substr(5));  
      q.push(x);
      
      
    }
}
  return 0;
}