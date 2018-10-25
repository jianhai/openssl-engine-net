/*
 *
 */

#ifndef NET_RSA_H
#define NET_RSA_H

#include <openssl/rsa.h>

RSA_METHOD *net_get_RSA_methods(void);

void net_free_RSA_methods(void);

#endif //NET_RSA_H
