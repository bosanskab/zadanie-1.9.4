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
	float a;
	float b;
	float c;
}LINE;

void randomAB(POINT *A, POINT *B)
{
	
	srand(time(NULL));
	
	A->x=-5+rand()%10;
	A->y=-5+rand()%10;
	B->x=-5+rand()%10;
	B->y=-5+rand()%10;	
		
}

void pointC (POINT *A,POINT *B,POINT *C)
{	
	C->x=((A->x)+(B->x))/2;
	C->y=((A->y)+(B->y))/2;
	
}									

char vectorAB (POINT *A, POINT *B, VECTOR *v,VECTOR *n)
{
	v->x=(B->x)-(A->x);
	v->y=(B->y)-(A->y);
	n->x=(v->y);
	n->y=-(v->x);	
	
	return 0;
}

char point_point_axis(POINT *A, POINT *B, LINE *p)
{
	float smernica,vseobecna,paramx,paramy;
	int vysledok;
	char t,x,y;
	POINT C;
	VECTOR v,n;
	
	pointC (&A,&B,&C);
	vectorAB (&A,&B,&v,&n);	
	
	p->a=(v.x);
	p->b=(v.y);
	p->c=-((C.x)*(p->a)+(C.y)*(p->b));
		
	paramx=(C.x)+(n.x)*t;
	paramy=(C.y)+(n.y)*t;
	vseobecna=(p->a)*x+(p->b)*y+(p->c);
	smernica=((p->a)*x+(p->c))/-(p->b);

    if ((A->x)==(B->x)&&(A->y)==(B->y))
        vysledok=0;
      		else vysledok=1;
  
	return vysledok;
}


main(){
	POINT A,B;
	LINE p;
	
	randomAB(&A,&B);

	if (point_point_axis(&A,&B,&p)==1)
       	printf("vypocet prebehol uspesne\n");
   		else printf(" vypocet zlyhal\n");
   
   	return 0;  
}
