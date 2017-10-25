/*[1010]:一元多项式求导*/
#include<stdio.h>
#include <stdlib.h> 
#include <string.h>

typedef struct PolyNode *Polynomial;
struct PolyNode{
	int coef;
	int expon;
	Polynomial link;
};

void Attach(int c, int e, Polynomial* Rear)
{
	Polynomial P;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->coef = c;
	P->expon = e;
	P->link = NULL;
	(*Rear)->link = P;
	(*Rear) = P;
}

Polynomial ReadPoly()
{
	int c, e=-1;
	Polynomial P,Rear,t;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->link = NULL;
	Rear = P;
	while (scanf("%d %d", &c, &e) != 0 ){
		Attach(c, e, &Rear);
		if (getchar() == '\n') break;
	}
	t = P; P = P->link; free(t);
	return P;
}

Polynomial ReversePoly(Polynomial P)
{
	int dc, de;
	Polynomial NewP, Rear, t;
	NewP = (Polynomial)malloc(sizeof(struct PolyNode));
	NewP->link = NULL;
	Rear = NewP;
	if ((!P)||(P->expon == 0)) {
		Attach(0, 0, &Rear);
	}
	else {
		while (P){
			if (P->expon != 0){
				dc = (P->expon)*(P->coef);
				de = (P->expon) - 1;
				Attach(dc, de, &Rear);
			}
			P = P->link;
		}
	}
	t = NewP; NewP = NewP->link; free(t);
	return NewP;
}
void PrintPoly(Polynomial P)
{
	if (!P)	{
		printf("0 0\n");
		return;
	}
	while (P){
		if (P->link)
			printf("%d %d ", P->coef, P->expon);
		else
			printf("%d %d", P->coef, P->expon);
		P = P->link;
	}
	//printf("\n");
}

int main(void)
{
	Polynomial P,Rever_P;
	/*读入数据*/
	P = ReadPoly();
//	PrintPoly(P);
	/*求导*/
	Rever_P = ReversePoly(P);
	PrintPoly(Rever_P);
	system("pause");
	return 0;

}
