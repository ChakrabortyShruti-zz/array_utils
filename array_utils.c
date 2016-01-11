#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"array_utils.h"

ArrayUtil create (int type_size, int length){
  ArrayUtil ele;
  ele.length = length;
  ele.type_size = type_size;
  ele.base = calloc(length,type_size);
  return ele;
}

int areEqual(ArrayUtil a, ArrayUtil b){
  int length = a.length > b.length ? a.length : b.length;
  int compare = memcmp(a.base, b.base, length);
  if(compare == 0 && a.length==b.length && a.type_size==b.type_size){
    return 0;
  }else{
    return 1;
  }
}

ArrayUtil resize(ArrayUtil util, int length){
  util.base = realloc(util.base,length);
  util.length = length;
  return util;  
}

int findIndex(ArrayUtil util, void *element){
  void *base = util.base;
  for(int i=0;i<util.length;i++){
    if(memcmp(base,element,util.type_size) == 0){
      return i;
    }
    base = base+util.type_size;
  }
  return -1;
}

void dispose(ArrayUtil util){
  void *base = util.base;
  util.length = 0;
  util.type_size = 0;
  free(util.base);
}

int isEven(void *hint,void *item){
  return (*(int *)item % 2 == 0);
}

int isDivisible(void *hint,void *item){
  return (*(int *)item) % (*(int *)hint) == 0;
}

void *findFirst(ArrayUtil util,MatchFunc *match,void *hint){
 void* base = util.base;
  for(int i=0;i<util.length;i++){
    if(match(hint,base) == 1)
      return base;
    base = base+util.type_size;
  }
  return NULL;
}

void *findLast(ArrayUtil util,MatchFunc *match,void *hint){
 void* base = util.base + (util.length-1)*util.type_size;
  for(int i=0;i<util.length;i++){
    if(match(hint,base) == 1){
      return base;
    }
    base = base-util.type_size;
  }
  return NULL;
}


int count(ArrayUtil util,MatchFunc *match,void *hint){
 void* base = util.base;
 int count=0;
  for(int i=0;i<util.length;i++){
    if(match(hint,base) == 1)
      count++;
    base = base+util.type_size;
  }
  return count;
}

int filter(ArrayUtil util,MatchFunc *match,void *hint,void **destination,int maxItems){
  int count = 0;
  void* base = util.base;
  for(int i=0;(i<util.length && count<maxItems);i++){
    if(match(hint,base)==1){
      destination[count] = base;
      count++;
    }
    base = base + util.type_size;
  }
  return count;
}

void add_one(void *hint,void *sourceItem,void *destinationItem){
  *(int *)destinationItem = *((int *)sourceItem) + *((int *)hint);
}

void map(ArrayUtil util,ArrayUtil destination,ConvertFunc *convert,void *hint){
  void *base = util.base;
  void *dest = destination.base;
  for(int i=0;i<util.length*util.type_size;i+=util.type_size){
    (convert)(hint,base+i,dest+i);
  }
}

void add_it(void *hint,void *item){
  *(int *)item = (*((int *)hint)) + (*((int *)item));
}

void forEach(ArrayUtil util,OperationFunc *operation,void *hint){
  void *base = util.base;
  for(int i=0;i<util.length*util.type_size;i+=util.type_size){
    operation(hint,base+i);
  }
}

void* add_all(void *hint,void *previousItem,void *item){
  *(int *)item = *(int *)previousItem + *(int *)item;
  return (int *)item;
}

void* reduce(ArrayUtil util,ReducerFunc* reducer,void *hint,void *initialValue){
  void *base = util.base;
  for(int i=0; i<util.length*util.type_size; i+=util.type_size){
    void *result = reducer(hint,initialValue,base+i);
    initialValue = result;
  }
  return initialValue;
}
