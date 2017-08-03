#include <iostream>

using namespace std;

long long total_possible_combinations(int coins[],int sum,int no_of_elements){
    long long memo[251][51];
    for(int i=0; i<=no_of_elements; ++i)
        memo[0][i] = 1;
    for(int i=1; i<=sum; ++i)
        memo[i][0] = 0;


    for(int row=1; row<=sum; ++row){
        for(int col=1; col<=no_of_elements; ++col){
            memo[row][col] = memo[row][col-1];
            if((row - coins[col]) >= 0){
                memo[row][col] += memo[row - coins[col]][col];
            }
        }
    }

    for(int row=0; row<=sum; ++row){
        for(int col=0; col<=no_of_elements; ++col){
            cout << memo[row][col]<< "\t";
        }
        cout << endl;
    }
    return memo[sum][no_of_elements];
}

int main()
{
    int sum, no_of_elements;
    cin >> sum >> no_of_elements;
    int coins[51];
    for(int i=1; i<=no_of_elements; ++i)
        cin >> coins[i];
    cout << total_possible_combinations(coins,sum,no_of_elements);
    return 0;
}
