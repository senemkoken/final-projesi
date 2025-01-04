#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

struct ders sonucAl(struct ders x);
void hedefKontrol(struct ders y);
float netHesaplama(struct ders z);

struct ders
{
    char isim[20];
    int dk;
    int dogru;
    int yanlis;
    int bos;
    float sure;
    float hdfSure;
};

struct ders t = {"T�RK�E", 0, 0, 0, 0, 0, 1.12};
struct ders m = {"MATEMAT�K", 0, 0, 0, 0, 0, 2.12};
struct ders f = {"FEN", 0, 0, 0, 0, 0, 1};
struct ders s = {"SOSYAL", 0, 0, 0, 0, 0, 0.75};

int main()
{
    setlocale(LC_ALL,"Turkish");

    int hedefSoru;
    char secim;

    printf("NET VE S�RE ANAL�Z� PROGRAMI\n\n");
    printf("Hedefledi�in toplam soru say�s�n� gir: ");
    scanf("%d", &hedefSoru);

    while(secim != 'x'){
        printf("\n\nDERS SE� (Bitirmek i�in 'x')");
        printf("\nT�rk�e 't' | Matematik 'm' | Fen 'f' | Sosyal 's': ");
        scanf(" %c", &secim);

        switch(secim){
            case 't':
                t = sonucAl(t);
                printf("T�RK�E netin: %.2f\n", netHesaplama(t));
                hedefKontrol(t);
                break;

            case 'm':
                m = sonucAl(m);
                printf("MATEMAT�K netin: %.2f\n", netHesaplama(m));
                hedefKontrol(m);
                break;

            case 'f':
                f = sonucAl(f);
                printf("FEN netin: %.2f\n", netHesaplama(f));
                hedefKontrol(f);
                break;

            case 's':
                s = sonucAl(s);
                printf("SOSYAL netin: %.2f\n", netHesaplama(s));
                hedefKontrol(s);
                break;
        }
    }

    int cozulenSoru = t.dogru + t.yanlis + t.bos + m.dogru + m.yanlis + m.bos + f.dogru + f.yanlis + f.bos + s.dogru + s.yanlis + s.bos;

    if (cozulenSoru >= hedefSoru){
        printf("\nSoru hedefine ula�t�n\n");
    } else {
        printf("\n%d soru daha ��zmen gerekiyor\n", hedefSoru - cozulenSoru);
    }

    return 0;
}

struct ders sonucAl(struct ders x)
{
    printf("\n\t%s\n", x.isim);
    printf("\tDogru: ");
    scanf("%d", &x.dogru);
    printf("\tYanl��: ");
    scanf("%d", &x.yanlis);
    printf("\tBo�: ");
    scanf("%d", &x.bos);
    printf("\tDakika: ");
    scanf("%d", &x.dk);

    x.sure = (float)x.dk / (x.dogru + x.yanlis + x.bos);

    return x;
}

void hedefKontrol(struct ders y){
    if(y.sure > y.hdfSure)
        printf("%s sorusu ��zme s�reni %%%.2f azaltmal�s�n\n", y.isim, 100 * (y.sure - y.hdfSure) / y.sure);
    else
        printf("%s s�re hedefine ula�t�n\n", y.isim);
}

float netHesaplama(struct ders z){
    return z.dogru - (z.yanlis * 0.25);
}
