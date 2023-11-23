#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct
{
    int key;
    int data;
}Hashnode;

Hashnode *HashTable[SIZE];

void hashTable(){
    for (int i = 0; i < SIZE; i++)
    {
        HashTable[i] = NULL;
    }
}

int hasFunction(int key){
    return key= key % SIZE;
}

void insert(int key, int data){
    int index = hasFunction(key);
    
    while (HashTable[index] != NULL && HashTable[index]->data != -1)
    {
        index = hasFunction(key+1);
    }

    HashTable[index] = (Hashnode *)malloc(sizeof(Hashnode));
    HashTable[index]->data = data;
    HashTable[index]->key = key;
}

void search(int key){
    int index = hasFunction(key);
    while (HashTable[index] != NULL)
    {
        if(HashTable[index]->key == key){
            printf("%d\n", HashTable[index]->data);
        }
        index = hasFunction(index + 1);
    }    
}

int main(){
    int length, key, data;
    printf("Enter no of element want to insert: ");
    scanf("%d", &length);
    for(int i=0; i<length; i++){
        printf("Enter %d Key: ", i);
        scanf("%d", &key);
        printf("Enter the Value: ");
        scanf("%d", &data);

        insert(key, data);
    }

    printf("Enter the key to Find: ");
    scanf("%d", &key);
    search(key);
}