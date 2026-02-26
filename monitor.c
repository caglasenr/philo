/*
GitHub Copilot

Tamam — monitöre geçmek için kısa, uygulanabilir bir yol haritası:

- Amaç
  - Her filozofun son yeme zamanını izle, herhangi biri time_to_die süresini aşarsa bir kere "died" yazdır ve simülasyonu durdur.
  - Eğer herkes gerekli sayıda yemeyi tamamladıysa monitör düzgün şekilde bitirsin (program ana döngüsüne/senaryosuna haber versin).

- Gerekli veri/struct alanları (t_table ve filozof struct'ında)
  - table->start_time (başlangıç zaman)
  - table->time_to_die (ms)
  - table->must_eat_count (opsiyonel, varsa tümünün yemesini kontrol etmek için)
  - table->print_mutex, table->is_dead (ve/veya table->finished)
  - filosofa ait: last_meal_time (struct timeval veya ms), meals_eaten (int), id
  - erişim için gerekli mutex’ler: en az print_mutex + her filin last_meal/mutex veya ortak bir mutex (philos mutex)

- Monitör thread imzası
  - void *monitor_routine(void *arg) — arg genelde t_table* veya wrapper struct (table ve philo array).

- Algoritma (ana döngü)
  1. Döngü: while (!table->is_dead && !table->finished) { ... }
  2. Her iterasyonda tüm filozofları dolaş:
     - mutex ile ilgili filozofun last_meal_time ve meals_eaten değerlerini oku (yarış koşulunu önle).
     - şu anki zaman - last_meal_time > time_to_die ise:
       - mutex ile table->is_dead kontrol et; eğer false ise is_dead = true; çağır print_action(table, id, "died");
       - unlock ve monitör thread'ten çık.
     - Eğer must_eat_count aktifse, sayacı kontrol et ve tümü >= must_eat_count ise table->finished = 1 ve çık.
  3. Döngü içinde kısa uyutma: usleep(1000) veya usleep(500) — busy-wait azaltmak için (1 ms iyi başlangıç).
  4. Döngüden çıkınca thread sonlanır; ana program bu duruma göre threadleri join edip temizler.

- Kilitleme stratejisi
  - Okuma için kısa süreli kilitleme: sadece last_meal ve meals_eaten okumak için gerekli mutex’i alıp hemen bırak.
  - Yazma (is_dead, finished) yaparken table->print_mutex veya ortak mutex ile koru.
  - print_action zaten kendi içinde print_mutex kullanıyorsa, monitör önce is_dead set edip sonra print_action çağırmak (veya print_action death durumunu tekil yazma olarak yapıyorsa sadece print_action çağırmak) yeterli.

- Zaman hesaplama
  - gettimeofday ile ms cinsinden now - start_time hesaplayan yardımcı fonksiyon kullan.
  - last_meal zamanını da ms cinsine veya timeval olarak tut; karşılaştırma aynı birimde olmalı.

- Nerede oluşturulur
  - Filozof threadleri oluşturulduktan sonra monitör thread yarat:
    - pthread_create(&monitor_tid, NULL, monitor_routine, table);
    - Program sonlanırken pthread_join(monitor_tid, NULL);

- Kenar durumlar
  - gettimeofday hatasına karşı tolerans.
  - Çok sık uyutma (çok küçük usleep) CPU tüketir, çok büyük uyutma ölüm tespitinde gecikme yapar — ~500–2000 µs arası uygundur.
  - print ve is_dead atomic davranışına dikkat et: ölüm bir kere bildirilmeli.

İstersen bu adımlardan yola çıkarak monitor_routine fonksiyonunun C halini yazayım. Hangisini tercih edersin: kodu ben yazayım mı yoksa sen mi denersin?

*/