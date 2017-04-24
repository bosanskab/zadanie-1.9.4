#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <limits.h>

typedef struct{
	int x;
	int y;
}POINT;

typedef struct{
	int x;
	int y;
}VECTOR;

typedef struct{
	int x;
	int y;
	int vseob;
	int smernica;
}LINE;

void randomAB(POINT *A, POINT *B){
	
	A->x=-50+rand()%100;
	A->y=-50+rand()%100;
	B->x=-50+rand()%100;
	B->y=-50+rand()%100;	
}

void pointC (POINT *A, POINT *B,POINT *C){
	
	C->x=((A->x)+(B->x))/2;
	C->y=((A->y)+(B->y))/2;
}									

char vectorAB (POINT *A, POINT *B, VECTOR *v,VECTOR *n){

	v->x=(B->x)-(A->x);
	v->y=(B->y)-(A->y);
	n->x=(v->y);
	n->y=-(v->x);

}

char point_point_axis(POINT *A, POINT *B,POINT *C, LINE *a,VECTOR *v,VECTOR *n){
	int c1,c2,vysledok;
	char t,x,y;

	c1=-(A->x)*(n->x)-(A->y)*(n->y);
	c2=-(C->x)*(v->x)-(C->y)*(v->y);	
	a->x=(C->x)+(n->x)*t;
	a->y=(C->y)+(n->y)*t;
	a->vseob=(v->x)*x+(v->y)*y+c2;
	a->smernica=((v->x)*x+c2)/-(v->y);

    if ((A->x)==(B->x)&&(A->y)==(B->y))
        vysledok=0;
      else vysledok=1;
  
	return vysledok;
}


main(){
	srand(time(NULL));
	POINT A,B,C;
	VECTOR v,n;
	LINE a;
	int *memory;

memory=malloc(3*sizeof(POINT)+2*sizeof(VECTOR)+sizeof(LINE));

randomAB(&A,&B);
pointC (&A,&B,&C);
vectorAB (&A,&B,&v,&n);	

if (point_point_axis(&A,&B,&C,&a,&v,&n)==1&& memory!=NULL)
       	printf("vypocet prebehol uspesne\n");
   else printf(" vypocet zlyhal\n");
   
void free(void *memory);
}
