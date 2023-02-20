#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <memory.h>
#include "dhexchange.h"

static void _print_key(const char* name, const DH_KEY key) 
{
	int i;

	printf("%s=\t", name);
	for (i = 0; i< DH_KEY_LENGTH; i++)
	{
		printf("%02x", key[i]);
	}
	printf("\n");
}

int main(void)
{
	DH_KEY alice_public = {87,0d,72,53,be,f3,e1,7b,e1,2d,97,38,93,75,31,dc}; // 0x 870d7253bef3e17be12d9738937531dc
	DH_KEY alice_private = {45,45,1f,ae,9b,3a,9d,5f,46,3c,cb,75,63,03,55,7c}; // 0x 45451fae9b3a9d5f463ccb756303557c
	DH_KEY bob_private; // ???
	DH_KEY bob_public = {cc,b1,cf,31,6e,f3,ea,88,68,48,14,72,e8,38,5a,7e}; // 0x ccb1cf316ef3ea8868481472e8385a7e
	DH_KEY alice_secret; // == bob_secret
	DH_KEY bob_secret; // == alice_secret

	time_t seed;
	time(&seed);
	srand((unsigned int)seed);

	/*Alice generate her private key and public key */
	DH_generate_key_pair(alice_public, alice_private);

	/*Bob generate his private key and public key */
	DH_generate_key_pair(bob_public, bob_private);

	/*Bob send his public key to Alice, Alice generate the secret key */
	DH_generate_key_secret(alice_secret, alice_private, bob_public);

	/*Alice send her public key to Bob, Bob generate the secret key */
	DH_generate_key_secret(bob_secret, bob_private, alice_public);

	_print_key("alice_private", alice_private);
	_print_key("alice_public", alice_public);
	_print_key("bob_private", bob_private);
	_print_key("bob_public", bob_public);
	_print_key("alice_secret", alice_secret);
	_print_key("bob_secret", bob_secret);

	if (memcmp(alice_secret, bob_secret, DH_KEY_LENGTH) != 0) 
	{
		printf("ERROR!\n");
		return 1;
	}
	return 0;
}
