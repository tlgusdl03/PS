#include <iostream>
#include <map>
using namespace std;

int main()
{
    int N;
    cin >> N;
    map<string, bool> m;

    m["ChongChong"] = true;

    int result = 1;
    for (int i = 0; i < N; i++)
    {
        string a, b;
        cin >> a >> b;

        if (m[a] == true && m[b] == false)
        {
            m[b] = true;
            result++;
        }
        else if (m[a] == false && m[b] == true)
        {
            m[a] = true;
            result++;
        }
    }

    cout << result;
}