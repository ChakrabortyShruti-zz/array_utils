typedef struct array {
  void * base;
  int type_size;
  int length;
} ArrayUtil;

typedef int MatchFunc (void*,void*);

typedef void ConvertFunc(void *,void *,void *);

typedef void OperationFunc(void *,void *);

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

void add_one(void *hint, void* sourceItem,void* destinationItem);

void map(ArrayUtil util,ArrayUtil destination,ConvertFunc* convert,void *hint);

void add_it(void *,void *);

void forEach(ArrayUtil util,OperationFunc *operation,void * hint);
