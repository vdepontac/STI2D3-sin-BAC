/**
 * Code simpliste de mesure de consommation électrique pour une utilisation 
 * un sous compteur à impulsions (avec 1000 impulsions par kWh).
 */
const int BATTERYPIN = A0; //pin de la batterie

const float TensionMin = 3.2; //tension min
const float TensionMax = 4.2; //tension max

/** Fonction setup() */
void setup() {
  
  /* Initialise le port série */
  Serial.begin(115200);
  
  /* Place la broche du compteur en entrée*/
  pinMode(2, INPUT);
}

int getBattery ()
{
  float b = analogRead(BATTERYPIN); //valeur analogique

  int minValue = (1023 * TensionMin) / 5; //Arduino
  int maxValue = (1023 * TensionMax) / 5; //Arduino

  //int minValue = (4095 * TensionMin) / 3; //ESP32
  //int maxValue = (4095 * TensionMax) / 3; //ESP32

  b = ((b - minValue) / (maxValue - minValue)) * 100; //mettre en pourcentage

  if (b > 100) //max is 100%
    b = 100;

  else if (b < 0) //min is 0%
    b = 0;
  int valeur = b;
  return b;
}
/** Fonction loop() */
void loop() {
      Serial.println(getBattery());
  delay(1000);
  static unsigned long previousMillis = 0;

  /* Si la broche est à LOW (impulsion) */
  if (digitalRead(2) == LOW) {
  
    /* Calcul le temps écoulé depuis la dernière impulsion */
    unsigned long currentMillis = millis();
    unsigned long elapsedMillis = currentMillis - previousMillis;
    
    /* Affiche le temps écoulé ainsi que la consommation équivalente */
    Serial.print(elapsedMillis);
    Serial.print(F("ms "));
    Serial.print(3600000 / elapsedMillis);
    Serial.println(F("Wh"));
    
    /* Garde en mémoire le temps actuel et attends la fin de l'impulsion */
    previousMillis = currentMillis;
      delay(150);
  }
}
