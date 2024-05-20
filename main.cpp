#include <Arduino.h>
#include <Servo.h>

int SDA_pin = D0;
int SCL_pin = D1;
LiquidCrystalI2C lcd(0x27, 16, 2);
Servo gate;
int angle = 0;

void setup(){
    gate.attach(D2);
    Wire.begin(SDA_pin, SCL_pin);
    lcd.begin(16, 2);
    lcd.init();
    lcd.backlight();
}

void loop(){
    if (angle < 90)
    {
        angle = 90;
        gate.write(angle);
        lcd.setCursor(0, 0);
        lcd.print("Pintu palang terbuka")
        delay(5000);
    } else {
        angle = 0;
        gate.write(angle);
        lcd.setCursor(0, 0);
        lcd.print("Pintu palang tertutup")
        delay(5000);
    }
}

/*
Penjelasan koding
2 baris pertama merupakan kode untuk memanggil library yang akan digunakan, yaitu arduino dan servo
baris-baris kode selanjutnya  menginisialisasi variabel yang akan digunakan. pada contoh diatas inisialisasi pin sda dan scl pada lcd dengan pin digital d0 dan d1, variabel lcd, servo, dan sudut/angle untuk servo

blok kode pada method setup melakukan inisialisasi servo dan lcd
pada method loop, kode akan dijalankan terus menerus, dimana apabila nilai angle kurang dari 90 berarti servo atau pintu gate tertutup.
variabel akan diubah nilainya menjadi 90 dan akan kita gunakan untuk merubah posisi servo.
setcursor kemudian menentukan pada kolom dan baris mana karakter akan ditampilkan. method print selanjutnya akan menampilkan teks argumen pada lcd display.

pada blok kode else dilakukan sebaliknya, apabila angle melebihi 90 maka akan dirubah nilai menjadi 0.
*/