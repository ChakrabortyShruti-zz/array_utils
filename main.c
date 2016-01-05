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

void test_resize_to_resize_array_to_bigger_length(){
  ArrayUtil a = create(sizeof(int),7);
  assert(7 == a.length);
  ArrayUtil b = resize(a,10);
  assert(10 == b.length);
  assert(4 == b.type_size);
  
  ArrayUtil c = create(sizeof(int),10);
  assert(0 == areEqual(b,c));
  assert(1 == areEqual(c,a));
}

void test_resize_to_resize_array_to_smaller_length(){
  ArrayUtil a = create(sizeof(int),7);
  assert(7 == a.length);
  ArrayUtil b = resize(a,5);
  assert(5 == b.length);

  ArrayUtil c = create(sizeof(int),5);
  assert(0 == areEqual(b,c));
  assert(-1 == areEqual(a,c));
}

void test_findIndex(){
  ArrayUtil a = create(sizeof(int),5);
  for(int i=0;i<a.length;i++){
     ((int *)a.base)[i] = i+4;
  }
  int number = 3;
  int number1 = 6;
  assert(-1 == findIndex(a,&number));
  assert(2 == findIndex(a,&number1));

  ArrayUtil alphabets = create(sizeof(char),10);
  for(int i=0;i<alphabets.length;i++){
    ((char *)alphabets.base)[i] = 65+i;
  }
  int alphabet = 'D';
  int alphabet1 = 'Z';
  assert(3 == findIndex(alphabets,&alphabet));
  assert(-1 == findIndex(alphabets,&alphabet1));
} 


int main(void){
  test_areEqual();
  test_resize_to_resize_array_to_bigger_length();
  test_findIndex();
  return 0;
}
