//
// Created by Anna Lambert on 04/07/2024.
//

#ifndef IPCALC_CALC_IP_H
#define IPCALC_CALC_IP_H

#include <stdio.h>
#include "valid_ip.h"

void ipv4_to_hex_and_bin(const char *ip);
void ipv6_to_hex_and_bin(const char *ip);
void print_subnet_mask(int prefix, IPType type);
void handle_ip_with_cidr(const char *ip_with_cidr);

#endif //IPCALC_CALC_IP_H
