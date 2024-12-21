#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct telement{
    char mot[100];
    struct telement *next;
};

//display the linked list
void Displaylist(struct telement *l){
    while (l != NULL){
        printf("%s", &l->mot);
        l = l->next;
        printf("\n");
    }
}

// create a new element
void createlement (char word[]){
     struct telement * p= (struct telement*)malloc(sizeof(struct telement));
   // p->mot = word;
    p->next = NULL;
}
// function to count number of elements in a list
int countelements(struct telement *l){
    int ne=0;
    while(l != NULL){
        ne++;
    }
    return ne;
}

// function to display the matrix
void DisplayMatrix(char matrix[][100], int rows) {
    for (int i = 0; i < rows; i++) {
        printf("{%s}\n", matrix[i]);
    }
    printf("\n");
}

// display function
void Display (int arr [] , int sizeofArr){
 for (int k = 0; k < sizeofArr; k++) {
    printf("%d ", arr[k]);
}
printf("\n");
}

// selection sorting
void SelectionSorting (int arr [] , int sizeofArr){
    int min ;
    int temp ;
    int nbrComp = 0 ;
    int nbrPerm = 0;

  for( int i = 0 ; i < sizeofArr -1 ;  i++){
    min =  i ;
    for (int j = i+1 ; j < sizeofArr ; j++){
        if ( arr[min] > arr[j]){
            min = j ;
            nbrComp++;
        }
    }
    temp = arr [i];
    arr[i] = arr[min];
    arr[min] = temp ;
    nbrPerm++ ;
    printf("Permutation %d: ", i + 1);
    Display(arr , sizeofArr);
  }
  printf("Number of comparisons : %d \n" , nbrComp);
  printf("Number of permutations : %d \n" , nbrPerm);
}

// bubble sorting
void bubbleSort(int arr[], int sizeofArr) {
    int i;
    int j;
    int temp;
    int nbrComp = 0 ;
    int nbrPerm = 0;
    for (i = 0; i < sizeofArr - 1; i++) {
        for (j = 0; j < sizeofArr - i - 1; j++) {
            nbrComp++;
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                nbrPerm++;
                printf("Permutation %d: ", nbrPerm);
                Display(arr , sizeofArr);
            }
        }
    }
    printf("\nNumber of comparisons: %d\n", nbrComp);
    printf("Number of permutations: %d\n", nbrPerm);
}

// bubble sort function for a matrix of characters
void BubbleSortMatrix(char matrix[][100], int rows) {
    char temp;
    int nbrComp = 0 ;
    int nbrPerm = 0 ;

    for (int i = 0; i < rows; i++) {
        int sizeofLine = strlen(matrix[i]);
        // Bubble sort for the current row
        for (int j = 0; j < sizeofLine - 1; j++) {
            for (int k = 0; k < sizeofLine - j - 1; k++) {
                if (matrix[i][k] > matrix[i][k + 1]) {
                    // Swap the characters
                    temp = matrix[i][k];
                    matrix[i][k] = matrix[i][k + 1];
                    matrix[i][k + 1] = temp;
                    nbrPerm++;
                printf("swap number %d\n" , nbrPerm);
                DisplayMatrix(matrix, rows);
                }
                nbrComp++;
            }
        }
    }
    printf("nombre de comparaison : %d \n" , nbrComp);
    printf("nombre de permutations : %d\n", nbrPerm);
}
// bubble sort of a linked list
void Bubblesortlist( struct telement *l){
     if (l == NULL || l->next == NULL{
      printf("the list is already sorted");
     }
     int n = countelements(l);
     int nbComp =0, nbPerm =0:
    struct telement *P;
    struct telement *Q;
     struct telement *prev;
     prev = NULL;
     Q = l;
     for (int i=0;i<n;i++){
            while(Q->next!=NULL){
                nbComp++;
                if(strcmp(Q->mot, Q->next->mot)>0){
                    P = Q->next;
                    Q->next = P->next;
                    P->next = Q;
                nbPerm++;
                    if(prev == NULL){
                        l = P;
                    }
                    else{
                        prev->next=P;
                    }
                }
                prev = P;
                else{
                    prev = Q;
                    Q = Q->next;
                }

            }
     }

}
// the function merge
 // global variables for comp & perm counters
int nbrComp = 0;
int nbrPerm = 0 ;
void Merge ( int arr[] , int low , int mid , int high ){
    int temp [high - low + 1];
    int left = low ;
    int right = mid + 1 ;
    int j = 0;
    while(left <= mid && right <= high){
        if (arr[left] <= arr[right]){
            temp[j] = arr[left];
            left ++ ;
            j++ ;
            nbrPerm++;
        } else {
        temp[j] = arr[right];
        right ++ ;
        j++;
        nbrPerm++;
        }
        nbrComp++;
    }
    while (left <= mid ){
        temp[j] = arr[left];
        left ++;
        j++;
        nbrPerm++;
    }
    while (right <= high){
        temp[j] = arr[right];
        right ++ ;
        j++;
        nbrPerm++;
    }
    //arr = temp ;
        for (int k = 0; k < high - low +1; k++) {
        arr[low + k] = temp[k];
    }

    printf("merged array in [%d , %d] ", left , right);
    Display(arr, right +1 );
}

//merge sort function
void MergeSort (int arr [] , int low , int high){
    if (low < high){
        int mid = (low + high) / 2 ;
        MergeSort(arr , low , mid );
        MergeSort(arr , mid +1 , high);
        Merge( arr , low , mid , high);
    }
}

// the function insertion sort
void insertionsort(int arr[], int sizeofarr){
    int i, j, temp;
    int nbrComp =0, nbrPerm=0;
    for(i=1;i<sizeofarr-1;i++){
        temp = arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp){
            nbrComp++;
            arr[j+1]=arr[j];
            nbrPerm++;
            j= j-1;
        }
        arr[j+1]= temp;
         nbrPerm++ ;
    Display(arr , sizeofarr);
    }
  printf("Number of comparisons : %d \n" , nbrComp);
  printf("number of permutations : %d \n" , nbrPerm);
}
// the insertion sort of a linked list
void  insertionsortlist(struct telement* l ) {
    if (l == NULL || l->next == NULL){
        printf("the list is already sorted");
    }
     int nbComp =0, nbPerm =0:
    struct telement *cur;
    struct telement *prev;
     struct telement *P2;
    struct telement *temp;
     prev= l;
    cur = l->next;
    while (cur!= NULL) {

        nbComp++;
        if (strcmp(cur->mot, prev->mot) > 0) {
         prev = cur;
         cur = cur->next;
        }
        else {
                temp = l;
        while(temp->next != NULL && strcmp(temp->next->mot, cur->mot)<0){
                temp = temp->next;

        }
        prev->next = cur->next;
        cur->next= temp ->next;
        temp->next= cur;
        nbPerm++:
        }
        cur = prev ->next;
    }
      printf("nombre de comparaison : %d \n" , nbrComp);
    printf("nombre de permutations : %d\n", nbrPerm);

}

