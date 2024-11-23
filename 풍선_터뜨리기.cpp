#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> v;
    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;
        v.push_back({i + 1, input});
    }

    int index = 0;
    int move = 0;
    int Size = N;
    while (!v.empty())
    {
        cout << v[index].first << " ";
        move = v[index].second;
        if (move > 0)
        {
            move--;
        }

        v.erase(v.begin() + index);
        if (--Size <= 0)
            break;

        index += move;

        index = (index >= 0 ? index : Size + index % Size);
        index %= Size;
    }
    return 0;
}