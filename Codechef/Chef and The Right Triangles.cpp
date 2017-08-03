#include <iostream>
#include <cmath>

using namespace std;

int isRightTriangle(int l1, int l2, int l3){
    if( l1+l2==l3 || l2+l3==l1 || l3+l1==l2)
        return 1;
    return 0;
}

int main()
{
    int triangles;
    int count = 0;
    cin >> triangles;
    while(triangles--){
        int x1,x2,x3,y1,y2,y3;
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        cin >> x3 >> y3;
        int l1 = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        int l2 = (x3-x2)*(x3-x2) + (y3-y2)*(y3-y2);
        int l3 = (x1-x3)*(x1-x3) + (y1-y3)*(y1-y3);
        count += isRightTriangle(l1,l2,l3);
    }
    cout << count;
    return 0;
}
