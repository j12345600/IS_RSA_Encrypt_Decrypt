#include "stdafx.h"
#include  "RSA_util.h"
RSA_util::RSA_util() {
	p = DH_new();
	q = DH_new();

	ctx = BN_CTX_new();
	a = BN_new();
	b = BN_new();
	c = BN_new();
	gen = BN_new();
	prime_mod = BN_new();
};
int RSA_util::square_and_multiply(BIGNUM*r, BIGNUM *a, BIGNUM *p, BN_CTX *ctx) {

}