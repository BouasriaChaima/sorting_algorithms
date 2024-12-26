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
    strcpy(p->mot,word);
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
            printf("enter the %d element:", i+1);
           scanf("%d", &arr[i]);
    }
}
// function to create a list
struct telement *createlist(int nelements) {
    struct telement *list = NULL;

    for (int i = 0; i < nelements; i++) {
        char word[50];
        struct telement *newele = (struct telement*)malloc(sizeof(struct telement));
        printf("Entrez le mot du %d element: ", i + 1);
        scanf("%s", &word);
       strcpy(newele->mot, word);
        newele->next = NULL;
        if (list == NULL) {
            list= newele;
        } else {
           while(list != NULL){
            list = list->next;
           }
           list->next=newele;
        }
    }

    return list;
}
// function to create a matrix of characters
void creatMatrix (int rows , int collones , char  matrix[rows][collones]){
  for (int i = 0 ; i < rows ; i++){
    for (int j = 0 ; i < collones ; j++){
        printf("give the %d element" , i+1);
        scanf("%d\n" , &matrix[i][j]);
    }
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
    int nbrIter = 0;
    for (i = 0; i < sizeofArr - 1; i++) {
            nbrIter++;
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
    printf("Number of iterations: %d\n", nbrIter);
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
int nbrIter = 0 ;
void Merge ( int arr[] , int low , int mid , int high ){
    int temp [high - low + 1];
    int left = low ;
    int right = mid + 1 ;
    int j = 0;
    while(left <= mid && right <= high){
            nbrIter++;
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
// merge sort with a matrix
 // merge function
void MergeMatrix(char arr[], int low, int mid, int high) {
    char temp[high - low + 1];
    int left = low;
    int right = mid + 1;
    int j = 0;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp[j] = arr[left];
            left++;
            j++;
            nbrPerm++;
        } else {
            temp[j] = arr[right];
            right++;
            j++;
            nbrPerm++;
        }
        nbrComp++;
    }
    while (left <= mid) {
        temp[j] = arr[left];
        left++;
        j++;
        nbrPerm++;
    }
    while (right <= high) {
        temp[j] = arr[right];
        right++;
        j++;
        nbrPerm++;
    }
    for (int k = 0; k < high - low + 1; k++) {
        arr[low + k] = temp[k];
    }
}
// merge sort function
void MergeSortMatrix(char arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }
}

// the function insertion sort
void insertionsort(int arr[], int sizeofarr){
    int i, j, temp;
    int nbrComp =0, nbrPerm=0;
    int nbrIter = 0;
    for(i=1;i<sizeofarr-1;i++){
        nbrIter++;
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
  printf("number of iterations : %d \n" , nbrIter);
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
    float shrinkfactor=1.3;
    int  gap = (int)floor(gap / shrinkfactor);
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
         gap = (int)floor(gap / shrinkfactor);
     }
  printf("Number of comparisons : %d \n" , nbrComp);
  printf("number of permutations : %d \n" , nbrPerm);
 }

int main()
{

    int choice;
    printf("choose what data structure do you want to sort");
      printf("\n====================================================================================\n");
    printf("     1. Vector Sort    2. Matrix Sort    3. Linked list Sort  \n");
      printf("\n====================================================================================\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:{
            int choice2;
            int sizearray;
            int arr[5];
            printf("You  have 6 vector sorting algorithms \n");
              printf("1.selection sort\n");
              printf("2.bubble Sort \n");
            printf("3.Merge Sort\n");
            printf("4.insertion Sort\n");
            printf("5.Quick Sort\n");
            printf("6.Comb Sort\n");
            printf("enter your choice (1-6):");
            scanf("%d", &choice2);
            printf("enter the size of your array:");
            scanf("%d", &sizearray);
            createarray(sizearray, arr);
            switch(choice2){
            case 1:
                printf("array before sorting:");
                Display(arr, sizearray);
                SelectionSorting(arr,sizearray);
                printf("array after selection sorting:");
                 Display(arr, sizearray);
                 break;
            case 2:
                 printf("array before sorting:");
                Display(arr, sizearray);
                bubbleSort(arr,sizearray);
                printf("array after bubble sorting:");
                 Display(arr, sizearray);
                 break;
            case 3:
                 printf("array before sorting:");
                Display(arr, sizearray);
               MergeSort(arr,0 , sizearray-1);
                printf("array after merge sorting:");
                 Display(arr, sizearray);
                 break;
            case 4:
                 printf("array before sorting:");
                Display(arr, sizearray);
                insertionsort(arr,sizearray);
                printf("array after insertion sorting:");
                 Display(arr, sizearray);
                 break;
            case 5:{
                 printf("quick  sorting execution: \n");
                int  NbrComp=0;
                int  NbrPerm=0;
                quicksort(arr ,0 , sizearray-1);
                printf("sorted array using quick sorting :\n ");
                Display(arr , sizearray);
                printf("Number of comparisons : %d \n" , NbrComp);
                printf("number of permutations : %d \n" , NbrPerm);
                 break;
            }
            case 6:
                 printf("array before sorting:");
                Display(arr, sizearray);
                combsort(arr,sizearray);
                printf("array after comb sorting:");
                 Display(arr, sizearray);
                 break;

            default:
                    printf("Invalid choice!\n");
            }
              free(arr); // Free the allocated memory
            break;
        }
        case 2:{
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
              int matrix[rows][columns];
              creatMatrix(rows,columns, matrix);
              switch(choice3){
              case 1:
                 printf("Original Matrix:\n");
                DisplayMatrix(matrix, rows);
                BubbleSortMatrix(matrix, rows);
                printf("matrix after bubble sort:\n");
                DisplayMatrix(matrix, rows);
                break;
              case 2:
                 printf("Original Matrix:\n");
                DisplayMatrix(matrix, rows);
              break;
                default:
            printf("Invalid choice.\n");
            break;
              }
            break;
        }
        case 3:{
            int choice4;
            int nele;
            printf("You have 2  sorting algorithms for Linked lists of words.\n");
              printf("1.Bubble sort\n");
              printf("2.insertion Sort \n");
              printf("enter your choice");
              scanf("%d", &choice4);
              printf("enter the number of elements of your list ");
            scanf("%d", &nele);
              struct telement *l =createlist(nele);
               switch(choice4){
               case 1:
                 printf("original list: \n");
                Displaylist(l);
                Bubblesortlist(l);
                printf("After bubble sorting: \n");
               Displaylist(l);
               break;
               case 2:
                printf("original list: \n");
                Displaylist(l);
                insertionsortlist(l);
                printf("After insertion sorting: \n");
                Displaylist(l);
                 break;

                 default:
                    printf("Invalid choice.\n");
               }
        }
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


  int arr1 [10] = {15, -8, 0, 42, 7, -3, 21, 9, 56, -1};
  int arr2 [20] = {3, -7, 12, 0, 25, -18, 9, 4, 31, -5, 17, 2, -10, 6, 28, -15, 11, 8, 22, -3};
  int arr3 [50] = {17, -8, 0, 42, 7, -3, 21, 9, 56, -1, 3, -7, 12, 0, 25, -18, 9, 4, 31, -5, 17,
   2, -10, 6, 28, -15, 11, 8, 22, -3,45, -21, 19, 1, 37, -12, 14, 6, 33, -8,20, -4, 16, 3, 39, -13, 15, 7, 35, -9};
  int arr4 [100] = {12, 45, 67, 23, 89, 34, 56, 78, 90, 43, 21, 65, 87, 32, 54, 76, 98, 31, 53,
   75, 97, 42, 64, 86, 19, 41, 63, 85, 18, 40, 62, 84, 17, 39, 61, 83, 16, 38, 60, 82, 15, 37, 59,
   81, 14, 36, 58, 80, 13, 35, 57, 79, 11, 33, 55, 77, 99, 22, 44, 66, 88, 20, 42, 64, 86, 28, 50,
   72, 94, 27, 49, 71, 93, 26, 48, 70, 92, 25, 47, 69, 91, 24, 46, 68, 90, 29, 51, 73, 95, 30, 52, 74, 96, 10, 8, 6, 4, 2, 1, 3, 5, 7, 9};
   int arr5 [200] = {12, 45, 67, 23, 89, 34, 56, 78, 90, 43, 21, 65, 87, 32, 54, 76, 98, 31, 53, 75, 97, 42, 64, 86, 19, 41, 63, 85, 18, 40, 62, 84,
   17, 39, 61, 83, 16, 38, 60, 82, 15, 37, 59, 81, 14, 36, 58, 80, 13, 35, 57, 79, 11, 33, 55, 77, 99, 22, 44, 66, 88, 20, 42, 64, 86, 28, 50, 72, 94,
   27, 49, 71, 93, 26, 48, 70, 92, 25, 47, 69, 91, 24, 46, 68, 90, 29, 51, 73, 95, 30, 52, 74, 96, 10, 8, 6, 4, 2, 1, 3, 5, 7, 9, 100, 102, 104, 106,
   108, 110, 112, 114, 116, 118, 120, 122, 124, 126, 128, 130, 132, 134, 136, 138, 140, 142, 144, 146, 148, 150, 152, 154, 156, 158, 160, 162, 164,
   166, 168, 170, 172, 174, 176, 178, 180, 182, 184, 186, 188, 190, 192, 194, 196, 198, 200, 199, 197, 195, 193, 191, 189, 187, 185, 183, 181, 179,
   177, 175, 173, 171, 169, 167, 165, 163, 161, 159, 157, 155, 153, 151, 149, 147, 145, 143, 141, 139, 137, 135, 133, 131, 129, 127, 125, 123, 121,
   119, 117, 115, 113, 111, 109, 107, 105, 103, 101};
   int arr6 [500] = {12, 45, 67, 23, 89, 34, 56, 78, 90, 43, 21, 65, 87, 32, 54, 76, 98, 31, 53, 75, 97, 42, 64, 86, 19, 41, 63, 85, 18, 40, 62, 84, 17,
   39, 61, 83, 16, 38, 60, 82, 15, 37, 59, 81, 14, 36, 58, 80, 13, 35, 57, 79, 11, 33, 55, 77, 99, 22, 44, 66, 88, 20, 42, 64, 86, 28, 50, 72, 94, 27, 49,
   71, 93, 26, 48, 70, 92, 25, 47, 69, 91, 24, 46, 68, 90, 29, 51, 73, 95, 30, 52, 74, 96, 10, 8, 6, 4, 2, 1, 3, 5, 7, 9, 100, 102, 104, 106, 108, 110, 112,
   114, 116, 118, 120, 122, 124, 126, 128, 130, 132, 134, 136, 138, 140, 142, 144, 146, 148, 150, 152, 154, 156, 158, 160, 162, 164, 166, 168, 170, 172, 174,
   176, 178, 180, 182, 184, 186, 188, 190, 192, 194, 196, 198, 200, 199, 197, 195, 193, 191, 189, 187, 185, 183, 181, 179, 177, 175, 173, 171, 169, 167, 165,
   163, 161, 159, 157, 155, 153, 151, 149, 147, 145, 143, 141, 139, 137, 135, 133, 131, 129, 127, 125, 123, 121, 119, 117, 115, 113, 111, 109, 107, 105, 103, 101,
   201, 203, 205, 207, 209, 211, 213, 215, 217, 219, 221, 223, 225, 227, 229, 231, 233, 235, 237, 239, 241, 243, 245, 247, 249, 251, 253, 255, 257, 259, 261, 263,
   265, 267, 269, 271, 273, 275, 277, 279, 281, 283, 285, 287, 289, 291, 293, 295, 297, 299, 300, 298, 296, 294, 292, 290, 288, 286, 284, 282, 280, 278, 276, 274,
   272, 270, 268, 266, 264, 262, 260, 258, 256, 254, 252, 250, 248, 246, 244, 242, 240, 238, 236, 234, 232, 230, 228, 226, 224, 222, 220, 218, 216, 214, 212, 210,
   208, 206, 204, 202, 301, 303, 305, 307, 309, 311, 313, 315, 317, 319, 321, 323, 325, 327, 329, 331, 333, 335, 337, 339, 341, 343, 345, 347, 349, 351, 353, 355,
   357, 359, 361, 363, 365, 367, 369, 371, 373, 375, 377, 379, 381, 383, 385, 387, 389, 391, 393, 395, 397, 399, 400, 398, 396, 394, 392, 390, 388, 386, 384, 382,
   380, 378, 376, 374, 372, 370, 368, 366, 364, 362, 360, 358, 356, 354, 352, 350, 348, 346, 344, 342, 340, 338, 336, 334, 332, 330, 328, 326, 324, 322, 320, 318,
   316, 314, 312, 310, 308, 306, 304, 302, 401, 403, 405, 407, 409, 411, 413, 415, 417, 419, 421, 423, 425, 427, 429, 431, 433, 435, 437, 439, 441, 443, 445, 447,
   449, 451, 453, 455, 457, 459, 461, 463, 465, 467, 469, 471, 473, 475, 477, 479, 481, 483, 485, 487, 489, 491, 493, 495, 497, 499, 500, 498, 496, 494, 492, 490,
   488, 486, 484, 482, 480, 478, 476, 474, 472, 470, 468, 466, 464, 462, 460, 458, 456, 454, 452, 450, 448, 446, 444, 442, 440, 438, 436, 434, 432, 430, 428, 426,
   424, 422, 420, 418, 416, 414, 412, 410, 408, 406, 404, 402};
   int arr7 [1000] = {12, 45, 67, 23, 89, 34, 56, 78, 90, 43, 21, 65, 87, 32, 54, 76, 98, 31, 53, 75, 97, 42, 64, 86, 19, 41, 63, 85, 18, 40, 62, 84, 17, 39, 61,
   83, 16, 38, 60, 82, 15, 37, 59, 81, 14, 36, 58, 80, 13, 35, 57, 79, 11, 33, 55, 77, 99, 22, 44, 66, 88, 20, 42, 64, 86, 28, 50, 72, 94, 27, 49, 71, 93, 26, 48,
    70, 92, 25, 47, 69, 91, 24, 46, 68, 90, 29, 51, 73, 95, 30, 52, 74, 96, 10, 8, 6, 4, 2, 1, 3, 5, 7, 9, 100, 102, 104, 106, 108, 110, 112, 114, 116, 118, 120,
    122, 124, 126, 128, 130, 132, 134, 136, 138, 140, 142, 144, 146, 148, 150, 152, 154, 156, 158, 160, 162, 164, 166, 168, 170, 172, 174, 176, 178, 180, 182, 184,
186, 188, 190, 192, 194, 196, 198, 200, 199, 197, 195, 193, 191, 189, 187, 185, 183, 181, 179, 177, 175, 173, 171, 169, 167, 165, 163, 161, 159, 157, 155, 153, 151,
 149, 147, 145, 143, 141, 139, 137, 135, 133, 131, 129, 127, 125, 123, 121, 119, 117, 115, 113, 111, 109, 107, 105, 103, 101, 201, 203, 205, 207, 209, 211, 213, 215,
  217, 219, 221, 223, 225, 227, 229, 231, 233, 235, 237, 239, 241, 243, 245, 247, 249, 251, 253, 255, 257, 259, 261, 263, 265, 267, 269, 271, 273, 275, 277, 279,
  281, 283, 285, 287, 289, 291, 293, 295, 297, 299, 300, 298, 296, 294, 292, 290, 288, 286, 284, 282, 280, 278, 276, 274, 272, 270, 268, 266, 264, 262, 260, 258,
  256, 254, 252, 250, 248, 246, 244, 242, 240, 238, 236, 234, 232, 230, 228, 226, 224, 222, 220, 218, 216, 214, 212, 210, 208, 206, 204, 202, 301, 303, 305, 307,
  309, 311, 313, 315, 317, 319, 321, 323, 325, 327, 329, 331, 333, 335, 337, 339, 341, 343, 345, 347, 349, 351, 353, 355, 357, 359, 361, 363, 365, 367, 369, 371, 373, 375, 377, 379, 381, 383, 385, 387, 389, 391,
   393, 395, 397, 399, 400, 398, 396, 394, 392, 390, 388, 386, 384, 382, 380, 378, 376, 374, 372, 370, 368, 366, 364, 362, 360, 358, 356, 354, 352, 350, 348, 346, 344, 342, 340, 338, 336, 334, 332, 330, 328, 326, 324, 322, 320, 318, 316, 314, 312,
   310, 308, 306, 304, 302, 401, 403, 405, 407, 409, 411, 413, 415, 417, 419, 421, 423, 425, 427, 429, 431, 433, 435, 437, 439, 441, 443, 445, 447, 449, 451, 453, 455, 457, 459, 461, 463, 465, 467, 469, 471, 473, 475, 477, 479, 481, 483, 485, 487, 489, 491, 493, 495,
497, 499, 500, 498, 496, 494, 492, 490, 488, 486, 484, 482, 480, 478, 476, 474, 472, 470, 468, 466, 464, 462, 460, 458, 456, 454, 452, 450, 448, 446, 444, 442, 440, 438, 436, 434, 432, 430, 428, 426, 424, 422, 420, 418, 416, 414, 412, 410, 408, 406, 404, 402, 501, 503, 505, 507, 509, 511, 513, 515, 517, 519, 521, 523, 525, 527, 529, 531, 533, 535, 537, 539, 541, 543,
    545, 547, 549, 551, 553, 555, 557, 559, 561, 563, 565, 567, 569, 571, 573, 575, 577, 579, 581, 583, 585, 587, 589, 591, 593, 595, 597, 599, 600, 598, 596, 594, 592, 590, 588, 586, 584, 582, 580, 578, 576, 574, 572, 570, 568, 566, 564, 562, 560, 558, 556, 554, 552, 550, 548, 546, 544, 542, 540, 538, 536, 534, 532, 530, 528, 526, 524, 522, 520, 518, 516, 514, 512, 510, 508, 506, 504,
     502, 601, 603, 605, 607, 609, 611, 613, 615, 617, 619, 621, 623, 625, 627, 629, 631, 633, 635, 637, 639, 641, 643, 645, 647, 649, 651, 653, 655, 657, 659, 661, 663, 665, 667, 669, 671, 673, 675, 677, 679, 681, 683, 685, 687, 689, 691, 693, 695, 697, 699, 700, 698, 696, 694, 692, 690, 688, 686, 684, 682, 680, 678, 676, 674, 672, 670, 668, 666, 664, 662, 660, 658, 656, 654, 652, 650, 648, 646, 644, 642, 640, 638, 636, 634, 632, 630, 628, 626, 624, 622, 620, 618, 616, 614, 612, 610, 608, 606, 604, 602, 701, 703, 705, 707, 709, 711, 713, 715, 717, 719, 721, 723, 725, 727, 729, 731, 733, 735, 737, 739, 741, 743, 745, 747, 749, 751, 753, 755, 757, 759, 761, 763, 765, 767, 769, 771, 773, 775, 777, 779, 781, 783, 785, 787, 789, 791, 793, 795, 797, 799, 800, 798, 796, 794, 792, 790, 788, 786, 784, 782,
     780, 778, 776, 774, 772, 770, 768, 766, 764, 762, 760, 758, 756, 754, 752, 750, 748, 746, 744, 742, 740, 738, 736, 734, 732, 730, 728, 726, 724, 722, 720, 718, 716, 714, 712, 710, 708, 706, 704, 702, 801, 803, 805, 807, 809, 811, 813, 815, 817, 819, 821, 823, 825, 827, 829, 831, 833, 835, 837, 839, 841, 843, 845, 847, 849, 851, 853, 855, 857, 859, 861, 863, 865, 867, 869, 871, 873, 875, 877, 879, 881, 883, 885, 887, 889, 891, 893, 895, 897, 899, 900, 898, 896, 894, 892, 890, 888, 886, 884, 882, 880, 878, 876, 874, 872, 870, 868, 866, 864, 862, 860, 858, 856, 854, 852, 850, 848, 846, 844, 842, 840, 838, 836, 834, 832, 830, 828, 826, 824, 822, 820, 818, 816, 814, 812, 810, 808, 806, 804, 802, 901, 903, 905, 907, 909, 911, 913, 915, 917, 919, 921, 923, 925, 927, 929, 931, 933, 935, 937, 939, 941, 943, 945, 947, 949, 951, 953, 955, 957, 959, 961, 963, 965, 967, 969, 971, 973, 975, 977, 979, 981, 983, 985, 987, 989, 991, 993, 995, 997, 999, 1000, 998, 996, 994, 992, 990, 988, 986, 984, 982, 980, 978, 976, 974, 972, 970, 968, 966, 964, 962, 960, 958, 956, 954, 952, 950, 948, 946, 944, 942, 940, 938, 936, 934, 932, 930, 928, 926, 924, 922, 920, 918, 916, 914, 912, 910, 908, 906, 904, 902};


// insrertions sort
printf("insertion sort\n");
insertionsort(arr1 , 10);
insertionsort(arr2 , 20);
insertionsort(arr3 , 50);
insertionsort(arr4 , 100);
insertionsort(arr5 , 200);
insertionsort(arr6 , 500);
insertionsort(arr7 , 1000);

 //bubble sort
printf("bubble sort\n");
bubbleSort(arr1,10);
bubbleSort(arr2,20);
bubbleSort(arr3,50);
bubbleSort(arr4,100);
bubbleSort(arr5,200);
bubbleSort(arr6,500);
bubbleSort(arr7,1000);

// merge sort
printf("merge sort\n");
MergeSort(arr1 , 0 , 9);
MergeSort(arr2 , 0 , 19);
MergeSort(arr3 , 0 , 49);
MergeSort(arr4 , 0 , 99);
MergeSort(arr5 , 0 , 199);
MergeSort(arr6 , 0 , 299);
MergeSort(arr7 , 0 , 999);
printf("comparisions %d \n", nbrComp);
printf("permutations %d \n" , nbrPerm);
printf("iterations %d \n", nbrIter);



    return 0;
}
