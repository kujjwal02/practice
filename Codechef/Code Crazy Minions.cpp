#include <iostream>
#include <string>

using namespace std;

int toInteger(char a){
    return (int)(a - 'a');
}

int main()
{
    int tests;
    cin >>tests;
    while(tests--){
        string word;
        cin >> word;
        int no_of_operations = 2;
        int buffer = toInteger(word[0]);
        for(int i=1; i<word.size(); ++i){
            if(toInteger(word[i]) < buffer)
                no_of_operations += 26 + toInteger(word[i]) - buffer;
            else
                no_of_operations += toInteger(word[i]) - buffer;

            buffer = toInteger(word[i]);
            no_of_operations+=1;
        }
        cout << (no_of_operations <= 11*word.size() ? "YES": "NO")<<endl;
    }
    return 0;
}
