//15.87%
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if(A > C || B > D || E > G || F > H)
			return 0;
		int area1((C - A) * (D - B)), area2((G - E) * (H - F));
		int h(0), w(0);
		if(C <= E || G <= A || D <= F || H <= B)
			return area1 + area2;
		if(E > A)
			A = E;
		if(G < C)
			C = G;
		if(F > B)
			B = F;
		if(H < D)
			D = H;
		h = D - B, w = C - A;
		return area1 - h * w + area2;
    }
};

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int left = max(A,E), right = max(min(C,G), left);
    int bottom = max(B,F), top = max(min(D,H), bottom);
    return (C-A)*(D-B) - (right-left)*(top-bottom) + (G-E)*(H-F);
}