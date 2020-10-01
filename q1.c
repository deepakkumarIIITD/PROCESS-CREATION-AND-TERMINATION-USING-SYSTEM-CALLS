#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
double averager(int a,int b,int c,int d){
	return ((a+b+c+d)/4);
}
int function(int aorb){
	FILE* fl = fopen("file.csv","r");
	if(fl==NULL){
		printf("FILE NOT READABLE\n");
		return 0;
	}
	int arr_id[400];
	int arr_sec[400];
	int arr_a1[400];
	int arr_a2[400];
	int arr_a3[400];
	int arr_a4[400];
	char line[100];
	int i = 0;
	int j = 0;
	while(fgets(line,sizeof(line),fl)){
		if(i > 0){
			char*id,*sec,*a1,*a2,*a3,*a4;
			id = strtok(line,",");
			sec = strtok(NULL,",");
			a1 = strtok(NULL,",");
			a2 = strtok(NULL,",");
			a3 = strtok(NULL,",");
			a4 = strtok(NULL,",");
			int aid = atoi(id);
			int asec = sec[0];
			int aa1 = atoi(a1);
			int aa2 = atoi(a2);
			int aa3 = atoi(a3);
			int aa4 = atoi(a4);
			arr_id[j] = aid;
			arr_sec[j] = asec;
			arr_a1[j] = aa1;
			arr_a2[j] = aa2;
			arr_a3[j] = aa3;
			arr_a4[j] = aa4;
			j++;
		}
		i++;
	}
	for (int i = 0; i < 400;i++)
	{
		if (arr_sec[i] == aorb)
		{
			double averagescore = averager(arr_a1[i],arr_a2[i],arr_a3[i],arr_a4[i]);
			printf("STUDENT WITH ID : ");
			printf("%d",arr_id[i]);
			printf(" HAS AN AVERAGE SCORE OF : ");
			printf("%f",averagescore);
			printf("\n");
		}
	}
	return 0;
}
int main()
{
	// function(65);
	pid_t pid = fork();
	if(pid <= -1){
		perror("FORK FAILED");
		exit(0);
	}
	if(pid == 0){
		// inside child
		printf("\nAVERAGES OF SECTION A IN CHILD\n\n");
		function(65);
		exit(0);
	}
	else{
		// inside parent
		int state;
		pid_t got_pid = waitpid(pid,&state,0);
		printf("\nAVERAGES OF SECTION B IN PARENT\n\n");
		function(66);
		exit(0);
	}
	return 0;
}