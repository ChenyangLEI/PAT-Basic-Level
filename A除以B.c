/*A除以B*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(void)
{
	int a[1000],b[1000];
	int B;
	char c[1003];
	int len;
	int i;
	int A, Q, R=0;

	/*Read in a & B*/
	gets(c);
	len = strlen(c);
	for (i = 0; i < len - 2; i++) a[i] = c[i] - '0';
	B = c[len - 1] - '0';

	/*Divide, 考虑0的情况*/
	int idx_b = 0;
	for (i = 0; i < len - 2; i++) {
		A = a[i] + R * 10;
		if (A >= B) {
			R = A % B;
			b[idx_b] = A / B;
			idx_b++;
		}
		else{
			R = A;
			if (idx_b != 0){
				b[idx_b] = 0;
				idx_b++;
			}
		}
	}

	/*特殊情况*/
	if (idx_b == 0) {
		b[idx_b] = 0;
		idx_b++;
	}
	/*PrintOut*/
	for (i = 0; i < idx_b; i++) printf("%d", b[i]);
	printf(" %d", R);

	system("pause");
	return 0;	
}