//ld
#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
int main()
{
char dirname[10];
DIR*p;
struct dirent *d;
printf("Enter directory name\n");
scanf("%s",dirname);
p=opendir(dirname);
if(p==NULL)
{
perror("Cannot find directory");
exit(-1);
}
while(d=readdir(p))
printf("%s\n",d->d_name);
return 0;
}

//cp
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
int f1, f2;
char buff[50];
long int n;
if(((f1 = open(argv[1], O_RDONLY)) == -1 || ((f2=open(argv[2], O_CREAT |
O_WRONLY | O_TRUNC, 0700))== 1)))
{
perror("problem in file");
exit(1);
}
while((n=read(f1, buff, 50))>0)
if(write(f2, buff, n)!=n)
{
perror("problem in writing");
exit(3);
}
if(n==-1)
{
perror("problem in reading");
exit(2);
}
close(f2);
exit(0);
}


// fcfs


#include<stdio.h>
int main(){

int n;
printf("Enter the number of process:");
scanf("%d",&n);

int pid[15];
printf("Enter the process id:");
for(int i=0;i<n;i++){
    scanf("%d",&pid[i]);
}

int bt[15];
printf("Enter the burst time:");
for(int i=0;i<n;i++){
    scanf("%d",&bt[i]);
}

int wt[n];
wt[0]=0;

for(int i=1;i<n;i++){
    wt[i]=wt[i-1]+bt[i-1];
}

printf("\nProcess id\t  busrt time\t  waiting time\t  turn around time\n");
float twt=0.0;
float tat=0.0;
for(int i=0;i<n;i++){
    printf("%d\t\t",pid[i]);
    printf("%d\t\t",bt[i]);
    printf("%d\t\t",wt[i]);
    printf("%d\t\t",wt[i]+bt[i]);

    twt+=wt[i];
    tat+=bt[i]+wt[i];
}

float awt=twt/n;
float att=tat/n;

printf("\ntotal average waiting time=%f\n",awt);
printf("\ntotal average waiting time=%f\n",att);

}

// srt

#include<stdio.h>

int main() 
{
 int a[10],b[10],x[10],i,j,smallest,count=0,time,n;
 double avg=0,tt=0,end;
  printf("enter the number of Processes:\n");
  scanf("%d",&n); 
 printf("enter arrival time\n");
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);
 printf("enter burst time\n");
 for(i=0;i<n;i++)
 scanf("%d",&b[i]); 
 for(i=0;i<n;i++)
 x[i]=b[i];

  b[9]=9999;
  
 for(time=0;count!=n;time++)
 {
   smallest=9;
  for(i=0;i<n;i++)
  {
   if(a[i]<=time && b[i]<b[smallest] && b[i]>0 )
   smallest=i;
  }
  b[smallest]--;
  if(b[smallest]==0)
  {
   count++;
   end=time+1;
   avg=avg+end-a[smallest]-x[smallest];
   tt= tt+end-a[smallest];
  }
 }
 printf("\n\nAverage waiting time = %lf\n",avg/n);
    printf("Average Turnaround time = %lf",tt/n);
    return 0;
}

// dining philosopher


#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t room;
sem_t chopstick[5];

void * philosopher(void *);
void eat(int);
int main()
{
	int i,a[5];
	pthread_t tid[5];
	
	sem_init(&room,0,4);
	
	for(i=0;i<5;i++)
		sem_init(&chopstick[i],0,1);
		
	for(i=0;i<5;i++){
		a[i]=i;
		pthread_create(&tid[i],NULL,philosopher,(void *)&a[i]);
	}
	for(i=0;i<5;i++)
		pthread_join(tid[i],NULL);
}

void * philosopher(void * num)
{
	int phil=*(int *)num;

	sem_wait(&room);
	printf("\nPhilosopher %d has entered room",phil);
	sem_wait(&chopstick[phil]);
	sem_wait(&chopstick[(phil+1)%5]);

	eat(phil);
	sleep(2);
	printf("\nPhilosopher %d has finished eating",phil);

	sem_post(&chopstick[(phil+1)%5]);
	sem_post(&chopstick[phil]);
	sem_post(&room);
}

void eat(int phil)
{
	printf("\nPhilosopher %d is eating",phil);
}

// bankers algo

