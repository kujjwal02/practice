#include <iostream>
#include <unordered_set>

using namespace std;

typedef long long ll;

unordered_set<ll> obstacles;

ll simpleHash(ll a,ll b,ll largest){
    return a + b*largest;
}

bool is_obstacle_pos(ll row, ll col,ll n){
    return obstacles.find(simpleHash(row,col,n)) != obstacles.end();
}

long long no_of_squares_possible(ll n,ll rq,ll cq){
    long long count = 0;

    //check upper boxes
    for(ll row=rq+1; row<=n; ++row){
        if(is_obstacle_pos(row,cq,n))
            break;
        ++count;
    }
    //cout << "after upper boxes : "<< count <<endl;

    //check lower boxes
    for(ll row=rq-1; row>0; --row){
        if(is_obstacle_pos(row,cq,n))
            break;
        ++count;
    }
    //cout << "after lower boxes : "<< count <<endl;

    //check right boxes
    for(ll col=cq+1; col<=n; ++col){
        if(is_obstacle_pos(rq,col,n))
            break;
        ++count;
    }
    //cout << "after right boxes : "<< count <<endl;

    //check left boxes
    for(ll col=cq-1; col>0; --col){
        if(is_obstacle_pos(rq,col,n))
            break;
        ++count;
    }
    //cout << "after left boxes : "<< count <<endl;

    //check upper right boxes
    for(ll col=cq+1,row=rq+1; col<=n&& row<=n; ++col,++row){
        if(is_obstacle_pos(row,col,n))
            break;
        ++count;
    }
    //cout << "after upper right boxes : "<< count <<endl;

    //check upper left boxes
    for(ll col=cq-1,row=rq+1; col>0&& row<=n; --col,++row){
        if(is_obstacle_pos(row,col,n))
            break;
        ++count;
    }
    //cout << "after upper left boxes : "<< count <<endl;

    //check lower right boxes
    for(ll col=cq+1,row=rq-1; col<=n&& row>0; ++col,--row){
        if(is_obstacle_pos(row,col,n))
            break;
        ++count;
    }
    //cout << "after lower right boxes : "<< count <<endl;

    //check lower left boxes
    for(ll col=cq-1,row=rq-1; col>0&& row>0; --col,--row){
        if(is_obstacle_pos(row,col,n))
            break;
        ++count;
    }
    //cout << "after lower left boxes : "<< count <<endl;

    return count;
}

int main()
{
    ll n,k,rq,cq;
    cin >> n >>k;
    cin >> rq >> cq;
    ll r,c;
    for(ll i=0; i<k; ++i){
        cin >> r >>c;
        obstacles.insert(simpleHash(r,c,n));
    }
    cout << no_of_squares_possible(n,rq,cq);
    return 0;
}
