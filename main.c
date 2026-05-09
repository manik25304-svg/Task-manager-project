#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_TASKS 100
#define MAX_LEN 256
#define FILE_NAME "tasklinelists.txt"

typedef struct {
    int id;
    char description[MAX_LEN];
    int done;  // 0 = pending, 1 = done
} Task;

void get_file_path(char *path, size_t size) {
    const char *home = getenv("HOME");    
    if (!home) home = getenv("USERPROFILE"); 
    if (!home) home = ".";                   

    snprintf(path, size, "%s/"FILE_NAME, home);
}

void add(char* arg){
    char* path=(char*)malloc(256*sizeof(char));
    get_file_path(path,256);
    FILE* F=fopen(path,"r");
    Task p;
    p.id=1;
    strncpy(p.description,arg,256);
    p.done=0;
    if(F!=NULL){
        char line[256];
        while(fgets(line,256,F)!=NULL){
            p.id++;
                                        }
        fclose(F); 
    }
     
    F=fopen(path,"a");
    if(F==NULL){
        printf("File not found error ");
        return;
    }
    fprintf(F,"%d|%s|not_done\n",p.id,p.description);
    fclose(F);
    free(path);

}

void list_tasks(){
    char* path=(char*)malloc(256*sizeof(char));
    get_file_path(path,256);
    FILE* F=fopen(path,"r");
    if(F==NULL){
        printf("File not found error ");
        return;
    }
    char line[256];
    while(fgets(line,256,F)!=NULL){
        printf("%s \n",line);
    }
    fclose(F);
    free(path);

}
void mark_done(int no){
    if(no<=0){printf("Invalid task number\n"); return; }
    char* path=(char*)malloc(256*sizeof(char));
    get_file_path(path,256);
    FILE* F=fopen(path,"r");
    if(F==NULL){
        printf("File not found error ");
        fclose(F);
        return;
    }
    Task T[256];
    char line[256];
    int i=0;
    char d[16];
    while(fgets(line,256,F)!=NULL){
        sscanf(line,"%d|%[^|]|%s",&T[i].id,T[i].description,d);
        if(strcmp(d,"done")==0) T[i].done=1;
        i++;
    }
    if(no>i){ printf("Task %d does not exist\n", no); return; }
    T[no-1].done=1;

    fclose(F);
    F=fopen(path,"w");
    for(int j=0;j<i;j++){
        if(T[j].done==1)
        fprintf(F,"%d|%s|done\n",T[j].id,T[j].description);
        else fprintf(F,"%d|%s|not_done\n",T[j].id,T[j].description);
    }
    fclose(F);
    free(path);

}

void delete(int no){
    if(no<=0){printf("Invalid task number\n"); return; }
    char* path=(char*)malloc(256*sizeof(char));
    get_file_path(path,256);
    FILE* F=fopen(path,"r");
    if(F==NULL){
        printf("File not found error ");
        return;
    }
    Task T[256];
    char line[256];
    int i=0;
    char d[16];
    while(fgets(line,256,F)!=NULL){
        sscanf(line,"%d|%[^|]|%s",&T[i].id,T[i].description,d);
        if(strcmp(d,"done")==0) T[i].done=1;
        i++;
    }
    fclose(F);
    if(no>i-1){ printf("Task %d does not exist\n", no); return; }
    F=fopen(path,"w");
    for(int j=0;j<i;j++){
        if(j==(no-1)) continue;
        if(T[j].done==1)
        fprintf(F,"%d|%s|done\n",T[j].id,T[j].description);
        else fprintf(F,"%d|%s|not_done\n",T[j].id,T[j].description);
    }
    fclose(F);
    free(path);

}



int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: todo [add|list|done|delete]\n");
        return 1;
    }

    if (strcmp(argv[1], "add") == 0)        add(argv[2]);
    else if (strcmp(argv[1], "list") == 0)  list_tasks();
    else if (strcmp(argv[1], "done") == 0)  mark_done(atoi(argv[2]));
    else if (strcmp(argv[1], "delete") == 0) delete(atoi(argv[2]));

    return 0;
}
