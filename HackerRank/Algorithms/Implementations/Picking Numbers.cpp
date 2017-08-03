#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>
#include <array>
#include <cmath>
#include <algorithm>
#include <functional>

#define ll long long

using namespace std;


ll less_than(vector<ll> &freq) {
    ll max_freq_sum = 0;
    for(size_t i=0; i<freq.size()-1; ++i) {
        if (freq[i] + freq[i + 1] > max_freq_sum)
            max_freq_sum = freq[i] + freq[i + 1];
    }
    return max_freq_sum;
}

int main() {
    int n;
    cin >> n;
    vector<ll> freq(101, 0);
    for(ll i=0, input=0; i<n;  ++i) {
        cin >> input;
        ++freq[input];
    }
    cout << less_than(freq) << endl;
    return 0;
}
