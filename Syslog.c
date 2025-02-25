#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_UZUNLUK 1024

// Bagli liste dugum yapisi
typedef struct Dugum {
    char veri[MAX_LOG_UZUNLUK];
    struct Dugum* sonraki;
} Dugum;

// Yeni dugum olusturma fonksiyonu
Dugum* yeni_dugum_olustur(const char* veri) {
    Dugum* yeni_dugum = (Dugum*)malloc(sizeof(Dugum));
    if (yeni_dugum == NULL) {
        perror("Bellek tahsisi basarisiz oldu");
        exit(1);
    }
    strncpy(yeni_dugum->veri, veri, MAX_LOG_UZUNLUK);
    yeni_dugum->sonraki = NULL;
    return yeni_dugum;
}

// Bagli listeye dugum ekleme fonksiyonu
void ekle(Dugum** bas, const char* veri) {
    Dugum* yeni_dugum = yeni_dugum_olustur(veri);
    if (*bas == NULL) {
        *bas = yeni_dugum;
    } else {
        Dugum* mevcut = *bas;
        while (mevcut->sonraki != NULL) {
            mevcut = mevcut->sonraki;
        }
        mevcut->sonraki = yeni_dugum;
    }
}

// Bagli listeyi ekrana yazdirma fonksiyonu
void goster(Dugum* bas) {
    Dugum* mevcut = bas;
    while (mevcut != NULL) {
        printf("%s", mevcut->veri);
        mevcut = mevcut->sonraki;
    }
}

// Guncel tarih ve saat bilgisi alma fonksiyonu
void su_an_ki_zamani_al(char* buffer, size_t boyut) {
    time_t simdi = time(NULL);
    struct tm* t = localtime(&simdi);
    strftime(buffer, boyut, "%Y-%m-%d %H:%M:%S", t);
}

int main() {
    Dugum* bas = NULL;
    char log_satir[MAX_LOG_UZUNLUK];
    char zaman_buffer[20];

    // ornek log mesajlari
    const char* log_mesajlari[] = {
        "INFO: Sistem baslatildi",
        "WARN: Bellek kullanimi yuksek",
        "ERROR: Disk alani yetersiz",
        "INFO: Yeni kullanici oturumu acildi",
        "ERROR: Ag baglantisi kesildi"
    };

    size_t log_mesaj_sayisi = sizeof(log_mesajlari) / sizeof(log_mesajlari[0]);

    // Guncel tarih ve saat ile loglar olusturma
    for (size_t i = 0; i < log_mesaj_sayisi; ++i) {
        su_an_ki_zamani_al(zaman_buffer, sizeof(zaman_buffer));
        snprintf(log_satir, MAX_LOG_UZUNLUK, "[%s] %s\n", zaman_buffer, log_mesajlari[i]);
        ekle(&bas, log_satir);
    }

    printf("Guncel tarih ve saat ile loglar:\n");
    goster(bas);

    // Hafizayi temizleme
    Dugum* mevcut = bas;
    Dugum* sonraki_dugum;
    while (mevcut != NULL) {
        sonraki_dugum = mevcut->sonraki;
        free(mevcut);
        mevcut = sonraki_dugum;
    }

    return 0;
}

