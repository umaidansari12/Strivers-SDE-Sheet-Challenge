

long long maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN; // maximum sum

    // Brute - consider i..j subarray fins its sum in the third loop
    // TC - O(N*N*N)
    // SC - O(1)

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // subarray = arr[i.....j]
            int sum = 0;

            //add all the elements of subarray:
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }

            maxi = max(maxi, sum);
        }
    }

    return maxi;
}


long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    // subarray sum of current subarray is always equal to sum of previous subarray + current_element
    // find subarray sum for each subarray and return maximum out of it
    // TC - O(N*N)
    // SC - O(1)
    long long int max_subarray_sum = 0;
    for (int i = 0; i < n; i++) {
        long long int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            max_subarray_sum = max(max_subarray_sum, sum);
        }
    }
    return max_subarray_sum;
}


long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    // don't consider negative elements in subarray anytime
    // TC - O(N)
    // SC - O(1)
    long long int max_subarray_sum = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        max_subarray_sum = max(sum, max_subarray_sum);
        if (sum < 0) {
            sum = 0;
        }
    }
    return max_subarray_sum;
}