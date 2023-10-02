#include <stdio.h>
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
int main(){
    printf("4 and 12: %d\n", and(4, 12)); // 4
    printf("4 or 12: %d\n", or(4, 12)); // 12
    printf("4 xor 12: %d\n", xor(4, 12)); // 8
    printf("not 4 : %d\n", not(4)); // -5
}