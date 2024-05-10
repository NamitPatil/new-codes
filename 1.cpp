#include<stdio.h>
#include<stdlib.h>


int front = -1, rear = -1;
int n = 5;
int q[5];
int startTime[5] = {0};

void dis();

void enqueue(int p, int start) {
	int i,j;
    if (rear == n - 1) {
        printf("\nQUEUE IS FULL!");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        q[rear] = p;
    } else {
        rear++;
        for(i=rear;i>=front;i--)
        {
        	if(start<startTime[i])
        	{
        		q[i+1]=q[i];
        		startTime[i+1]=startTime[i];
			}
			else
			{
				break;
			}
		}
        q[i+1]=p;
        startTime[i+1]=start;
    }
    startTime[rear] = start;
    dis();
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("\nQUEUE IS EMPTY!");
    } else if (front == rear) {
        printf("\nThe Dequeued element is: %d", q[front]);
        front = rear = -1;
    } else {
        printf("\nThe Dequeued element is: %d ", q[front]);
        front++;
    }
    dis();
}

void view() {
    if (front == -1 && rear == -1) {
        printf("\nQUEUE IS EMPTY!");
    } else {
        printf("\nPeek element is: %d", q[front]);
    }
}

void dis() {
    int wait = 0;
    if (front == -1 && rear == -1) {
        printf("\nQUEUE IS EMPTY!");
    } else {
        printf("\nprocess\t\tstart time\twait\n");
        for (int j = front; j <= rear; j++) {
            if (j == front) {
                wait = 0;
            } else {
                wait = startTime[j] + wait;
            }
            printf("[%d]\t\t%d\t\t%d\t\t\n", q[j], startTime[j], wait);
        }
    }
}

void queue() {
    int y, p, start = 0;
    while (y != 5) {
        printf("\n1.enqueue\n2.display\n5.exit\n");
        printf("\nEnter the operation :");
        scanf("%d", &y);
        switch (y) {
            case 1:
                printf("\nEnter the process: ");
                scanf("%d", &p);
                printf("\nEnter the start time: ");
                scanf("%d", &start);
                enqueue(p, start);
                break;
        
            case 2:
                dis();
                break;
            case 3:
                exit(0);
                break;
        }
    }
}
//void merge(int starttime[], int lb, int mid, int ub) {
//    int b[ub - lb + 1];
//    int i = lb, j = mid + 1, k = 0;
//
//    while (i <= mid && j <= ub) {
//        if (starttime[i] < starttime[j]) {
//            b[k] = starttime[i];
//            i++;
//        } else {
//            b[k] = starttime[j];
//            j++;
//        }
//        k++;
//    }
//    
//    while (i <= mid) {
//        b[k] = starttime[i];
//        i++;
//        k++;
//    }
//    
//    while (j <= ub) {
//        b[k] = starttime[j];
//        j++;
//        k++;
//    }
//
//    for (int i = lb, k = 0; i <= ub; i++, k++) {
//        starttime[i] = b[k];
//    }
//}
//
//void mergesort(int starttime[], int lb, int ub) {
//    if (lb < ub) {
//        int mid = (lb + ub) / 2;
//        mergesort(starttime, lb, mid);
//        mergesort(starttime, mid + 1, ub);
//        merge(starttime, lb, mid, ub);
//    }
//}
//
//void mergeSortStartTime(int starttime[], int n) {
//    mergesort(starttime, 0, n - 1);
//}

int main() {
    int choice;
    while (choice != 3) {
        printf("\n1.QUEUE\n2.EXIT");
        printf("\nEnter the operation : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                queue();
                break;
            case 2:
                exit(0);
                break;
        }
    }

    return 0;
}
