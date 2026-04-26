#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* content;
const char* keyword[]={"if","else","for","while","int","char","long","return"};
typedef struct vector 
{
    char** data;
    size_t size;
    size_t capacity;
}vector;
vector token;
char* GetFileContent(const char* file_name,size_t* size_point){
    FILE* file_point=fopen(file_name,"rb");
    if(file_point==NULL){
        return NULL;
    }
    fseek(file_point,0,SEEK_END);
    *size_point=ftell(file_point);
    rewind(file_point);
    char* buffer=(char*)malloc((*size_point)+1);
    if(buffer==NULL){
        return NULL;
    }
    size_t size_read=fread(buffer,1,*size_point,file_point);
    if(size_read<*size_point){
        printf("ERROR:UNKNOW ERROR WHEN READING THE CODE");
    }
    buffer[size_read]='\0';
    return buffer;
}
void VectorPush(vector *vector_point, char *element)
{
    if(vector_point->size==vector_point->capacity){
        if(vector_point->capacity==0){
            char** data=malloc(4);
        }
        else{
            char** data=realloc(vector_point->data,vector_point->capacity*2);
        }
    }
    vector_point->data[vector_point->size++]=element;
}
char* VectorGet(vector* vector_point,size_t index){
    if(index<0&&index>=vector_point->size){
        printf("ERROR:OUT OF RANGE");
    }
    return vector_point->data[index];
}
void VectorFree(vector* vector_point){
    free(vector_point->data);
    vector_point->data=NULL;
    vector_point->size=0;
    vector_point->capacity=0;
}

int main(int argc,char* argv[]){
    if(argc==1){
        printf("ERROR:NO FILE NAME");
        return 256;
    }
    size_t size;
    content=GetFileContent(argv[1],&size);

    return 0;
}