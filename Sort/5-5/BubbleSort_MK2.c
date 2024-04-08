#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_SIZE 100

void BubbleSort(int DataSet[], int Length)
{
    int i = 0, j = 0, temp = 0;
    int isSorted = 0; // 정렬 여부를 나타내는 변수

    for(i = 0; i < Length - 1; i++)
    {
        isSorted = 1; // 초기값을 1로 설정

        for(j = 0; j < Length - (i + 1); j++)
        {
            if(DataSet[j] > DataSet[j + 1])
            {
                temp = DataSet[j + 1];
                DataSet[j + 1] = DataSet[j];
                DataSet[j] = temp;

                isSorted = 0; // 정렬이 필요한 경우 0으로 설정
            }
        }

        if(isSorted == 1) // 정렬이 이미 완료된 경우
        {
            break; // 함수 종료
        }
    }
}

int main()
{
    int DataSet[ARRAY_SIZE];

    // 난수 생성기 초기화
    srand(time(NULL));

    // 배열을 난수로 채우기
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        DataSet[i] = rand();
    }


    int Length = sizeof (DataSet)/sizeof DataSet[0];

    BubbleSort(DataSet,Length);

    printf("Sort done this is result:\n");
    for (int i = 0; i < Length; ++i)
    {
        printf("%d \n",DataSet[i]);
    }
    printf("\n");

    return 0;
}