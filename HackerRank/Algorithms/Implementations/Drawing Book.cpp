#include <iostream>
#include <cstdio>
#include <string>
#include <array>
#include <functional>

using namespace std;

using ll = long long;


int main() {
    ll total_pages, page;
    cin >> total_pages >> page;
    if (total_pages % 2)
        --total_pages;
    if (page % 2)
        --page;
    ll from_front = page / 2;
    ll from_back = (total_pages - page) / 2;
    cout << min(from_front, from_back) << endl;
    system("pause");
    return 0;
}
