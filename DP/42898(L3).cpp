#include <string>
#include <vector>
using namespace std;
bool water[101][101];
int dp[101][101];

int mod = 1000000007;
int solution(int m, int n, vector<vector<int>> v) {
    int answer = 0;
    // ¿õµ¢ÀÌ
    for (int i = 0; i < v.size(); i++) {
        int x = v[i][0];
        int y = v[i][1];
        water[y][x] = true;
    }
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // ¿õµ¢ÀÌ¸é pass
            if (water[i][j]) {
                continue;
            }
            // À§ÂÊ¿¡¼­ ¿À´Â ·çÆ®
            if (i - 1 >= 1) {
                dp[i][j] += dp[i - 1][j];
            }
            // ¿ÞÂÊ¿¡¼­ ¿À´Â ·çÆ®
            if (j - 1 >= 1) {
                dp[i][j] += dp[i][j - 1];
            }
            dp[i][j] %= mod;
        }
    }
    answer = dp[n][m];
    return answer;
}