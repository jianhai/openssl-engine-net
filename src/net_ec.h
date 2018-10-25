/*
 *
 */
#ifndef NET_EC_H
#define NET_EC_H

EC_KEY_METHOD *net_get_EC_methods(void);

void net_free_EC_methods(void);

#endif //NET_EC_H
