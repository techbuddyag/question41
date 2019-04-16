
#include<stdio.h>
#include<pthread.h>
void *function1(void *);
void *function2(void *);
int flag[2]; //if process is ready to enter in the critical stage	
FILE*fptr1;
int turn=0;//whose turn it is to enter into the critical section
int i=0;
int main()
{
	
	pthread_t t1; 	
	pthread_t t2; 	
	pthread_create(&t1,NULL,function1,NULL);	//creating thread 1 
	pthread_create(&t2,NULL,function2,NULL);	//creating thread 2 
	pthread_join(t1,NULL);	
	pthread_join(t2,NULL);	
	return 0;
}

void *function1(void *p) 	//process 1 active function
{
    while(i<2)		
    {
        flag[0]=1;	//active process p1 state
        turn=1;		//turn of process p1
        while(flag[1]==1 && turn==1);
		file1();	//process p1 falls into critical state 
        flag[0]=0;	//exits the process state
        i++;
    }
}

void *function2(void *p) 	//process 1 active function
{
    while(i<2)		
    {
        flag[1]=1;	//active process p2 state
        turn=0;		//turn of process p2
        while(flag[0]==1 && turn==0);
        file2();	// critical state 
        flag[1]=0;	//exits the process state
        i++;
    }
}


int file1() 		
{
	fptr1=fopen("FILE.txt","w");
	//writing in file
	if(fptr1==NULL)
	{
		printf("FILE DOES NoT EXISTS.");
	}
	else
	{
		printf("Writing");
		fprintf(fptr1,"Process P1 is writing on the shared file.");
		fprintf(fptr1,"\nFile Writing Complete");
	}
	
	fclose(fptr1);
	return 0;
}

int file2() 		 
{
	fptr1=fopen("FILE.txt","w");
	//writing in file
	if(fptr1==NULL)
	{
		printf("FILE DOES NoT EXISTS.");
	}
	else
	{
		printf("Writing");
		fprintf(fptr1,"Process P2 is writing on the shared file.");
		fprintf(fptr1,"\nFile Writing Complete");
	}
	
	fclose(fptr1);
	return 0;
}


