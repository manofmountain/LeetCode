# 50.64%
class Solution(object):
    def computeArea(self, A, B, C, D, E, F, G, H):
        """
        :type A: int
        :type B: int
        :type C: int
        :type D: int
        :type E: int
        :type F: int
        :type G: int
        :type H: int
        :rtype: int
        """
        if A > C or B > D or E > G or F > H:
            return 0
        
        area1, area2 = (C - A) * (D - B), (G - E) * (H - F)
        if C <= E or G <= A or H <= B or D <= F:
            return area1 + area2
        C, A = C if C < G else G, A if A > E else E
        D, B = D if D < H else H, B if B > F else F
        return area1 - (C - A) * (D - B) + area2
		
def computeArea(self, A, B, C, D, E, F, G, H):
    overlap = max(min(C,G)-max(A,E), 0)*max(min(D,H)-max(B,F), 0)
    return (A-C)*(B-D) + (E-G)*(F-H) - overlap