/*
    Kandane's Algorithm - Largest Sum Contiguous Subarray

    The idea of Kadane’s algorithm is to maintain a variable curr_sum that 
    stores the maximum sum contiguous subarray ending at current index and 
    a variable max_sum stores the maximum sum of contiguous subarray found so far, 
    Everytime there is a positive-sum value in curr_sum compare it with max_sum 
    and update max_sum if it is greater than max_sum.

*/

#include<iostream>
#include<vector>
using namespace std;

int maxSum(vector<int>& arr , int n ){
    int max_sum = INT_MIN;
    int curr_sum = 0;

    for(int i = 0 ;i< n;i++){
        curr_sum += arr[i];

        if(max_sum < curr_sum)max_sum = curr_sum;
        if(curr_sum < 0) curr_sum = 0;

    }
    return max_sum;

}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);

    for(int i = 0;i<n;i++)cin>>arr[i];

    cout<<maxSum(arr , n);
}
/*
    Testcase:
    8
    -2 -3 4 -1 -2 1 5 -3

    Output:
    7
*/