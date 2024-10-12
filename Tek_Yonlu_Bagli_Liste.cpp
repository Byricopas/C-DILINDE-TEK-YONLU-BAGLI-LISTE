//kutuphane bolumu
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

//burada struct yapimizi tanimliyoruz
typedef struct Liste{
    int sayi;
    struct Liste *sonraki;
}BList;

//burada listemizin ilk ve son karakterini sifira esitleyip global bir degisken olarak tutuyoruz  
BList *ilk=NULL , *son=NULL;

//ekleme fonksiyonu
void ekle(int data){
    
    //burada yeni dugum olusturup bellek tahsisi yapiyoruz
    BList *yeniDugum = (BList *)malloc(sizeof(BList));
    
    //bu kontrol blogunda yaptigimiz bellek tahsisinin gerceklesip gerceklesmedigini kontrol ediyoruz
    if (yeniDugum == NULL) {
        printf("Bellek tahsisinde hata!\n");
        return;
    }

    //Burada olusturdugumuz dügüme kullanicinin girdigi sayiyi ekliyoruz ve sonraki karakteri NULL gosterecek sekilde ayarliyoruz
    yeniDugum->sayi = data;
    yeniDugum->sonraki = NULL;

    //burada listedeki ilk elemanin olup olmadigini kontrol ediyoruz eger listemiz bossa sayimiz ilk karaktere ataniyor eger degilse else bloguyla sondaki karaktere atama yapiyoruz
    if (ilk == NULL){
        ilk = yeniDugum;
        son = yeniDugum;
    }
    else {
        son->sonraki = yeniDugum;
        son = yeniDugum;
    }
    printf("%d sayisi eklendi\n", data);
}

//Listeleme fonksiyonu
void listele(){

    //liste icinde gezmek icin bir gecici tanimliyoruz ve ilk karaktere esitliyoruz
    BList *gecici;
    gecici=ilk;

    //gecici NULLa esitse liste bos demektir bu yuzden listeleme fonksiyonunu burada bitiriyoruz
    if(gecici==NULL){
        printf("Hata!");
        return;
    }

    //bir while dongusuyle gecici karakteri listenin sonuna kadar geziyor liste bittikten sonra while dongusunden cikiyor
    while(gecici!=NULL){
        printf("\n%d" , gecici->sayi);
        gecici=gecici->sonraki;
    }
    printf("\nLISTELEME ISLEMI BITTI!");
}

//arama fonksiyonu
void ara(int aranan){

    //listelemede yaptigimiz gibi listenin basindan sonuna kadar gezmesi icin bir gecici tanimliyoruz
    BList *gecici;
    gecici=ilk;

    //aradigimiz sayidan kac tane oldugunu saymak icin bir sayac degiskeni tutuyoruz
    int sayac=0;

    //gecici NULLa esitse liste bos demektir bu yuzden arama fonksiyonunu burada bitiriyoruz
    if(gecici==NULL){
        printf("Hata!");
        return;
    }

    //listeleme fonksiyonundaki gibi ilk karakterden son karaktere kadar kontrol etmek icin bir while dongusu tanimliyoruz
    while(gecici!=NULL){

        //eger aradigimiz sayidan varsa sayaca ekliyoruz
        if(gecici->sayi==aranan){
            sayac++;
        }
        gecici=gecici->sonraki;
    }

    //eger aradigimiz sayi bulunduysa veya bulunmadiysa buna göre bir çıktı belirliyoruz
    if(sayac>0){
        printf("Aradiginiz sayi %d kere bulundu ! " , sayac);
    }
    else{
        printf("Aradiginiz sayi bulunamadi");
    }
}

//listeden karakter silme fonksiyonu
void sil (int silinecek){

    //listelemede yaptigimiz gibi listenin basindan sonuna kadar gezmesi icin bir gecici tanimliyoruz
    BList *gecici;
    gecici = ilk;
    
    //gecici NULLa esitse liste bos demektir bu yuzden silme fonksiyonunu burada bitiriyoruz
    if(gecici==NULL){
        printf("Hata!");
        return;
    }

    //eger aradigmiz sayi ilk sayiysa ilk sayiyi degistirip onceki ilk sayiyi siliyoruz
    if(gecici->sayi == silinecek){
        gecici=gecici->sonraki;
        free(ilk);
        ilk=gecici;
        printf("%d sayisi silindi.\n", silinecek);
        return;
    }

    //silinecek sayi ilk sayi degilse diger sayilari kontrol ediyoruz
    while(gecici->sonraki != NULL){

        //bir onceki sayidan silecegimiz sayiyi kontrol ediyoruz eger silinecek sayi bulunusa if blogunun icine giriyoruz 
        if (gecici->sonraki->sayi == silinecek) {

            //silinecek sayi icin bir gecici tanimliyoruz
            BList *silinecekDugum = gecici->sonraki;

            //silinecek sayidan önceki sayiyi silinecek sayidan sonraki sayiya bagliyoruz boylelikle listenin bagi bozulmamis oluyor
            gecici->sonraki = silinecekDugum->sonraki;
            
            //sayiyi siliyoruz
            free(silinecekDugum);
            printf("%d sayisi silindi.\n", silinecek);
            return;
        }
        gecici = gecici->sonraki; 

    }


}


//ana fonksiyon 
int main(){

    char secim;
    int data , silinecek , eklenecek , aranacak;
    
    printf("HOSGELDINIZ! ");
    //sonsuz dongu yapiyoruz
    while (1) {
        //burada kullanicidan yapmak istedigi islemi secmesini istiyoruz
        printf("\nIslem Seciniz : \nEKLEME = e \nSILME = s \nLISTELEME = l \nARAMA = a \nCikis = q\n\nGIRINIZ : ");
        scanf(" %c", &secim);

        //burada kullanicinin yapmak istedigi seçime göre islemleri yapmak icin switch case yapisini kullaniyoruz
        switch (secim) {
            case 'e':
            case 'E':
                printf("Eklemek istediginiz sayiyi giriniz : ");
                scanf("%d", &eklenecek);
                ekle(eklenecek);
                break;

            case 's':
            case 'S':
                printf("Silmek istediginiz sayiyi giriniz : ");
                scanf("%d", &silinecek);
                sil(silinecek);
                break;

            case 'l':
            case 'L':
                printf("Listeleme Yapiyorsunuz : ");
                listele();
                break;

            case 'a':
            case 'A':
                printf("Aramak istediginiz sayiyi giriniz : ");
                scanf("%d", &aranacak);
                ara(aranacak);
                break;

            case 'q':
            case 'Q':
                printf("Programdan cikiliyor.\n");
                return 0;
                break;

            //gecersiz karakter girilmesi durumunda calisir
            default:
                printf("Gecersiz secim. Lutfen gecerli bir secim yapin.\n");
        }
    }

    return 0;

}
