#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<bool> job = vector<bool> (1000,false);
    int T,n,m;
    vector<int> chef = vector<int>();
    vector<int> assistant = vector<int> ();
    cin >>T;
    while(T--){
        cin >> n >> m;
        int index;
        for(int i=1; i<=m; ++i){
            cin >> index;
            job[index] = true;
        }
        /*
        cout << "job: ";
        for(int i=1; i<=n; ++i){
            if(job[i])
                cout<< 1<< " ";
            else
                cout<< 0 << " ";
        }
        cout<<endl;
        */
        int toggle = true;
        for(int i=1; i<=n; ++i){
            if(job[i] == false){
                if(toggle){
                    chef.push_back(i);
                    toggle = false;
                }
                else{
                    assistant.push_back(i);
                    toggle = true;
                }

                job[i] = true;
            }
        }

        for(int j: chef){
            cout << j << " ";
        }

        cout <<endl;

        for(int j: assistant){
            cout << j << " ";
        }
        cout << endl;

        for(int i=1; i<=n; ++i)
            job[i] = false;

        chef.clear();
        assistant.clear();
    }
    return 0;
}
