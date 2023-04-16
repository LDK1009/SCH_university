void insert(int array[], int loc, int value)
{
	int temp, items=0;
	for (int i = items; i > loc; i--)
		array[i + 1] = array[i];
	array[loc] = value;
	items++;
	return 0;
}