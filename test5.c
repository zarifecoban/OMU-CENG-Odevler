#include <stdio.h>
#include <math.h>

int main(){
    float ana_para,zaman,faiz_oranı,faiz_miktarı,birlesık_faiz_miktarı;
    
    
    printf("ana para mıktarını gırınız: ");
    scanf("%f",&ana_para);

    printf("zamanı giriniz: ");
    scanf("%f",&zaman);

    printf("faiz oranı giriniz: ");
    scanf("%f",&faiz_oranı);


    /*basit faiz hesapı*/
    faiz_miktarı=(ana_para*zaman*faiz_oranı)/100;

    printf("basit faiz hesapı ile hesaplanan faiz miktarı = %f\n",faiz_miktarı);


    /*bilesik faiz hesapı*/
    birlesık_faiz_miktarı = ana_para * (pow((1 + faiz_oranı / 100),zaman));

    printf("bırlesık faiz mıktarı = %f",birlesık_faiz_miktarı);

    return 0;

    

}
