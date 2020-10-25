#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct conference
{
    int start;
    int finish;
}Conference;

bool sortfunc(Conference c1, Conference c2)
{
    if(c1.finish < c2.finish)
    {
        return true;
    }
    else if(c1.finish == c2.finish)
    {
        if(c1.start < c2.start)
        {
            return true;
        }
    }
    return false;
}

class AssignConf
{
    private:
        int length;
        int count;
        vector<Conference> timeline;

    public:
        AssignConf(int len):length(len), count(0)
        {
            Conference sample = {0, 0};
            timeline.assign(length, sample);
            for(int i=0; i<len; i++)
            {
                cin >> timeline[i].start >> timeline[i].finish;
            }
            sort(timeline.begin(), timeline.end(), sortfunc);
        }

        void assignconf()
        {
            int fin = timeline[0].finish;
            ++count;
            for(int i=1; i<length; i++)
            {
                if(fin <= timeline[i].start)
                {
                    fin = timeline[i].finish;
                    ++count;
                }
            }
            
            cout << count << '\n';
        }
};

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);


    int num;
    cin >> num;
    AssignConf confroom(num);
    confroom.assignconf();


    return 0;
}