#include <iostream>
#include <vector>

using namespace std;

class Coincnt
{
    private:
        int num;
        int max;
        vector<int> coin_list;
    public:
        Coincnt(int number, int maximum) : num(number), max(maximum)
        {
            coin_list.assign(num, 0);
            for(int i=0; i<num; i++)
            {
                cin >> coin_list[i];
            }
        }
        
        int find_min()
        {
            int i, idx;
            int list_len = coin_list.size() - 1;
            idx = list_len;
            for(i=0; max > 0; i++)
            {
                while(max < coin_list[idx])
                {
                    idx--;
                }
                max -= coin_list[idx];
            }
            return i;
        }
};

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int num, max;

    cin >> num >> max;
    Coincnt coin(num, max);

    cout << coin.find_min() << '\n';

    return 0;
}