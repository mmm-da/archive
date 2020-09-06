#include <math.h>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

float *create_str(int size,float start_init){
    float *temp_str=(float*)malloc(sizeof(float)*size);
    for(int j=0;j<size;j++){
        temp_str[j]=start_init;
    }
    return temp_str;
}

 class Matr{
     int n,m; //n - кол-во строк m - кол-во столбцев
     float **matr;
 public:
     Matr(int n,int m):n(n),m(m){
         this->matr=(float**)malloc(sizeof(float*)*n);
         for(int i=0;i<m;i++){
             this->matr[i]=(float*)malloc(sizeof(float)*m);
         }
     };
     void scan();
     void scan_with_str(float* str);

     void print();
     void print_with_str(float* str);
     
     void sum_str(int dest,float* str,float mult);
     void div_str(int i,float div);
     void mult_str(int i,float mult);
     void swap_str(int str1,int str2);
     void del_str(int i);
     int gause_step(int prev_resolve_str,float* str);
     void to_basis(float *str);
     void gen_all_basis();

     int check_basis(float *str);
     
     char is_rect();
     bool is_basis_col(int j);
     bool is_empty_str(int i);

     float* get_str(int i); //возвращает i-ую строку из матрицы (нужно осовободить память после работы с строкой)
     ~Matr(){
         for(int i=0;i<m;i++){
             free(this->matr[i]);
         }
         free(this->matr);
     }
};

float* Matr::get_str(int i){
   float *temp_str=(float*)malloc(sizeof(float)*m);
   cout << endl;
   for(int j=0;j<m;j++){
       temp_str[j]=matr[i][j];
   }
   return temp_str;
};

void Matr::swap_str(int str1,int str2){
   float temp;
   for(int j=0;j<m;j++){
       temp=matr[str1][j];
       matr[str1][j]=matr[str2][j];
       matr[str2][j]=temp;
    }
};

void Matr::div_str(int i,float div){
    for(int j=0;j<m;j++){
         this->matr[i][j]=this->matr[i][j]/div; 
    };

};

void Matr::mult_str(int i,float mult){
    for(int j=0;j<m;j++){
        this->matr[i][j]=this->matr[i][j]*mult;
    };
};

void Matr::sum_str(int dest,float* str,float mult){
   for(int j=0;j<m;j++) this->matr[dest][j]+=mult*str[j];
};

void Matr::del_str(int i){
    if(i!=(this->n-1)){
        for(int j=i;j<n-1;j++){
            this->matr[j]=this->matr[j+1];
        }
    };
    this->n--;
};

void Matr::scan(){
    float temp;
    cout<<"Введите матрицу размера "<<this->n<<" на "<<this->m<<": "<<endl;
    for(int i=0;i<this->n;i++){
        for(int j=0;j<this->m;j++){
            cin>>temp;
            this->matr[i][j]=temp;
        }
    }
};

void Matr::scan_with_str(float* str){
    float temp;
    cout<<"Введите матрицу размера "<<this->n<<" на "<<this->m+1<<" : "<<endl;
    for(int i=0;i<this->n;i++){
        for(int j=0;j<this->m;j++){
            cin>>temp;
            this->matr[i][j]=temp;
        }
            cin>>temp;
            str[i]=temp;
    }
};


void Matr::print(){
    cout<<endl;
    for(int i=0;i<this->n;i++){
        for(int j=0;j<this->m;j++){
            cout<<setw(4)<<this->matr[i][j]<<" ";
        }
        cout<<endl;
    }
};

char Matr::is_rect(){
    return n==m;
};

bool Matr::is_basis_col(int j){
    //наличие только 1 единицы
    bool flag1=false;
    int count=0;
    //все остальное это нули
    bool flag2=true;
    for(int i=0;i<this->n;i++){
        if(this->matr[i][j]==1) count=count+1;
    }
    if(count==1){
        flag1=true;
        int i=0;
        while(flag2&&(i<this->n)){
            if((this->matr[i][j]!=0)&&(this->matr[i][j]!=1)) flag2=false;
            i++;
        }
    }
    else return false;
    return flag1 && flag2;
};

