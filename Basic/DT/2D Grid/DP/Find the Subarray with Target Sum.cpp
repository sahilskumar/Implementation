/*
https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/discuss/303750/JavaC%2B%2BPython-Find-the-Subarray-with-Target-Sum
Tushar Roy 
Idea : converting 2D grid to 1D then using kadane Algorithm(for maximum sum) or map (for counting ranges)
1)2 Pointer on column l(0-n),r(l-n) store(make an 1d array of size of size row) the sum from l column to r column for every row(Prefix Sum).
2) For finding maximum sum: Use kadane algorithm on every 1d array generated above and find max sum.
3) For finding no. of submatrix that target to target sum:Use map
*/

1)
int Solution::solve(vector<vector<int> > &A) {
        int n = A.size();
        if(n==0)
            return 0;
        int m = A[0].size();
        if(m==0)
            return 0;
        //Calculating prefix sum of each row
        int target=0;
        for (int i = 0; i < n; i++)
            for (int j = 1; j < m; j++)
                A[i][j] += A[i][j - 1];
        int res = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = i; j < m; j++) {
                unordered_map<int, int> counter;
                counter[0] = 1; 
                int cur = 0;
                for (int k = 0; k < n; k++) { //For each row sum from column [i to j]
                    cur += A[k][j] - (i > 0 ? A[k][i - 1] : 0); //calculating prefix sum
                    res += counter[cur-target]; 
                    counter[cur]++;
                }
            }
        }
        return res;
    }

2)
int Solution::solve(vector<vector<int> > &A) {
    int count  = 0;
    int row = A.size(), col = row>0?A[0].size():0;
    for(int c=0;c<col;c++){// from each coloumn make a submatrix
        vector<int> arr(row, 0);
        for(int j=c;j<col;j++){
            for(int i=0;i<row;i++){
                arr[i] += A[i][j];
            }
            /// find zero sum in array algo
            unordered_map<int,int> hash;
            int sum = 0;
            hash[0] = 1;
            for(int i=0;i<row;i++){
                sum += arr[i];
                if(hash.count(sum))
                    count += hash[sum];
                hash[sum]++;
            }
        }
    }
    return count;
}
