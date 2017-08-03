#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int permutation[1001];
    for(int i=1; i<=n; ++i)
        cin >> permutation[i];
    bool visited[1001]{false};
    vector<vector<int>> cycle_record;
    int cycles = 0;
    for(int v=1; v<=n; ++v){
        if(!visited[v]){
            ++cycles;
            vector<int> curr_cycle;
            curr_cycle.push_back(v);
            int itterator = permutation[v];
            do{
                visited[itterator] = true;
                curr_cycle.push_back(itterator);
                itterator = permutation[itterator];
            }while(itterator != permutation[v]);
            cycle_record.push_back(curr_cycle);
        }
    }

    cout << cycles<<endl;
    for(auto curr_cycle : cycle_record){
        for(auto index : curr_cycle)
            cout << index << " ";
        cout << endl;
    }
    return 0;
}
