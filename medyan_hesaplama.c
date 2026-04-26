#include <stdio.h>

int main(){
    int n ,j,i;

    int dizi[n];
    printf("diziyi aralarında bosluk bırakarak giriniz :");
    for(i=0;i<n ; i++);{
        scanf("%d",&dizi[i]);
            if(dizi[j]=dizi[n-j])
            printf("palidrom sayıdır");
        }

    
    


}

#include <stdio.h>

int main() {
    int n, i, j, gecici;

    printf("Kac sayi gireceksin: ");
    scanf("%d", &n);

    int dizi[n];

    printf("Sayilari gir ama aralarında bosluk bırak: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &dizi[i]);
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < n - 1; j++) {
            if(dizi[j] > dizi[j + 1]) {
                gecici = dizi[j];
                dizi[j] = dizi[j + 1];
                dizi[j + 1] = gecici;
            }
        }
    }

    float median;

    if(n % 2 == 0) {
        median = (dizi[n/2] + dizi[n/2-1 ]) / 2.0;
    } else {
        median = dizi[n/2];
    }

    printf("Median: %f\n", median);

    

    return 0;
}
