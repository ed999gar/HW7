#include <stdio.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
};

void fcfs(struct Process p[], int n) {
    int current_time = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].arrival_time > p[j + 1].arrival_time) {
                struct Process t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;
            }
        }
    }
    float total_wt = 0, total_tat = 0, total_rt = 0;
    printf("\nFCFS Scheduling:\n");
    printf("PID\tAT\tBT\tWT\tTAT\tRT\n");
    int seq[n];
    for (int i = 0; i < n; i++) {
        if (current_time < p[i].arrival_time) current_time = p[i].arrival_time;
        seq[i] = p[i].pid;
        p[i].response_time = current_time - p[i].arrival_time;
        p[i].waiting_time = p[i].response_time;
        current_time += p[i].burst_time;
        p[i].turnaround_time = current_time - p[i].arrival_time;
        total_wt += p[i].waiting_time;
        total_tat += p[i].turnaround_time;
        total_rt += p[i].response_time;
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].arrival_time, p[i].burst_time,
               p[i].waiting_time, p[i].turnaround_time, p[i].response_time);
    }
    printf("\nGantt Chart:\n");
    for (int i = 0; i < n; i++) printf("| P%d ", seq[i]);
    printf("|\n");
    printf("\nAverage WT = %.2f, TAT = %.2f, RT = %.2f\n",
           total_wt / n, total_tat / n, total_rt / n);
}

void sjf(struct Process p[], int n) {
    int completed = 0, current_time = 0;
    int done[n];
    for (int i = 0; i < n; i++) done[i] = 0;
    float total_wt = 0, total_tat = 0, total_rt = 0;
    int seq[n], k = 0;
    while (completed != n) {
        int idx = -1, min_bt = 1e9;
        for (int i = 0; i < n; i++) {
            if (!done[i] && p[i].arrival_time <= current_time) {
                if (p[i].burst_time < min_bt ||
                   (p[i].burst_time == min_bt && p[i].arrival_time < p[idx].arrival_time)) {
                    min_bt = p[i].burst_time;
                    idx = i;
                }
            }
        }
        if (idx == -1) {
            current_time++;
            continue;
        }
        seq[k++] = p[idx].pid;
        p[idx].response_time = current_time - p[idx].arrival_time;
        p[idx].waiting_time = p[idx].response_time;
        current_time += p[idx].burst_time;
        p[idx].turnaround_time = current_time - p[idx].arrival_time;
        done[idx] = 1;
        completed++;
        total_wt += p[idx].waiting_time;
        total_tat += p[idx].turnaround_time;
        total_rt += p[idx].response_time;
    }
    printf("\nSJF Scheduling:\n");
    printf("PID\tAT\tBT\tWT\tTAT\tRT\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].arrival_time, p[i].burst_time,
               p[i].waiting_time, p[i].turnaround_time, p[i].response_time);
    printf("\nGantt Chart:\n");
    for (int i = 0; i < k; i++) printf("| P%d ", seq[i]);
    printf("|\n");
    printf("\nAverage WT = %.2f, TAT = %.2f, RT = %.2f\n",
           total_wt / n, total_tat / n, total_rt / n);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process a[n], b[n];
    for (int i = 0; i < n; i++) {
        a[i].pid = i + 1;
        printf("Enter Arrival Time for Process %d: ", a[i].pid);
        scanf("%d", &a[i].arrival_time);
        printf("Enter Burst Time for Process %d: ", a[i].pid);
        scanf("%d", &a[i].burst_time);
        b[i] = a[i];
    }
    fcfs(a, n);
    sjf(b, n);
    return 0;
}

