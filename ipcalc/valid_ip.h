//
// Created by Anna Lambert on 04/07/2024.
//

#ifndef IPCALC_VALID_IP_H
#define IPCALC_VALID_IP_H

#include <ctype.h>
#include <string.h>

typedef enum {
    INVALID_IP = 0,
    IPV4,
    IPV6
} IPType;

int is_valid_ipv4(const char *ip);
int is_valid_ipv6(const char *ip);
IPType detect_ip_type(const char *ip);

#endif //IPCALC_VALID_IP_H
