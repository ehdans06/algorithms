#include<stdio.h>

int N, D[1010101], i, j;

int main(){
	scanf("%d", &N); D[0]=1;
	for(i=1; i<=N; i<<=1){
		for(j=i; j<=N; j++)D[j]+=D[j-i], D[j]%=1000000000;
	}
	printf("%d\n", D[N]);
	return 0;
}
