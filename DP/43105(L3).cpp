#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int dp[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    dp[0][0] = triangle[0][0];
    // 삼각형 2째줄부터 탐색
    for (int i = 1; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            // 첫 칸
            if (j == 0) {
                dp[i][j] += dp[i - 1][j] + triangle[i][j];
            }
            // 마지막 칸
            else if (j == triangle[i].size() - 1) {
                dp[i][j] += dp[i - 1][j - 1] + triangle[i][j];
            }
            // 중간 칸
            else {
                int temp = max(dp[i - 1][j - 1], dp[i - 1][j]);
                dp[i][j] += temp + triangle[i][j];
            }
            // 마지막 줄이라면 최댓값 갱신
            if (i == triangle.size() - 1) {
                answer = max(answer, dp[i][j]);
            }
        }
    }
    return answer;
}