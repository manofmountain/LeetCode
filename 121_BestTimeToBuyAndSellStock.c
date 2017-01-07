//4.46%
int maxProfit(int* prices, int pricesSize) {
    if(!prices)
		return 0;
	int max = 0;
	//A trick to start the circulation
	int buy = prices[0] + 1;
	for(int i = 0; i < pricesSize - 1; i++){
		if(prices[i] >= buy)
			continue;
		else
			buy = prices[i];
		int sell = buy;
		for(int j = i + 1; j < pricesSize; j++){
			if(prices[j] > sell)
				sell = prices[j];
		}
		if(sell - buy > max)
			max = sell - buy;
	}
	return max;
}

//5.94%
int maxProfit(int* prices, int pricesSize) {
    if(!prices || 1 >= pricesSize)
		return 0;
	
	int min = prices[0];
	int minIndex = 0;
	int max = min;
	int maxIndex = 0;
	for(int i = 1; i < pricesSize; i++)
		if(prices[i] >= max){
			maxIndex = i;
			max = prices[i];
		}
		else if(prices[i] < min){
			min = prices[i];
			minIndex = i;
		}
	if(maxIndex >= minIndex)
		return max - min;
	int maxPl = maxProfit(prices, maxIndex + 1);
	int maxPr = maxProfit(prices + minIndex, pricesSize - minIndex);
	int maxPm = maxProfit(prices + maxIndex + 1, minIndex - maxIndex - 1);
	if(maxPr > maxPl)
		maxPl = maxPr;
	if(maxPm > maxPl)
		maxPl = maxPm;
	
	return maxPl;
}

//7.43%
//Basically it's maximum sub-array problems
int maxProfit(int* prices, int pricesSize) {
    if(!prices || 1 >= pricesSize)
		return 0;
	int maxAll = 0;
	int maxNow = 0;
	for(int i = 1; i < pricesSize; i++){
		maxNow += (prices[i] - prices[i - 1]);
		if(maxNow < 0)
			maxNow = 0;
		else if(maxNow > maxAll)
			maxAll = maxNow;
	}
	return maxAll;
}

//My old solution
int maxProfit(int* prices, int pricesSize) 
{
    if(!prices || 1 >= pricesSize)
		return 0;
	int i, minPrice, result;
	minPrice = prices[0];
	result = prices[1] - prices[0];
	for(i = 0; i < pricesSize; i++)
	{
		if(prices[i] < minPrice)
			minPrice = prices[i];
		if(result < prices[i] - minPrice)
			result = prices[i] - minPrice;
	}
	
	return result;
}