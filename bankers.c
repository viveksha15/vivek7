#include <stdio.h> 
int main() { 
int n, m, i, j, k; 
int allocation[10][10], max[10][10], available[10], need[10][10], finish[10], safeSequence[10], 
work[10]; 
int count = 0; 
printf("Enter the number of processes: "); 
scanf("%d", &n);  
printf("Enter the number of resources: "); 
scanf("%d", &m); 
printf("Enter the allocation matrix:\n"); 
for (i = 0; i < n; i++) { 
for (j = 0; j < m; j++) { 
scanf("%d", &allocation[i][j]); 
} 
} 
    printf("Enter the maximum matrix:\n"); 
    for (i = 0; i < n; i++) { 
        for (j = 0; j < m; j++) { 
            scanf("%d", &max[i][j]); 
        } 
    } 
     
    printf("Enter the available resources: "); 
    for (i = 0; i < m; i++) { 
        scanf("%d", &available[i]); 
    } 
     

    for (i = 0; i < n; i++) { 
        for (j = 0; j < m; j++) { 
            need[i][j] = max[i][j] - allocation[i][j]; 
        } 
    } 
        for (i = 0; i < n; i++) { 
        finish[i] = 0; 
    } 
 
    for (k = 0; k < n; k++) { 
        for (i = 0; i < n; i++) { 
            if (finish[i] == 0) {  
                int flag = 1; 
                for (j = 0; j < m; j++) { 
                    if (need[i][j] > available[j]) { 
                        flag = 0; 
                        break; 
                    } 
                } 
                  
                if (flag == 1) {  
                    for (j = 0; j < m; j++) { 
                        available[j] += allocation[i][j]; 
                    } 
                    safeSequence[count++] = i; 
                    finish[i] = 1; 
                } 
            } 
        } 
    } 
  
    int flag = 1; 
    for (i = 0; i < n; i++) { 
        if (finish[i] == 0) { 
            flag = 0; 
            printf("The system is in an unsafe state.\n"); 
            break; 
        } 
    } 
      
    if (flag == 1) { 
        printf("The system is in a safe state.\nSafe sequence is: "); 
for (i = 0; i < n; i++) { 
printf("%d ", safeSequence[i]); 
} 
printf("\n"); 
} 
return 0; 
}