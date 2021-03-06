#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "timer.h"

#define MAX_RANDOM 65535

/* Declaration global variables */
float f_insert, f_delete, f_member;
int sample;
struct list_node_s* head = NULL;
int n = 1000;	// n - no of elements
int m = 10000;	// m - no of operations
int randomarray[10000];
int operations[10000];



/* Declaration of the Linked List node */          
struct list_node_s {
    int data;
    struct list_node_s* next;
};

/* Functions Declaration */
int Insert(int value, struct list_node_s** head_pp);

int Delete(int value, struct list_node_s** head_pp);

int Member(int value, struct list_node_s* head_p);

void getInputs(int argc, char* argv[]);

void shuffle(int* array, size_t n);

int calculateSTD(double time_list[], int samples, double mean);

void freeMemory(struct list_node_s** head_pp);

void initializeRandomArray(struct list_node_s** head_pp,int n,int m,int* randomarray);

void initializeOperations(int* operations,int m_member,int m_insert,int m_delete);

void doOperations(struct list_node_s** head_pp,int m,int* operations,int* randomarray);


/* main */
int main(int argc, char* argv[]) {

    getInputs(argc, argv);		// initialize user arguements

    int m_insert, m_delete, m_member;
    double start, finish, elapsed,mean;
    double total_time = 0 ;
    double time_list[sample];

    m_member = m * f_member;	//	calculate individual number of sub operations for member operation
    m_insert = m * f_insert;	//	calculate individual number of sub operations for insert operation
    m_delete = m * f_delete;	//	calculate individual number of sub operations for delete operation
    
    int j;
    for(j = 0 ; j < sample; j++){
        
        initializeRandomArray(&head,n,m,randomarray);	

		initializeOperations(operations,m_member,m_insert,m_delete);

        shuffle(operations, m);		// shuffle the operations array
        shuffle(randomarray, m);	// shuffle the random number array

        GET_TIME(start);	// get start time of the operation

        doOperations(&head,m,operations,randomarray);	// execute operation

        GET_TIME(finish);	// get finished time of the operation
        
        /* calculate the elapsed time for the operation */
        elapsed = finish - start;
        time_list[j] = elapsed;
        total_time += elapsed;
        
        //printf("   Elapsed time = %e seconds\n", elapsed);
        
        freeMemory(&head);
        
    }
    
    mean = total_time/sample;
    
    calculateSTD(time_list, sample, mean);
    
    return 0;
} /* main */



/*
 * Function		: Member
 * Purpose		: check whether given element is existing in the linked list
 * In args		: int value, struct list_node_s* head_p
 */
int Member(int value, struct list_node_s* head_p){
    struct list_node_s* curr_p = head_p;

    while(curr_p != NULL && curr_p->data < value)
        curr_p = curr_p ->next;

    if(curr_p == NULL || curr_p->data > value){
        return 0;
    }else{
        return 1;
    }
} /* Member */



/*
 * Function		: Insert
 * Purpose		: insert an element to the linked list
 * In args		: int value, struct list_node_s* head_p
 */
int Insert(int value, struct list_node_s** head_pp) {
    struct list_node_s* curr_p = *head_pp;
    struct list_node_s* pred_p = NULL;
    struct list_node_s* temp_p = NULL;

    while (curr_p != NULL && curr_p->data < value) {
        pred_p = curr_p;
        curr_p = curr_p->next;
    }

    if (curr_p == NULL || curr_p->data > value) {
        temp_p = malloc(sizeof(struct list_node_s));
        temp_p->data = value;
        temp_p->next = curr_p;

        if (pred_p == NULL)  /* New first node */
            *head_pp = temp_p;
        else
            pred_p->next = temp_p;

        return 1;
    }
    else{ /* Value Already in list */
		return 0;
	}
} /* Insert */



/*
 * Function		: Delete
 * Purpose		: delete an element from the linked list
 * In args		: int value, struct list_node_s* head_p
 */
int Delete(int value, struct list_node_s** head_pp) {
    struct list_node_s* curr_p = *head_pp;
    struct list_node_s* pred_p = NULL;

    while (curr_p != NULL && curr_p->data < value) {
        pred_p = curr_p;
        curr_p = curr_p->next;
    }

    if (curr_p != NULL && curr_p->data == value) {
        if (pred_p == NULL) { /* Deleting the first Node in the list*/
            *head_pp = curr_p->next;
            free(curr_p);
        }
        else {
            pred_p->next = curr_p->next;
            free(curr_p);
        }
        return 1;
    }
    else{  /* Value is not in the list*/
        return 0;
	}
} /* Delete */