#include<stdio.h>  
int main()  
{  
    // P0 , P1 , P2 , P3 , P4 are the Process names here  
    int n , m , i , j , k;  
    n = 5; // Number of processes  
    m = 3; // Number of resources  
    int alloc[ 5 ] [ 3 ] = { { 0 , 1 , 0 }, // P0 // Allocation Matrix  
                        { 2 , 0 , 0 } , // P1  
                        { 3 , 0 , 2 } , // P2  
                        { 2 , 1 , 1 } , // P3  
                        { 0 , 0 , 2 } } ; // P4  
    int max[ 5 ] [ 3 ] = { { 7 , 5 , 3 } , // P0 // MAX Matrix  
                    { 3 , 2 , 2 } , // P1  
                    { 9 , 0 , 2 } , // P2  
                    { 2 , 2 , 2 } , // P3  
                    { 4 , 3 , 3 } } ; // P4  
    int avail[3] = { 3 , 3 , 2 } ; // Available Resources  
    int f[n] , ans[n] , ind = 0 ;  
    for (k = 0; k < n; k++) {  
        f[k] = 0;  
    }  
    int need[n][m];  
    for (i = 0; i < n; i++) {  
        for (j = 0; j < m; j++)  
            need[i][j] = max[i][j] - alloc[i][j] ;  
    }  
    int y = 0;  
    for (k = 0; k < 5; k++){  
        for (i = 0; i < n; i++){  
            if (f[i] == 0){  
                int flag = 0;  
                for (j = 0; j < m; j++) {  
                    if(need[i][j] > avail[j]){  
                        flag = 1;  
                        break;  
                    }  
                }  
                if ( flag == 0 ) {  
                    ans[ind++] = i;  
                    for (y = 0; y < m; y++)  
                        avail[y] += alloc[i][y] ;  
                    f[i] = 1;  
                }  
            }  
        }  
    }  
    int flag = 1;   
    for(int i=0;i<n;i++)  
    {  
    if(f[i] == 0)  
    {  
        flag = 0;  
        printf(" The following system is not safe ");  
        break;  
    }  
    }  
    if (flag == 1)  
    {  
    printf(" Following is the SAFE Sequence \ n ");  
    for (i = 0; i < n - 1; i++)  
        printf(" P%d -> " , ans[i]);  
    printf(" P%d ", ans[n - 1]);  
    }  
    return(0);  
}  


// memory allocation

#include<stdio.h>
 
void main()
{
int fragment[20],b[20],p[20],i,j,nb,np,temp,lowest=9999;
static int barray[20],parray[20];
printf("\n\t\t\tMemory Management Scheme - Best Fit");
printf("\nEnter the number of blocks:");
scanf("%d",&nb);
printf("Enter the number of processes:");
scanf("%d",&np);
printf("\nEnter the size of the blocks:-\n");
for(i=1;i<=nb;i++)
    {
printf("Block no.%d:",i);
        scanf("%d",&b[i]);
    }
printf("\nEnter the size of the processes :-\n");
for(i=1;i<=np;i++)
    {
        printf("Process no.%d:",i);
        scanf("%d",&p[i]);
    }
for(i=1;i<=np;i++)
{
for(j=1;j<=nb;j++)
{
if(barray[j]!=1)
{
temp=b[j]-p[i];
if(temp>=0)
if(lowest>temp)
{
parray[i]=j;
lowest=temp;
}
}
}
fragment[i]=lowest;
barray[parray[i]]=1;
lowest=10000;
}
printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment");
for(i=1;i<=np && parray[i]!=0;i++)
printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,p[i],parray[i],b[parray[i]],fragment[i]);
}

// producer consumer

#include<stdio.h>

int mutex=1,empty=3,full=0,x=0;

int wait(int s){
    return --s;
}

int signal(int s){
    return ++s;
}

void producer(){

mutex=wait(mutex);
empty=wait(empty);
full=signal(full);
x++;

printf("Producer produces an item=%d\n",x);

if(x==3){
    printf("items in buffer are:%d %d %d",x-2,x-1,x);
}

mutex=signal(mutex);
}


void consumer(){

mutex=wait(mutex);
empty=signal(empty);
full=wait(full);
x--;

printf("items remianing in the buffer is %d,%d\n",x-1,x);

mutex=signal(mutex);
}

