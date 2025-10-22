# CPU Scheduling Simulator (FCFS & SJF)

This program simulates **CPU scheduling** using:

1. **FCFS (First Come First Served)**  
2. **SJF (Shortest Job First, Non-preemptive)**

It calculates **waiting time**, **turnaround time**, and **response time** for each process and displays a **Gantt chart**.

---

## Requirements

- GCC or any C compiler  
- Terminal or command prompt

---

## Files

- `process.c` — the C source code implementing FCFS and SJF algorithms.

---

## How to Compile

Open a terminal in the project directory and run:

```bash
gcc process.c -o scheduler
```

- `process.c` — source file  
- `scheduler` — output executable name

---

## How to Run

Run the compiled program:

```bash
./scheduler    # Linux / Mac
scheduler.exe  # Windows
```

The program will prompt you to:

1. Enter the number of processes.
2. Enter the **arrival time** and **burst time** for each process.

Example:

```
Enter number of processes: 4
Enter Arrival Time for Process 1: 0
Enter Burst Time for Process 1: 8
Enter Arrival Time for Process 2: 1
Enter Burst Time for Process 2: 4
Enter Arrival Time for Process 3: 2
Enter Burst Time for Process 3: 9
Enter Arrival Time for Process 4: 3
Enter Burst Time for Process 4: 5
```

---

## Output

The program will display:

1. **Gantt Chart** showing the order of execution.  
2. **Process table** with:

| PID | AT | BT | WT | TAT | RT |

- AT — Arrival Time  
- BT — Burst Time  
- WT — Waiting Time  
- TAT — Turnaround Time  
- RT — Response Time

3. **Average waiting, turnaround, and response times**.

Example output:

```
FCFS Scheduling:
PID     AT      BT      WT      TAT     RT
1       0       8       0       8       0
2       1       4       7       11      7
3       2       9       10      19      10
4       3       5       18      23      18

Gantt Chart:
| P1 | P2 | P3 | P4 |

Average WT = 8.75, TAT = 15.25, RT = 8.75
```

```
SJF Scheduling:
PID     AT      BT      WT      TAT     RT
1       0       8       0       8       0
2       1       4       7       11      7
3       2       9       15      24      15
4       3       5       9       14      9

Gantt Chart:
| P1 | P2 | P4 | P3 |

Average WT = 7.75, TAT = 14.25, RT = 7.75
```

---

## Notes

- Both **FCFS** and **SJF** are non-preemptive.  
- If no process has arrived at the current time, the CPU stays idle until a process arrives.  
- In SJF, if multiple processes have the same burst time, the one with **earlier arrival** is selected first.
