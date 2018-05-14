#include <stdio.h>
#include <stdlib.h>

void printArr(int arr[], int size){
    printf("\n\n");
    for(int i=0;i<size;i++){
        printf("%d - ", arr[i]);
    }
}

int isExist(int arr[], int size, int elem){
    int i;
    for(i=0;i<size;i++){
        if(arr[i] == elem)
            return 1;
    }
    return 0;
}
int hasSubset(int set[], int n, int sum){
    int i, numOfArr=0;
    /**Insertion Sort (to be edited) **/
    // O(n^2)
    int j, key;
    for(j=1;j<n;j++){
        key = set[j];
        i = j-1;
        while(i >= 0 && set[i] > key){
            set[i+1] = set[i];
            i=i-1;
        }
        set[i+1] = key;
    }
    /**Insertion Sort **/
    int subset[n];
    // O (n)
    // Best case 1
    int m;
    for(i=0, m=0;i<n;++i){
        if( set[i] < sum){
            if(!isExist(subset, numOfArr, set[i])){
                numOfArr++;
                subset[m] = set[i];
                m++;
            }
        }else if(set[i] == sum){/**Case 0 **/
            return 1;
        }else{ /** End Case 0 **/
            break;
        }
    }
    //numOfArr is the size of the new subset
    /** Case 1 **/
    // Best = Avg = Worst = O(n)
    int sumSubset=0;
    for(i=0;i<numOfArr && sumSubset <= sum;i++){
        sumSubset += subset[i];
    }
    if(sumSubset == sum){
       return 1;
    }

    /** End Case 1 **/

    /** Case 2 **/
    // O(n^2)
    int sumC=0;
    for(i=0;i<numOfArr;i++){
        sumC = subset[i];
        for(j=i+1;j<(i==0 ? numOfArr-1 : numOfArr);j++){ // because of case 1
           sumC += subset[j];
            if(sumC == sum){
                return 1;
            }
        }
    }

    /** End Case 2 **/


    int sumB = 0, sumA=0, y;

    /** Case 3 **/

    for(i=0;i<numOfArr;i++){
        sumB = subset[i];
        sumA=0;
       // printf("%d: ", subset[i]);
        for(j=i+2;j<numOfArr;j++){
            sumB += subset[j];
            printf("%d ", subset[j]);
            if(sumB == sum){
                return 1;
            }
        }
        if(i > 1){
            printf(" - "); // backwards
            for(y=i;y>=0;y--){
                if((y == i-1) || y == i)continue;
                sumB += subset[y];
                sumA = subset[i] + subset[y];
                //printf("%d ", subset[y]);
                if(sumB == sum || sumA == sum){
                    return 1;
                }
            }
        }
        //printf("\n");
    }
     /** End Case 3 **/
    return 0;
}
int main()
{
    int n, sum;
    printf("Enter the size: ");
    scanf("%d", &n);
    int set[n];
    for(int i=0;i<n;i++){
        printf("Enter number %d: ", i+1);
        scanf("%d", &set[i]);
    }

    printf("Enter the sum: ");
    scanf("%d", &sum);

    printf("\n\n%s ", (hasSubset(set,n,sum) ? "True" : "False") );
    return 0;
}
