#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int op1, op2;
    do
    {
        cin >> op1 >> op2;
        if (op1 == 0 || op2 == 0)
        {
            break;
        }

        if (op2 / op1 > 0)
        {
            if (op2 % op1 != 0)
            {
                cout << "neither" << '\n';
            }
            else
            {
                cout << "factor" << '\n';
            }
        }
        else if (op1 % op2 == 0)
        {
            cout << "multiple" << '\n';
        }
        else
        {
            cout << "neither" << '\n';
        }
    } while ((op1 != 0) && (op2 != 0));

    return 0;
}