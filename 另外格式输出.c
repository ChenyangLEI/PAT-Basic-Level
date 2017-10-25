#include<stdio.h>
#include <stdlib.h> 

int main(){
	int n, i, j;
	int n_count = -1;
	int bit_n[4];
	
	scanf("%d", &n);
	while (n != 0){
		n_count++;
		bit_n[n_count] = n % 10;
		n /= 10;
	}

	for (i = n_count; i >= 0; i--){
		if (i == 2)
			for (j = 0; j < bit_n[i]; j++) printf("B");
		else if (i == 1)
			for (j = 0; j < bit_n[i]; j++) printf("S");
		else if (i == 0)
			for (j = 1; j <= bit_n[i]; j++) printf("%d", j);
	}
	printf("\n");
	system("pause");
	return 0;
}