#include <stdio.h>
#include <math.h>
int main(){
/*üs alma*/
    double taban,kuvvet,sonuc;
    /*kullanıcıda kı sayı alıyorum*/
    printf("taban degerini giriniz : ");
    scanf("%lf", &taban);
    printf("kuvvet degerını gırınız: ");
    scanf("%lf", &kuvvet);
    /*taban ve kuvvet degerını hesaplıyorum*/

    sonuc = pow(taban,kuvvet);

    printf("%.2lf ^ %.2lf = %.2lf", taban,kuvvet,sonuc);

    /*kare kök alma*/
    double sayı,karekök;
    printf("karekökü hesaplanacak sayıyı giriniz: ");
    scanf("lf", &sayı);
    /*sayının karekökunu hesapla*/
    karekök =sqrt(sayı);

    /*sonucu yazdır*/
    printf("%.2lf sayının karekökü = %.2lf",sayı,karekök);
    return 0;





    

}
