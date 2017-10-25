/*Title：说反话*/
#include<stdio.h>
#include <stdlib.h> 
#include <string.h>

void PrintStr(char str[], int i, int j)
{
	int k;
	for (k = i; k < j; k++)
		printf("%c", str[k]);
}

int main(){
	int n, i,j;
	int last;
	char str[81];
	int space[81] = {0}, idx = 1;
	int len;

	/*Read in the string!*/
	/*用scanf读入会出错，gets便没有问题*/
	//	scanf("%s", str);
	gets(str);
	len = strlen(str);
//	printf("%d\n", len);

	/*Get the position of 0*/
	for (i = 0; i < len; i++)
		if (str[i] == ' ') space[idx++] = i;
	space[idx] = len;
	for (j = 0; j <= idx; j++)
//		printf("%d ", space[j]);

	/*PrintOut according to order.*/
	while (i != 0){
		j = idx;
		i = j-1;
	    idx--;
//		printf("%d, %d", space[i], space[j]);
		if (i != 0){
			PrintStr(str, space[i] + 1, space[j]);
			printf(" ");
		}
		else
			PrintStr(str, space[i], space[j]);
	}

	printf("\n");
	system("pause");
	return 0;
}