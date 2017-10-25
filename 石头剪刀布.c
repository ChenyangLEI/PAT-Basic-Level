/*A除以B*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int N;
	int Jia[3] = {0,0,0};
	int Yi[3] = {0,0,0};
	/*C:1, J:2, B:0*/
	int JiaWin[3] = {0,0,0};
	int YiWin[3] = {0,0,0};
	char JiaO, YiO;
	char Win[3] = { 'B', 'C', 'J' };
	scanf("%d", &N);
	getchar();
	while (N--){
		scanf("%c %c", &JiaO, &YiO);
		getchar();
	//	printf("%c %c", JiaO, YiO);
		if (JiaO == YiO){
			Jia[1]++;
			Yi[1]++;
		}
		else if ((JiaO == 'C' && YiO == 'J') || (JiaO == 'J' && YiO == 'B') || (JiaO == 'B' && YiO == 'C')){
			Jia[0]++;
			Yi[2]++;
			if (JiaO == 'C') JiaWin[1]++;
			else if (JiaO == 'J') JiaWin[2]++;
			else JiaWin[0]++;
		}
		else{
			Yi[0]++;
			Jia[2]++;
			if (YiO == 'C') YiWin[1]++;
			else if (YiO == 'J') YiWin[2]++;
			else YiWin[0]++;
		}
	}

	int i,maxJia=0,maxYi=0;
	int maxJiaIdx=0, maxYiIdx=0;

	for (i = 0; i < 3; i++) {
		if (JiaWin[i] > maxJia) {
			maxJia = JiaWin[i];
			maxJiaIdx = i;
		}
		if (YiWin[i] > maxYi) {
			maxYi = YiWin[i];
			maxYiIdx = i;
		}
	}

	for (i = 0; i < 2; i++) printf("%d ", Jia[i]);
	printf("%d\n",Jia[2]);
	for (i = 0; i < 2; i++) printf("%d ", Yi[i]);
	printf("%d\n",Yi[2]);

	printf("%c %c", Win[maxJiaIdx], Win[maxYiIdx]);
	system("pause");
	return 0;	
}