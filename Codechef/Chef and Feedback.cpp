#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--){
        string feedback;
        cin >> feedback;
        string good = "Bad";
        if(feedback.find("010") != -1 || feedback.find("101") != -1)
            good = "Good";
        cout << good <<endl;
    }
    return 0;
}
