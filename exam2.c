#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define shapeText(TYPE) \
    char name[10]; \
    int (*perimeter)(struct TYPE*); \
    int (*area)(struct TYPE*);

typedef struct shape_s { shapeText(shape_s); } shape_s;

typedef struct shapeData{
    char type[10];
    int perimeter;
    int area;
}shapeData;

typedef struct circle_s {
    shapeText(circle_s);
    int radius;
} circle_t;
typedef struct rectangle_s
{
    shapeText(rectangle_s);
    int width, height;
} rectangle_t;
typedef struct square_s{
    shapeText(square_s);
    int side;
} square_t;
typedef struct triangle_s {
    shapeText(triangle_s);
    int s1, s2, s3;
} triangle_t;
int circle_per(circle_t *obj){return obj->radius *2 *4;}
int circle_area(circle_t *obj){return obj->radius * obj->radius * 4;}
int rectangle_per(rectangle_t *obj){return (obj->width + obj->height)*2;}
int rectangle_area(rectangle_t *obj){return obj->width * obj->height;}
int square_per(square_t *obj){return obj->side *4;}
int square_area(square_t *obj){return obj->side * obj->side;}
int triangle_per(triangle_t *obj){return obj->s1 + obj->s2 + obj->s3;}
int triangle_area(triangle_t *obj){
    int s = (obj->s1 + obj->s2 + obj->s3)/2;
    return (int) sqrt(s*(s-obj->s1)*(s-obj->s2)*(s-obj->s3));
}
int comepare(const void *a,const void *b){
    shapeData *A = (shapeData*)a;
    shapeData *B = (shapeData*)b;
    if(A->perimeter != B->perimeter) return A->perimeter - B->perimeter;
    else return A->area - B->area;
}
int main() {
    int N;
    scanf("%d", &N);
    shapeData data[N];
    for(int i = 0; i < N; i++){
        char type[10];
        scanf(" %s", type);
        if(strcmp(type,"circle")==0){
            circle_t circle;
            scanf(" %d", &circle.radius);
            strcpy(data[i].type, "circle");
            data[i].perimeter = circle_per(&circle);
            data[i].area = circle_area(&circle);
        }
        else if(strcmp(type,"rectangle")==0){
            rectangle_t rect;
            scanf(" %d %d",&rect.width, &rect.height);
            strcpy(data[i].type, "rectangle");
            data[i].perimeter = rectangle_per(&rect);
            data[i].area = rectangle_area(&rect);
        }
        else if(strcmp(type,"square")==0){
            square_t square;
            scanf(" %d", &square.side);
            strcpy(data[i].type, "square");
            data[i].perimeter = square_per(&square);
            data[i].area = square_area(&square);
        }
        else if(strcmp(type,"triangle")==0){
            triangle_t tri;
            scanf(" %d %d %d", &tri.s1, &tri.s2, &tri.s3);
            strcpy(data[i].type, "triangle");
            data[i].perimeter = triangle_per(&tri);
            data[i].area = triangle_area(&tri);
        }
    }
    qsort(data,N,sizeof(shapeData),comepare);
    int total_per=0,total_area=0;
    for(int i = N-1; i>=0; i--){
        total_per += data[i].perimeter;
        total_area += data[i].area;
        printf("%s %d %d\n", data[i].type, data[i].perimeter, data[i].area);
    }
    printf("%d %d\n", total_per, total_area);
    return 0;
}
