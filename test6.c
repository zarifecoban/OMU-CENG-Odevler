#include <stdio.h>
int main(){

/* getchar gırdı ,putchar cıktı ıslemını yapar */
/*getchar bır karekter alır ve saklar sayı degerı almaz */
    char ogrenci_notu;
    printf("ögrenci notunu gırınız: ");

    ogrenci_notu = getchar();/*ogrencı notunu getchar ıle alıyoruz ve ogrencı_notu degıskenınde saklıyoruz*/


    /*putchar() komutu ile notu cıktı olarak ver */
    putchar(ogrenci_notu);

    return 0;
}
