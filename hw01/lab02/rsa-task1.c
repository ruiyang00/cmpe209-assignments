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

  /*initilizing for all varibles*/
  BN_hex2bn(&p, "F7E75FDC469067FFDC4E847C51F452DF");
  BN_hex2bn(&q, "E85CED54AF57E53E092113E62F436F4F");
  BN_hex2bn(&e, "0D88C3");
  BN_dec2bn(&one, "1");


  /*calculate the n*/
  BN_sub(res1, p , one);
  BN_sub(res2, q , one);
 
  BN_mul(n, res1, res2, ctx);

  /*publick key = (e, n)*/
  printBN("e=", e);
  printBN("n=", n);
  
  BN_mod_inverse(d, e, n, ctx);
  printBN("d=", d);
  

  return 0;
}

