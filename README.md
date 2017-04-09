# Linked List Implementation : Serial & Parallel (Mutex, Read Write Locks)

This repository contains linked list implementation as follows; 
  - Serial program
  - Parallel program (based on Pthreads) with one mutex for the entire linked list
  - Parallel program (based on Pthreads) with read-write locks for the entire linked list
  
All these implementation of the linked list supports Member( ), Insert( ), and Delete( ) functions of the linked list.

- timer.h -: Header file for calculating execution time.
- run.sh -: Shell script to run all combinations and get results.

#### ------------- Executing all combinations -----------------------

1. Run the run.sh file using following command and get the command line output to text file.
	
	`./run.sh > output.txt`

2. If the *-bash: ./rn.sh: Permission denied* give execution permit to the script using following command.

	`chmod +x run.sh`

#### ------------- Executing serial version -----------------------

1. Compile the serial_version.c using following command.
```C
	gcc serial_version.c -g -Wall -o serial_version -lpthread -lm
```
2. Run the serial_version using following command with wanted parameters.  
	./serial_version <m_f> <i_f> <d_f> <no_of_samples>  
	eg -: `./serial_version 0.99 0.005 0.005 200`

#### ------------- Executing mutex version -----------------------

1. Compile the mutex_version.c using following command.

```C
	gcc mutex_version.c -g -Wall -o mutex_version -lpthread -lm
````
2. Run the mutex_version using following command with wanted parameters.  
	./mutex_version <m_f> <i_f> <d_f> <no_of_samples> <no_of_threads>  
	eg -: `./mutex_version 0.99 0.005 0.005 200 4`


#### ------------- Executing Read Write Lock version -----------------------

1. Compile the rwlock_version.c using following command.
```C
	`gcc rwlock_version.c -g -Wall -o rwlock_version -lpthread -lm`
```
2. Run the mutex_version using following command with wanted parameters.  
	./rwlock_version <m_f> <i_f> <d_f> <no_of_samples> <no_of_threads>  
	eg -: `./rwlock_version 0.99 0.005 0.005 200 4`
