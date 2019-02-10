void usort(void *arr,int size,int el_size,char (*attrubte) (const void*,const void*));
struct lb_std{
    char *name;
    int m1;
    int m2;
    int m3;
};

typedef struct lb_std t_std;

int cmp_l(const void *a, const void *b);
int cmp_avr (const void *a, const void *b);
int read_student(FILE *f, t_std **x);
void write_student(t_std *s);
