#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct term{
    int i,j,val;//stores value and i j pos of each term
};
struct mat{
    int row;
    int col;
    int n;//number of non-zero elements
    struct term *t;//will store elements in a series
};
void display(struct mat *p);
struct mat* transpose(struct mat *m);
void create(struct mat **ml);

int main(){
  struct mat *mt;
  create(&mt);
  display(mt);
  struct mat *trans=(struct mat*)malloc(sizeof(struct mat));
  trans=transpose(mt);
  printf("transpose of matrix is\n");
  display(trans);
  return 0;
}
void display(struct mat *p){
    int row=p->row;
    int col=p->col;
    int c=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(p->t[c].i==i && p->t[c].j==j){
                printf("%d ",p->t[c].val);
                c++;
                /*since elements are stored in proper i and j sequence only 2 loops required*/
            }
            else{
                printf("0 ");
            }
        }printf("\n");
    }
}
struct mat* transpose(struct mat *m){
        int size=m->n;
        int row=m->row;
        int col=m->col;
        int k=0;
        struct mat *tmp=m;
        struct mat *trans=(struct mat*)malloc(sizeof(struct mat));
        trans->col=row;
        trans->row=col;
        trans->t=(struct term*)malloc((m->n)*sizeof(struct term));
        for(int i=0;i<col;i++){
            for(int j=0;j<row;j++){
               for(int c=0;c<size;c++){
                    if(tmp->t[c].j==j){
                        /*interchanging the i and j values 
                        and storing the transpose elements in a sequence
                        because we are printing the array in a sequence*/
                        trans->t[i].j=tmp->t[c].i;
                        trans->t[i].i=tmp->t[c].j;
                        trans->t[i].val=tmp->t[c].val;
                        i++;
                        tmp->t[c].j=-1;
                    }
               }
            }
        }
    return trans;

}
void create(struct mat **ml){
    int n;
    int num;
    int c=0;
    int z;
    int row,col;
    struct mat *m;
    m=(struct mat*)malloc(sizeof(struct mat));
    printf("enter the number of rows\n");
    scanf("%d",&row);
    printf("enter the number of columns\n");
    scanf("%d",&col);
    m->col=col;
    m->row=row;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("enter the element");
            scanf("%d",&num);
            if(num!=0)
            {
                c++;
                m->t=(struct term*)realloc(m->t,c*sizeof(struct term));
                /*whenever entered element is not 0 we realloc the m->t array 
                and place i and j values and the num value*/
                m->t[c-1].i=i;
                m->t[c-1].j=j;
                m->t[c-1].val=num;
                 
            }
        }
    }
    m->n=c;
    *ml=m;//pointing the passed variable to created pointer
}
