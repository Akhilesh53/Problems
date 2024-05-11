#include <bits/stdc++.h>
using namespace std;

/*
   The problem is about finding the longest sequence of consecutive 1s in a binary array,
   under the condition that we are allowed to flip at most one 0 to 1.

   This task tests our ability to manipulate subarrays in a binary context and optimize our approach
   to account for small alterations in the array to achieve the desired outcome.
*/

int maxConsecutiveOnes(vector<int>& arr){
    int n = arr.size();
    int left = 0, right = 0, zeroCount = 0, maxLen = 0;
    while(right < n){
        if(arr[right] == 0){
            zeroCount++;
        }
        while(zeroCount > 1){
            if(arr[left] == 0){
                zeroCount--;
            }
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
        right++;
    }
    return maxLen;
}