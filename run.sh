echo "----Welcome to concurrent programming Lab 2---"
echo "----------------------------------------------"

printf "\n1.Serial version of the program\n"
gcc serial_version.c -g -Wall -o serial_version -lpthread -lm
printf "\n --- 0.99 0.005 0.005 200 ---\n"
./serial_version 0.99 0.005 0.005 200
printf "\n --- 0.9 0.05 0.05 200 ---\n"
./serial_version 0.9 0.05 0.05 200
printf "\n --- 0.5 0.25 0.25 200 ---\n"
./serial_version 0.5 0.25 0.25 200


printf "\n1.Mutex for whole linked list\n"
gcc mutex_version.c -g -Wall -o mutex_version -lpthread -lm

printf "\n ----------------------------------------------------------------------------------------\n"
printf "\n --- 0.99 0.005 0.005 200 1 ---\n"
./mutex_version 0.99 0.005 0.005 200 1
printf "\n --- 0.99 0.005 0.005 200 2 ---\n"
./mutex_version 0.99 0.005 0.005 200 2
printf "\n --- 0.99 0.005 0.005 200 4 ---\n"
./mutex_version 0.99 0.005 0.005 200 4
printf "\n --- 0.99 0.005 0.005 200 8 ---\n"
./mutex_version 0.99 0.005 0.005 200 8

printf "\n ----------------------------------------------------------------------------------------\n"
printf "\n --- 0.9 0.05 0.05 200 1 ---\n"
./mutex_version 0.9 0.05 0.05 200 1
printf "\n --- 0.9 0.05 0.05 200 2 ---\n"
./mutex_version 0.9 0.05 0.05 200 2
printf "\n --- 0.9 0.05 0.05 200 4 ---\n"
./mutex_version 0.9 0.05 0.05 200 4
printf "\n --- 0.9 0.05 0.05 200 8 ---\n"
./mutex_version 0.9 0.05 0.05 200 8

printf "\n ----------------------------------------------------------------------------------------\n"
printf "\n --- 0.5 0.25 0.25 200 1 ---\n"
./mutex_version 0.5 0.25 0.25 200 1
printf "\n --- 0.5 0.25 0.25 200 2 ---\n"
./mutex_version 0.5 0.25 0.25 200 2
printf "\n --- 0.5 0.25 0.25 200 4 ---\n"
./mutex_version 0.5 0.25 0.25 200 4
printf "\n --- 0.5 0.25 0.25 200 8 ---\n"
./mutex_version 0.5 0.25 0.25 200 8

printf "\n1.Using Read Write Locks\n"
gcc rwlock_version.c -g -Wall -o rwlock_version -lpthread -lm

printf "\n ----------------------------------------------------------------------------------------\n"
printf "\n --- 0.99 0.005 0.005 200 1 ---\n"
./rwlock_version 0.99 0.005 0.005 200 1
printf "\n --- 0.99 0.005 0.005 200 2 ---\n"
./rwlock_version 0.99 0.005 0.005 200 2
printf "\n --- 0.99 0.005 0.005 200 4 ---\n"
./rwlock_version 0.99 0.005 0.005 200 4
printf "\n --- 0.99 0.005 0.005 200 8 ---\n"
./rwlock_version 0.99 0.005 0.005 200 8

printf "\n ----------------------------------------------------------------------------------------\n"
printf "\n --- 0.9 0.05 0.05 200 1 ---\n"
./rwlock_version 0.9 0.05 0.05 200 1
printf "\n --- 0.9 0.05 0.05 200 2 ---\n"
./rwlock_version 0.9 0.05 0.05 200 2
printf "\n --- 0.9 0.05 0.05 200 4 ---\n"
./rwlock_version 0.9 0.05 0.05 200 4
printf "\n --- 0.9 0.05 0.05 200 8 ---\n"
./rwlock_version 0.9 0.05 0.05 200 8

printf "\n ----------------------------------------------------------------------------------------\n"
printf "\n --- 0.5 0.25 0.25 200 1 ---\n"
./rwlock_version 0.5 0.25 0.25 200 1
printf "\n --- 0.5 0.25 0.25 200 2 ---\n"
./rwlock_version 0.5 0.25 0.25 200 2
printf "\n --- 0.5 0.25 0.25 200 4 ---\n"
./rwlock_version 0.5 0.25 0.25 200 4
printf "\n --- 0.5 0.25 0.25 200 8 ---\n"
./rwlock_version 0.5 0.25 0.25 200 8