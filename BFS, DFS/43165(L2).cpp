#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// ����, cnt
queue<pair<int, int>> q;
int solution(vector<int> numbers, int target) {
    int answer = 0;
    int Size = numbers.size();
    // ù ���� push
    q.push(make_pair(numbers[0], 1));
    q.push(make_pair(-numbers[0], 1));
    // �ι�° ���ں���
    while (!q.empty()) {
        int num = q.front().first;
        int cnt = q.front().second;
        q.pop();
        // ������ �԰�, Ÿ�� �ѹ��� ������ answer++
        if (cnt == Size) {
            if (num == target) {
                answer++;
            }
        }
        // ���� �ƴ� ��쿡�� ���� ���ڿ� numbers�� ������ ��, ���� push
        else {
            q.push(make_pair(num + numbers[cnt], cnt + 1));
            q.push(make_pair(num - numbers[cnt], cnt + 1));
        }
    }
    return answer;
}