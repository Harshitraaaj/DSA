#include<stdio.h> 
void towerOfHanoi(int n, char from_rod,char to_rod, char aux_rod)   
{   
    if (n == 1)   
    {   
        printf("Move disk %d from rod %c to rod %c\n" ,  
                  n, 
                  from_rod , 
                  to_rod);   
        return;   
    } 
    // Push all values of n, from_rod, aux_rod, to_rod stack 
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);   
    // Pop all values of n, from_rod, aux_rod, to_rod stack 
    printf("Move disk %d from rod %c to rod %c\n" , n,from_rod 
,to_rod);   
     // Push all values of n, from_rod, aux_rod, to_rod stack 
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);   
     // Pop all values of n, from_rod, aux_rod, to_rod stack 
}   
   
// Driver code  
int main()   
{   
    int n = 3;   
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods   
    return 0;   
}   
