#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    map<string, int> fashion;

    string name, type;
    int test_case, num, result;
    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        result = 1;
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            cin >> name >> type;
            if (fashion.find(type) == fashion.end()) /* if type doesn't exist in fashion map */
            {
                fashion.insert(pair<string, int>(type, 1));
            }
            else
            {
                fashion[type]++;
            }
        }
        /* checking all cases and prints result*/
        for (map<string, int>::iterator iter = fashion.begin(); iter != fashion.end(); iter++)
        {
            result *= (iter->second + 1);
        }
        result -= 1;
        cout << result << '\n';
        fashion.clear();
    }

    return 0;
}