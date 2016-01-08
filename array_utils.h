typedef struct array {
  void * base;
  int type_size;
  int length;
} ArrayUtil;

typedef int MatchFunc (void*,void*);

ArrayUtil create(int, int);

int areEqual(ArrayUtil, ArrayUtil);

ArrayUtil resize(ArrayUtil, int);

int findIndex(ArrayUtil, void*);

void dispose(ArrayUtil);

int isEven(void *,void *);

int isDivisible(void *, void *);

void* findFirst(ArrayUtil  util,MatchFunc *match,void *hint);

void* findLast(ArrayUtil util,MatchFunc *match, void *hint);

int count(ArrayUtil util,MatchFunc *match, void *hint);

int filter(ArrayUtil util,MatchFunc *match,void *hint,void **destination,int maxItems);
