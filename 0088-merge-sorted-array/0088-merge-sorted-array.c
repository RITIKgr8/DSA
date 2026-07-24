void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i=0;
    int j=0;
    int *arr = (int *)malloc((m+n) * sizeof(int));
    for(int k=0 ; k<(m+n) ;k++){
        if(i<m && (j>=n || nums1[i] <= nums2[j])){
            arr[k] = nums1[i];
            i++;
        }else if(j<n && (i>=m || nums1[i] > nums2[j])){
            arr[k]= nums2[j];
            j++;
        }
    }
    for(int a=0; a<(m+n) ; a++){
        nums1[a]=arr[a];
    }
    free(arr);
}