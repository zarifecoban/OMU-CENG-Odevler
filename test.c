#include <stdio.h>

int main(){
    int dizi[100];
    int n,i;
    int polindrom = 1;//basta dogru kabul edıyoruz
    printf("dızının boyutunu gırınız: ");
    scanf("%d", &n);
    printf("diziyi gir: ");

    for (i = 0; i<n ; i++){
        scanf("%d", &dizi[i]);
    }

    for(i=0 ; i<n/2; i++){
        if(dizi[i] != dizi[n-1-i]){
            polindrom = 0;
            break;
        }
    }
    if (polindrom ==1)
    printf("dizi polındromdur");
    else
    printf("dizi polındrom degıldır");
    return 0;


}

