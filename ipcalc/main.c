#include <stdio.h>
#include "calc_ip.h"

int get_line_n(char *array, int max) {
    if (array == NULL || max <= 0)
        return -1;

    int actual = 0;
    int aChar;

    while (actual < max - 1) {
        aChar = getchar();
        if (aChar == EOF) {
            if (actual == 0)
                return -1;
            break;
        }
        if (aChar == '\n')
            break;
        array[actual] = (char) aChar;
        actual += 1;
    }
    array[actual] = '\0';

    return actual;
}


int main() {
    char input[100];
    printf("Enter ip:");
    int length = get_line_n(input, sizeof(input));
    if (length < 0) {
        printf("Error reading input.\n");
    } else {
        printf("Input: %s\n", input);
        char ip[40];
        int prefix;
        if (sscanf(input, "%39[^/]/%d", ip, &prefix) == 2) {
            printf("IP: %s\n", ip);
            printf("Prefix: %d\n", prefix);
            handle_ip_with_cidr(ip);
        } else if (sscanf(input, "%39[^/]", ip) == 1) {
            printf("IP: %s\n", ip);
            handle_ip_with_cidr(ip);
        } else {
            printf("Invalid IP/CIDR format.\n");
        }
    }
    return 0;
}