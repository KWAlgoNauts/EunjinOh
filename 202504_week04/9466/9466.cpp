#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<int>& vec) {
    int n = vec.size();
    vector<bool> visited(n, false); // 각 학생이 방문된 상태인지 추적
    vector<bool> isInTeam(n, false); // 팀에 속한 학생을 추적
    int cnt = 0; // 팀에 속하지 않는 학생 수

    // 각 학생에 대해 순차적으로 탐색
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vector<int> cycle; // 순환 관계를 추적하
            int current = i;

            // 하나의 학생으로 시작하여 순환을 찾음
            while (!visited[current]) {
                visited[current] = true;
                cycle.push_back(current);
                current = vec[current] - 1; // 선택한 학생으로 이동 
            }

            // 순환이 형성되면, 해당 순환에 속한 학생을 모두 팀에 속한 학생으로 처리
            bool isCycle = false;
            for (int j = 0; j < cycle.size(); j++) {
                if (cycle[j] == current) {
                    isCycle = true;
                }
                if (isCycle) {
                    isInTeam[cycle[j]] = true;
                    cnt++; // 팀에 속하는 학생 수 증가
                }
            }
        }
    }

    // 전체 학생 수에서 팀에 속하지 않은 학생 수 계산
    cout << n - cnt << endl;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> vec(n);
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
        }

        bfs(vec);
    }

    return 0;
}