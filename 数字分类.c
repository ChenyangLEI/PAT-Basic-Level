/*数字分类*/
#include <stdio.h>
#include <stdlib.h>

typedef struct ModNode *ModList;
struct ModNode{
	int a;
	ModList Next;
};

void Attach(int a,  ModList *Rear)
{
	ModList L;
	L = (ModList)malloc(sizeof(struct ModNode));
	L->a = a;
	L->Next = NULL;
	(*Rear)->Next = L;
	(*Rear) = L;
}

ModList ReadList()
{
	ModList L, Rear, t;
	int count, a;

	L = (ModList)malloc(sizeof(struct ModNode));
	L->Next = NULL;
	Rear = L;
	scanf("%d", &count);
	while (count--){
		scanf("%d", &a);
		Attach(a, &Rear);
	}

	t = L; L = L->Next; free(t);
	return L;
}

void PrintList(ModList L)
{
	while (L){
		printf("%d ", L->a);
		L = L->Next;
	}
	printf("\n");
}

void PrintMod(ModList L)
{
	int data;
	int count[5] = { 0, 0, 0, 0, 0 };
	int A1=0, A2=0, A3 = 0, A4 = 0, A5=0;
	int flag = 1;
	double answerA4;
	while (L){
		data = (L->a) % 5;
		switch (data){
			case 0: 
				if (L->a % 2 == 0){
					count[0]++;
					A1 += L->a;
				}
				break;
			case 1:
				count[1]++;
				A2 = A2 + flag * (L->a);
				flag = - flag;
				break;
			case 2:
				count[2]++;
				break;
			case 3:
				count[3]++;
				A4 += L->a;
				break;
			case 4:
				count[4]++;
				if (L->a >= A5) A5 = L->a;
				break;
			default:
			break;
		}
		L = L->Next;
	}

	answerA4 = A4 / 1.0 / count[3];
	A3 = count[2];

	if (count[0] == 0)	printf("N ");
	else printf("%d ", A1);

	if (count[1] == 0)	printf("N ");
	else printf("%d ", A2);

	if (count[2] == 0)	printf("N ");
	else printf("%d ", A3);

	if (count[3] == 0)	printf("N ");
	else printf("%.1f ", answerA4);

	if (count[4] == 0)	printf("N");
	else printf("%d", A5);
}

int main(void)
{
	ModList L;
	/*Read in.*/
	L = ReadList();
//	PrintList(L);
	/*Print*/
	PrintMod(L);
	//PrintModSum(L);
	//PrintMod1(L);
	//PrintMod2(L);
	//PrintMod3(L);
	//PrintMod4(L);
	system("pause");
	return 0;
}