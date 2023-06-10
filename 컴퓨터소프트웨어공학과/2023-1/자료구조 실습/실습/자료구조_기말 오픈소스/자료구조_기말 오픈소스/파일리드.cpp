// 리드 방법 1
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
		fscanf(fp, "%d", &nTemp); // 읽을 파일 포인터, 형식지정, 데이터 넣을 곳

	}

	fclose(fp);
}

// 리드 방법2

ListNode* read_file(ListNode* head)
{
	ifstream in("data.txt");
	if (!in)
	{
		printf("File Open Error\n");
		return nullptr;
	}

	element el;
	while (in >> el.id >> el.name >> el.korScore >> el.engScore >> el.mathScore)  // 파일에 들어가있는 데이터 형식 에 따라 읽어 들인다.
	{
		el.totalScore = el.korScore + el.engScore + el.mathScore;
		el.avgScore = (float)el.totalScore / NUMBER_SUBJECT;
		head = insert_last(head, el);
	}
	return head;
}