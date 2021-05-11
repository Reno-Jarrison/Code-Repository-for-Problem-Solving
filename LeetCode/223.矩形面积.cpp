class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long a1 = (C - A) * (D - B), a2 = (G - E) * (H - F);
        long long l = max(A, E), r = min(C, G);
        long long d = max(B, F), u = min(D, H);
        return a1 + a2 - 1LL * max(0LL, r - l) * max(0LL, u - d);
    }
};