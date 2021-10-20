/*Kirsten Richard October 26, 2018
CSCI 2132 A4 This program is about finding the median
and average of a bunch of numbers in an array.
Note: merge_Sort algorithm for software dev*/

#include <stdio.h>

    //function declarations
    void merge_sort(double array[], int lower, int upper);
    void merge(double array[], int lower, int middle, int upper);
    double median(double array1[], int length);
    
int main() {
    int len, i;
    double average, sum = 0, median1 = 0;
    //length of array
    scanf("%d", &len);
    while(len > 0){
        average = 0;
        sum = 0;
        median1 = 0;
            double array[len];
            
            //sorts numbers in array
            for (i = 0; i < len; i++){
                scanf("%lf", &array[i]);
            }   
            
            merge_sort(array, 0, len-1);
            
            //finding the sum of the array
            for (i = 0; i < len; i++){
                sum = sum + array[i]; //adds each element together and assigns it to the sum variable
            }
            //calculates the average and median of the array
            average = sum/len;
            median1 = median(array, len);
            
            //print those outputs
            printf("Avg: %.3lf Med: %.3lf", average, median1);
            printf("\n");
            scanf("%d", &len);
    }
return 0;
}
        
    //merge_sort method that sorts the elements of the array by splitting it up
    void merge_sort(double array[], int lower, int upper) {
        int middle;
        if (lower < upper) {
            
            if (upper%2==0){
                middle=(lower+upper-1)/2;
            }else{
                middle=(lower+upper)/2;
            }
            merge_sort(array, lower, middle);
            merge_sort(array, middle+1, upper);
            merge(array, lower, middle, upper);
        }
    }
    
    //merge method that merges the two halves of the array
    void merge(double array[], int lower, int middle, int upper) {
        int len_left = middle - lower + 1;
        int len_right = upper - middle;
        
        double left[len_left], right[len_right];
        int i, j, k;
        
        
        for (i = 0, j=lower; i < len_left; i++, j++)
            left[i] = array[j];
        for (i = 0, j = middle+1 ; i < len_right; i++, j++)
            right[i] = array[j];
            i = j = 0; k = lower;
        while (i < len_left && j < len_right) {
            if (left[i] <= right[j]) array[k++] = left[i++];
            else array[k++] = right [j++];
        }
        while (i < len_left) array[k++] = left [i++];
        while (j < len_right) array[k++] = right[j++];
        
    }
    
    //median method that finds the middle of the array
    double median(double array1[], int length){
        double median = 0.0;
        /*if the length of array is an even number it 
        will return the average of the two middle elements*/
        if(length % 2 == 0){
            median = 0.5*(array1[(length/2)-1]+array1[(length/2)]);
        }
        //if the length of array is odd, it returns middle
        else{
            median = array1[length/2];
        }
        return median;
    }

