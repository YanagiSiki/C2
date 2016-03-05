#include <stdio.h>
#include <string.h>
#include<math.h>
#define ShapeText(TYPE) char name[10];float (*perimeter)(struct TYPE*);float (*area)(struct TYPE*)

typedef struct _Shape {
  ShapeText(_Shape);
} Shape;

typedef struct _Circle {
  ShapeText(_Circle);
  float radius;
} Circle;

typedef struct _Rectangle {
  ShapeText(_Rectangle);
  float width;
  float length;
} Rectangle;

typedef struct _Square {
  ShapeText(_Square);
  float width;
} Square;

typedef struct _Triangle {
  ShapeText(_Triangle);
  float width1;
  float width2;
  float width3;
} Triangle;

float ShapeArea(Shape *obj) { return 0; }
float ShapePerimeter(Shape *obj) { return 0; }

void ShapeNew(Shape *obj) {
  strcpy(obj->name,"shape");
  obj->perimeter = ShapePerimeter;
  obj->area = ShapeArea;
}

float CircleArea(Circle *obj) {  return 3.14 * obj->radius * obj->radius; }
float CirclePerimeter(Circle *obj) { return 2*3.14 * obj->radius; }

void CircleNew(Circle *obj) {
  strcpy(obj->name,"circle");
  obj->perimeter = CirclePerimeter;
  obj->area = CircleArea;
}

float RectangleArea(Rectangle *obj) { return (obj->length * obj->width); }
float RectanglePerimeter(Rectangle *obj) { return (2*(obj->length + obj->width));}

void RectangleNew(Rectangle *obj) {
  strcpy(obj->name,"rectangle");
  obj->perimeter = RectanglePerimeter;
  obj->area = RectangleArea;
}

float SquareArea(Square *obj) { return (obj->width * obj->width); }
float SquarePerimeter(Square *obj) { return (2*(obj->width + obj->width));}

void SquareNew(Square *obj) {
  strcpy(obj->name,"square");
  obj->perimeter = SquarePerimeter;
  obj->area = SquareArea;
}

float TriangleArea(Triangle *obj) {
    float m=obj->perimeter(obj)/2;
    return sqrt(m*(m- (obj->width1))*(m- (obj->width2))* (m- (obj->width3)));
}
float TrianglePerimeter(Triangle *obj) { return obj->width1 + obj->width2 + obj->width3;}

void TriangleNew(Triangle *obj) {
  strcpy(obj->name,"triangle");
  obj->perimeter = TrianglePerimeter;
  obj->area = TriangleArea;
}

int main() {
  int i,n=0;
  char word;
  scanf("%d%*c",&n);
  float Allarea=0,Allperimeter=0;

  Shape shape[n];
  Circle circle[n];
  Rectangle rectangle[n];
  Square square[n];
  Triangle triangle[n];

  for(i=0;i<n;i++){
    scanf("%c",&word);
    ShapeNew(&shape[i]);
    if(word=='C'){
        //return 1;
        scanf("%*c%f%*c",&circle[i].radius);
        CircleNew(&circle[i]);
        shape[i].area=circle[i].area;
        shape[i].perimeter=circle[i].perimeter;
        printf("%.2f,%.2f\n",shape[i].perimeter(&circle[i]),shape[i].area(&circle[i]));
        Allarea+=shape[i].perimeter(&circle[i]);
        Allperimeter+=shape[i].area(&circle[i]);
    }
    if(word=='R'){
        //return 2;
        scanf("%*c%f",&rectangle[i].width);
        scanf("%*c%f%*c",&rectangle[i].length);
        RectangleNew(&rectangle[i]);
        shape[i].area=rectangle[i].area;
        shape[i].perimeter=rectangle[i].perimeter;
        printf("%.2f,%.2f\n",shape[i].perimeter(&rectangle[i]),shape[i].area(&rectangle[i]));
        Allarea+=shape[i].perimeter(&rectangle[i]);
        Allperimeter+=shape[i].area(&rectangle[i]);
    }
    if(word=='S'){
        //return 3;
        scanf("%*c%f%*c",&square[i].width);
        SquareNew(&square[i]);
        shape[i].area=square[i].area;
        shape[i].perimeter=square[i].perimeter;
        printf("%.2f,%.2f\n",shape[i].perimeter(&square[i]),shape[i].area(&square[i]));
        Allarea+=shape[i].perimeter(&square[i]);
        Allperimeter+=shape[i].area(&square[i]);
    }
    if(word=='T'){
        //return 4;
        scanf("%*c%f",&triangle[i].width1);
        scanf("%*c%f",&triangle[i].width2);
        scanf("%*c%f%*c",&triangle[i].width3);
        TriangleNew(&triangle[i]);
        shape[i].area=triangle[i].area;
        shape[i].perimeter=triangle[i].perimeter;
        printf("%.2f,%.2f\n",shape[i].perimeter(&triangle[i]),shape[i].area(&triangle[i]));
        Allarea+=shape[i].perimeter(&triangle[i]);
        Allperimeter+=shape[i].area(&triangle[i]);
    }
  }


  printf("%.2f,%.2f\n",Allarea,Allperimeter);

  system("PAUSE");
}
