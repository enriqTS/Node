#include <iostream>

template <typename T>
void swap( T data[], T data1[])
{
    T tmp[] = data[];
    data[] = data2[];
    data2[] = tmp[];
}

template <typename T>
void selectionsort( T data[], int n)
{
    int j, least;
    for(int i = 0; i < n-1; i++)
    {
        for(j = i+1, least=i; j<n; j++)
            if(data[j < data[least]])
                least = j;
        swap(data[least], data[i]);        
    }
} 

int main()
{
    int Data[5] = {5,1,2,3,4};
    float Data1[5] = {6.6,7.7,9.9,8.8,10.10};
    for(int i = 0; i < 5; i++)
    {
        std::cout << "Itens do vetor: " << Data[i] << "\n";
    }
    selectionsort(Data, 5);
    for(int i = 0; i < 5; i++)
    {
        std::cout << "Itens do vetor(Organizados): " << Data[i] << "\n";
    }    
}