#include <string>
#include <vector>
#include <map>
using namespace std;

// ��ǰ�� ���ι޾ƾ� �ϴ� ������ ������ �ִ� map
map<string, int> cntMap;

// �ʱ�ȭ
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

// ������ �� ���� �� �ִ��� �˻��ϴ� �Լ�
bool Check(vector<string> want)
{
    // want vector�� ��� ��ǰ�� ���� ���� ����(cntMap == 0)�̸� true ����
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

    // ó�� ���� �׳� �˻�
    if (Check(want))
        answer++;

    /* �� ���� ���� discount ���� �迭�� ���� ����(���� �޾����Ƿ�) 
    discount ���� �迭 ���� ����(���� ���� �� �����Ƿ�) */
    for (int i = 10; i < discount.size(); i++)
    {
        cntMap[discount[i]]--;
        cntMap[discount[i - 10]]++;

        if (Check(want))
            answer++;
    }

    return answer;
}