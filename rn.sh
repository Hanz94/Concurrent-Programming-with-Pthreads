
gcc mutex_version.c -g -Wall -o mutex_version -lpthread -lm
./mutex_version 0.99 0.005 .005 100 2

#gcc -g -Wall -o serial_run serial.c -lpthread -lm
#./serial_run 1000 10000 0.99 0.005 .005 100 
