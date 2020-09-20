#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct _member
{
    int age;
    string name;
    int priority;
} Member;

bool compare(Member &m1, Member &m2)
{
    if (m1.age == m2.age)
    {
        if (m1.priority >= m2.priority)
            return false;
        return true;
    }
    else
    {
        if (m1.age < m2.age)
            return true;
        return false;
    }
    return false;
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int num;
    Member temp = {0, "", 0};

    vector<Member> memarr;

    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> temp.age >> temp.name;
        temp.priority = i;
        memarr.push_back(temp);
    }
    sort(memarr.begin(), memarr.end(), compare);
    for (int i = 0; i < memarr.size(); i++)
    {
        cout << memarr[i].age << " " << memarr[i].name << '\n';
    }

    return 0;
}