int main(){
    int n;
    printf("1. Producer  2. Consumer  3. Exit\n");
    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            if ((mutex == 1) && (empty != 0))
                producer();
            else
                printf("Buffer is full\n");
            break;
        case 2:
            if ((mutex == 1) && (full != 0))
                consumer();
            else
                printf("Buffer is empty\n");
            break;
        case 3:
            exit(0);
            break;
        }
    }
    return 0;
}


// scan disk

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int choice, track, no_req, head, distance;
int disc_req[100];

void menu() {
    printf("\n\n*MENU*");
    printf("\n1. Input data\n  2. SCAN \n 3. Exit");
    printf("\n\n Enter your choice: ");
    scanf("%d", &choice);
}

void input() {
    printf("Enter Total number of tracks: ");
    scanf("%d", &track);
    printf("Enter total number of disc requests: ");
    scanf("%d", &no_req);

    if (no_req == 0) {
        printf("No requests to process.\n");
        return;
    }

    printf("\nEnter disc requests in FCFS order: ");
    for(int i = 0; i < no_req; i++) {
        scanf("%d", &disc_req[i]);
    }

    printf("\nEnter current head position: ");
    scanf("%d", &head);
}

void sort() {
    int temp;
    for(int i = 0; i < no_req - 1; i++) {
        for(int j = i + 1; j < no_req; j++) {
            if(disc_req[i] > disc_req[j]) {
                temp = disc_req[i];
                disc_req[i] = disc_req[j];
                disc_req[j] = temp;
            }
        }
    }
}

void scan() {
    int dir, i, index;

    distance = 0;
    printf("\nEnter the direction of head \n1 - Towards higher disc (Right) \n0 - Towards lower disc (Left): ");
    scanf("%d", &dir);

    sort();
    printf("\nSorted Disc requests are: ");
    for(i = 0; i < no_req; i++) {
        printf("%d ", disc_req[i]);
    }

    for(i = 0; i < no_req; i++) {
        if(disc_req[i] > head) {
            index = i;
            break;
        }
    }

    printf("\nCurrent head position: %d\n", head);
    printf("%d => ", head);

    if (dir == 1) {
        for(i = index; i < no_req; i++) {
            printf("%d => ", disc_req[i]);
            distance += abs(head - disc_req[i]);
            head = disc_req[i];
        }
        distance += abs(head - (track - 1));
        head = track - 1;
        printf("%d => ", head);

        for(i = index - 1; i >= 0; i--) {
            printf("%d => ", disc_req[i]);
            distance += abs(head - disc_req[i]);
            head = disc_req[i];
        }
    } else {
        for(i = index - 1; i >= 0; i--) {
            printf("%d => ", disc_req[i]);
            distance += abs(head - disc_req[i]);
            head = disc_req[i];
        }
        distance += abs(head - 0);
        head = 0;
        printf("0 => ");

        for(i = index; i < no_req; i++) {
            printf("%d => ", disc_req[i]);
            distance += abs(head - disc_req[i]);
            head = disc_req[i];
        }
    }

    printf("End\n");
    printf("Total Distance Traversed: %d\n", distance);
}

int main() {
    while(1) {
        menu();
        switch(choice) {
        case 1: 
            input();
            break;
        case 2: 
            scan();
            break;
        case 3: 
            exit(0);       
            break;
        default:
            printf("\nEnter a valid choice.\n");
            break;
        }
    }

    return 0;
}


// file allocation

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void recurse(int files[]){
    int flag = 0, startBlock, len, j, k, ch;
    printf("Enter the starting block and the length of the files: ");
    scanf("%d%d", &startBlock, &len);
    for (j=startBlock; j<(startBlock+len); j++){
        if (files[j] == 0)
            flag++;
    }
    if(len == flag){
        for (int k=startBlock; k<(startBlock+len); k++){
            if (files[k] == 0){
                files[k] = 1;
                printf("%d\t%d\n", k, files[k]);
            }
        }
        if (k != (startBlock+len-1))
            printf("The file is allocated to the disk\n");
    }
    else
        printf("The file is not allocated to the disk\n");

    printf("Do you want to enter more files?\n");
    printf("Press 1 for YES, 0 for NO: ");
    scanf("%d", &ch);
    if (ch == 1)
        recurse(files);
    else
        exit(0);
    return;
}

int main()
{
int files[50];
for(int i=0;i<50;i++)
files[i]=0;
printf("Files Allocated are :\n");

recurse(files);
getch();
return 0;
}
