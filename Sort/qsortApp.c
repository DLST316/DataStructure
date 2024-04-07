#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Point.h"

int ComparePoint( const void *_elem1, const void *_elem2)
{
    Point* elem1 = (Point*)_elem1;
    Point* elem2 = (Point*)_elem2;
    if( elem1->point > elem2->point)
        return 1;
    else if( elem1->point < elem2->point)
        return -1;
    else
        return 0;
}

int main()
{
    int Length = sizeof DataSet / sizeof DataSet[0];
    int i = 0;

    qsort((void*)DataSet, Length, sizeof(Point), ComparePoint);

    for ( i = 0; i < Length; i++)
    {
        printf("%d번째 %d %f\n",i+1, DataSet[i].id, DataSet[i].point);
    }
    printf("%d %f\n", DataSet[14142].id, DataSet[14142].point);

    return 0;
}