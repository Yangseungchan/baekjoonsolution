#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    if (a < b)
    {
        return gcd(b, a);
    }
    else
    {
        if (b == 0)
        {
            return a;
        }
        else
        {
            return gcd(b, a % b);
        }
    }
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int num, temp, gcd_ring;
    vector<int> ring;

    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> temp;
        ring.push_back(temp);
    }

    for (int i = 1; i < num; i++)
    {
        gcd_ring = gcd(ring[0], ring[i]);
        cout << ring[0] / gcd_ring << '/' << ring[i] / gcd_ring << '\n';
    }
    return 0;
}