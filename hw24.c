#include <stdio.h>
#include <string.h>
#include <math.h>
#define ShapeText(TYPE) \
    char name[10];\
    float (*perimeter)(struct TYPE*);\
    float (*area)(struct TYPE*)

int pow_num(int x, int y){
    for(int i=0;i<y-1;i++){
        x *= x;
    }
    return x;
}

float RoundNum(float x, int y){
    int temp = x*pow_num(10,y+1);
    float ans;
    if(temp%10 >= 5){
        ans = (temp/10 + 1)/pow_num(10,y);
    }
    else ans=temp/pow_num(10, y);
    return ans;
}
typedef struct shape_s {
    ShapeText(shape_s);
    int radius,lenth,width,edge0,edge1,edge2;
} shape_t;

float CirclePerimeter(shape_t *obj){return RoundNum( 2* 3.14 * obj->radius,2);}
float RectanglePerimeter(shape_t *obj){return RoundNum(2 * (obj->lenth + obj->width), 2);}
float SquarePerimeter(shape_t *obj){return RoundNum(4 * obj->edge0, 2);}
float TrianglePerimeter(shape_t *obj){return RoundNum(obj->edge0 + obj->edge1 + obj->edge2, 2);}
float CircleArea(shape_t *obj){return RoundNum(3.14 * obj->radius * obj->radius, 2);}
float RectangleArea(shape_t *obj){return RoundNum(obj->lenth * obj->width, 2);}
float SquareArea(shape_t *obj){return RoundNum(obj->edge0 * obj->edge0, 2);}
float TriangleArea(shape_t *obj){
    float s=(obj->edge0+obj->edge1+obj->edge2)/2;
    return RoundNum(sqrt(s*(s-obj->edge0)*(s-obj->edge1)*(s-obj->edge2)), 2);
}
void ShapeNew(shape_t *obj,char shapeName[10])
{
    strcpy(obj->name, shapeName);
    if(strcmp(obj->name, "Circle")==0){
        obj->perimeter = CirclePerimeter;
        obj->area = CircleArea;
    }
    else if(strcmp(obj->name, "Rectangle")==0){
        obj->perimeter = RectanglePerimeter;
        obj->area = RectangleArea;
    }
    else if(strcmp(obj->name, "Square")==0){
        obj->perimeter = SquarePerimeter;
        obj->area = SquareArea;
    }
    else if(strcmp(obj->name, "Triangle")==0){
        obj->perimeter = TrianglePerimeter;
        obj->area = TriangleArea;
    }
    else printf("wrong name\n");
}

int main(){
    int n,radius,lenth,width,edge0,edge1,edge2;
    float sumP=0,sumA=0;
    shape_t shapeData[5];
    shape_t *list[5];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char shape_type;
        scanf(" %c",&shape_type);
        switch (shape_type)
        {
        case 'C':
            scanf("%d",&radius);
            ShapeNew(&shapeData[i], "Circle");
            shapeData[i].radius = radius;
            printf("%d\n",radius);
            break;
        case 'R':
            scanf("%d %d",&lenth,&width);
            ShapeNew(&shapeData[i], "Rectangle");
            shapeData[i].lenth = lenth;
            shapeData[i].width = width;
            printf("%d %d\n",lenth,width);
            break;
        case 'S':
            scanf("%d",&edge0);
            ShapeNew(&shapeData[i], "Square");
            shapeData[i].edge0 = edge0;
            printf("%d\n",edge0);
            break;
        case 'T':
            scanf("%d %d %d",&edge0,&edge1,&edge2);
            ShapeNew(&shapeData[i], "Triangle");
            shapeData[i].edge0 = edge0;
            shapeData[i].edge1 = edge1;
            shapeData[i].edge2 = edge2;
            printf("%d %d %d\n",edge0,edge1,edge2);
            break;
        default:
            printf("wrong input\n");
            break;
        }
    }
    for(int i=0;i<n;i++){
        printf("%f %f\n", shapeData[i].perimeter(&shapeData[i]), shapeData[i].area(&shapeData[i]));
    }
}