#pragma once
#include "stdafx.h"
#include"..\openssl-1.0.2e-vs2015\include\openssl\bn.h"
#include"..\openssl-1.0.2e-vs2015\include\openssl\dh.h"
#include <iostream>
#define BYTETOBINARYPATTERN "%d%d%d%d%d%d%d%d"
#define BYTETOBINARY(byte)  \
  (byte & 0x80 ? 1 : 0), \
  (byte & 0x40 ? 1 : 0), \
  (byte & 0x20 ? 1 : 0), \
  (byte & 0x10 ? 1 : 0), \
  (byte & 0x08 ? 1 : 0), \
  (byte & 0x04 ? 1 : 0), \
  (byte & 0x02 ? 1 : 0), \
  (byte & 0x01 ? 1 : 0) 
using namespace std;

class RSA_util
{
	BIGNUM *a, *b, *c, *d, *gen, *prime_mod;
	DH *p, *q;
	BN_CTX *ctx;
public:
	RSA_util();
	int square_and_multiply(BIGNUM*r, BIGNUM *a, BIGNUM *p, BN_CTX *ctx);
	int RSA_key_pair_gen(int length);
};
