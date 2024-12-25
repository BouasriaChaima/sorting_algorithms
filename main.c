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
        l=l->next;
    }
    return ne;
}
// function to create array of integers
void  createarray(int n,int arr[]){
    for(int i=0;i<n;i++){
            printf("enter the %d element", &i+1);
           scanf("%d", &arr[i]);
    }
}

// function to display the matrix
void DisplayMatrix(char matrix[][100], int rows) {
    for (int i = 0; i < rows; i++) {
        printf("{%s}\n", matrix[i]);
    }
    printf("\n");
}

// display  vector function
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

// bubble sort of the linked list
void Bubblesortlist(struct telement *list) {
    if (list == NULL || list->next == NULL) {
        printf("The list is already sorted\n");// si la liste a un seul element elle est triee
        return;
    }

    int n = countelements(list);// on compte le num des elements de la liste
    int nbComp = 0, nbPerm = 0;
    struct telement *P;
    struct telement *Q;
    struct telement *prev;

    for (int i = 0; i < n - 1; i++) {//boucle pour la repetition du traitement
        prev = NULL;//on initialise li'element precedent par null (precedent de la tete)
        Q = list;// et on va parcourir la list par Q

        while (Q->next != NULL) {
            nbComp++;// on commence la comparaison
            if (strcmp(Q->mot, Q->next->mot) > 0) {// Q.mot est superieur a Q>next.mot
                P = Q->next;// on fait la permutation
                Q->next = P->next;
                P->next = Q;
                nbPerm++;// et on incremente le nbr de permutation
                if (prev == NULL) {// si on est ds la tete
                    list = P;
                } else {
                    prev->next = P;// on met a jor la tete par le nv element
                }
              prev = P;//on met a jour l'element precedent
              printf("la liste apres la pernutation num  %d: ", nbPerm);
                Displaylist(list);// affichage
            }
             else {// si on est pas besoin du permutation
                prev = Q;
                Q = Q->next;// on va juste aller a l'element suivant
            }
        }
        Q = list;
    }
     printf("nombre de comparaison et permutations : %d , %d\n" , nbComp, nbPerm);
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
void insertionsortlist(struct telement *list) {
    if (list == NULL || list->next == NULL) {
        printf("The list is already sorted\n");
    }

    int nbComp = 0, nbPerm = 0;
    struct telement *cur = list->next;
    struct telement *prev = list;
    struct telement *temp;

    while (cur != NULL) {
        nbComp++;
        if (strcmp(prev->mot, cur->mot) <= 0) {
            prev = cur;
            cur = cur->next;
        } else {
            temp = list;
            prev->next = cur->next;

            if (strcmp(list->mot, cur->mot) > 0) {
                cur->next = list;
                list = cur;
                nbPerm++;
            } else {
                while (temp->next != NULL && strcmp(temp->next->mot, cur->mot) < 0) {
                    temp = temp->next;
                    nbComp++;
                }
                cur->next = temp->next;
                temp->next = cur;
                nbPerm++;
            }
            cur = prev->next;
        }
        printf("Apres %d permutations:\n", nbPerm);
        Displaylist(list);
    }
    printf(" nombre de Comparisons: %d\n et de permutations: %d\n", nbComp, nbPerm);
}

// the function of quick sort
// the function that does the partitioning
int NbrComp = 0, NbrPerm = 0;// global variables so we can use them

int partition(int arr[], int start, int end) {
    int pivot = arr[end];
    int i = start - 1;

    for (int j = start; j < end; j++) {
        NbrComp++;
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            NbrPerm++;
            printf("apres %d permutations\n", NbrPerm);
            Display(arr, end + 1);
        }
    }

    i++;
    int temp = arr[i];
    arr[i] = arr[end];
    arr[end] = temp;
    NbrPerm++;

    return i;
}

