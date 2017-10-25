/*[A+B and C]*/
#include <stdio.h>
#include <stdlib.h>

typedef struct ABC_Node *ABC_List;
struct ABC_Node{
	int a;
	int b;
	int c;
	ABC_List Next;
};

void Attach(int a, int b, int c, ABC_List *Rear)
{
	ABC_List L;
	L = (ABC_List)malloc(sizeof(struct ABC_Node));
	L->a = a;
	L->b = b;
	L->c = c;
	L->Next = NULL;
	(*Rear)->Next = L;
	(*Rear) = L;
}

ABC_List NewNode()
{
	ABC_List L;
	L = (ABC_List)malloc(sizeof(struct ABC_Node));
	L->Next = NULL;
	return L;
}

ABC_List ReadList()
{
	ABC_List L, Rear, t;
	int count, a, b, c;

	L = (ABC_List)malloc(sizeof(struct ABC_Node));
	L->Next = NULL;
	Rear = L;

	scanf("%d", &count);
	while (count--){
		scanf("%d %d %d", &a, &b, &c);
		Attach(a, b, c, &Rear);
	}

	t = L; L = L->Next; free(t);
	return L;
}

int CmpList(ABC_List L)
{
	double a, b, c;
	a = L->a / 2.0;
	b = L->b / 2.0;
	c = L->c / 2.0;
//	printf("%f, %f, %f", a, b, c);
	if ((a + b) > c) return 1;
//	if ((L->a + L->b) > L->c) return 1;
	else return 0;
}

void CmpAndPrint(ABC_List L)
{	
	int count = 1;
	while (L){
		printf("Case #%d: ", count);
		if (CmpList(L)) printf("true\n");
		else printf("false\n");
		L = L->Next;
		count++;
	}
}
void PrintList(ABC_List L)
{
	while (L){
		printf("%d %d %d\n", L->a, L->b, L->c);
		L = L->Next;
	}
}
int main(void)
{
	ABC_List L;
	/*Read in.*/
	L = ReadList();
//	PrintList(L);
	/*Compare*/
	CmpAndPrint(L);
	/*Print*/
	system("pause");
	return 0;
}