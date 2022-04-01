#include <stdio.h>
#include <string.h>

typedef struct student{
	char M[100];
	char R[15];
} data;

int main (){
	FILE *fp;
	fp = fopen("testdata.in", "r");
	
	int T;
	fscanf(fp, "%d\n", &T);
	student data[T];
	
	for (int i = 0; i < T; i++){
		fscanf(fp, "%[^ ] %[^\n]\n", data[i].R, data[i].M);
	}
	
	for (int i = 0; i < T; i++){
		for (int j = i+1; j < T; j++){
			if (strcmp(data[i].R, data[j].R) > 0){
				char temp[100]; 
				strcpy(temp, data[i].R);
				strcpy(data[i].R, data[j].R);
				strcpy(data[j].R, temp);
				char temp2[100];
				strcpy(temp2, data[i].M);
				strcpy(data[i].M, data[j].M);
				strcpy(data[j].M, temp2);
			}
		}
	}
	for (int i=0; i<T; i++){
		printf("%s %s\n", data[i].R, data[i].M);
	}
	fclose(fp);
	return(0);
}
