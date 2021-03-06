#include <stdio.h>
#include <malloc.h>
#define FIN "matrix.in"

void freeMatrix(int **mat, int n) {

     int i; 

     for(i = 0; i < n; ++i) {

        free(mat[i]);
     }  

     free(mat);
}

void* readMatrix(int *a, int *b) {

      int i, j;
      freopen(FIN, "r", stdin);

      scanf("%d %d", a, b);

      int n, m; 
          n = *a; 
          m = *b;

       //pointer to pointer
      int **mat = NULL;

      //allocate memory for rows;
      mat = (int **)malloc(sizeof(int*) * n);
      
      //allocate memory for colls
      for(i = 0; i < n; ++i) {

          mat[i] = (int*)malloc(sizeof(int) * m);
      }

      for(i = 0; i < n; ++i) {

      	  for(j = 0; j < m; ++j) {
              
      	  	  scanf("%d ", &mat[i][j]);      	  	  
      	  }
      }
        
      return mat;
};

void display(int **mat, int n, int m) {

      int i, j; 

      printf("\n----\n");

      for(i = 0; i < n; ++i) {

      	  for(j = 0; j < m; ++j) {

      	  	  printf("%d ", mat[i][j]);
      	  }
      	  printf("\n");
      }

      printf("\n----\n");
}

void* sum(int **mat1, int **mat2, int n, int m) {
      int **sum;
      int i, j;

      sum = (int**)malloc(sizeof(int*)*n);

      for(i = 0; i < n; ++i) sum[i] = (int*)malloc(sizeof(int*)*m);

      for(i = 0; i < n; ++i) {

      	  for(j = 0; j < m; ++j) {

      	  	  sum[i][j] = mat1[i][j] + mat2[i][j];
      	  }
      }        	
      return sum;
}

int main(int argc, char const *argv[])
{
  int **mat, **m1, **m2;	 
  int n, m;  
  m1 = (int**)readMatrix(&n,&m);	 
  display(m1, n, m);  
  m2 = (int**)readMatrix(&n,&m);  
  display(m2, n, m);
  mat = sum(m1,m2, n, m);  
  display(mat, n, m);
  
  //clean up
  freeMatrix(m1,n);
  freeMatrix(m2,n);
  freeMatrix(mat,n);
  return 1;
}

