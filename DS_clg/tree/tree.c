#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
}*root;


void insleft(struct node *root, int data){
    struct node *temp;
    root->left = malloc(sizeof(struct node));
    temp = root->left;
    if(temp->left != NULL){
        insleft(temp, data);
    }
    temp->data =data;
}

void create(){
    int data = 1;
    while(data != 0){
        printf("Enter data to insert: ");
        scanf("%d", &data);
        if(root == NULL){
            root = malloc(sizeof(struct node));
            root->data = data;
            root->left = NULL;
            root->right = NULL;
        }
        else if((root->data)>data){
            if(root->left != NULL){
                insleft(root, data);
            }
        }
    }
}

void display(){
    struct node *temp;
    temp = root;
    while(temp->left == NULL){
        printf("%d",temp->data);
        temp= temp->left;
    }
}

int main(){
    printf("Welcome\n");
    create();
    display();
    return 0;
}