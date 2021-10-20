#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  FILE *fp;
  int array[1024];
  int i, length = 0;
  float average, total = 0.0;
  //using a buffer array
  char commas[1024];
  char *aux; 

  fp = fopen("numbers.txt", "r");

  if (fp == NULL){
      printf("Error Reading File\n");
      return 1;
  }

  //using commas to read the lines of the file
  fgets(commas, 1023, fp);
  aux = strtok(commas, ",");

  while(aux){
    array[length] = atoi(aux);
    length++;
    //ah ha how to replace commas
    aux = strtok(NULL, ",");
  }

  //printing the contents
  printf("The contents of the array:\n");
  for (i = 0; i < length; i++){
    printf("%d ", array[i]);
    total += array[i];
  }

  //calculations for average, max, and min value
  average = total / length;
  int max = array[0];
  int min = array[0];

  //max value
  for (i = 0; i < length; i++) {
    if (array[i] > max){
      max = array[i]; 
    }
  }

  //min value
  for (i = 0; i < length; i++) {
    if (array[i] < min){
      min = array[i]; 
    }
  }

  //printing the min, max, and average values
  printf("\nMin Value: %d", min);
  printf("\nMax Value: %d", max);
  printf("\nAverage: %.2f", average);
  printf("\n");

  fclose(fp);
  return 0;
}
