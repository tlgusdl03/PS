#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MAX = -1000000001;
int MIN = 1000000001;

void solve(int N, int count, int result, vector<int> &input, vector<int> &operators)
{
    if (count == N)
    {
        MAX = max(MAX, result);
        MIN = min(MIN, result);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (operators[i] > 0)
        {
            operators[i]--;
            if (i == 0)
            {
                solve(N, count + 1, result + input[count], input, operators);
            }
            else if (i == 1)
            {
                solve(N, count + 1, result - input[count], input, operators);
            }
            else if (i == 2)
            {
                solve(N, count + 1, result * input[count], input, operators);
            }
            else if (i == 3 && input[count] != 0)
            {
                solve(N, count + 1, result / input[count], input, operators);
            }
            operators[i]++;
        }
    }
}

int main()
{
    int N;
    cin >> N;

    vector<int> input(N);
    for (int i = 0; i < N; i++)
    {
        cin >> input[i];
    }

    vector<int> operators(4);
    for (int i = 0; i < 4; i++)
    {
        cin >> operators[i];
    }

    solve(N, 1, input[0], input, operators);

    cout << MAX << '\n'
         << MIN;
}