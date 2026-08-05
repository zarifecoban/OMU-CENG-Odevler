#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char isim[50]; // Düğümde tutulacak veri (string)
    char telefon[15]; // Düğümde tutulacak veri (string)   
    struct Node* next; // Bir sonraki düğümün bellek adresini tutar
} kisi;

typedef struct {
    kisi* kisiler; // Listenin başını tutan gösterici
    int kapasite; // Listenin kapasitesi
    int kisiSayisi; // Listede bulunan kişi sayısı
} rehber;

void rehberOlustur(rehber* r, int kapasite) {
    r->kapasite = 2; // Başlangıç kapasitesi 2 olarak ayarlanıyor
    r->kisiSayisi = 0;
    r->kisiler = (kisi*)malloc(r->kapasite * sizeof(kisi));


    if (r->kisiler == NULL) {
        printf("Hata: Bellek ayarlanamadı!\n");
        exit(1);
    }
}
void kisiekle(rehber* r, const char* isim, const char* telefon) {
    if (r->kisiSayisi >= r->kapasite) {
        // Kapasiteyi iki katına çıkar
        r->kapasite *= 2;
        r->kisiler = (kisi*)realloc(r->kisiler, r->kapasite * sizeof(kisi));
        printf("\n[sistem] kapsite doldu! yeni kapasite: %d kisi\n", r->kapasite);
    }

    // Yeni kişiyi ekle
    strcpy(r->kisiler[r->kisiSayisi].isim, isim);
    strcpy(r->kisiler[r->kisiSayisi].telefon, telefon);
    r->kisiSayisi++;

    printf("\n-> %s rehbere eklendi!\n", isim);
}
void rehberlistele(rehber*r){
    printf("\n=== REHBER ===\n",r->kisiSayisi,r->kapasite);
    if (r->kisiSayisi == 0) {
        printf("Rehber boş!\n");
        return;
    }
    for (int i = 0; i < r->kisiSayisi; i++) {
        printf("%d. %s - %s\n", i + 1, r->kisiler[i].isim, r->kisiler[i].telefon);
    }
    printf("-------------------------------------\n");
}
void kisiara(rehber* r, const char* aranacakisim) {
    printf("\n-> %s aranıyor...\n", aranacakisim);
    for (int i = 0; i < r->kisiSayisi; i++) {
        if (strcmp(r->kisiler[i].isim, aranacakisim) == 0) {
            printf("\n-> %s bulundu: %s\n", r->kisiler[i].isim, r->kisiler[i].telefon);
            return;
        }
    }
    printf("\n-> %s rehberde bulunamadı!\n", aranacakisim);
}
void rehbertemizle(rehber* r) {
    free(r->kisiler);
    r->kisiler = NULL;
    r->kisiSayisi = 0;
    r->kapasite = 0;
    printf("\n-> Rehber temizlendi!\n");
}
int main() {
    rehber benimRehberim;
    rehberOlustur(&benimRehberim, 2);

    kisiekle(&benimRehberim, "Ahmet", "1234567890");
    kisiekle(&benimRehberim, "Mehmet", "0987654321");
    kisiekle(&benimRehberim, "Ayşe", "5555555555"); // Kapasiteyi artıracak

    rehberlistele(&benimRehberim);

    kisiara(&benimRehberim, "Mehmet");
    kisiara(&benimRehberim, "Ali"); // Bulunamayacak

    rehbertemizle(&benimRehberim);
    return 0;
}
