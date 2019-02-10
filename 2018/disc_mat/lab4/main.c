#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct dot{
    int x;
    int y;
};

void create_rel(struct dot* M, int n, int ** A) {
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            A[i][j]=(M[i].y<M[j].y);
}

int check_anti_sym (int **R, int N) {
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            if((i != j) && (R[i][j]*R[j][i]))
                return 0;
    return 1;
}

int check_transitive (int **R, int N) {
    for (int i=0; i<N; i++)
        for (int k=0; k<N; k++)
            if (R[i][k])
                for (int j=0; j<N; j++)
                    if (R[k][j] && (R[i][j] == 0))
                        return 0;
    return 1;
}

int check_order(int **R, int N) {
    int tmp1, tmp2;
    tmp1 = check_anti_sym(R,N);
    tmp2 = check_transitive(R, N);
    return (tmp1*tmp2);
}

int check (int **A, int x, int y) {
    for (int i= x+1; i<y; i++)
        if (A[x][i] && A[i][y])
            return 1;
    return 0;
}

void create_domin_rel (int **A, int N) {
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            if (A[i][j])
                if (i == j)
                    A[i][j] = 0;
                else
                    if (check (A, i, j))
                        A[i][j] = 0;
}

void print_matr (int **A, int N) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++)
            printf ("%i ", A[i][j]);
        printf ("\n");
    }
}

void mem_free (int **A, int N) {
    for (int i=0; i<N; i++)
        free (A[i]);
    free (A);
}

void print_a (int **A, int N) {
    for (int i=0; i<N; i++)
        printf("%i ", A[i]);
    printf ("\n\n\n");
}

int check_nut (int *A, int N) {
    int i;
    for(i=0;i<N && A[i]<0;i++);
    return (i<N);
}

void matr_subs_mass (int  **A, int *B, int N, int i) {
    for (int j=0; j<N; j++)
        B[j] = B[j] - A[i][j];
}

void create_top_sort (int **A, int N, struct dot *M) {
    int i, k=0;
    int *B = (int*)calloc(N,sizeof(int));
    for (i=0; i<N; i++) {
        B[i] = 0;
        for (int j=0; j<N; j++)
            B[i] = B[i] + A[j][i];
    }
    do {
        printf("%i lvl: ", k);
        for (i=0; i<N; i++)
            if (B[i] == 0) {
                printf("(%i, %i)", M[i].x, M[i].y);
                B[i] = -k-1;
            }
        printf("\n");
        for (i=0; i<N; i++)
            if (B[i] == -k-1)
                matr_subs_mass(A, B, N, i);
        k++;
    }
    while (check_nut(B,N) && (k<N));
}

int main(){
    int n1=9, n2=13;
    struct dot *M1 = ((struct dot*) calloc(n1, sizeof(struct dot)));
    struct dot *M2 = ((struct dot*) calloc(n2, sizeof(struct dot)));
    int XY[3]={-1, 0, 1};
    int k=0;
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++){
            M1[k].x = M2[k].x = XY[i];
            M1[k].y = M2[k].y = XY[j];
            k++;
        }
    M2[9].x -= 2; M2[9].y = 0;
    M2[10].x = 0; M2[10].y -= 2;
    M2[11].x = 2; M2[11].y = 0;
    M2[12].x = 0; M2[12].y = 2;
    int** A1 = (int**) calloc(n1, sizeof(int*));
    for (int i=0; i<n1; i++)
        A1[i] = (int*) calloc(n1, sizeof(int));
    printf("Relationship matrix on set M1:\n\n");
    create_rel (M1, n1, A1);
    print_matr (A1, n1);
    if (check_order(A1, n1)) {
        printf("check_order\n");
        create_domin_rel (A1, n1);
        printf("\nThe dominance relation matrix in the matrix of an check_order relation on the set M1:\n\n");
        print_matr(A1, n1);
        printf("\n");
        create_top_sort (A1, n1, M1);
    }
    else{
        printf("Not check_order\n");
    }
    int** A2 = (int**) calloc (n2, sizeof(int*));
    for (int i=0; i<n2; i++)
        A2[i] = (int*) calloc (n2, sizeof(int));
    create_rel (M2, n2, A2);
    printf ("\nRelationship matrix on set M2:\n\n");
    print_matr(A2,n2);
    if (check_order(A2,n2)) {
        create_domin_rel(A2,n2);
        printf("\nThe dominance relation matrix in the matrix of an check_order relation on the set M2:\n\n");
        print_matr(A2,n2);
        printf("\n");
        create_top_sort(A2,n2,M2);
    }
    else{
        printf("Not check_order\n");
    }
    mem_free(A1,n1);
    mem_free(A2,n2);
    getchar();
    return 0;
}