// The quick sort algorithm using recursive calls
void quicksort(int arr[], int start, int end) {
    if (start < end) {
        int pivot = partition(arr, start, end);
        quicksort(arr, start, pivot - 1);
        quicksort(arr, pivot + 1, end);
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
    int choice;
    printf("choose what data structure do you want to sort");
      printf("\n=========================================================\n");
    printf("     1. Vector Sort    2. Matrix Sort    3. Linked list Sort  \n");
     printf("\n=========================================================\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            int choice2;
            int sizearray;
            int arr[];
            printf("You  have 6 vector sorting algorithms \n");
              printf("1.selection sort\n");
              printf("2.bubble Sort \n");
            printf("3.Merge Sort\n");
            printf("4.insertion Sort\n");
            printf("5.Quick Sort\n");
            printf("6.Comb Sort\n");
            printf("enter your choice (1-6):");
            scanf("%d", &choice2);
            printf("enter the size of your array");
            scanf("%d", &sizearray);
            createarray(sizearray, arr);
            switch(choice2){
            case 1:
                printf("array before sorting");
                Display(arr, sizeofarray);
                SelectionSorting(arr,sizeofarray);
                printf("array after selection sorting:");
                 Display(arr, sizeofarray);
                 break;
            case 2:
                 printf("array before sorting");
                Display(arr, sizeofarray);
                bubbleSort(arr,sizeofarray);
                printf("array after bubble sorting:");
                 Display(arr, sizeofarray);
                 break;
            case 3:
                 printf("array before sorting");
                Display(arr, sizeofarray);
               MergeSort(arr,0 , sizeofarray-1);
                printf("array after merge sorting:");
                 Display(arr, sizeofarray);
                 break;
            case 4:
                 printf("array before sorting");
                Display(arr, sizeofarray);
                insertionsort(arr,sizeofarray);
                printf("array after insertion sorting:");
                 Display(arr, sizeofarray);
                 break;
            case 5:
                 printf("array before sorting");
                Display(arr, sizeofarray);
                quicksort(arr,0, sizeofarray-1);
                printf("array after quick sorting:");
                 Display(arr, sizeofarray);
                 break;
            case 6:
                 printf("array before sorting");
                Display(arr, sizeofarray);
                combsort(arr,sizeofarray);
                printf("array after comb sorting:");
                 Display(arr, sizeofarray);
                 break;
            }
        case 2:
            int choice3;
            int rows, columns;
             printf("You  have 2 character matrix sorting algorithms \n");
              printf("1.Bubble sort\n");
              printf("2.Merge Sort \n");
              printf("enter your choice");
              scanf("%d", &choice3);
              printf("enter the number of rows of the matrix ");
                scanf("%d", &rows);
            printf("enter the number of columns of the matrix ");
              scanf("%d", &columns);
              // making the matrix
              switch (choice3){
              }
            break;
        case 3:
            printf("You selected Linked List Sort.\n");

            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    char matrix[][100] = {"gfr","zvc","qwe", "axd"};
    int rows = sizeof(matrix) / sizeof(matrix[0]);

    int array [] = {64 , 34 , 25 , 12 , 22 , 11 , 90};
    int arraySize = sizeof(array) / sizeof(array[0]);

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
/*
    printf("comb sorting execution \n");
    combsort(array , arraySize);
    printf("sorted array using comb sorting \n ");
    Display(array , arraySize);

     struct telement * l = malloc(sizeof(struct telement));
    struct telement* second = malloc(sizeof(struct telement));
   struct telement* third = malloc(sizeof(struct telement));

    strcpy(l->mot, "chaima");
    strcpy(second->mot, "manel");
    strcpy(third->mot, "algo");

    l->next = second;
    second->next = third;
    third->next = NULL;

    printf("original list: \n");
    Displaylist(l);
    insertionsortlist(l);
    printf("After insertion sorting: \n");
    Displaylist(l);

     printf("original list: \n");
    Displaylist(l);
    Bubblesortlist(l);
    printf("After bubble sorting: \n");
    Displaylist(l);
*/
    return 0;
}
