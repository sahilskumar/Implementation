/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.
Return an integer corresponding to the maximum product possible.

Example :

Input : [2, 3, -2, 4]
Return : 6 

Possible with [2, 3]
*/

/*
Approach:
this is very similar to the " max cumulative sum subarray" problem. here you keep 2 values: the max cumulative product UP TO current 
element starting from SOMEWHERE in the past, and the minimum cumuliative product UP TO current element . it would be easier to see the 
DP structure if we store these 2 values for each index, like maxProduct[i],minProduct[i] .

at each new element, u could either add the new element to the existing product, or start fresh the product from current index 
(wipe out previous results), hence the 2 max() lines.

if we see a negative number, the "candidate" for max should instead become the previous min product, because a bigger number 
multiplied by negative becomes smaller, hence the swap()
*/

int maxProduct(int A[], int n) {
    // store the result that is the max we have found so far
    int r = A[0];

    // imax/imin stores the max/min product of
    // subarray that ends with the current number A[i]
    for (int i = 1, imax = r, imin = r; i < n; i++) {
        // multiplied by a negative makes big number smaller, small number bigger
        // so we redefine the extremums by swapping them
        if (A[i] < 0)
            swap(imax, imin);

        // max/min product for the current number is either the current number itself
        // or the max/min by the previous number times the current one
        imax = max(A[i], imax * A[i]);
        imin = min(A[i], imin * A[i]);

        // the newly computed max value is a candidate for our global result
        r = max(r, imax);
    }
    return r;
}
