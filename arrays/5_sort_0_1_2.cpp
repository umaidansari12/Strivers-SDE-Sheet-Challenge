#include <bits/stdc++.h>


void sort012(int *arr, int n)
{
   //   Write your code here
   // Brute
   // TC - O(NlogN)
   // SC - O(1)
   sort(arr, arr + n);
}
void sort012(int *arr, int n)
{
   //   Write your code here
   // Better maintain a counter array and place element on the basis of count, place element
   // TC - O(N+N)
   // SC - O(1)
   int count[3] = {0};
   for (int i = 0; i < n; i++) {
      count[arr[i]]++;
   }
   int index = 0;
   for (int i = 0; i < 3; i++) {
      int freq = count[i];
      while (freq--)
         arr[index++] = i;
   }
}

void sort012(int *arr, int n)
{
   //   Write your code here

   // variation of dutch national flag algorithm
   // arr[0........low-1] contains 0, extreme left part
   // arr[low............mid-1] contains 1
   // arr[high+1...........n-1] contains 2, extreme right part
   // middle part i.e arr[mid....high] is the unsorted segment.

   //Here, as the entire array is unsorted, we have placed the mid pointer in the first index and the high pointer in the last index. The low is also pointing to the first index as we have no other index before 0. Here, we are mostly interested in placing the ‘mid’ pointer and the ‘high’ pointer as they represent the unsorted part in the hypothetical array.

   // TC - O(N)
   // SC - O(1)
   int first = 0, last = n - 1, mid = 0;
   while (mid <= last) {
      if (arr[mid] == 0) {
         swap(arr[mid++], arr[first++]);
      }
      else if (arr[mid] == 2) {
         swap(arr[mid], arr[last--]);
      }
      else {
         mid++;
      }
   }
}