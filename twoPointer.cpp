/*
    Two Pointer 
    -> Find if there exists any pair of elements (A[i], A[j]) such that their sum is equal to X
    -> Find the closest pair from two sorted arrays

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Find if a pair exist
bool isPairSum(vector<int> arr , int n , int x){

    sort(arr.begin() , arr.end());
    int low = 0 , high = n - 1;
    while(low < high){
        if(arr[low] + arr[high] > x){
            high--;
        } else if( arr[low] + arr[high] < x){
            low++;
        } else return true;
    }
    return false;
    /*
        Time Complexity - O(n log n) due to sorting
        Space Complexity - O(1)
    */
}


//    Given two arrays arr1[0…m-1] and arr2[0..n-1], and a number x, the task is to 
//    find the pair arr1[i] + arr2[j] such that absolute value of (arr1[i] + arr2[j] – x) is minimum.
vector<int> closestPair(vector<int> arr1 , vector<int> arr2 , int m , int n , int x){
    
    int min_val = INT_MAX;
    int low = 0 , high = n-1;
    int ele1 , ele2;
    while(low < m && high >=0 ){
        if( abs(arr1[low] + arr2[high] - x) < min_val ){
            min_val = abs(arr1[low] + arr2[high] - x);
            ele1 = arr1[low];
            ele2 = arr2[high];
        } 
        if( arr1[low] + arr2[high]  > x) high--;
        else low++;
    }
    return {ele1, ele2};

}

int main(){

    //Question 1
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i = 0;i<n;i++)cin>>arr[i];
    
    int x;
    cin>>x;
    
    cout<<isPairSum(arr , n , x);
    
    //Question 2
    int m , l;
    cin>>m>>l;
    vector<int> arr1(m) , arr2(l);

    for(int i = 0;i<m;i++)cin>>arr1[i];
    for(int i = 0;i<l;i++)cin>>arr2[i];

    int p ;
    cin>>p;

    vector<int> result = closestPair(arr1 , arr2 , m , l , p);

    cout<<result[0]<<" "<<result[1]<<" ";
}

/*
    TestCase for isPairSum :
    6
    10 20 35 50 75 80
    70 
    Output : 1

    TestCase for closestPair :
    4 4
    1 4 5 7
    10 20 30 40
    50
    Output: 7 40
*/