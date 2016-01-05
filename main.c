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

void test_resize(){
  ArrayUtil a = create(sizeof(int),7);
  assert(7 == a.length);
  ArrayUtil b = resize(a,10);
  assert(10 == b.length);
  assert(4 == b.type_size);
  
  ArrayUtil c = create(sizeof(int),10);
  assert(0 == areEqual(b,c));
  assert(1 == areEqual(c,a));
}

void test_findIndex(){
  ArrayUtil a = create(sizeof(4),5);
  for(int i=0;i<a.length;i++){
     ((int *)a.base)[i] = i+4;
  }
  int number = 3;
  int number1 = 6;
  assert(-1 == findIndex(a,&number));
  assert(2 == findIndex(a,&number1));
} 

int main(void){
  test_areEqual();
  test_resize();
  test_findIndex();
  return 0;
}
