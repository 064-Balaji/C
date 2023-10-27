#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
}*root;

void insright();

void insleft(struct node **temp, int data){
    if(*temp == NULL){
        *temp = malloc(sizeof(struct node));
        (*temp)->data = data;
        (*temp)->left = NULL;
        (*temp)->right = NULL;
         
    }
    else if((*temp)->data > data){
        insleft(&((*temp)->left), data);
         
    }
    else{
        insright(&((*temp)->right), data);
         
    }
}

void insright(struct node **temp, int data){
    if(*temp == NULL){
        *temp = malloc(sizeof(struct node));
        (*temp)->data = data;
        (*temp)->left = NULL;
        (*temp)->right = NULL;
         
    }
    else if((*temp)->data < data){
        insright(&((*temp)->right), data);
         
    }
    else{
        insleft(&((*temp)->left), data);
         
    }
}

void create(){
    int data = 1;
    while(data != 0){
        printf("Enter data to insert: " );
        scanf("%d", &data);
        if(root == NULL){
            root = malloc(sizeof(struct node));
            root->data = data;
            root->left = NULL;
            root->right = NULL;
        }
        else if(root->data > data){
            insleft(&(root->left), data);
        }
        else{
            insright(&(root->right), data);
        }
    }
}
void display(struct node *temp){
    if(temp == NULL){
         return;
    }
    printf("%d ->", temp->data);
    display(temp->left);
    display(temp->right);
}


int main(){
    printf("Welcome\n");
    create();
    display(root);
    return 0;
}
