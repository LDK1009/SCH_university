// ���� ��� 1
void main()
{
	FILE* fp;
	int nTemp;

	fp = fopen("data_Queue2.txt", "r");
	if (fp == NULL)
	{
		printf("file open error \n");
		exit(0);
	}

	nCount = 1;
	while (!feof(fp))
	{
		fscanf(fp, "%d", &nTemp); // ���� ���� ������, ��������, ������ ���� ��

	}

	fclose(fp);
}

// ���� ���2

ListNode* read_file(ListNode* head)
{
	ifstream in("data.txt");
	if (!in)
	{
		printf("File Open Error\n");
		return nullptr;
	}

	element el;
	while (in >> el.id >> el.name >> el.korScore >> el.engScore >> el.mathScore)  // ���Ͽ� ���ִ� ������ ���� �� ���� �о� ���δ�.
	{
		el.totalScore = el.korScore + el.engScore + el.mathScore;
		el.avgScore = (float)el.totalScore / NUMBER_SUBJECT;
		head = insert_last(head, el);
	}
	return head;
}