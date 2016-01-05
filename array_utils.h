typedef struct array {
  void * base;
  int type_size;
  int length;
} ArrayUtil;

ArrayUtil create(int,int);

int areEqual(ArrayUtil ,ArrayUtil);

ArrayUtil (ArrayUtil , int);
