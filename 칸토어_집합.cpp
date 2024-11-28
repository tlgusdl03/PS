#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void solve(string &s, int left, int right)
{
    if (right - left < 3)
    {
        return;
    }

    int length = (right - left) / 3;

    for (int i = left + length; i < left + 2 * length; i++)
    {
        s[i] = ' ';
    }

    solve(s, left, left + length);
    solve(s, left + 2 * length, right);
}

int main()
{
    int N;
    while (cin >> N)
    {
        int lenght = pow(3, N);
        string s(lenght, '-');
        solve(s, 0, lenght);
        cout << s << '\n';
    }
}