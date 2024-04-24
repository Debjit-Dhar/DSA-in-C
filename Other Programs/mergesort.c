#include <stdio.h>
void main()
{
    int n,i,j;
    printf("Enter size of the array.\n");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        printf("Enter element no %d\n",i+1);
        scanf("%d",&a[i]);
    }
    printf("Original Array.\n");
    for(i=0;i<n;i++)
     printf("%d\t",a[i]);
    printf("\n"); 
    //MERGE SORT
    msort(a,0,n-1);
    //DISPLAY SORTED ARRAY.
    printf("Sorted Array.\n");
    for(i=0;i<n;i++)
     printf("%d\t",a[i]);
    printf("\n");    
}
 void merge(int arr[], int l, int m, int r)
    {
        // Find sizes of two subarrays to be merged
        int n1 = m - l + 1, n2 = r - m;
        /* Create temp arrays */
        int L[n1],R[n2];
         /*Copy data to temp arrays*/
        for (int i = 0; i < n1; ++i)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = arr[m + 1 + j];
         /* Merge the temp arrays */
         // Initial indexes of first and second subarrays
        int i = 0, j = 0;
         // Initial index of merged subarray array
        int k = l;
        while (i < n1 && j < n2) 
            if (L[i] <= R[j]) 
                arr[k++] = L[i++];
            else 
                arr[k++] = R[j++];
         /* Copy remaining elements of L[] if any */
        while (i < n1) 
            arr[k++] = L[i++];
        /* Copy remaining elements of R[] if any */
        while (j < n2) 
            arr[k++] = R[j++];
    }
    void msort(int arr[], int l, int r)
    {
        if (l < r) {
            // Find the middle point
            int m = l + (r - l) / 2;
             // Sort first and second halves
            msort(arr, l, m);
            msort(arr, m + 1, r);
             // Merge the sorted halves
            merge(arr, l, m, r);
        }
    } 