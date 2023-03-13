#include<stdio.h>
#include<stdint.h>
#include<time.h>
#include<stdlib.h>

// mang bat ky vd arr ={1,7,8,2,3,8,3,7,6,7,8,8,2}
// sap xep mang theo thu tu tang dan
// liet ke cac phan tu co so lan xuat hien giong nhau

typedef struct{
    uint8_t size;
    uint8_t *firstAdd;
}typeArray;

int randomA(int minN, int maxN){
    return minN + rand()%(maxN+1-minN);
}

void randomArray(typeArray *value, uint8_t length){
    srand((int)time(0));
    value->size = length;
    value->firstAdd = (uint8_t *)malloc(sizeof(uint8_t)*value->size);
    int r;
    for (int i = 0; i < value->size; i++)
    {
        value->firstAdd[i] = randomA(0,10);
    }
    
}
// sap xep mang
#if 0
void sortArr(typeArray *arr){
    for (int i = 0; i < (arr->size)-1; i++)
    {
        for (int j = i+1; j < arr->size; j++)
        {
            if(arr->firstAdd[i]>arr->firstAdd[j]){
                uint8_t temp = arr->firstAdd[i];
                arr->firstAdd[i]=arr->firstAdd[j];
                arr->firstAdd[j] = temp;
            }
        }
        
    }
    

}
int main(int argc, char const *argv[])
{
   typeArray arr;
   randomArray(&arr, 20);
   for (int i = 0; i < arr.size; i++)
   {
    printf("a[%d] = %d\n",i,arr.firstAdd[i]);
   }
   sortArr(&arr);
   printf("Mang sau khi sap xep sortArr la:\n");
    for (int i = 0; i < arr.size; i++)
    {
        printf(" %d ", arr.firstAdd[i]);
    }

    return 0;
}
#endif
// Dem so lan xuat hien
// cach 1
#if 0
void sortArr(typeArray *arr )  
{
    for(int i=0; i< (arr->size)-1; i++)
    {
        for(int j=i+1; j< arr->size ; j++)
        {
            if(arr->firstAdd[i] > arr->firstAdd[j])
            {
                uint8_t temp = arr->firstAdd[i];
                arr->firstAdd[i] = arr->firstAdd[j];
                arr->firstAdd[j] = temp;               
            }

        }
    }

}

void countArr(typeArray *arr)
{
    int dem=1;
    for(int i=0; i < arr->size ; i++)
    {  
        if (arr->firstAdd[i] == arr->firstAdd[i+1] )
        {
            dem ++;
        }
        if(arr->firstAdd[i] != arr->firstAdd[i+1])
          {
            printf("\nSo %d xuat hien %d lan",arr->firstAdd[i], dem);
            dem=1;
          } 
    }      
}

int main(int argc, char const *argv[])
{
    typeArray arr;

    randomArray(&arr, 10);

    for (int i = 0; i < arr.size; i++)
    {
        printf("arr[%d] = %d\n",i, arr.firstAdd[i]);
    }
    
    sortArr(&arr);
    printf("-Mang sau khi sap xep sortArr:\n");
    for (int i = 0; i < arr.size; i++)
    {
        printf("arr[%d] = %d, ",i, arr.firstAdd[i]);
    }

    countArr(&arr);

    return 0;
}
#endif
#if 0
//cach 2
void countArr(typeArray *arr)
{
    int dem1=0;
    for(int i=0; i< arr->size; i++)
    {
        if(arr->firstAdd[i]==0)
        {
            dem1++;    
        }
    }
    printf("so 0 xuat hien %d lan\n", dem1);

    int dem2=1;
    for(int i= 0; i< arr->size; i++)
    {
        if(arr->firstAdd[i] !=0)
        {
        for(int j=i+1; j< arr->size; j++)
        {
           if(arr->firstAdd[i] == arr->firstAdd[j])  
            {
              dem2++;                                
              arr->firstAdd[j]= 0;
            }
            if(j==(arr->size)-1)     
            {
                printf("so %d xuat hien %d lan\n", arr->firstAdd[i], dem2);
                dem2 =1;
            }
        }
        }
    }
}

int main(int argc, char const *argv[])
{
    typeArray arr;

    randomArray(&arr, 10);

    for (int i = 0; i < arr.size; i++)
    {
        printf("arr[%d] = %d\n",i, arr.firstAdd[i]);
    }
    
    countArr(&arr);

    return 0;
}
#endif
#if 1
int evenValuearr(typeArray *arr){
    for (int i = 0; i < arr->size; i++)
    {
        if(arr->firstAdd[i]%2==0)
        printf(" %d\n", arr->firstAdd[i]);
    } 
    return -1;
}
int lastEvenValuearr(typeArray *arr)
{
    for (int i = (arr->size)-1; i >= 0; i--)
    {
        if(arr->firstAdd[i]%2==0)
        return  arr->firstAdd[i];
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    typeArray arr;
    randomArray(&arr, 20);
    for (int i = 0; i < arr.size; i++)
    {
        printf("a[%d]= %d\n", i, arr.firstAdd[i]);
    }
    printf("gia tri chan cua mang la: ");
    evenValuearr(&arr);
    printf("gia tri chan cuoi cung cua mang la: %d",lastEvenValuearr(&arr));
}
#endif
#if 0
void valuemaxArr(typeArray *arr){
  int b[100]={0};
  int max =0;
  for (int i = 0; i < arr->size; i++)
  {
    for (int j = 0; i < 100; j++)
    {
        if(arr->firstAdd[i]==j){
            b[j]++;
        }
        if(b[j]>max)
        max = b[j];
    }
    
  }
  for (int j = 0; j < 100; j++)
  {
    if(b[j]==max)
    printf("so %d xuat hien nhieu nhat %d lan\n", j, max);
  }
}
int main(int argc, char const *argv[])
{
    typeArray arr;
    randomArray(&arr, 20);
    for (int i = 0; i < arr.size; i++)
    {
    printf("a[%d]= %d\n", i, arr.firstAdd[i]);
    }
   valuemaxArr(&arr);
    return 0;
}
#endif