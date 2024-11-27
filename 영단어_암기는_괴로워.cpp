#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct Node
{
    string word;
    int count;

    bool operator<(const Node &other) const
    {
        if (count == other.count)
        {
            if (word.length() == other.word.length())
            {
                return word > other.word;
            }
            else
            {
                return word.length() < other.word.length();
            }
        }
        else
        {
            return count < other.count;
        }
    }
};

int main()
{
    int N, M;
    cin >> N >> M;

    priority_queue<Node> pq;
    map<string, int> m;

    for (int i = 0; i < N; i++)
    {
        string word;
        cin >> word;

        if (word.length() >= M)
        {
            m[word]++;
        }
    }

    for (auto &e : m)
    {
        Node newNode = {e.first, e.second};
        pq.push(newNode);
    }

    while (!pq.empty())
    {
        Node e = pq.top();
        pq.pop();

        cout << e.word << '\n';
    }
}