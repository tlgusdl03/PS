#include <iostream>
#include <string>
using namespace std;

void isPalindrome(string input, int count, int l, int r)
{
    count++;
    if (l >= r)
    {
        cout << 1 << " " << count << '\n';
        return;
    }

    if (input[l] != input[r])
    {
        cout << 0 << " " << count << '\n';
        return;
    }

    isPalindrome(input, count, l + 1, r - 1);
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int count = 0;
        string input;
        cin >> input;
        isPalindrome(input, count, 0, input.length() - 1);
    }
}