// the function of quick sort
// the function that does the partitioning
int NbrComp=0,NbrPerm=0;
int partition(int arr[], int start, int end ){
    int pivot, i , j, temp;
    pivot = arr[end];
    i= start-1;
    for(j=start;j<end-1;j++){
            NbrComp++;
        if(arr[j]<pivot){
           i++;
           temp = arr[i];
           arr[i] = arr[j];
           arr[j] = temp;

        NbrPerm++;
        }
    }
    i++;
    temp = arr[i];
    arr[i]= arr[end];
    arr[end] = temp;
    NbrPerm++;
    return i;

}

 // the quick sort algorithm using the recursive calls
 void quicksort( int arr, int start, int end){
       int nbrComp =0, nbrPerm =0;
     if (start < end){
        int pivot = partition(arr, start, end);
        quicksort(arr, start, pivot -1);
        quicksort(arr, pivot +1, end);
     }
 }

 // comb sort function using 1.3 factor(the most common used factor)
 void combsort(int arr[], int sizeofarr){
     int n= sizeofarr;
     int nbrComp =0, nbrPerm =0;
     int gap = n / 1.3;
     while(gap >=1){
        for(int i=0;i<sizeofarr-1-gap;i++){
            nbrComp++;
            if(arr[i]>arr[i+gap]){
                int temp = arr[i];
                arr[i]=arr[i+gap];
                arr[i+gap]=temp;
            nbrPerm++;
            }
        }
        Display(arr,sizeofarr);
        gap = gap / 1.3;
     }
  printf("Number of comparisons : %d \n" , nbrComp);
  printf("number of permutations : %d \n" , nbrPerm);
 }

int main()
{/*
    int array [] = {64 , 34 , 25 , 12 , 22 , 11 , 90};
    int arraySize = sizeof(array) / sizeof(array[0]);

    char matrix[][100] = {"gfr","zvc","qwe", "axd"};
    int rows = sizeof(matrix) / sizeof(matrix[0]);

    printf ("original array \n");
    Display(array , arraySize);


    printf("Selection sorting execution \n");
    SelectionSorting(array , arraySize);
    printf("sorted array using selection sorting \n ");
    Display(array , arraySize);

    printf("Bubble sorting execution \n");
    bubbleSort(array , arraySize);
    printf("sorted array using bubble sorting \n ");
    Display(array , arraySize);

    printf("merge sort execution \n");
    MergeSort(array , 0 , arraySize -1 );
    printf("comparisions %d \n", nbrComp);
    printf("permutations %d \n" , nbrPerm);
    printf("sorted array using merge sorting \n");
    Display(array , arraySize);


    printf("Original Matrix:\n");
    DisplayMatrix(matrix, rows);

    BubbleSortMatrix(matrix, rows);
    printf("matrix after bubble sort:\n");
    DisplayMatrix(matrix, rows);

    printf("each step of the insertion sorting process \n");
    insertionsort(array , arraySize);
    printf("sorted array using insertion sorting \n ");
    Display(array , arraySize);

    printf("insertion sorting execution \n");
    insertionsort(array , arraySize);
    printf("sorted array using insertion sorting \n ");
    Display(array , arraySize);

     printf("quick  sorting execution \n");
     NbrComp=0;
     NbrPerm=0;
     quicksort(array ,0 , arraySize-1);
     printf("sorted array using quick sorting \n ");
     Display(array , arraySize);
     printf("Number of comparisons : %d \n" , NbrComp);
     printf("number of permutations : %d \n" , NbrPerm);

    printf("comb sorting execution \n");
    combsort(array , arraySize);
    printf("sorted array using comb sorting \n ");
    Display(array , arraySize);
    */
     struct telement * l = malloc(sizeof(struct telement));
    struct telement* second = malloc(sizeof(struct telement));
   struct telement* third = malloc(sizeof(struct telement));

    strcpy(l->mot, "chaima");
    strcpy(second->mot, "manel");
    strcpy(third->mot, "algo");

    l->next = second;
    second->next = third;
    third->next = NULL;

    printf("Before sorting: \n");
    Displaylist(l);

   insertionsortlist(l);

    printf("After sorting: \n");
    Displaylist(l);


    return 0;
}
