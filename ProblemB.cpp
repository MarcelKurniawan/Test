#include <stdio.h>
#include <string.h>

typedef struct data {
	char M[100];
	char R[100];
} a;

int main (){
	FILE *fp = fopen("testdata.in", "r");
	
	int N;
	char *token;
	fscanf(fp, "%d\n", &N); 
	data a[N];
	for (int i=0; i<N; i++){
		fscanf(fp, "%[^#]#%[^\n]\n", a[i].M, a[i].R);
	}
	
	int O;
	fscanf(fp, "%d\n", &O);
	char P[O][100];
	char s[2] = '';
	for (int i=0; i<O; i++){
		fscanf(fp, "%[^\n]\n", P[i]);
	}
	token = strtok(P, s);
	for (int i = 0; i < O; i++){
		int count = 0;
		printf("Case #%d: ", i+1);
		for (int j = 0; j < N; j++){
			if (strcmp(a[j].M, token) == 0){
				printf("%s", a[j].R);
			}
			else{
				count += 1;
			}
		}
		if (count == N){
			printf("%s", P[i]);
		}
		printf("\n");
	}
	fclose(fp);
	return(0);
}
