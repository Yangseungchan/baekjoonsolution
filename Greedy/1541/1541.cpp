#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> formula; /* -2 = +, -1 = -, 0~ = integer */
    vector<int> new_formula;

    string form;
    cin >> form;
    int num = 0;
    int result;
    for (int i = 0; i < form.length(); i++) /* changing given string to integer formula */
    {
        if (form[i] == '+')
        {
            formula.push_back(num);
            num = 0;
            formula.push_back(-2);
        }
        else if (form[i] == '-')
        {
            formula.push_back(num);
            num = 0;
            formula.push_back(-1);
        }
        else
        {
            num = num * 10 + (form[i] - '0');
            if (i == form.length() - 1)
            {
                formula.push_back(num);
            }
        }
    }

    /*cout << "formula : " << endl;
    for (int i = 0; i < formula.size(); i++)
    {
        cout << formula[i] << endl;
    }
    cout << endl;
    */

    if (formula.size() == 1)
    {
        new_formula.push_back(formula[0]);
    }

    for (int i = 1; i < formula.size(); i += 2)
    {
        if (formula[i] == -2) /* formula[i] = + */
        {

            if (i + 2 < formula.size()) /* if next operator exists */
            {
                if (formula[i + 2] == -2) /* formula[i+2] is + */
                {
                    formula[i + 1] += formula[i - 1];
                }
                else
                {
                    new_formula.push_back(formula[i - 1] + formula[i + 1]);
                }
            }
            else
            {
                new_formula.push_back(formula[i - 1] + formula[i + 1]);
            }
        }
        else /* formula[i] = - */
        {
            if (i == 1)
            {
                new_formula.push_back(formula[i - 1]);
            }
            if (i + 2 < formula.size())
            {
                if (formula[i + 2] == -1)
                {
                    new_formula.push_back(formula[i + 1]);
                }
            }
            else
            {
                new_formula.push_back(formula[i + 1]);
            }
        }
    }

    /* cout << "new_formula : " << endl;
    for (int i = 0; i < new_formula.size(); i++)
    {
        cout << new_formula[i] << endl;
    }
    cout << endl;
    */

    result = new_formula[0];
    for (int i = 1; i < new_formula.size(); i++)
    {
        result -= new_formula[i];
    }

    cout << result << '\n';

    return 0;
}