/*
Input

The first line of the input contains an integer T, denoting the number of test cases.
The description of T test cases follows.
Each test case consist a binary string S, which describes a match.
'0' means Chef lose a point, whereas '1' means he won the point.

Output

For each test case,
output on a separate line a string describing who won the match.
If Chef won then print "WIN" (without quotes), otherwise print "LOSE" (without quotes).

Constraints

1 ≤ T ≤ 1000
1 ≤ length(S) ≤ 100


Example

Input:
2
0101111111111
11100000000000

Output:
WIN
LOSE
*/
#include <iostream>
#include <cstdio>

using namespace std;

char s[100];

void decideIfDraw(char *s)
{
    int win = 0;
    int lose = 0;

    while(*s != '\0')
    {
        if (*(s++) == '1')
            ++win;
        else
            ++lose;

        if((win - lose) == 2)
            cout << "WIN\n";
        else if((win - lose) == -2)
            cout << "LOSE\n";

    }
}

void decide(char s[])
{
    int win = 0;
    int lose = 0;

    while(*s != '\0')
    {
        if (*(s++) == '1')
            ++win;
        else
            ++lose;

        if( win == 10 && lose == 10)
        {
            decideIfDraw(s);
            return;
        }

        if( win == 11){
            cout << "WIN\n";
            return;
        }
        else if(lose == 11){
            cout << "LOSE\n";
            return;
        }


    }
}

int main()
{
    int t;


    cin >> t;

    while(t--)
    {
        //get the string
        cin >> s;

        //compute WIN or LOSE
        decide(s);
    }
    return 0;
}
