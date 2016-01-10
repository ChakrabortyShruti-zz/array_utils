#include <stdio.h>
#include <stdlib.h>
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
  assert(1 == areEqual(a,c));
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
  dispose(a);

  ArrayUtil alphabets = create(sizeof(char),10);
  for(int i=0;i<alphabets.length;i++){
    ((char *)alphabets.base)[i] = 65+i;
  }
  int alphabet = 'D';
  int alphabet1 = 'Z';
  assert(3 == findIndex(alphabets,&alphabet));
  assert(-1 == findIndex(alphabets,&alphabet1));
  dispose(alphabets);
}

void test_findFirst_isEven(){
  ArrayUtil a = create(sizeof(4),5);
  for(int i=0;i<a.length;i++){
    ((int *)a.base)[i] = i+3;
  }
  int firstFirst_Of_isEven = *((int *)findFirst(a,&isEven,0));
  assert(4 == firstFirst_Of_isEven);
}

void test_findFirst_isDivisible(){
  ArrayUtil a = create(sizeof(4),7);
  for(int i = 0; i<a.length;i++){
    ((int *)a.base)[i] = i+5;
  }
  int hint = 4;
  int findFirst_Of_isDivisible = *((int *)findFirst(a,&isDivisible,&hint));
  assert(8 == findFirst_Of_isDivisible);
  int hint1 = 7;
  int findFirst_Of_isDivisible1 = *((int *)findFirst(a,&isDivisible,&hint1));
  assert(7 == findFirst_Of_isDivisible1);
}

void test_findLast_isEven(){
  ArrayUtil a = create(sizeof(4),4);
  for(int i=0;i<a.length;i++){
    ((int *)a.base)[i] = i+5;
  }
  int firstLast_Of_isEven = *((int *)findLast(a,&isEven,0));
  assert(8 == firstLast_Of_isEven);
}

void test_findLast_isDivisible(){
  ArrayUtil a = create(sizeof(4),4);
  for(int i=0;i<a.length;i++){
    ((int *)a.base)[i] = i+5;
  }
  int hint = 3;
  int firstLast_Of_isDivisible = *((int *)findLast(a,&isDivisible,&hint));
  assert(6 == firstLast_Of_isDivisible);
}

void test_count_isEven(){
  ArrayUtil a = create(sizeof(4),6);
  for(int i=0;i<a.length;i++){
    ((int *)a.base)[i] = i;
  }
  assert(3 == count(a,&isEven,0));
}

void test_count_isDivisible(){
  ArrayUtil a = create(sizeof(4),5);
  for(int i=0;i<a.length;i++){
    ((int *)a.base)[i] = i;
  }
  int hint =2;
  assert(3 == count(a,&isDivisible,&hint));
}

void test_count_with_isDivisible(){
  ArrayUtil a = create(sizeof(4),7);
  for(int i=0;i<a.length;i++){
    ((int *)a.base)[i] = i+2;
  }
  int hint = 3;
  assert(2 == count(a,&isDivisible,&hint));
}

void test_filter_function(){
  ArrayUtil a = create(sizeof(4),5);
  for(int i=0;i<a.length;i++){
    ((int *)a.base)[i] = i+3;
  }
 void *array;
 int hint = 2;
 int count = filter(a,&isDivisible,&hint,&array,5);
 int *result = (int *) array;
 assert(2 == count);
}

void test_map_function(){
  ArrayUtil a = create(sizeof(4),5);
  for(int i=0;i<a.length;i++){
   ((int *)a.base)[i] = i+3;
  }
  int hint = 1;
  ArrayUtil array = create(sizeof(4),5);
  ConvertFunc *func = &add_one;
  map(a,array,func,&hint);
  assert(5 == ((int *)a.base)[2]);
  assert(6 == ((int *)array.base)[2]);
  assert(7 == ((int *)array.base)[3]);
}

void test_forEach(){
  ArrayUtil a = create(sizeof(4),7);
  for(int i=0; i<a.length; i++){
    ((int *)a.base)[i] = i+5;
  }
  int hint = 1;
  OperationFunc *func = &add_it;
  forEach(a,func,&hint);
  assert(6 == ((int *)a.base)[0]);
  assert(7 == ((int *)a.base)[1]);
  assert(8 == ((int *)a.base)[2]);
}

