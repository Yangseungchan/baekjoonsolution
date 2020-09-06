#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(void)
{
    int num;

    int tile_list[1000001] = {
        0,
    };

    tile_list[1] = 1;
    tile_list[2] = 2;

    cin >> num;
    if (tile_list[num] == 0)
    {
        for (int i = 3; i <= num; i++)
        {
            tile_list[i] = (tile_list[i - 1] % 15746 + tile_list[i - 2] % 15746) % 15746;
        }
    }

    cout << tile_list[num] << endl;

    return 0;
}