#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

typedef long long ll;

ll count=0;

void merge(ll arr[],ll first,ll mid,ll last){
	ll left_size=mid-first+1;
	ll rightsize=last-mid;
	ll combined_size = left_size + rightsize;
    ll left[left_size+1],right[rightsize+1];

    for(ll i=0; i<left_size; ++i)
        left[i] = arr[first+i];
    for(ll i=0; i<rightsize; ++i)
        right[i] = arr[mid+1+i];

    left[left_size] = LONG_MAX;
    right[rightsize] = LONG_MAX;

	ll left_index,right_index;
	left_index= 0;
	right_index=0;

	for(ll i=first; i<last-first+1; ++i){
        if(left[left_index]>right[right_index]){
            count += left_size - left_index;
            arr[i] = right[right_index++];
        }
        else
            arr[i] = left[left_index++];
	}

}

void merge_sort(ll arr[],ll first,ll last){
	if(first<last){
		ll mid=(first+last)/2;
		merge_sort(arr,first,mid);
		merge_sort(arr,mid+1,last);
		merge(arr,first,mid,last);
	}
}


int main()
{
    ll n;
    cin >> n;
    ll arr[n];
    for(ll i=0; i<n; ++i)
    	cin >> arr[i];
    merge_sort(arr,0,n-1);
    /*
    for(ll i=0; i<n; ++i)
    	cout <<  arr[i]<<" ";
    cout << endl;
    */
    cout << count;
    return 0;
}
