#include <iostream>

template <typename T>
void selectionsort( T data[], int n)
{
    int j, least;
    for(int i = 0; i < n-1; i++)
    {
        for(j = i+1, least=i; j<n; j++)
            if(data[j] < data[least])
                least = j;
        std::swap(data[least], data[i]);        
    }
} 

int main()
{
    int Data[5] = {5,1,2,3,4};
    float Data1[5] = {7.7,6.6,9.9,8.8,10.10};
    for(int i = 0; i < 5; i++)
    {
        std::cout << "Itens do vetor: " << Data[i] << "\n";
    }
    selectionsort(Data, 5);
    for(int i = 0; i < 5; i++)
    {
        std::cout << "Itens do vetor(Organizados): " << Data[i] << "\n";
    }   
    for(int i = 0; i < 5; i++)
    {
        std::cout << "Itens do vetor: " << Data1[i] << "\n";
    }
    selectionsort(Data1, 5);
    for(int i = 0; i < 5; i++)
    {
        std::cout << "Itens do vetor(Organizados): " << Data1[i] << "\n";
    }   
    
    return 0;
}