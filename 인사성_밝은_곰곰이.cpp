#include <iostream>
#include <set>
using namespace std;

int main()
{
    int result = 0;
    int N;
    cin >> N;

    set<string> count;

    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;

        if (input == "ENTER")
        {
            result += count.size();
            count.clear();
        }
        else
        {
            count.insert(input);
        }
    }

    result += count.size();
    count.clear();

    cout << result << '\n';
}