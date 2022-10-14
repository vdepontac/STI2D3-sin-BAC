/**
 * Code simpliste de mesure de consommation électrique pour une utilisation 
 * un sous compteur à impulsions (avec 1000 impulsions par kWh).
 */
 
/** Fonction setup() */
void setup() {
  
  /* Initialise le port série */
  Serial.begin(115200);
  
  /* Place la broche du compteur en entrée*/
  pinMode(2, INPUT);
}

/** Fonction loop() */
void loop() {
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
