#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Adresse LCD (souvent 0x27)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Déclaration des pins
int led = 7;
int buzzer = 8;
int bouton = 2;
int pot = A0;

int etatBouton = 0;
int valeurPot = 0;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(bouton, INPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Systeme Pret");
  delay(2000);
  lcd.clear();
}

void loop()
{
  // lire le potentiometre
  valeurPot = analogRead(pot);

  // lire bouton
  etatBouton = digitalRead(bouton);

  // afficher sur LCD
  lcd.setCursor(0,0);
  lcd.print("Valeur: ");
  lcd.print(valeurPot);
  lcd.print("   ");

  // si bouton appuye
  if(etatBouton == HIGH)
  {
    digitalWrite(led, HIGH);
    tone(buzzer, 1000);

    lcd.setCursor(0,1);
    lcd.print("Bouton ON ");
  }
  else
  {
    digitalWrite(led, LOW);
    noTone(buzzer);

    lcd.setCursor(0,1);
    lcd.print("Bouton OFF");
  }

  delay(200);
}
