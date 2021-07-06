//menginisialisasi
int const trigPin = 6; //pin trigger Sensor A
int const echoPin = 5; //pin echo Sensor A
int const spkPin = 13; //pin speaker
const byte ledPin = 12; //pin led
int const btrigPin =10; //Sensor B
int const bechoPin = 11; //sensor B
int const ctrigPin = 9; //sensor C
int const cechoPin = 3; //sensor C
#define NOTE_F4 550 //membuat nada NOTE_F4 dengan frekuensi 550

int duration;//inisialisasi nilai duration sensor A
int distance;//inisialisasi nilai distance sensor A
int bduration;//inisialisasi nilai duration sensor B
int bdistance;//inisialisasi nilai distance sensor B
int cduration;//inisialisasi nilai duration sensor C
int cdistance;//inisialisasi nilai distance sensor C


//mendeklarasi pin dan menyambungkan ke serial 
void setup(){
  Serial.begin(9600);//menyambungkan ke serial
  pinMode(trigPin, OUTPUT); //pin trigger akan menjadi output yang mengeluarkan sinyal pulsa
  pinMode(echoPin, INPUT); //pin echo akan menjadi input untuk mendapatkan lebar sinyal pulsa
  pinMode(spkPin,OUTPUT);//pin speaker sebagai input
  pinMode(ledPin, OUTPUT);//pin led sebagai output
  pinMode(btrigPin, OUTPUT); //trig pin Sensor B
  pinMode(bechoPin, INPUT); //echo pin Sensor B
  pinMode(ctrigPin, OUTPUT);
  pinMode(cechoPin, INPUT);
  }

void loop(){
digitalWrite(trigPin,LOW); //Sensor A
delayMicroseconds (2); //lama waktu trigPin sensor A dalam keadaan LOW
digitalWrite(trigPin, HIGH);//Sensor A
delayMicroseconds(10);//lama waktu trigpin Sensor A menghasilkan pulsa
digitalWrite(trigPin,LOW); //nilai trigPin sensor A dalam keadaan low setelah menghasilkan pulsa
duration = pulseIn(echoPin,HIGH); //pin Echo sensor A akan terbaca HIGH jika terdapat objek didepannya
distance = duration*0.034/2;//menghitung jarak antara sensor dan objek


digitalWrite(btrigPin,LOW); //sensor B
delayMicroseconds (2); 
digitalWrite(btrigPin, HIGH); //Sensor B
delayMicroseconds(10);
digitalWrite(btrigPin,LOW); // Sensor B
bduration = pulseIn(bechoPin,HIGH);
bdistance = bduration*0.034/2; //calculating for sensor B

digitalWrite(ctrigPin,LOW); //sensor C
delayMicroseconds (2); 
digitalWrite(ctrigPin, HIGH); //Sensor C
delayMicroseconds(10);
digitalWrite(ctrigPin,LOW); // Sensor C
cduration = pulseIn(cechoPin,HIGH);
cdistance = cduration*0.034/2; //calculating for sensor C

//jika input sensor terbaca jarak kurang dari 100 dan jarak lebih dari 0 cm maka led akan menyala dan langsung menjalankan fungsi alarmsound()
if(distance <= 100 && distance >= 0){
  digitalWrite(ledPin, HIGH);//led akan menyala dan buzzer akan berbunyi ketika jarak kuran dari 100 cm
  alarmSound();
}else{//jika input sensor terbaca lebih dari 100 maka led mati dan speaker mati
  digitalWrite(spkPin,LOW);
  digitalWrite(ledPin,LOW);
}
Serial.println("jarak dari Sensor A: ");//menampilkan jarak ke serial
Serial.print(distance);
Serial.println("cm");
delay(100);

if(bdistance <= 100 && bdistance >= 0){
  digitalWrite(ledPin, HIGH);
  alarmSound();
}else{//jika input sensor terbaca lebih dari 100 maka led mati dan speaker mati
  digitalWrite(spkPin,LOW);
  digitalWrite(ledPin,LOW);
}
Serial.println("jarak dari Sensor B: ");//menampilkan jarak ke serial
Serial.print(bdistance);
Serial.println("cm");
delay(100);


if(cdistance <= 100 && cdistance >= 0){
  digitalWrite(ledPin, HIGH);
  alarmSound();
}else{//jika input sensor terbaca lebih dari 100 maka led mati dan speaker mati
  digitalWrite(spkPin,LOW);
  digitalWrite(ledPin,LOW);
}
Serial.println("jarak dari Sensor C: ");//menampilkan jarak ke serial
Serial.print(cdistance);
Serial.println("cm");
delay(100);
}

//membuat fungsi untuk membunyikan speaker
void alarmSound(){
  tone(spkPin,NOTE_F4,200);
  delay(200);
}
