/*Kirsten Richard November 12, 2018 A5
CSCI 2132 This program is the 
Luhn's checksum algorithm and checks 
the inputted numbers if it passes
the test or fails*/

#include <stdio.h>

//function declarations
int luhn_checksum(int len, int a[]); 
    
int main() {
    int T, i, n;
    //scans for the length of array
    scanf("%d", &T);
    
    int a[50];
    char ch[50];
    
    for(i = 0; i < T; i++){
        n = -1;
        scanf("%50s", ch);

        //here it copies the ch array to a array
        while(ch[++n] != '\0')
            a[n] = ch[n] - '0';

        //results
        if(luhn_checksum(n, a))
            printf("PASS\n");
        else 
            printf("FAIL\n");
    }
    return 0;
}

//checksum that determines if the input passes or fails
int luhn_checksum(int len, int a[]){
    int i, total_sum = 0;
    
    //adds each second digit
    for(i = len-2; i >= 0; i-=2){
        int even = (a[i]*2);
        if(even > 9)
            total_sum += even%10 + even/10;
        else
            total_sum += even%10;
    }
    
    //adds the total sum together of array
    for(i = len-1; i >= 0; i = i-2)
        total_sum += a[i];
    
    //if it passes return 1
    if(total_sum%10 == 0)
        return 1;
    else 
        return 0;
}