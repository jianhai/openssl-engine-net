/*
 *
 */
#include <openssl/ecdh.h>

#include "net_ec.h"

static EC_KEY_METHOD *net_ec_method = NULL;

EC_KEY_METHOD *net_get_EC_methods(void)
{
	if (net_ec_method != NULL)
		return net_ec_method;

	return net_ec_method;
}

void net_free_EC_methods(void)
{
}
