#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
}*root;

void ins_lef();
void ins_rig();
int length, choice, data;

int main(){

    return 0;
}

void create(){
    printf("Enter the no of elements on tree:");
    scanf("%d", &length);

    for(int i=0; i<length; i++){
        printf("Enter the %d value:", i);
        scanf("%d", &data);

        if(root==NULL){
            root = malloc(sizeof(struct node));
            root->data = data;
            root->left = NULL;
            root->right = NULL;
        }

        else if ((root->data)<data)
        {
            ins_lef(root->left, data);
        }

        else{
            ins_rig();
        }
    }
}

void ins_lef(struct node temp, int data){

}