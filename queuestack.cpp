#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// 큐만 저장하기
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> v(N);
    deque<int> q;

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> v[i];
    }

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        if (v[i] == 0)
        {
            q.push_back(temp);
        }
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int input;
        cin >> input;

        q.push_front(input);
        cout << q.back() << " ";
        q.pop_back();
    }
}