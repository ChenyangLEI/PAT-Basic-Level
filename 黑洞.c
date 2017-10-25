/*1019. 数字黑洞 (20)*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int TransNum(int a[])
{
	int num;
	num = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
	return num;
}

void TransArray(int num_a, int a[])
{
	int i;
	for (i = 0; i < 4; i++){
		a[3 - i] = num_a % 10;
		num_a = num_a / 10;
	}
}
void SortDes(int a[])
{
	int i, j, idx=0,tmp;
	int max = a[0];

	for (i = 0; i < 4; i++){
		for (j = i; j < 4; j++){
			if (a[j] >= a[i]) {
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}

	}
}

void SortUp(int a[])
{
	int i, j, idx=0, tmp;
	int min = a[0];
	for (i = 0; i < 4; i++){
		for (j = i; j < 4; j++){
			if (a[j] <= a[i]) {
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}

int main(void)
{
	int a[4] = { 1, 2, 3, 4 };
	int A[4], B[4], C[4];
	int num_a, i;
	int begin, end;
	/*Read in nums.*/
	scanf("%d", &num_a);
	TransArray(num_a, a);
	if (num_a == 6174){
		printf("7641 - 1467 = 6714\n");
		return 0;
	}
	begin = TransNum(a);
	end = begin + 1;

	int Des, Up;

	while (begin != end){
		begin = TransNum(a);
		/*降序和升序*/
		SortDes(a);
		Des = TransNum(a);
		for (i = 0; i < 4; i++) A[i] = a[i];
		SortUp(a);
		Up = TransNum(a);
		for (i = 0; i < 4; i++) B[i] = a[i];

		/*相减*/
		end = Des - Up;
		TransArray(end, a);
		/*输出*/
		if (begin != end){
			for (i = 0; i < 4; i++) printf("%d", A[i]);
			printf(" - ");
			for (i = 0; i < 4; i++) printf("%d", B[i]);
			printf(" = ");
			for (i = 0; i < 4; i++) printf("%d", a[i]);
			printf("\n");
		}
	}
	
	system("pause");
	return 0;	
}