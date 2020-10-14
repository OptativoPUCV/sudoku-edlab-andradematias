#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          fscanf (file, "%d", &n->sudo[i][j]);
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
   
   int i,j, u;

    int a[10];

    for (u = 0 ; u < 10 ; u++) {
      a[u] = 0;
    }
    
    for (i = 0 ; i < 10 ; i++) {
      for (j = 0 ; j < 10 ; j++) {  
            if (n->sudo[i][j] != 0) {
               if (a[n->sudo[i][j]] != 0) {
                   return 0;
                } else {
                  a[n->sudo[i][j]] = 1; 
                }    
            }
      for (u = 0 ; u < 9 ; u++) {
      a[u] = 0;
      }         
    }
  }

    for (i = 0 ; i < 10 ; i++) {
      for (j = 0 ; j < 10 ; j++) {  
            if (n->sudo[j][i] != 0) {
               if (a[n->sudo[j][i]] != 0) {
                   return 0;
                } else {
                  a[n->sudo[j][i]] = 1; 
                }    
            }
      for (u = 0 ; u < 10 ; u++) {
      a[u] = 0;
      }         
    }
  }

    int k,p;
   
    for (k = 0; k < 10 ; k++) {
        for(p=0;p<10;p++){
            if (n->sudo[i][j] != 0) {
              if (a[n->sudo[i][j]] != 0) {
                return 0;
              } else {
                a[n->sudo[i][j]] = 1;
              }
            
            }
            }
            i=3*(k/3) + (p/3);
            j=3*(k%3) + (p%3);            
            if(p == 8) {
                for (i = 0 ; i < 9 ; i++) {
                a[i] = 0;
                }                
            }
        }



  return 1;
}


List* get_adj_nodes(Node* n){
    List* list=createList();
    int i, j, k;  

    for (i = 0 ; i < 9 ; i++) {      
      for (j = 0 ; j < 9 ; j++) {        
        if (n->sudo[i][j] == 0) {
          for (k = 1 ; k <= 9 ; k++) {
            Node *adj_node = copy(n);
            adj_node->sudo[i][j] = k;
            pushBack(list, adj_node);
          }
          return list;
        }
      }
    }
    return list;    
}


int is_final(Node* n){    
    int i, j;
    for (i = 0 ; i < 9 ; i++) {
      for (j = 0 ; j < 9 ; j++) {
        if (n->sudo[i][j] == 0) return 0;
      }
    }
    
    return 1;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/