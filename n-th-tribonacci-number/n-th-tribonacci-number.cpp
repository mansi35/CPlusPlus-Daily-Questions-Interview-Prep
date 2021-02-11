class Solution {
public:
    int tribonacci(int n) {
        // Recursive way
        
        // if (n == 0)
        //     return 0;
        // if (n == 1 or n == 2)
        //     return 1;
        // return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
        
        // Iterative dp way
        
        int *F = new int[38];
        F[0] = 0;
        F[1] = 1;
        F[2] = 1;
        for (int i = 0; i <= 34; i++) {
            F[i+3] = F[i] + F[i+1] + F[i+2];
        }
        return F[n];
    }
};