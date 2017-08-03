#include <iostream>
#include <string>

using namespace std;

int main()
{
    string necklace = "";
    char currChar ;
    int T, length, rfactor, currPos, prevB, B, currB;
    cin >> T;
    for(int j = 0; j < T; ++j )
    {
        cin >> necklace;
        length = (int)necklace.length();
        prevB = B = rfactor = 0;
        currB = currPos = 1;
        currChar = (char)necklace[0];

        while(rfactor != 2 &&length>1)
        {
            //printf("prevB : %d\nB : %d\ncurrB : %d\n\ncurrChar : %c\ncurrPos : %d\n\n",prevB,B,currB,currChar,currPos);
            if(necklace[currPos] == currChar)
                ++currB;
            else
            {
                currChar = necklace[currPos];
                if(currB >= B)
                {
                    prevB = B;
                    B = currB;
                    currB = 1;
                }

                if(rfactor == 1)
                    break;
            }

            if(currPos == (length-1))
            {
                currPos = 0;
                ++rfactor;
            }
            else
                ++currPos;
        }

       // printf("After calculation :\nprevB : %d\nB : %d\n\n",prevB,B);


        if(B == 1)
            B = 2;
        else if(B == 0)
            B = 1;
        else
            B = prevB;

        printf("Case %d: %d\n",j+1,B);
    }
    return 0;
}
