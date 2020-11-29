#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;         //matrix size
    int size;     //size for Von Neumann’s Neighborhood
    int **arr;   //array pointer
    int mdl,i,j;//mdl for finding middle coordinate of array , i and j are loop variables
    int counter=0, rowCount=0; //counter for number of one, rowCount for number of ones per row
    printf("Enter matrix size: ");
    scanf("%d",&n);

    size=2*(n+1)+1; //calculate the centered square number
    /*Dynamic memory allocation*/
    arr=(int*)malloc(size*sizeof(int*));
    for(i=0; i < size; i++) {
        arr[i] = (int )malloc(size * sizeof(int));
    }
    //calculate middle number for starting point
    mdl=(int)size/2;
    //start calculating von Neumann Neighborhood
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            arr[i][j]=0;//assign zero to array values
            //if von Neumann neighborhood of range is proper
            if(abs(mdl-j)+abs(mdl-i)<= n){
                arr[i][j]=1;
                counter+=1;//counter for total number of one
                rowCount+=1;//counter for number of ones per row
            }
        }
        //print number of ones per row
        printf("\nnumber of 1 in %d. row:  %d\n", i,rowCount);
        rowCount=0;
    }
     printf("\n");
     for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            printf("%d ", arr[i][j]);//print array elements
        }
        printf("\n");
    }

    printf("\nTotal number of ones: %d \n", counter);
    return 0;
}
