#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <limits.h>

typedef struct{
	float x;
	float y;
}POINT;

typedef struct{
	float x;
	float y;
}VECTOR;

typedef struct{
	float x;
	float y;
	float vseob;
	float smernica;
}LINE;

void randomAB(POINT *A, POINT *B)
{
	A->x=-5+rand()%10;
	A->y=-5+rand()%10;
	B->x=-5+rand()%10;
	B->y=-5+rand()%10;	
		
	return 0;
}

void pointC (POINT *A, POINT *B,POINT *C)
{	
	C->x=((A->x)+(B->x))/2;
	C->y=((A->y)+(B->y))/2;
	
	return 0;
}									

char vectorAB (POINT *A, POINT *B, VECTOR *v,VECTOR *n)
{
	v->x=(B->x)-(A->x);
	v->y=(B->y)-(A->y);
	n->x=(v->y);
	n->y=-(v->x);	
	
	return 0;
}

char point_point_axis(POINT *A, POINT *B,POINT *C, LINE *a,VECTOR *v,VECTOR *n)
{
	float c;
	int vysledok;
	char t,x,y;

	c=-((C->x)*(v->x)+(C->y)*(v->y));
		
	a->x=(C->x)+(n->x)*t;
	a->y=(C->y)+(n->y)*t;
	a->vseob=(v->x)*x+(v->y)*y+c;
	a->smernica=((v->x)*x+c)/-(v->y);

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

	randomAB(&A,&B);
	pointC (&A,&B,&C);
	vectorAB (&A,&B,&v,&n);	

	if (point_point_axis(&A,&B,&C,&a,&v,&n)==1)
       	printf("vypocet prebehol uspesne\n");
   		else printf(" vypocet zlyhal\n");
   
   	return 0;  
}
