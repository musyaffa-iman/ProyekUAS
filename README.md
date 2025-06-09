# Kalkulator Panas Total dengan Metode Aturan Trapesium

Proyek ini merupakan implementasi metode numerik Aturan Trapesium (Trapezoidal Rule) untuk menyelesaikan studi kasus perhitungan panas total dalam mata kuliah Pemrograman Numerik.

**Nama:** Musyaffa Iman Supriadi
**NPM:** 2306208464

---

## Deskripsi Program

[cite_start]Program ini dibuat dalam bahasa C untuk menghitung jumlah panas total ($\Delta H$) yang diperlukan untuk menaikkan suhu suatu material dari suhu awal ($T_1$) ke suhu akhir ($T_2$).  Perhitungan ini didasarkan pada kapasitas kalor material, $c(T)$, yang nilainya berubah terhadap suhu dan dimodelkan sebagai fungsi polinomial.

Metode numerik yang digunakan adalah **Aturan Trapesium**, di mana area di bawah kurva fungsi $c(T)$ diaproksimasi dengan menjumlahkan luas dari sejumlah segmen berbentuk trapesium.

### Studi Kasus

- **Massa Material ($m$):** 1000 g
- **Suhu Awal ($T_1$):** -100 °C
- **Suhu Akhir ($T_2$):** 200 °C
- **Fungsi Kapasitas Kalor:**
  $$ c(T) = 0.132 + 1.56 \times 10^{-4}T + 2.64 \times 10^{-7}T^2 $$

### Fitur Program

Program ini memiliki beberapa fungsi utama:
1.  **Menghitung Panas Total:** Mengalkulasi nilai $\Delta H$ secara numerik menggunakan Aturan Trapesium.
2.  **Analisis Error:** Membandingkan hasil numerik dengan solusi analitik (eksak) untuk menghitung persentase error.
3.  **Variasi Segmen:** Menampilkan hasil perhitungan untuk berbagai jumlah segmen ($n$) untuk menunjukkan bagaimana akurasi meningkat seiring bertambahnya jumlah segmen.
4.  **Demonstrasi Langkah-demi-Langkah:** Menyajikan rincian proses perhitungan untuk 10 segmen untuk menunjukkan cara kerja algoritma secara transparan.
