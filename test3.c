#include <stdio.h>
int main(){
    int sayı1 = 17, sayı2 = 5;
    int tamsayı_bolme_sonucu;
    float gercel_sayı_bolme_sonucu_float;
    double gercel_bolme_sonucu_double;
    int gercel_bolme_sonucu_float_tamsayı;

    tamsayı_bolme_sonucu = sayı1/sayı2;
    printf("tamsayı bolme sonucu = %d\n",tamsayı_bolme_sonucu);

    gercel_sayı_bolme_sonucu_float = (float) sayı1/sayı2;
    printf("gercel sayı bolme sonucu = %.20f\n",gercel_sayı_bolme_sonucu_float );

    gercel_bolme_sonucu_double = (double) sayı1/sayı2;
    printf("gercek bolme sonucu (double)= %.20f\n",gercel_bolme_sonucu_double);

    gercel_bolme_sonucu_float_tamsayı = (int) sayı1/sayı2;
    printf("gercek bolme sonucu (float)'un tamsayıya donusturulmus hali = %d\n",gercel_bolme_sonucu_float_tamsayı);







    int a= 35;//10'luk sayı duzenınde(decımal)
    int b = 0b00100011;//2'lık sayı duzenınde (binary)
    int c =0x23;//16'lık sayı duzenınde (hexadecımal)


    printf("a= %d\n",a);
    printf("b=%d\n",b);
    printf("c=%d\n",c);

    


    float cm,metre,km;
    /*uzunlugu cn cınsınden al */
    printf("uzunlugu cm cınsınden gırınız: ");
    scanf("%f",&cm);


    /* cevrım ıslemlerını gerceklestır */
    metre = cm / 100.0;
    km = cm / 100000.0;

    printf("metre cınsınden uzunluk = %.2f m \n",metre);
    printf("km cınsınden uzunluk = %.2f km\n",km);

    return 0;


}
