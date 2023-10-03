#include <stdio.h>

#include <stdbool.h>
// basic operations

int and(int byte1, int byte2){ 
    return byte1 & byte2;
}
int or(int byte1, int byte2){
    return byte1 | byte2; 
}
int xor(int byte1, int byte2){
    return byte1 ^ byte2;
}
int not(int byte1){
    return ~byte1; 
}

int my_Abs(int num){
    const int bit31 = num >> 31; //63 for 64-bit sistem
    return (num ^ bit31) - bit31;
}

bool is_powerof2(int num){
    return ((num & (num - 1)) == 0);
}

int main(){
    printf("4 and 12: %d\n", and(4, 12)); // 4
    printf("4 or 12: %d\n", or(4, 12)); // 12
    printf("4 xor 12: %d\n", xor(4, 12)); // 8
    printf("not 4 : %d\n", not(4)); // -5
    printf("absolute value of -3: %d", my_Abs(-3)); // 3
    printf("is 128 power of 2: %d", is_powerof2(128));
}