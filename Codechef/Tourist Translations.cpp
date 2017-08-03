#include <iostream>
#include <string>
#include <map>
#include <cstring>

using namespace std;

int main()
{
    int T;
    string char_code;
    map<char,char> char_map;
    cin >> T >> char_code;
    for(int i=0; i<26; ++i){
        char_map['a' + i] = char_code[i];
        char_map['A' + i] = toupper(char_code[i]);
    }
    while(T--){
        string line;
        cin >> line;
        for(int i=0; i<line.size(); ++i){
            if(isalpha(line[i]))
                cout << char_map[line[i]];
            else if(line[i] == '_')
                cout << " ";
            else
                cout << line[i];

        }
        cout <<endl;
    }
    return 0;
}
