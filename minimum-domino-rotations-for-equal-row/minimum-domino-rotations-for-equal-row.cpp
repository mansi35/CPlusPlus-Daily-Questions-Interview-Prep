class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> umap1, umap2, common;
        int n = A.size();
        for (int i = 0; i < n; i++) {
            umap1[A[i]] += 1;
            if (A[i] == B[i])
                common[A[i]] += 1;
            else
                umap2[B[i]] +=1;
        }
        for (int i = 1; i <= 6; i++) {
            if (umap1[i] == n or umap2[i] == n) {
                return 0;
            }
            if (umap1[i] + umap2[i] >= n) {
                return n - max(umap1[i], umap2[i] + common[i]);
            }
        }
        return -1;
    }
};