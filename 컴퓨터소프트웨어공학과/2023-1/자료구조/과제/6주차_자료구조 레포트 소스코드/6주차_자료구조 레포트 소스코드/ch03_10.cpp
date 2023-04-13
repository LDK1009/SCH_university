int delete(int array[], int loc)
{
	int items = 0;
	int temp = array[loc];
	for (int i = loc; i < items; i++)
		array[i] = array[i + 1];
	array[items - 1] = 0;
	items--;
	return temp;
}