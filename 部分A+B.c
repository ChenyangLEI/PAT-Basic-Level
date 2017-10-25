/*部分A+B*/
#include <stdio.h>
#include <stdlib.h>


int GetP(int A, int DA)
{
	int PA = 0;
	while (A != 0){
		if (A % 10 == DA) PA = 10 * PA + DA;
		A = A / 10;
	}
	return PA;
}

int main(void)
{
	int A, DA, B, DB;
	int PA, PB,P;
	scanf("%d %d %d %d", &A, &DA, &B, &DB);
	PA = GetP(A, DA);
	PB = GetP(B, DB);
	P = PA + PB;
	printf("%d", P);
	system("pause");
	return 0;
}