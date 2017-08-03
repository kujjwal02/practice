#include <iostream>
#include <string>

using namespace std;

bool canMarry(string man,string woman){
    string small,large;
    if(man.size() < woman.size()){
        small = man;
        large = woman;
    }
    else{
        small = woman;
        large = man;
    }
    int i=0,j=0;
    for(; i<small.size()&&j<large.size();){
        if(small[i] == large[j])
            ++i;
        ++j;
    }

    return (i==small.size() ? true:false);
}

int main()
{
    int cases;
    cin >> cases;
    while(cases--){
        string m,w;
        cin >> m >> w;
        cout << (canMarry(m,w) ? "YES":"NO")<< endl;
    }
    return 0;
}
