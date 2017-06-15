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
	POINT C;
	VECTOR v,n;
	
	pointC (A,B,&C);
	vectorAB (A,B,&v,&n);	
	
	p->a=(v.x);
	p->b=(v.y);
	p->c=-((C.x)*(p->a)+(C.y)*(p->b));
		
}


main(){
	POINT A,B;
	LINE p;
	int vysledok;
	
	randomAB(&A,&B);	
	if ((A.x)==(B.x)&&(A.y)==(B.y))
		vysledok=0;
		else vysledok=1;
	
	if (vysledok==0){
   		printf(" vypocet zlyhal\n");
		return 0; 
	}
		
   point_point_axis(&A,&B,&p);
       	printf("vypocet prebehol uspesne\n");
   	
   	return 0;  
}
