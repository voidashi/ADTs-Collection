#define TamFila 100

typedef struct fila{
    int ini, fim, total;
    void **itens;
    int tamElem;
}fila_t;


fila_t* create(int TamElem);
void destroy(fila_t *f);
int isFull(fila_t *f);
int isEmpty(fila_t *f);
int insert(fila_t *f, void *x);
int remover(fila_t *f, void *x);