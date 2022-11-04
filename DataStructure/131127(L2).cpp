#include <string>
#include <vector>
#include <map>
using namespace std;

// 물품의 할인받아야 하는 개수를 가지고 있는 map
map<string, int> cntMap;

// 초기화
void Init(vector<string> want, vector<int> number, vector<string> discount)
{
    for (int i = 0; i < want.size(); i++)
    {
        cntMap[want[i]] = number[i];
    }

    for (int i = 0; i < 10; i++)
    {
        cntMap[discount[i]]--;
    }
}

// 할인을 다 받을 수 있는지 검사하는 함수
bool Check(vector<string> want)
{
    // want vector의 모든 물품이 할인 받은 상태(cntMap == 0)이면 true 리턴
    for (int i = 0; i < want.size(); i++)
    {
        if (cntMap[want[i]] != 0)
            return false;
    }

    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    Init(want, number, discount);

    // 처음 경우는 그냥 검사
    if (Check(want))
        answer++;

    /* 그 다음 경우는 discount 끝의 배열의 값은 감소(할인 받았으므로) 
    discount 앞의 배열 값은 증가(이제 할인 못 받으므로) */
    for (int i = 10; i < discount.size(); i++)
    {
        cntMap[discount[i]]--;
        cntMap[discount[i - 10]]++;

        if (Check(want))
            answer++;
    }

    return answer;
}