#include <string>
#include <vector>
#include <queue>
using namespace std;

bool visited[201];
int result;

void bfs(int start, vector<vector<int>> v, int length) {
    // 방문했으면 return
    if (visited[start])
        return;
    // 네트워크 존재하므로 result++
    result++;
    visited[start] = true;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        node--;
        q.pop();
        // 인근 노드 방문
        for (int i = 0; i < length; i++) {
            // 연결되어있지 않으면 continue
            if (!v[node][i])
                continue;
            int next = i + 1;
            // 연결되어있고 방문한 적이 없으면 push
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        bfs(i, computers, n);
    }
    answer = result;
    return answer;
}