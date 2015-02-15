#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

#define TS 0
#define S 1
#define U 2
#define NUM_THREADS     20

// declare semaphores
sem_t l_cluster;
sem_t r_cluster;

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
	pthread_t Thread;
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

void push(pthread_t thread)
{
	struct Node *temp;
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp->Thread = thread;
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
 printf("\nQueue is Empty");
 }*/

// Print a message confirming pthread creation
void *PrintHello(void *threadid)
{
	long tid;
	tid = (long)threadid;
	printf("Hello World! It's me, thread #%ld!\n", tid);
	pthread_exit(NULL);
}

// Create an unclassified job that sleeps for a bit before getting back in line.
void *UnclassifiedJob()
{
	// lock semaphore
	
	// sleep
	
	// unlock semaphore
}

int main(){
	
	//Create queues for each type of job
	struct Node *tsq;  //top secret
	struct Node *sq;  //secret
	struct Node *uq;  //unclassified
	
	//initialize semaphore for each cluster
	sem_init(&l_cluster, 0, 1);
	sem_init(&r_cluster, 0, 1);
	
	//Test pthread creation and termination
	pthread_t threads[NUM_THREADS];
	int rc;
	long t;
	for(t=0; t<NUM_THREADS; t++){
		printf("In main: creating thread %ld\n", t);
		rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
		if (rc){
			printf("ERROR; return code from pthread_create() is %d\n", rc);
			exit(-1);
		}
		push(threads[t]);
	}
	
	/* Last thing that main() should do */
	pthread_exit(NULL);
	
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



