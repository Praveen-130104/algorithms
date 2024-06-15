/*
    Sliding Window - 
    1. To find the maximum sum of all subarrays of size K
    2. Find Indexes of a subarray with given sum
    Other Questions related to Slinding Window - https://www.geeksforgeeks.org/window-sliding-technique/
*/
#include<iostream>
#include<vector>
using namespace std;


//fixed window length k
int maxSum(vector<int>& arr , int n , int k){
    int max_sum = INT_MIN;
    int curr_sum = 0;

    for(int i = 0;i<k;i++)curr_sum+=arr[i];
    max_sum = curr_sum;
    for(int i = k;i<n;i++){
        curr_sum = curr_sum-arr[i-k]+arr[i];
        if(curr_sum > max_sum)max_sum = curr_sum;
    }
    return max_sum;
}

//Variable window length  returns the start and end index
vector<int> subarraySum(vector<int>& arr, int n, int s){

    int curr_sum = 0;
    int start = 0;
    for(int end = 0 ; end < n ; end++){
        curr_sum += arr[end];   
        //condition for the window 
        while(curr_sum > s && start < end){
            curr_sum -= arr[start];
            start++;
        }
            
        if(curr_sum == s){
            return {start+1 , end+1};
        }
    }
    return {-1};
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0;i<n;i++)cin>>arr[i];
    int k;
    cin>>k;

    cout<<maxSum(arr , n , k);

    int s;
    cin>>s;

    vector<int> result = subarraySum(arr, n ,s);
    for(auto i: result)cout<<i<<" ";
}
/*
    Test Case 1:
    9 
    1 4 2 10 23 3 1 0 20 
    4 - value of k 
    Output:
    39

    Test Case 2:
    5
    1 2 3 7 5
    12 - value of s 
    Output:
    2 4
*/