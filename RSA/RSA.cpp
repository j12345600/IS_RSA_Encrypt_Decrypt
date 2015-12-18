// RSA.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include  "RSA_util.h"
int main()
{
	BIGNUM *a, *b, *c, *d, *gen, *prime_mod;
	char *c_str;
	unsigned char *unc_str;
	BN_CTX *ctx; /* used internally by the bignum lib */
	DH *p,*q;
	int csize;
	p = DH_new();
	q = DH_new();

	ctx = BN_CTX_new();
	a = BN_new();
	b = BN_new();
	c = BN_new();
	gen = BN_new();
	prime_mod = BN_new();

	/* find a safe 512-bit random prime for generator 5 */
	//dhparms = DH_generate_parameters(2048, 5, NULL, NULL);
	DH_generate_parameters_ex(p, 512, 5, NULL);
	DH_generate_parameters_ex(q, 512, 2, NULL);
	int sizeP, sizeQ, sizePQ;
	sizeP = BN_num_bytes(p->p);
	sizeQ = BN_num_bytes(q->p);
	sizePQ = BN_num_bytes(prime_mod);
	printf("sizep=%i sizeq=%i sizepq=%i\n", sizeP, sizeQ, sizePQ);

	prime_mod = p->p;
	c_str = BN_bn2dec(prime_mod);
	printf("p=%s\n", c_str);

	c_str = BN_bn2dec(q->p);
	printf("q=%s\n", c_str);

	BN_add(prime_mod, p->p, q->p);
	c_str = BN_bn2dec(prime_mod);
	printf("p*q=%s\n", c_str);

	//int sizeP, sizeQ, sizePQ;
	sizeP = BN_num_bytes(p->p);
	sizeQ = BN_num_bytes(q->p);
	sizePQ = BN_num_bytes(prime_mod);
	printf("sizep=%i sizeq=%i sizepq=%i\n", sizeP, sizeQ, sizePQ);
	unc_str = (unsigned char *)malloc(sizeQ);
	BN_bn2bin(q->p, unc_str);
	for (int i = 0; i < sizeQ; i++) printf(BYTETOBINARYPATTERN " ", BYTETOBINARY(unc_str[i]));
	BN_set_word(a, 512);
	BN_set_word(b, 1);

	c_str = BN_bn2dec(p->p);
	printf("p=%s\n", c_str);

	c_str = BN_bn2dec(q->p);
	printf("q=%s\n", c_str);

	BN_mul(c, a, b, ctx);
	//BN_set_word(a, 1);
	//BN_sub(c,c,a);
	c_str = BN_bn2dec(c); /* there's also a BN_dec2bn() */
	printf("512*2=%s\n", c_str);
	unc_str =(unsigned char *) malloc(BN_num_bytes(c));
	std::cout << "size= " << BN_num_bytes(c)<<std::endl;
	std::cout << "size= " << sizeof(unsigned char) << std::endl;
	BN_bn2bin(c, unc_str); /* there's also a BN_dec2bn() */
	printf("6*7=%s\n", unc_str);
	csize = BN_num_bits(c);
	d = BN_dup(a);

	if (BN_is_bit_set(prime_mod, 10)) { printf("Toast is yummy."); }

	BN_CTX_free(ctx);
	system("pause");
    return 0;
}

