#include <iostream>
#include <string>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    while(cases--){
        int no_of_buildings;
        string blast_code;
        cin >> no_of_buildings >> blast_code;
        bool building[1002];

        for(int i=1; i<=no_of_buildings;++i)
            building[i] = true;

        for(int i=1; i<=no_of_buildings; ++i){
            if(blast_code[i-1] == '1'){
                building[i-1] = building[i] = building[i+1] = false;
            }
        }
        int count = 0;
        for(int i=1; i<=no_of_buildings; ++i)
            if(building[i])
                ++count;

        cout << count<<endl;
    }
    return 0;
}
