#include <iostream>
using namespace std;

long long factor(long long N)
{
    if (N == 1 || N == 0)
    {
        return 1;
    }

    return N * factor(N - 1);
}
int main()
{
    int N;
    cin >> N;

    long long result = factor(N);

    cout << result << '\n';
}