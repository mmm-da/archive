#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct S_edge{
	int x;
	int y;
}edge;

//Возвращает количество букетов/деревьев в остовном лесе
//В B записаны букеты
//N - количество вершин
int Kruskal(int** G, int *B, int N){
	int count = N, i, j, k;
	//Изначально каждая вершина представляет собой букет
    for(i = 0; i < N; i++){
		B[i] = i;
    }
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
            //Если две вершины связаны, и принадлежат разным букетам,
			if(G[i][j] && B[i] != B[j]){
                //объединим букеты
				for(k = 0; k < N; k++){
                    int t = B[j];
					if(B[k] == t){
					    B[k] = B[i];
                    }
                }
				count--; //количество букетов уменьшается
			}
		}
	}
	return count;
}

//Подсчитывает количество ребер по матрице и записывает их в массиив edge_arr
edge* EdgesCount(int **G, int N,int *count_of_edge){
    int i = 0;
	edge *edge_arr=(edge*) malloc(sizeof(edge)*100);
    for (int i = 0; i<N; i++){
        for (int j = i+1; j<N; j++){
            if (G[i][j]){
                i++;
				edge_arr[i].x=i;
				edge_arr[i].y=j;
            }
        }
    }
	*count_of_edge=i;
    return edge_arr;
}



//выводит массив граней
void print_edge_arr(edge *arr, int size){
	for(int i=0;i<size;i++){
		printf("(%d,%d),",arr[i].x,arr[i].y);
	}
	printf("\b \n");
}

//Копирует массив в другой
void Copy1(const int *A, int *B, int N){
    for (int i = 0; i<N; i++){
        B[i] = A[i];
    }
}

//Копирует двумерный массив в другой
void Copy2(int **A, int **B, int N){
    for (int i = 0; i<N; i++){
        for (int j = 0; j<N; j++){
            B[i][j] = A[i][j];
        }
    }
}

//Поэлементно вычитает из A B
void Minus(int **A, int **B,int** result, int N){
	for (int i = 0; i<N; i++){
        for (int j = 0; j<N; j++){
            result[i][j]=A[i][j] - B[i][j];
        }
    }
}

void clear_matr(int **A, int N){
    for (int i = 0; i<N; i++){
        for (int j = 0; j<N; j++){
            A[i][j] = 0;
        }
    }
}

//Выводит ребра графа G
void PrintEdges(int **G, int N){
    for (int i = 0; i<N; i++){
        for (int j = i+1; j<N; j++){
            if (G[i][j]){
                printf("%i <-> %i\n", i+1, j+1);
            }
        }
    }
}

//Выводит граф в формате DOT
void PrintDot(FILE *f, int **G, int N){
    fprintf(f, "graph auto{\n");
    for (int i = 0; i<N; i++){
        fprintf(f, "%i;", i+1);
        for (int j = i+1; j<N; j++){
            if (G[i][j]){
                fprintf(f, "%i--%i;\n", i+1, j+1);
            }
        }
    }
    fprintf(f, "}\n");
}

int **GetMem(int N){
    int **r = malloc(sizeof(int *)*N);
    for (int i = 0; i<N; i++){
        r[i] = malloc(sizeof(int)*N);
    }
    return r;
}

void FreeMem(int **G, int N){
    for (int i = 0; i<N; i++){
        free(G[i]);
    }
    free(G);
}

void clear_edge_arr(edge* arr){
	free(arr);
	arr=(edge*)malloc(sizeof(edge)*100);
}
//Выводит матрицу графа G
void PrintAdjG(int **G, int N){
    for (int i = 0; i<N; i++){
        for (int j = 0; j<N; j++){
            printf("%i ", G[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//Вводит матрицу графа G
void ReadAdjG(FILE *f, int **G, int N){
    for (int i = 0; i<N; i++){
        for (int j = 0; j<N; j++){
            fscanf(f, "%i", &G[i][j]);
        }
    }
}

void task(int **G, int N){
	int *B; //массив для Краскала
	B = malloc(sizeof(int)*N);
	int **temp_matr1=GetMem(N);
	int **temp_matr2=GetMem(N);
	int count_of_edge;
	edge *sub_edge_arr=(edge*)malloc(sizeof(edge)*100);
	int count_of_edge_in_sub =0;
	int k=0;
	edge *edge_arr=EdgesCount(G,N,&count_of_edge);
	unsigned count_of_sub_arr = pow(2, count_of_edge);
	for (int i = 0; i < count_of_sub_arr;i++){
		clear_matr(temp_matr1,N);
		clear_edge_arr(sub_edge_arr);
		k=0;
		for (int j = 0;j<count_of_edge;j++){
			if ( i & (1 << j) ){ //--если j-й бит установлен
				temp_matr1[edge_arr[j].x][edge_arr[j].y]=1;
				temp_matr1[edge_arr[j].y][edge_arr[j].x]=1;
				sub_edge_arr[k]=edge_arr[j];
				k++;
			}
		}
		Minus(G,temp_matr1,temp_matr2,N);
		if (Kruskal(temp_matr2, B, N) == 2){
			print_edge_arr(sub_edge_arr,k-1);
		}

	}
}

int main(){
	FILE *f;
    FILE *g_out;
	int** G;
	int** E;
	int N;
	f = fopen("graph.txt","r");
	fscanf(f,"%i",&N);
    printf("%i\n", N);
	G = GetMem(N);
	ReadAdjG(f,G,N);
	PrintAdjG(G,N);
        g_out = fopen("gin.gv", "w");
        PrintDot(g_out, G, N);
        fclose(g_out);
	fclose(f);
    //Получим подграф, содержащий три комп. св.
    //и максимально возможное кол-во ребер
    task(G,N);
    //получим в G мн-во удаленных ребер
    FreeMem(G, N);
	return 0;
}
