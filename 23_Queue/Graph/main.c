#include "Graph.h"
int main(void)
{
    int allTop,allEdge;
        FILE *file;

        file = fopen("Graph.txt", "r");
        if(file == NULL)
        {
            fprintf(stderr, "err\n");
            exit(1);
        }

        fscanf(file,"%d %d\n",&allTop,&allEdge);

        Node **list=NULL;
        list=(Node **)malloc(allTop*sizeof(Node *));
        if(list==NULL){
            fprintf(stderr,"err\n");
            exit(1);
        }

        for(int i=0;i<allTop;i++){

            list[i]=NULL;
        }
        for(int i=0;i<allEdge;i++){
            int a,b;
            fscanf(file,"%d %d",&a,&b);
            addList(&list[a-1],b-1);
            addList(&list[b-1],a-1);

        }

        for(int i=0;i<allTop;i++){
            printf("%d-",i+1);
            printfs(list[i]);
            printf("\n");

        }

        for(int i=0;i<allTop;i++){

            clears(&list[i]);
        }
        free(list);

    return 0;
}

