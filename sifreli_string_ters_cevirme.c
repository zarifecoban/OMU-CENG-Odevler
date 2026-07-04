#include<stdio.h>

int main(){
    char giriş_sifresi[] = "kahve";
    char *ptr = giriş_sifresi;
    int sifre = 4231;
    int sifre_tahmini;
    int i;

    printf("lutfen tahmın ettıgınız sıfreyı gırınız: ");
    scanf("%d",&sifre_tahmini);

    if (sifre_tahmini == sifre)
    {
        for(i=4;i>=0;i--)
        {
            printf("%c",*(ptr+i));

        }
    }
    else
    {
        printf("giris engellendi");
    }
    return 0;
}
