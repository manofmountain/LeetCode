//20.41%
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    //Check boundary conditions
	if(C < A || D < B || G < E || H < F)
		return 0;
	
	int area1 = (C - A) * (D - B);
	int area2 = (G - E) * (H - F);
	int commonArea = 0;
	int h = 0, w = 0; //h : commonHeight, w : commonWidth
	if( C <= E || G <= A || B >= H || F >= D){
		commonArea = 0;
		return area1 + area2;
	}
	if(E > A){
		if(G < C)
			w = G - E;
		else
			w = C - E;
	}else{
		if(G < C)
			w = G - A;
		else
			w = C - A;
	}
	
	if(B > F){
		if(H < D)
			h = H - B;
		else
			h = D - B;
	}else{
		if(H < D)
			h = H - F;
		else
			h = D - F;
	}
	commonArea = h * w;
	return area1 - commonArea + area2;
		
}