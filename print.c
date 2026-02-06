//filozofların hepsi aynı anda printf çağırabilir bu olmaması için bizim printi kilitlememiz lazım 
//timestamp philid msg
/*
GitHub Copilot

Aşağıda print.c içinde uygulaman gereken mantığı ve dikkat etmen gereken noktaları adım adım anlatıyorum — kod vermiyorum, sen yazarsın.

Amaç
- Filozofların olaylarını (thinking, eating, sleeping, died vb.) zaman damgası ile tek satır halinde konsola yazmak.
- Yazıların karışmasını önlemek (çoklu thread’lerde birbirinin içine girmesin).
- Ölüm durumunda yalnızca bir kere "died" mesajı yazılsın ve sonrası yazmalar engellensin.

Gerekli veri/bağlam
- Proje içinde muhtemelen bir ortak yapı (ör. t_table veya sim) var; içinde başlangıç zamanı (start_time), yazma mutex’i (print_mutex) ve ölüm bayrağı (is_dead) bulunmalı. print fonksiyonları bu yapıya erişmeli.
- Fonksiyon imzası: print fonksiyonu filozof kimliği (id), olay tipi/metin ve ortak yapı işaretçisi almalı.

Zaman damgası
- Konsola yazılacak ilk değer, simülasyon başlangıcından geçen milisaniye olmalı.
- Bunu hesaplamak için gettimeofday veya clock_gettime kullan: şu an - start_time -> ms olarak hesapla.
- Hesaplamayı print fonksiyonu içinde yap; böylece her yazı doğru zamanlı olur.

Eşzamanlılık (thread-safety)
- Tüm yazma işi tek bir mutex ile korunmalı:
  - mutex lock
  - (eğer ölüm için kontrol gerekiyorsa) is_dead kontrol et: zaten dead ise çoğu olayı yazma (death olayları hariç)
  - eğer yazılacak olay "died" ise önce is_dead = true olarak ayarla, sonra yaz
  - formatla ve yaz
  - mutex unlock
- Mutex’i çok uzun süre tutmaktan kaçın: sadece formatlama + write kısmını koru.

Yazma biçimi
- Satır formatı önerisi: "<timestamp> <id> <action>\n" (ör: "123 3 is eating\n")
- Tek seferde yazılacak şekilde hazırlanmış bir tampon kullan; ardından write() çağır. Bu şekilde, alt seviye buffering/printf karışmaları minimize edilir.
- snprintf ile tampon hazırla, sonra write veya dprintf ile tek çağrıda gönder. (printf tek başına thread-safe olsa da çıktıların birbirine girmesini tam güvence altına almak için mutex hâlâ gerekli.)

Death (ölüm) davranışı
- Ölüm mesajı kesinlikle bir kere yazılmalı:
  - print fonksiyonu death durumunu tespit edince mutex içinde is_dead kontrolünü yap, eğer false ise is_dead = true yap ve death mesajını yaz.
  - Diğer thread’ler is_dead true iken başka mesaj yazmamalı (isteğe bağlı olarak bazı projeler sadece death harici tüm mesajları engeller).

Hata ve kenar durumları
- gettimeofday/clock_gettime başarısızlığında mantıklı bir fallback veya 0 ms döndürebilirsin.
- write başarısız olursa genelde program akışını bozmaya gerek yok; ama istersen hata kodunu logla.

Dosya içeriği ve bağımlılıklar
- print.c içinde gereken include’lar: zaman ve thread fonksiyonları, stdio/unistd, string vs. (küçük bir listesi: sys/time.h, time.h veya errno.h, stdio.h, unistd.h, pthread.h, stdlib.h, stdint.h)
- Projendeki ortak başlık (ör. philo.h) ile print fonksiyonunun prototipini ve erişeceği yapı tiplerini kullan.

Özet adımlar (senin yazman için)
1. Ortak yapıdan start_time, print_mutex, is_dead alanlarını belirle.
2. Zaman hesaplama yardımcı fonksiyonu yaz (ms cinsinden).
3. print_action(id, action, sim_struct*) şeklinde fonksiyon oluştur.
4. Fonksiyonda mutex lock → is_dead kontrol ve/veya set → satırı formatla → tek write çağrısı → mutex unlock.
5. Death olayı için özel kontrol: set is_dead önce, yaz sonra.
6. Gerekirse küçük helper’lar/prototipler header’a ekle.

İstersen dosya yapısı/başlık isimleri ve ortak yapı isimleri hakkında proje dosyalarını söyle, hangi struct alanlarını kullanacağına dair daha somut öneri vereyim.
*/
#include "philo.h"

void    print_status(t_philo *philo, char *msg)
{
    long long now;
    now = get_time();
}