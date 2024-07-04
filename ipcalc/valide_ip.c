//
// Created by Anna on 04/07/2024.
//

#include "valid_ip.h"

int is_valid_ipv4(const char *ip) {
    int num, dots = 0;
    const char *ptr = ip;

    while (*ptr) {
        if (!isdigit(*ptr) && *ptr != '.') return 0;
        if (isdigit(*ptr)) {
            num = 0;
            while (isdigit(*ptr)) {
                num = num * 10 + (*ptr - '0');
                if (num > 255) return 0;
                ptr++;
            }
            dots++;
        } else if (*ptr == '.') {
            if (*(ptr - 1) == '.' || *(ptr + 1) == '.' || *(ptr + 1) == '\0') return 0;
            ptr++;
        } else return 0;
    }
    return dots == 4;
}

int is_valid_ipv6(const char *ip) {
    int colons = 0;
    const char *ptr = ip;

    while (*ptr) {
        if (!isxdigit(*ptr) && *ptr != ':') return 0;
        if (isxdigit(*ptr)) {
            int count = 0;
            while (isxdigit(*ptr) && count < 4) {
                ptr++;
                count++;
            }
        } else if (*ptr == ':') {
            colons++;
            if (*(ptr + 1) == ':') ptr++;
            ptr++;
        } else return 0;
    }
    return colons >= 2 && colons <= 7;
}

IPType detect_ip_type(const char *ip) {
    if (is_valid_ipv4(ip)) {
        return IPV4;
    } else if (is_valid_ipv6(ip)) {
        return IPV6;
    } else {
        return INVALID_IP;
    }
}
