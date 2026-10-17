#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
String Humidity = "Humidity:";
String Temperature="Temperature:";
int position = 0;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  dht.begin();
  lcd.print(Humidity);
  lcd.setCursor(0,1);
  lcd.print(Temperature);
}

void loop() {
  delay(2000);
  float humidity = dht.readHumidity(); 
  float temperature = dht.readTemperature();
  // put your main code here, to run repeatedly:
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  delay(2000);
  String Humidity_1 = String(humidity,1);
  String Temperature_1 = String(temperature,1);
  lcd.setCursor(Humidity.length(),0);

  while(Humidity_1[position] != '\0'){
    lcd.print(Humidity_1[position]);
    delay(200);
    lcd.setCursor(Humidity_1.length()+position,0);
  }
  lcd.print("%");
  position = 0; 
  lcd.setCursor(Temperature.length(),0);
  while(Temperature_1[position] != '\0'){
    lcd.print(Temperature_1[position]);
    delay(200);
    lcd.setCursor(Temperature.length()+position,0);
  }
}
