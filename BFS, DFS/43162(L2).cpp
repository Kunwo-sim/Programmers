#include <string>
#include <vector>
#include <queue>
using namespace std;

bool visited[201];
int result;

void bfs(int start, vector<vector<int>> v, int length) {
    // �湮������ return
    if (visited[start])
        return;
    // ��Ʈ��ũ �����ϹǷ� result++
    result++;
    visited[start] = true;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        node--;
        q.pop();
        // �α� ��� �湮
        for (int i = 0; i < length; i++) {
            // ����Ǿ����� ������ continue
            if (!v[node][i])
                continue;
            int next = i + 1;
            // ����Ǿ��ְ� �湮�� ���� ������ push
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