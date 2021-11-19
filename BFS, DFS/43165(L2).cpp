#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// 숫자, cnt
queue<pair<int, int>> q;
int solution(vector<int> numbers, int target) {
    int answer = 0;
    int Size = numbers.size();
    // 첫 숫자 push
    q.push(make_pair(numbers[0], 1));
    q.push(make_pair(-numbers[0], 1));
    // 두번째 숫자부터
    while (!q.empty()) {
        int num = q.front().first;
        int cnt = q.front().second;
        q.pop();
        // 끝까지 왔고, 타겟 넘버랑 같으면 answer++
        if (cnt == Size) {
            if (num == target) {
                answer++;
            }
        }
        // 끝이 아닌 경우에는 현재 숫자와 numbers의 숫자의 합, 차를 push
        else {
            q.push(make_pair(num + numbers[cnt], cnt + 1));
            q.push(make_pair(num - numbers[cnt], cnt + 1));
        }
    }
    return answer;
}