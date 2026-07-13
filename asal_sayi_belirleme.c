#include <stdio.h>
int main(){
    int sayı;
    int i;
    int asalmı = 1;

    printf("lutfen kullanıcıdan bır sayı gırınız ");
    scanf("%d",&sayı);

    if (sayı <= 1){
        asalmı = 0;
    }else{
        for (i=2;i<=sayı/2; i++){
            if(sayı % i == 0){
                asalmı = 0 ;
                break;
            }

        }
        
    }

if(asalmı == 1){
    printf("%d bir asal sayıdır. \n ",sayı);
}else{
    printf("%d bir asal sayı ddegildir.\n",sayı);
}
return 0;
}
