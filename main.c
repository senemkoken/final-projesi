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

struct ders t = {"TÜRKÇE", 0, 0, 0, 0, 0, 1.12};
struct ders m = {"MATEMATÝK", 0, 0, 0, 0, 0, 2.12};
struct ders f = {"FEN", 0, 0, 0, 0, 0, 1};
struct ders s = {"SOSYAL", 0, 0, 0, 0, 0, 0.75};

int main()
{
    setlocale(LC_ALL,"Turkish");

    int hedefSoru;
    char secim;

    printf("NET VE SÜRE ANALÝZÝ PROGRAMI\n\n");
    printf("Hedeflediðin toplam soru sayýsýný gir: ");
    scanf("%d", &hedefSoru);

    while(secim != 'x'){
        printf("\n\nDERS SEÇ (Bitirmek için 'x')");
        printf("\nTürkçe 't' | Matematik 'm' | Fen 'f' | Sosyal 's': ");
        scanf(" %c", &secim);

        switch(secim){
            case 't':
                t = sonucAl(t);
                printf("TÜRKÇE netin: %.2f\n", netHesaplama(t));
                hedefKontrol(t);
                break;

            case 'm':
                m = sonucAl(m);
                printf("MATEMATÝK netin: %.2f\n", netHesaplama(m));
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
        printf("\nSoru hedefine ulaþtýn\n");
    } else {
        printf("\n%d soru daha çözmen gerekiyor\n", hedefSoru - cozulenSoru);
    }

    return 0;
}

struct ders sonucAl(struct ders x)
{
    printf("\n\t%s\n", x.isim);
    printf("\tDogru: ");
    scanf("%d", &x.dogru);
    printf("\tYanlýþ: ");
    scanf("%d", &x.yanlis);
    printf("\tBoþ: ");
    scanf("%d", &x.bos);
    printf("\tDakika: ");
    scanf("%d", &x.dk);

    x.sure = (float)x.dk / (x.dogru + x.yanlis + x.bos);

    return x;
}

void hedefKontrol(struct ders y){
    if(y.sure > y.hdfSure)
        printf("%s sorusu çözme süreni %%%.2f azaltmalýsýn\n", y.isim, 100 * (y.sure - y.hdfSure) / y.sure);
    else
        printf("%s süre hedefine ulaþtýn\n", y.isim);
}

float netHesaplama(struct ders z){
    return z.dogru - (z.yanlis * 0.25);
}
