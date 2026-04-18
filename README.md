## 📝 C Syslog Simulator (Linked List Based)
Bu proje, C programlama dili kullanılarak geliştirilmiş, sistem loglarını simüle eden basit bir Syslog Log Üreticisi uygulamasıdır. Program, log mesajlarını oluşturur, her birine zaman damgası ekler ve bu verileri dinamik bir Bağlı Liste (Linked List) veri yapısında saklar.

## 🚀 Özellikler
Dinamik Veri Yapısı: Loglar, çalışma zamanında (runtime) bağlı liste kullanılarak yönetilir.
Zaman Damgası (Timestamp): Her log mesajı, oluşturulduğu andaki YYYY-MM-DD HH:MM:SS formatındaki tarih ve saat bilgisini içerir.
Bellek Yönetimi: Program sonunda kullanılan tüm bellek alanları (malloc ile ayrılanlar) düzgün bir şekilde temizlenir.
Modüler Yapı: Log ekleme, listeleme ve zaman alma işlevleri fonksiyonlara bölünmüştür.

## 🛠️ Gereksinimler
İşletim Sistemi: Windows (Önerilen) veya Linux.
Derleyici: GCC veya herhangi bir C11 uyumlu derleyici.
Standart: C99 veya C11.

## 📁 Kurulum ve Çalıştırma
Projeyi yerel makinenize klonlamak veya dosyayı indirmek için:
Terminali/Komut İstemcisini açın.
Dosyanın bulunduğu dizine gidin.

1.Aşağıdaki komutu kullanarak kodu derleyin:
   ```Bash
    gcc -std=c11 syslog.c -o syslog
   ```
2. Programı çalıştırın:
   ```Bash
   ./syslog
   ```
## 💻 Örnek Çıktı
Program çalıştığında konsolda aşağıdaki gibi bir çıktı üretecektir:
```Text
Guncel tarih ve saat ile loglar:
[2023-10-27 14:30:05] INFO: Sistem baslatildi
[2023-10-27 14:30:05] WARN: Bellek kullanimi yuksek
[2023-10-27 14:30:05] ERROR: Disk alani yetersiz
[2023-10-27 14:30:05] INFO: Yeni kullanici oturumu acildi
[2023-10-27 14:30:05] ERROR: Ag baglantisi kesildi
```

## 🧠 Kod Yapısı Hakkında
1. Dugum Yapısı: Log metnini ve bir sonraki düğümün adresini tutar.
2. ekle() Fonksiyonu: Yeni bir log mesajını listenin sonuna ekler (O(n) karmaşıklığı).
3. su_an_ki_zamani_al(): time.h kütüphanesini kullanarak sistem saatini biçimlendirilmiş bir stringe dönüştürür.
4. Bellek Temizleme: main fonksiyonunun sonunda tüm düğümler tek tek free() edilerek bellek sızıntısı (memory leak) önlenir.
