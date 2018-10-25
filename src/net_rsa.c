/*
 *
 */
#include "net_rsa.h"

static RSA_METHOD *net_rsa_method = NULL;

RSA_METHOD *net_get_RSA_methods(void)
{
	if (net_rsa_method != NULL)
		return net_rsa_method;

	net_rsa_method = (RSA_METHOD *)RSA_get_default_method();

	return net_rsa_method;
}

void net_free_RSA_methods(void)
{
}