//Возвращает номер ведущей строки учавствующей в шаге метода Гаусса 
int Matr::gause_step(int prev_resolve_str,float* str){
    bool flag=true;
    // Поиск разрешающего элемента и строки.
    int resolve_el,resolve_str;
     for(int i=0;((i<n)&&flag);i++){
        if(i==prev_resolve_str) continue;
        for(int j=0;((j<m)&&flag);j++){
            if((this->matr[i][j]!=0)&&!this->is_basis_col(j)){
                resolve_el=j;
                resolve_str=i;
                flag=false;
            } 
        }
        i++;
    }
    //Получение ведущей строки
    this->div_str(resolve_str,this->matr[resolve_str][resolve_el]);
    //Преобразующий элемент для дополнительного столбца
    str[resolve_str]=str[resolve_str]/matr[resolve_str][resolve_el];    
    //Преобразование матрицы при помощи ведущей строки
    float* res_str=create_str(m,0.0);
    res_str=this->get_str(resolve_str);
    for(int i=0;i<n;i++){
        if(i==resolve_str) continue;
        str[i]=str[i]+str[resolve_el]*-this->matr[i][resolve_el];
        this->sum_str(i,res_str,-this->matr[i][resolve_el]);
    }
    free(res_str);
    
    return resolve_str;
}

//0 - прервать цикл гаусса, 1 - продолжить.
int Matr::check_basis(float *str){
    if(n>=2){
    //удаление нулевых строк и проверка на совместимость.
    for(int i=0;i<n;i++){
        if(this->is_empty_str(i)){
            if(str[i]==0){
                this->del_str(i);
                for(int j=i;j<n-1;j++){
                    str[j]=j+1;
                }
            }
            else{
                cout<<"Полученная система несовместима. Error";
                exit(1);
            }
        }
    }
    if(n<2){
        cout<<"Полученное уравнение не является системой.";
        return 0;
    }
    else{        
    //проверка на базисность системы.
    int count_basis_columm=0;
    for(int i=0;i<m;i++){
        if(this->is_basis_col(i)){
            count_basis_columm=count_basis_columm+1;
        }
    }
        if(count_basis_columm>=n){
            cout<<"Получена базисная форма"<<endl;
            return 0;
        }
        else{
            return 1;
        }
        
    }
    }
    else{
        cout<<"Полученное уравнение не является системой.";
        return 0;
    }
}

void Matr::to_basis(float *str){
    bool flag=true;
    int prev_str=-1; 
    while(flag){
        flag=this->check_basis(str);
        prev_str=this->gause_step(prev_str,str);
    }
};

bool Matr::is_empty_str(int i){
    int j=0;
    bool flag=true;
    while((j<m-1)&&flag){
       if(this->matr[i][j]!=0) flag=false;
       j++;
    }
    return flag;
}

void Matr::print_with_str(float* str){
    cout<<endl;
    for(int i=0;i<this->n;i++){
        for(int j=0;j<this->m;j++){
            cout<<setw(4)<<this->matr[i][j]<<" ";
        }
        cout<<setw(4)<<str[i]<<" ";
        cout<<endl;
    }
}

int Matr::all_basis_step(int i,int j,float* str){
    this->div_str(i,this->matr[i][j]);
    str[i]=str[i]/matr[i][j];    
    float* res_str=create_str(m,0.0);
    res_str=this->get_str(resolve_str);
    for(int k=0;k<n;k++){
        str[k]=str[k]+str[j]*-this->matr[k][j];
        this->sum_str(k,res_str,-this->matr[k][j]);
    }
    free(res_str);
    
    return resolve_str;
}


int main(){
    int n,m;
    cout<<"Input count of str - ";
    cin>>n;
    cout<<"Input count of columns - ";
    cin>>m;
    float* str=create_str(n,3);
    Matr test(n,m);
    test.scan_with_str(str);
    test.to_basis(str);
    test.print_with_str(str);
    return 0;
}
