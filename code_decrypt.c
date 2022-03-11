//Name: Suman Saurabh
//Roll Number: 2111MC13

#include<stdio.h>

/* They key point here I am using is: the string of last characters of lexicographically ordered strings and the string which
we will get after sorting the given string in reverse order will be placed at adjacent position in original string, therefore I am just comparing
respective character of given string and sorted string one by one and putting it to it's original position in actual res string by comparing one of the
two character if I have positioned it otherwise I am just going to the next character of given string and reversed sorted string.*/

void heapify_arr(char arr[], int n, int i) {          // Function to compare left child right child and parent to heapify the whole tree
    void swap(char *ele1, char *ele2);
    int larg = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[larg])  // Comparing left child and largest
      larg = left;

    if (right < n && arr[right] > arr[larg])   // Comparing right child and largest
      larg = right;

    if (larg != i) {               // Checking if largest is not parent
      swap(&arr[i], &arr[larg]);

      heapify_arr(arr, n, larg);
    }
  }

void swap(char *ele1, char *ele2) {                // Swapping the two element in the array
    char temp = *ele1;
    *ele1 = *ele2;
    *ele2 = temp;
  }

void heap_Sort(char arr[], int n) {
    void swap(char *ele1, char *ele2) ;          // Main function of heap sort
    void heapify_arr(char arr[], int n, int i);
    for (int i = n / 2 - 1; i >= 0; i--)          // Heapify starting from mid element building max heap
      heapify_arr(arr, n, i);


    for (int i = n - 1; i >= 0; i--) {                // Swapping first and ith element to sort the heap array
      swap(&arr[0], &arr[i]);
      heapify_arr(arr, i, 0);
    }
  }



void printA(char arr[], int n) {
    for (int i = 0; i < n; ++i)
      printf("%c ", arr[i]);
    printf("\n");
  }

  // Driver code
  int main() {
    void printA(char arr[], int n);
    void heap_Sort(char arr[], int n);
    int ts;
    printf("\nEnter the number of test cases: ");   // Taking test cases
    scanf("%d",&ts);

    while(ts>0){
    int n,pos;
    printf("\nEnter the number of character in string: ");
    scanf("%d",&n);
    char arr[n];
    printf("\nEnter the characters: ");
    scanf("%s",arr);
    printA(arr,n);
    printf("\nEnter position of first character: ");
    scanf("%d",&pos);


    char arr_copy[n];          // Creating Copy of entered string
    for(int i=0;i<n;i++){
        arr_copy[i] = arr[i];
    }
    heap_Sort(arr, n);              //Sorting Given string in reverse order
    char arr_rev[n];
    int j=0;
    for(int i=n-1;i>=0;i--){
        arr_rev[j++] = arr[i];
    }
    printf("Sorted array is \n");
    printA(arr_copy, n);                 // Printing Sorted string of character in reverse order
    char res[n];
    for(int i=0;i<n;i++){
        if(i==pos-1){
            res[i] = arr_copy[0];     //Putting first character of given string in correct position of actual word res
        }
        else{
            res[i] = '#';           // Putting # in rest of the postion as we dont know the rest of the character position
        }
    }
    for(int i=0;i<n;i++){
        char a = arr_copy[i],b = arr_rev[i];         // Comparing ith character of given string and ith character of sorted string and

                                                        // placing the character depending on relative position of both character
        if(a==b){             // For the case when both character are same
            for(int k=0;k<n;k++){
                if(res[k]==a){
                    if(res[k+1]=='#')
                        res[k+1]=b;
                    else{
                        char temp=res[k+1];
                        res[k+1] = b;
                        res[k+2] = temp;
                    }
                    break;
                }
            }
        }
        else{
        for(int k=0;k<n;k++){
            if(res[k]==a || res[k]==b){            // Finding the postion of character in the output string
                if(res[k]==a){

                    if(k+1>n-1){
                       res[0] = b;
                    }
                    else
                        res[k+1] = b;
                }
                else{
                    if(k-1<0){
                        res[n-1] = a;
                    }
                    else{
                        res[k-1] = a;
                    }
                }
                break;
            }

        }
        }


    }


    printf("Actual String is \n");
    printA(res, n);
    ts--;
    }

  }
