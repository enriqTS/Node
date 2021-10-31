#include <string.h>
#include <iostream>

using namespace std;

void bubble (char *item, int count);
void shaker (char *item, int count);
void selection (char *item, int count);
void insertion (char *item, int count);
void shell (char *item, int count);
void quick (char *item, int count);
void qs (char *item, int left, int right);
void peneira (int p, int m, int v[]); 
void heapsort (char* v, int count);
void intercala (int p, int q, int r, char* v);
void mergesort (int p, int r, char* v);

void peneira2 (int p, int m, int v[]); 
void heapsort2 (char* v, int count);


int main (){
   char s[80];
   cout << "Digite uma string: ";
   cin.getline(s,80);

   //bubble(s, strlen(s));
   //shaker(s, strlen(s));
   //selection (s, strlen(s));
   //insertion (s, strlen(s));
   //shell (s, strlen(s));
   quick(s, strlen(s));
   //heapsort2(s,strlen(s));
   //mergesort(0, strlen(s), s);
   
   cout << "String ordenada : " << s << endl;
   
   return 0;
   
}

// BUBLE SORT
void bubble (char *item, int count){
  register int a, b;
  register char t;
  for(a=1;a<count;++a)
	 for (b=count-1; b>=a; --b)
		  if(item[b-1]>item[b]){
			  /*troca os elementos*/
			  t = item[b-1];
			  item[b-1]=item[b];
			  item[b] = t;
		  }
}

// SHAKER SORT
void shaker (char *item, int count){
  register int a;
  register char t;
  int change;
  do {
      change = 0;
      for(a=count-1;a>0;--a)
  	     if(item[a-1]>item[a]){
			  /*troca os elementos*/
			  t = item[a-1];
			  item[a-1]=item[a];
			  item[a] = t;
			  change = 1;
		 }
      //for(a=1;a>count;--a)
      for(a=1;a<count;++a)
  	     if(item[a-1]>item[a]){
			  /*troca os elementos*/
			  t = item[a-1];
			  item[a-1]=item[a];
			  item[a] = t;
			  change = 1;
		 }
  }while (change);
}

// SELECTION SORT
void selection (char *item, int count){
  register int a,b,c;
  register char t;
  int change;
  for(a=0;a<count-1;++a){
     change = 0;
     c = a;
     t = item[a];
     for (b=a+1; b<count;++b)
         if (item[b] < t){
            c = b;
            t = item[b];
            change = 1;
         }
     if (change){
        item[c] = item[a];
        item[a] = t;
        }
  }
}


// INSERTION SORT
void insertion (char *item, int count){
  register int a,b;
  register char t;

  for(a=1;a<count;++a){
     t = item[a];
     for (b=a-1; b>=0 && t<item[b];b--)
         item[b+1] = item[b];
     item[b+1] = t;
  }
}

// SHELL
void shell (char *item, int count){
  register int i, j, gap, k;
  register char x, a[5];

  // Defininção do gap
  a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

  for (k=0; k <5; k++){
      gap = a[k];
      for (i=gap; i<count; i++){
          x = item[i];
          for(j=i-gap; x<item[j] && j>=0; j=j-gap)
              item[j+gap] = item[j];
          item[j+gap] = x;
      }
  }
}

// QUICK SORT
void quick (char *item, int count){
     qs (item, 0, count-1);     
}
void qs (char *item, int left, int right){
  register int i, j;
  register char x, y;
  i = left; j = right;
  x = item[(left+right)/2];
  do {
      while(item[i]<x && i<right) i++;
      while(x<item[j] && j>left) j--;
      if (i<=j){
          y = item[i];
          item[i] = item[j];
          item[j] = y;
          i++; j--;      
      }
  } while (i<=j);
  if(left<j) qs (item, left, j);
  if(i<right) qs (item, i, right);   
}

// HEAP SORT
void peneira (int p, int m, char* v){ 
   int x = v[p];
   while (2*p <= m) {
      int f = 2*p;
      if (f < m && v[f] < v[f+1])  ++f;
      if (x >= v[f]) break;
      v[p] = v[f];
      p = f;
   }
   v[p] = x;
}


void peneira2 (int p, int m, char* v){ 
   int x = v[p];
   int j = (2*p)+1;
   while (j <= m) {
      if(j < m)
        if(v[j] < v[j+1])
          j++;
      if(x < v[j]){
		v[p] = v[j];
		p = j;
		j = (2*p)+1;  
	  }
      else j = m + 1;
   }
   v[p] = x;
}

void heapsort2 (char* v, int count){
   int p, m, x;
   for (p = (count-1)/2; p >= 0; p--)
      peneira2 (p, count-1, v);
   for (m = count-1; m >= 1; m--) {
      x = v[0], v[0] = v[m], v[m] = x;
      peneira2 (0, m-1, v);
   }
}


void heapsort (char* v, int count){
   int p, m, x;
   for (p = count/2; p >= 0; --p)
      peneira (p, count, v);
   for (m = count; m >= 2; --m) {
      x = v[1], v[1] = v[m], v[m] = x;
      peneira (1, m-2, v);
   }
}

// MERGE SORT
void intercala (int p, int q, int r, char* v){
   int i, j, k, *w;
   w = new int[r-p];
   i = p; j = q;
   k = 0;
   while (i < q && j < r) {
      if (v[i] <= v[j])  w[k++] = v[i++];
      else  w[k++] = v[j++];
   }
   while (i < q)  w[k++] = v[i++];
   while (j < r)  w[k++] = v[j++];
   for (i = p; i < r; ++i)  v[i] = w[i-p];
   delete [] w;
}

// A função mergesort rearranja o vetor v[p..r-1] em ordem crescente.
void mergesort (int p, int r, char* v){
   if (p < r-1) {
      int q = (p + r)/2;
      mergesort (p, q, v);
      mergesort (q, r, v);
      intercala (p, q, r, v);
   }
}
