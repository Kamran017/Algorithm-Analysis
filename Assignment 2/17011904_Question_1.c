#include <stdlib.h>
#include <stdio.h>

double calculateRecursively(double win,int i , int j, int n){
    double arr[n][n];
    double lose = 1 - win;
	if(i==0)
		return 1;
	if(j==0)
		return 0;
	
	if(i>=0){
		arr[i][j] = win*calculateRecursively(win,i-1, j,n) + lose*calculateRecursively(win,i,j-1,n);
		return arr[i][j];
	}
}

int main(){
    printf("Result: %f", calculateRecursively(0.6,4,4,7));
    return 0;
}
