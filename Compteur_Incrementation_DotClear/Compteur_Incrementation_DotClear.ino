#include <ESP8266WiFi.h>
#include <PinChangeInterrupt.h>     // bibliothèque de gestion des interruptions sur ttes les broches
  const byte bint=8;                           // broche utilisée pour déclencher l'interruption 
  volatile long cpt0 = 0;                     // compteur d'impulsions

void setup() {

  pinMode(bint, INPUT_PULLUP);       // la broche est positionnée en entrée avec une résistance à 5v
        // on suppose que notre impulsion correspond à un "0" bref (contact à la masse par exemple) 
  attachPinChangeInterrupt(digitalPinToPinChangeInterrupt(cpt), Fcpt0, FALLING);     // sur mise à 0 du signal, appel de Fcpt0()
        // vous notez que l'interruption est déclenchée sur le passage de l'état "1" à l'état "0" (falling)

void Fcpt0(void) {
 cpt0++;           // incrément de compteur (notre programme est très court !

void loop() {
 NombreDimpulsions=cpt0;        // utilisation du compteur
 cpt0=0;                                  // il faut évidemment penser à remettre notre compteur à zéro
}
