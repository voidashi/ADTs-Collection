#define TamFila 100

typedef int elem;

typedef struct fila{
    int ini, fim, total;
    elem itens[TamFila];
}fila_t;


fila_t* create();
void destroy(fila_t *p);
int isFull(fila_t *p);
int isEmpty(fila_t *p);
int insert(fila_t *p, elem x);
int removeElem(fila_t *p, elem *x);
int top(fila_t *p, elem *x);
