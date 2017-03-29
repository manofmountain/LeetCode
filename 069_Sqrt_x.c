int mySqrt(int x) 
{
	if(x <= 1)
		return x;
		
	const double eps=0.000001;
	
	double v = x;
	double intVal = v;
	double last;
	while(abs(v - last) > eps)
	{
		last = v;
		v = (v + intVal / v) / 2;
	}
	
	return (int)v;
}