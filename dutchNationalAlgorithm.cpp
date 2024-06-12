/*
    Dutch National Algorithm - to sort three variables
    -> You have three pointers low,mid,high 
    -> if arr[mid] = 0 , swap and increase low and mid by 1
    -> if arr[mid] = 2 , swap and decrease high by 1
    -> if arr[mid] = 1 , increase mid by 1
*/
#include<iostream>
#include<vector>
using namespace std;

void sort(vector<int>& arr){
    
    int low = 0 , mid = 0 , high = arr.size()-1;

    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low],arr[mid]);
            mid++;
            low++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else {
            swap(arr[mid],arr[high]);
            high--;
        }
    }

    return ;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i = 0;i<n;i++)cin>>arr[i];

    sort(arr);

    for(int i = 0;i<n;i++)cout<<arr[i]<<" ";
}
/*
    Test case:
    6
    0 2 1 0 1 2

    Output:
    0 0 1 1 2 2 
*/