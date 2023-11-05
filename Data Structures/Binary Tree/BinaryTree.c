#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
}*root;

void create();
void insert();
void ins_right();
void ins_left();
void display();
void search();

int data, length, choice;


int main()
{
    root = NULL;
    printf("\t \t Binary Tree \n");
    create();

    do
    {
        printf("What do you want to do: \n");
        printf("1.Insertion   2.Deletion   3.Display   4.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert();
                break;

            case 2:
                break;

            case 3:
                display(root);
                printf("\n");
                break;

            case 4:
                return 0;
                break;

            default:
                printf("Choose the correct option");
                break;
        }
    }while(choice != 4);

    return 0;
}

void create()
{
    printf("Creating...\n");
    printf("Enter no of elements to insert: ");
    scanf("%d", &length);
    
    for (int i = 0; i < length; i++)
    {
        printf("Enter the %d element: ", i+1);
        scanf("%d", &data);
        if(root == NULL)
        {
            root = malloc(sizeof(struct node));
            root->data = data;
            root->left = NULL;
            root->right = NULL;
        }
        else if (root->left != NULL)
        {
            ins_left(&(root->left), data);
        }
        else
        {
            ins_right(&(root->right), data);
        }
    }

    display(root);
    printf("\n");
    
}

void ins_left(struct node **temp, int data)
{
    if(*temp == NULL)
    {
        *temp = malloc(sizeof(struct node));
        (*temp)->data = data;
        (*temp)->left = NULL;
        (*temp)->right = NULL;
    }
    else if ((*temp)->left == NULL)
    {
        ins_left(&((*temp)->left), data);
    }
    else
    {
        ins_right(&((*temp)->right), data);
    }
}

void ins_right(struct node **temp, int data)
{
    if(*temp == NULL)
    {
        *temp = malloc(sizeof(struct node));
        (*temp)->data = data;
        (*temp)->left = NULL;
        (*temp)->right = NULL;
    }
    else if ((*temp)->left == NULL)
    {
        ins_left(&((*temp)->left), data);
    }
    else
    {
        ins_right(&((*temp)->right), data);
    }
}

struct node *create_node(int value) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node *insert_node(struct node *root, int value) {
    if (root == NULL) {
        return create_node(value);
    }
    if (root->left == NULL) {
        root->left = create_node(value);
    } else if (root->right == NULL) {
        root->right = create_node(value);
    } else {
        if (rand() % 2 == 0) {
            root->left = insert_node(root->left, value);
        } else {
            root->right = insert_node(root->right, value);
        }
    }
    return root;
}

void insert()
{
    display(root);
    printf("Enter value to inser: ");
    scanf("%d", &data);

    root = insert_node(root, data);
}

void display(struct node *temp)
{
    if(temp == NULL)
    {
        return;
    }
    printf("%d-> ", temp->data);
    display(temp->left);
    display(temp->right);
}