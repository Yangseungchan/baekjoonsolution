#include <iostream>
#include <vector>

//분할 정복을 사용한 거듭제곱과 페르마의 소정리를 이용해 곱셈의 역원을 구하는 문제

using namespace std;

vector<long long> fact_dp;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long rest_idx = 1000000007;
    long long num_n, num_k;
    long long bottom_num;
    long long result, multiply;
    long long multi_cnt = rest_idx - 2;

    cin >> num_n >> num_k;
    fact_dp = vector<long long>(num_n + 1, 0);
    fact_dp[0] = fact_dp[1] = 1;
    for (int i = 2; i <= num_n; i++)
    {
        fact_dp[i] = (i % rest_idx) * (fact_dp[i - 1] % rest_idx) % rest_idx;
    }

    bottom_num = (fact_dp[num_k] % rest_idx) * (fact_dp[num_n - num_k] % rest_idx) % rest_idx;
    result = 1;
    multiply = bottom_num;
    while (multi_cnt > 0)
    {
        if (multi_cnt % 2 != 0)
        {
            result = (result % rest_idx) * (multiply % rest_idx) % rest_idx;
        }
        multiply = (multiply % rest_idx) * (multiply % rest_idx) % rest_idx;
        multi_cnt /= 2;
    }

    cout << (fact_dp[num_n] % rest_idx) * (result % rest_idx) % rest_idx << '\n';

    return 0;
}
