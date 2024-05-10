#include <stdio.h>
#include <stdbool.h>

// Structure to represent a job
struct Job {
    int deadline;  // Effective deadline after subtracting maxDeadlineOffset
    int profit;
};

// Function to find maximum deadline among all jobs
int findMaxDeadline(struct Job jobs[], int n) {
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }
    return maxDeadline;
}

// Job Sequencing with Deadlines algorithm
void jobSequencing(struct Job jobs[], int n, int maxDeadlineOffset) {
    // Find maximum deadline among all jobs
    int maxDeadline = findMaxDeadline(jobs, n);

    // Adjust job deadlines based on maxDeadlineOffset
    for (int i = 0; i < n; i++) {
        jobs[i].deadline = maxDeadline - jobs[i].deadline;  // Subtract user input deadline from maxDeadline
    }

    // Initialize schedule array and profit array
    bool schedule[maxDeadline + 1];
    int profit[maxDeadline + 1];
    for (int i = 0; i <= maxDeadline; i++) {
        schedule[i] = false; // Initialize all slots as available
        profit[i] = 0; // Initialize profit array
    }

    int totalProfit = 0;

    // Schedule jobs
    for (int i = 0; i < n; i++) {
        int deadline = jobs[i].deadline;
        while (deadline > 0) {
            if (!schedule[deadline]) {
                schedule[deadline] = true; // Mark slot as occupied
                profit[deadline] = jobs[i].profit; // Set profit for this slot
                totalProfit += jobs[i].profit;
                break;
            } else {
                deadline--; // Move to the previous deadline
            }
        }
    }

    // Output total profit and schedule
    printf("Total Profit: %d\n", totalProfit);
    printf("Job Schedule:\n");
    for (int i = 1; i <= maxDeadline; i++) {
        if (schedule[i]) {
            printf("Deadline %d: Job scheduled (Profit: %d)\n", maxDeadline - i + maxDeadlineOffset, profit[i]);
        } else {
            printf("Deadline %d: No job scheduled\n", maxDeadline - i + maxDeadlineOffset);
        }
    }
}

int main() {
    int n, maxDeadlineOffset;

    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    printf("Enter the maximum deadline offset: ");
    scanf("%d", &maxDeadlineOffset);

    struct Job jobs[n];

    // Input details for each job
    for (int i = 0; i < n; i++) {
        printf("Enter deadline and profit for job %d: ", i + 1);
        scanf("%d %d", &jobs[i].deadline, &jobs[i].profit);
    }

    jobSequencing(jobs, n, maxDeadlineOffset);

    return 0;
}
