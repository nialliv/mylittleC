#include <stdio.h>
#include <stdint.h>

int main() {
    uint64_t table = 0x726F6C6564574820;
    uint64_t idx = 0xEFC86B61;
    while (idx)
    {
        putchar((table >> (8*(idx &7))) &0xFF);
        idx >>= 3;
    }
    
    return 0; 
}