#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n;
    int k;
    int count = 0;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0;i < n;i++){
       cin >> a[i];
    }
    for(int i = 0;i < n;++i)
        for(int j = i+1;j < n; ++j)
    {
        if((a[i] + a[j])%k == 0)
            ++count;
    }
    cout << count;
    return 0;
}
