#include <stdio.h>
#include <openssl/bn.h>

void printBN(char* msg, BIGNUM * a){
    char * number_str = BN_bn2hex(a);
    printf("%s 0x%s\n", msg, number_str);
    OPENSSL_free(number_str);
}

int main ()
{
  BN_CTX *ctx = BN_CTX_new();
  /*points for p , q, e, n*/
  BIGNUM *p = BN_new();
  BIGNUM *q = BN_new();
  BIGNUM *e = BN_new();
  BIGNUM *res1 = BN_new();
  BIGNUM *res2 = BN_new();
  BIGNUM *n = BN_new();
  BIGNUM *d = BN_new();
  BIGNUM *encrypt = BN_new();
  BIGNUM *decrypt = BN_new();
  BIGNUM *one = BN_new();
  BIGNUM *m = BN_new();
  BIGNUM *c = BN_new();

  /*initilizing for all varibles*/
  BN_hex2bn(&p, "F7E75FDC469067FFDC4E847C51F452DF");
  BN_hex2bn(&q, "E85CED54AF57E53E092113E62F436F4F");
  BN_hex2bn(&m, "4120746f702073656372657421");
  BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
  BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");
  BN_hex2bn(&e, "010001");
  BN_hex2bn(&c, "8C0F971DF2F3672B28811407E2DABBE1DA0FEBBBDFC7DCB67396567EA1E2493F"); 
  

  /*decryption: m = c^d(mod n) */

  BN_mod_exp(decrypt, c, d, n, ctx);
  printBN("plaintext=", decrypt);


  

  return 0;
}

