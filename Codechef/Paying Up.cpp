#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

typedef long long ll;

using namespace std;
//void printTable(int table,int n,int m);

bool paying_up_dynamic(int notes[],int n,int sum){
    bool table[sum+1][n+1];
    for(int i=0; i<n; ++i){
        cout << notes[i] <<"\t";
    }
    cout << endl;
    for(int i=0; i<=n; ++i)
        table[0][i] = true;
    for(int i=1; i<=sum; ++i)
        table[i][0] = false;
    for(int i=1; i<=sum; ++i)
        for(int j = 1; j<=n; ++j){
            table[i][j] = table[i][j-1];
            if(i >= notes[j-1])
                table[i][j] = table[i][j] || table[i-notes[j-1]][j-1];
        }

    //printTable(table,sum+1,n+1);
    for(int i=0; i<=sum; ++i){
        for(int j=0; j<=n; ++j){
            cout << table[i][j] <<"\t";
        }

        cout << endl;
    }
    return table[sum][n];
}
/*
void printTable(int table,int n,int m){
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cout << table[i][j] <<"\t";
        }

        cout << endl;
    }
}
*/

bool paying_up_bruteforce(int notes[],int n,int m){
    for(int i=1 ,last=pow(2,n); i<last; ++i){
        int sum = 0;
        int num = i;
        for(int index = 0; num>0 && index<n; ++index,num/=2)
            if(num%2)
                sum += notes[index];
        if(sum == m){
            return true;
        }
    }
    return false;
}

int main(){
    int T;
    int notes[20];
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        for(int i=0; i<n; ++i)
            cin >> notes[i];
        /*
        bool avail = false;

        for(int i=1 ,last=pow(2,n); i<last; ++i){
            int sum = 0;
            int num = i;
            for(int index = 0; num>0 && index<n; ++index,num/=2)
                if(num%2)
                    sum += notes[index];
            if(sum == m){
                avail = true;
                break;
            }
        }

        cout << (avail ? "Yes" : "No") << endl;
        */

        cout << (paying_up_dynamic(notes,n,m) ? "Yes" : "No") << endl;
    }
    return 0;
}
