#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_gorev 50
#define DOSYA_adi "gorevler.txt"
typedef enum {
    BEKLIYOR,
    DEVAM_EDIYOR,
    TAMAMLANDI
} Durum;    

typedef struct {
    int id;
    char baslik[100];
    Durum durum;
} Gorev;

gorev liste[MAX_gorev];
int gorev_sayisi = 0;

const char* durumMetni(Durum d) {
    switch (d) {
        case BEKLIYOR: return "Bekliyor";
        case DEVAM_EDIYOR: return "Devam Ediyor";
        case TAMAMLANDI: return "Tamamlandı";
        default: return "Bilinmiyor";
    }
}

void dosyaoku() {
    FILE *file = fopen(DOSYA_adi, "r");
    if (file == NULL) {
        printf("Dosya acilamadi.\n");
        return;
    }
    gorev_sayisi = 0;
    while (fscanf(file, "%d;%99[^;];%d\n", &liste[gorev_sayisi].id,
        liste[gorev_sayisi].baslik, (int*)&liste[gorev_sayisi].durum) != EOF) {
        gorev_sayisi++;
        if (gorev_sayisi >= MAX_gorev) break;
    }

    fclose(file);
    printf("%d gorev dosyadan okundu.\n", gorev_sayisi);
}

void dosyayaz() {
    FILE *file = fopen(DOSYA_adi, "w");
    if (file == NULL) {
        printf("Dosya acilamadi.\n");
        return;
    }
    for (int i = 0; i < gorev_sayisi; i++) {
        fprintf(file, "%d;%s;%d\n", liste[i].id, liste[i].baslik, liste[i].durum);
    }
    fclose(file);
    printf("%d gorev dosyaya yazildi.\n", gorev_sayisi);
}
void gorev_ekle() {
    if (gorev_sayisi >= MAX_gorev) {
        printf("Gorev listesi dolu.\n");
        return;
    }

    Gorev yeni ;
    yeni.id = gorev_sayisi + 1;
    printf("Gorev basligini giriniz: ");
    getchar();//klavyeden girilen '\n' karakterini temizler
    fgets(yeni.baslik, sizeof(yeni.baslik), stdin);
    yeni.baslik[strcspn(yeni.baslik, "\n")] = 0; // '\n' karakterini kaldırır
    yeni.durum = BEKLIYOR;

    liste[gorev_sayisi++] = yeni;
    printf("Gorev eklendi: %s\n", yeni.baslik);
    dosyayaz();//anlık olarak dosyaya kaydet       
}
void gorev_listele() {
    printf("\n=======================Gorev Listesi=======================\n");
    if (gorev_sayisi == 0) {
        printf("Gorev listesi bos.\n");
        return;
    }
    for (int i = 0; i < gorev_sayisi; i++) {
        printf("[%d] %-30s | Durum: %s\n",
             liste[i].id, liste[i].baslik, durumMetni(liste[i].durum));
    }
    printf("\n==========================================\n");
}
void durumguncelle() {
    int id,secim;
    printf("Durumunu guncellemek istediginiz gorevin ID'sini giriniz: ");
    scanf("%d", &id);

    if (id < 1 || id > gorev_sayisi) {
        printf("Gecersiz ID.\n");
        return;
    }
    printf("Yeni durumu seciniz:\n");
    printf("0. Bekliyor\n");   
    printf("1. Devam Ediyor\n");
    printf("2. Tamamlandi\n");
    printf("Seciminizi yapiniz: ");
    scanf("%d", &secim);
    if (secim < 0 || secim > 2) {
        printf("Gecersiz secim.\n");
        return;
    }
    liste[id - 1].durum = (Durum)secim;
    printf("Gorev durumu guncellendi: %s\n", id);
    dosyayaz();//anlık olarak dosyaya kaydet
}

int main() {
    dosyaoku();
    int secim;
    do {
        printf("\n=======================To-Do Yonetici=======================\n");
        printf("0. Gorev Ekle\n");
        printf("1. Gorev Listele\n");
        printf("2. Gorev Durumunu Guncelle\n");
        printf("3. Cikis\n");
        printf("Seciminizi yapiniz: ");
        scanf("%d", &secim);

        switch (secim) {
            case 0:
                gorev_ekle();
                break;
            case 1:
                gorev_listele();
                break;
            case 2:
                durumguncelle();
                break;
            case 3:
                printf("Cikis yapiliyor...\n");
                break;
            default:
                printf("Gecersiz secim. Tekrar deneyin.\n");
        }
    } while (secim != 3);

    return 0;
}
