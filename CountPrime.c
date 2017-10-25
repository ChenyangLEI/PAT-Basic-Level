/*Count Prime*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int IsPrime(int i)
{
	double d_i = i;
	int j = 2;
	/*避免超时，用sqrt*/
	int sqrt_i = sqrt(d_i);
	while (j <= sqrt_i){
		if (i % j == 0)	return 0;
		j++;
	}
	return 1;
}

void CountPrime(int M, int N)
{
	int count = 0;
	int num = 2;
	while (count < N)
	{
		if (IsPrime(num)){
			count++;
			if (count >= M) {
				printf("%d", num);
				if (count != N){
					if ((count-M+1) % 10 == 0) printf("\n");
					else printf(" ");
				}
			}
		}
		num++;
	}
}
int main(void)
{
	int N, M;
	/*读入N与M*/
	scanf("%d %d", &M, &N);
	CountPrime(M, N);
	system("pause");
	return 0;
}