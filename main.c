#include <stdio.h>
#include <assert.h>
#include "array_utils.h"

void test_areEqual(){
  ArrayUtil a = create(sizeof(char),6);
  ArrayUtil b = create(sizeof(char),6);
  ArrayUtil c = create(sizeof(int),7);
  assert(0 == areEqual(a,b));
  assert(1 == b.type_size);
  assert(6 == b.length);
  assert(1 == areEqual(b,c));
}

int main(void){
  test_areEqual();
  return 0;
}