/*
 * Function		: getInputs
 * Purpose		: get the command line args
 * In args		: int argc, char* argv
 */
void getInputs(int argc, char* argv[]) {
    if (argc != 5)
    {
        printf("Please give the command: ./serial_version <f_Member> <f_Insert> <f_Delete> <sample size>\n");
        exit(0);
    }

    f_member = (float) atof(argv[1]);
    f_insert = (float) atof(argv[2]);
    f_delete = (float) atof(argv[3]);
    sample	 = (int) strtol(argv[4], (char**)NULL, 10);

   if ( f_member + f_insert + f_delete!=1.0) {
	   printf("Please enter valid fractions\n");
       exit(0);
   }

} /* getInputs */



/*
 * Function		: shuffle
 * Purpose		: shuffle the given array to get random pattern
 * In args		: int* array, size_t n
 */
void shuffle(int* array, size_t n)
{
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
         
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
} /* shuffle */



/*
 * Function		: calculateSTD
 * Purpose		: calculate the standard deviation of times
 * In args		: double[] time, int samples, double mean
 */
int calculateSTD(double time_list[], int samples, double mean){
	int i;
	float std=0;
	float temp=0.0;
	float min_samples;
	
	for(i=0; i<samples; i++){
		time_list[i] -= mean;
		temp = time_list[i]*time_list[i];
		std += temp;
	}
	
	std = std/samples;
	std = sqrt(std);
	min_samples = pow((100*1.96*std)/(5*mean),2);
	printf("Average time spent = %f\n",mean);
	printf("Standard Deviation = %f\n",(std));
	printf("Minimum samples need = %f\n", min_samples);

	return 0;
} /* calculateSTD */



/* 
 * Function		: freeMemory
 * Purpose		: free the storage used by the list
 * In/out args	: struct list_node_s** head_pp - pointer to the head of the list pointer
 */
void freeMemory(struct list_node_s** head_pp) {
	struct list_node_s* curr_p;
	struct list_node_s* succ_p;

	if (head_pp == NULL)
		return;

	curr_p = *head_pp;
	succ_p = curr_p->next;

	while (succ_p != NULL) {
		free(curr_p);
		curr_p = succ_p;
		succ_p = curr_p->next;
	}

	free(curr_p);
	*head_pp = NULL;
} /* freeMemory */



/* 
 * Function		: initializeRandomArray
 * Purpose		: initialize the random array
 * In/out args	: struct list_node_s** head_pp -,int n,int m,int* randomarray
 */ 
void initializeRandomArray(struct list_node_s** head_pp,int n,int m,int* randomarray){
	int i = 0;
	while (i < n) {
		int x = (rand() % MAX_RANDOM) + 1;
		if (Insert(x, &head) == 1){
			randomarray[i] = x;
			i++;
		}
	}

	for(i = 0; i < m-n; i++){
		randomarray[i+n] = (rand() % MAX_RANDOM) + 1;
	}
	 
} /* initializeRandomArray */



/* 
 * Function		: initializeOperations
 * Purpose		: initialize the operations array
 * In/out args	: int* operations,int m_member,int m_insert,int m_delete
 */ 
void initializeOperations(int* operations,int m_member,int m_insert,int m_delete){
	int count_member = 0;
	int count_insert = 0;
	int count_delete = 0;
	int count_tot = 0;
	
	while (count_tot < (m_member+m_insert+m_delete)) {

		int rand_select = rand() % 3;

		if (rand_select == 0 && count_member < m_member) {
			operations[count_tot] = 0;
			count_member++;
		}

		else if (rand_select == 1 && count_insert < m_insert) {
			operations[count_tot] = 1;
			count_insert++;
		}

		else if (rand_select == 2 && count_delete < m_delete) {
			operations[count_tot] = 2;
			count_delete++;
		}

		count_tot = count_insert + count_member + count_delete;
	} 
} /* initializeOperations */



/* 
 * Function		: doOperations
 * Purpose		: execute the operations
 * In/out args	: int* operations,int m_member,int m_insert,int m_delete
 */  
void doOperations(struct list_node_s** head_pp,int m,int* operations,int* randomarray){
	int count_tot;
	
	for(count_tot =0 ; count_tot < m ; count_tot++){

		int rand_select = operations[count_tot];
		int in_value = randomarray[count_tot];

		if (rand_select == 0) {
			Member(in_value, head);
		}

		else if (rand_select == 1) {
			Insert(in_value, &head);
		}

		else if (rand_select == 2) {
			Delete(in_value, &head);
		}
	}
} /* doOperations */



