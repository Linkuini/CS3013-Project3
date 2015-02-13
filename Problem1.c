#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define TS 0
#define S 1
#define U 2

//random time generator for usleep
/*float randTime(){
	srand(time (NULL));
	float maxTime = 2.0;
	float minTime = .25;
	float diff = 1.75;
	return rand();
}*/
	
//create a queue linked list of different jobs
struct Node{
	int Thread;
	struct Node* next;
}*front, *rear;

void dQueue(){
	struct Node *temp, *var=front;
	if(var==front)
	{
	//put in cluster
	front = front->next;
	free(var);
}
else
printf("\n Queue Empty");
}

void push(int value)
{
	struct Node *temp;
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp->Thread = value;
	if(rear == NULL){
		rear = temp;
		rear->next = NULL;
		front = rear;
	}
	else{
		rear->next = temp;
		rear = temp;
		rear->next = NULL;
	}
}

/*void display(){
	struct Node *var = rear;
	if(var != NULL){
		printf("\nElements are as: ");
		while(var != NULL){
			printf("\t%d", var-> Thread);
			var = var->next;
		}
		printf("\n");
	}
	else
		printf("\nQueue is EMpty");
}*/

int main(){

//Create queues for each type of job	
struct Node *tsq;  //top secret 
struct Node *sq;  //secret 
struct Node *uq;  //unclassified 

}
//create top secret threads
/*int totalThreads = 6;
pthread_t threads[totalThreads];
int rc;
long t;
createThreads(int ID,int type, int cluster){
	for(t=0; t < totalThreads; t++){
		pthread_t thread[t] = pthread_create(Node.jobID = ID, Node.jobType = type, Node.cluster = cluster);
		t++;
	}
*/


//this was used to make the queue from user input to test that pushing and popping worked
/*int i = 0;
	rear = NULL;
	printf(" \n1. Push to Queue");
	printf(" \n2. Pop from Queue");
	printf(" \n3. Display Queue");	
	printf(" \n4. Exit\n");
	while(1)
	{
		printf(" \nChoose option: ");
		scanf("%d", &i);
		switch(i)
		{
			case 1:
			{
				int value;
				printf("\n Enter val to push: ");
				scanf("%d", &value);
				push(value);
				//display();
				break;
			}
			case 2:
			{
				dQueue();
				//display();
				break;	
			}
			case 3:
			{
				//display();
				break;
			}
			case 4: 
			{
				exit(0);
			}
			default:
			{
				printf("\n error");
			}
		}
	}*/




