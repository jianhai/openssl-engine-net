/*
 *
 */
#include <string.h>
#include <openssl/engine.h>

#include "net_rsa.h"
#include "net_ec.h"

//const char *engine_net_id = "net";
const char *engine_net_id = "/home/luan/workspaces/openssl-engine-net/src/net_engine.so";
const char *engine_net_name = "A impementation of net crypto engine";

static int bind_net(ENGINE *e, const char *id)
{
	int rc = 0;

	printf("id:%s\n", id);

	if (id && (strcmp(id, engine_net_id) != 0)) {
		printf("NGINE_id defined already!\n");
		goto end;
	}

	if (!ENGINE_set_id(e, engine_net_id)) {
		printf("ENGINE_set_id failed\n");
		goto end;
	}

	if (!ENGINE_set_name(e, engine_net_name)) {
		printf("ENGINE_set_name failed\n");
		goto end;
	}

	if (!ENGINE_set_RSA(e, net_get_RSA_methods())) {
		printf("ENGINE_set_RSA failed\n");
		goto end;
	}	

	if (!ENGINE_set_EC(e, net_get_EC_methods())) {
		printf("ENGINE_set_EC failed\n");
		goto end;
	}

	rc = 1;
end:
	return rc;
}

IMPLEMENT_DYNAMIC_BIND_FN(bind_net)
IMPLEMENT_DYNAMIC_CHECK_FN()
