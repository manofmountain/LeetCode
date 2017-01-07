
//83.33%
typedef struct {
    int maxSize;
	int size;
	int minBaseSize;
	int *base;
	int *minBase;
} MinStack;

/** initialize your data structure here ->  */
MinStack* minStackCreate(int maxSize) {
    MinStack *myStack = (MinStack *)malloc(sizeof(MinStack));
	myStack -> size = 0;
	myStack -> minBaseSize = 0;
	myStack -> maxSize = maxSize;
	myStack -> base = (int *)malloc(sizeof(int) * maxSize);
	myStack -> minBase = (int *)malloc(sizeof(int) * maxSize);
	return myStack;
}

void minStackPush(MinStack* obj, int x) {
    if(obj -> size == obj -> maxSize)
		return;
	obj -> base[obj -> size++] = x;
	if(!obj -> minBaseSize || obj -> minBase[obj -> minBaseSize - 1] >= x)
		obj -> minBase[obj -> minBaseSize++] = x;
}

void minStackPop(MinStack* obj) {
    if(!obj -> size)
		return;
	if(obj -> minBase[obj -> minBaseSize - 1] == obj -> base[obj -> size - 1])
		obj -> minBaseSize--;
	obj -> size--;
}

int minStackTop(MinStack* obj) {
    if(obj -> size <= 0)
		exit(-1);
	return obj -> base[obj -> size - 1];
}

int minStackGetMin(MinStack* obj) {
    if(obj -> minBaseSize <= 0)
		exit(-1);
	return obj -> minBase[obj -> minBaseSize - 1];
}

void minStackFree(MinStack* obj) {
    free(obj -> base);
	free(obj -> minBase);
	free(obj);
	obj = NULL; //This is import to avoid dangling pointers.
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */