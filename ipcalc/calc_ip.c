#include "calc_ip.h"

void ipv4_to_hex_and_bin(const char *ip) {
    unsigned int bytes[4];
    sscanf(ip, "%u.%u.%u.%u", &bytes[0], &bytes[1], &bytes[2], &bytes[3]);

    printf("IPv4 Hex: %02X.%02X.%02X.%02X\n", bytes[0], bytes[1], bytes[2], bytes[3]);
    printf("IPv4 Bin: ");
    for (int i = 0; i < 4; i++) {
        for (int j = 7; j >= 0; j--) {
            printf("%d", (bytes[i] >> j) & 1);
        }
        if (i < 3) printf(".");
    }
    printf("\n");
}

void ipv6_to_hex_and_bin(const char *ip) {
    unsigned int bytes[8];
    sscanf(ip, "%x:%x:%x:%x:%x:%x:%x:%x",
           &bytes[0], &bytes[1], &bytes[2], &bytes[3],
           &bytes[4], &bytes[5], &bytes[6], &bytes[7]);

    printf("IPv6 Hex: %x:%x:%x:%x:%x:%x:%x:%x\n",
           bytes[0], bytes[1], bytes[2], bytes[3],
           bytes[4], bytes[5], bytes[6], bytes[7]);

    printf("IPv6 Bin: ");
    for (int i = 0; i < 8; i++) {
        for (int j = 15; j >= 0; j--) {
            printf("%d", (bytes[i] >> j) & 1);
        }
        if (i < 7) printf(":");
    }
    printf("\n");
}

void print_subnet_mask(int prefix, IPType type) {
    if (type == IPV4) {
        unsigned int mask = 0xFFFFFFFF << (32 - prefix);
        printf("Subnet Mask: %u.%u.%u.%u\n",
               (mask >> 24) & 0xFF,
               (mask >> 16) & 0xFF,
               (mask >> 8) & 0xFF,
               mask & 0xFF);
    } else if (type == IPV6) {
        printf("Subnet Mask: /%d\n", prefix);
    }
}

void handle_ip_with_cidr(const char *ip_with_cidr) {
    char ip[40];
    int prefix;
    sscanf(ip_with_cidr, "%39[^/]/%d", ip, &prefix);

    IPType type = detect_ip_type(ip);

    if (type == IPV4) {
        printf("IP is IPv4\n");
        ipv4_to_hex_and_bin(ip);
        print_subnet_mask(prefix, type);
    } else if (type == IPV6) {
        printf("IP is IPv6\n");
        ipv6_to_hex_and_bin(ip);
        print_subnet_mask(prefix, type);
    } else {
        printf("IP is Invalid\n");
    }
}