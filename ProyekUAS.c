#include <stdio.h>
#include <math.h>

// Menghitung nilai kapasitas kalor c(T) pada suhu T tertentu
double heatCapacity(double T) {
    return 0.132 + (1.56e-4 * T) + (2.64e-7 * T * T);
}

// Menghitung integral dari fungsi menggunakan Aturan Trapesium
double trapezoidalRule(double T1, double T2, int n) {
    // Hitung lebar setiap segmen (step size), h
    double h = (T2 - T1) / n;

    // Inisialisasi jumlah (sum) dengan nilai fungsi di titik awal dan akhir
    double sum = heatCapacity(T1) + heatCapacity(T2);

    // Lakukan iterasi untuk menjumlahkan nilai fungsi di titik-titik tengah
    for (int i = 1; i < n; i++) {
        double xi = T1 + i * h;
        sum += 2 * heatCapacity(xi);
    }

    // Kalikan hasil akhir dengan (h/2) untuk mendapatkan luas total
    return (h / 2.0) * sum;
}

int main() {
    const double m = 1000.0;     // Massa material dalam gram 
    const double T1 = -100.0;    // Suhu awal dalam Celcius 
    const double T2 = 200.0;     // Suhu akhir dalam Celcius 
    const double analytical_solution = 42732.0; // Nilai eksak dari solusi analitik 

    printf("=========================================================\n");
    printf("   Kalkulator Panas Total (delta H) - Metode Trapesium\n");
    printf("=========================================================\n");
    printf("Menghitung panas untuk menaikkan suhu %.1f g material dari %.1f C ke %.1f C.\n", m, T1, T2);
    printf("Fungsi Kapasitas Kalor: c(T) = 0.132 + 1.56e-4*T + 2.64e-7*T^2\n\n");

    printf("Solusi Analitik (Eksak): %.0f kalori\n\n", analytical_solution);

    // Array segmen untuk diuji
    int segments[] = {10, 20, 50, 100, 200, 500, 1000};
    int num_segments = sizeof(segments) / sizeof(segments[0]);

    printf("=== Hasil Aturan Trapesium ===\n");
    printf("Segmen\t\tIntegral\t\tDelta H (kal)\t\tError (%%)\n");
    printf("----------------------------------------------------------------\n");

    for (int i = 0; i < num_segments; i++) {
        int n = segments[i];
        
        // Hitung nilai integral menggunakan Aturan Trapesium
        double integral_value = trapezoidalRule(T1, T2, n);
        
        // Hitung total panas
        double delta_H_numerical = m * integral_value;
        
        // Hitung error relatif
        double relative_error = fabs((delta_H_numerical - analytical_solution) / analytical_solution) * 100.0;
        
        printf("%d\t\t%.6f\t\t%.3f\t\t\t%.6f\n", n, integral_value, delta_H_numerical, relative_error);
    }

    printf("\n=== Demonstrasi Langkah demi Langkah (10 segmen) ===\n");
    int demo_n = 10;
    double h = (T2 - T1) / demo_n;
    printf("Lebar segmen h = (%.0f - (%.0f))/%d = %.1f C\n", T2, T1, demo_n, h);
    printf("\nTitik temperatur dan nilai c(T):\n");
    printf("i\tT(C)\t\tc(T)\t\tKoef\t\tc(T)*Koef\n");
    printf("--------------------------------------------------------\n");
    
    double sum = 0.0;
    
    // Titik awal dan akhir (koefisien 1)
    double T_start = T1;
    double c_start = heatCapacity(T_start);
    sum += c_start;
    printf("0\t%.1f\t\t%.6f\t1\t\t%.6f\n", T_start, c_start, c_start);
    
    // Titik tengah (koefisien 2)
    for (int i = 1; i < demo_n; i++) {
        double T_i = T1 + i * h;
        double c_i = heatCapacity(T_i);
        double contribution = 2 * c_i;
        sum += contribution;
        printf("%d\t%.1f\t\t%.6f\t2\t\t%.6f\n", i, T_i, c_i, contribution);
    }
    
    // Titik akhir
    double T_end = T2;
    double c_end = heatCapacity(T_end);
    sum += c_end;
    printf("%d\t%.1f\t\t%.6f\t1\t\t%.6f\n", demo_n, T_end, c_end, c_end);
    
    double integral_demo = (h / 2.0) * sum;
    double delta_H_demo = m * integral_demo;
    
    printf("\nJumlah = %.6f\n", sum);
    printf("Integral = (%.6f * %.1f) / 2 = %.6f\n", sum, h, integral_demo);
    printf("Delta H = %.0f * %.6f = %.0f kalori\n", m, integral_demo, delta_H_demo);
    
    printf("==========================================================\n");

    return 0;
}