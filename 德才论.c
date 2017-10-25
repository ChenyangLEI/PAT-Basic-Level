/*德才论*/
/*
Case1: D >= H && C >= H, ordered by D + C
Case2: D >= H && C < H, ordered by D + C
Case3: D < H  && C < H && D > C, ordered by D + C
Case4: D > L && C > L, ordered by D + C
*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int N, L, H;
	int ID, D, C;
	scanf("%d %d %d", &N, &L, &H);

	/*Create DangAn*/
	while (N--){
		scanf("%d %d %d", &ID, &D, &C);
		if (D >= H && C >= H);
		else if (D >= H && C < H);
		else if (D < H  && C < H && D > C);
		else if (D > L && C > L);
	}

	/*Sort by D + C*/

	/*PrintOut*/

	system("pause");
	return 0;
}