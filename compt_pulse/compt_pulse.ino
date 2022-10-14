
// ////////////////////  PRESENTATION DU PROGRAMME ////////////////////

// -------- Que fait ce programme ? ---------
 /* Ce programme compte les impulsions en provenance d'un opto-coupleur en fourche
en utilisant l'interruption externe n°0 sur la broche 2 de la carte Arduino.
Le résultat est affiché dans le Terminal Série du logiciel Arduino.  */

// --- Fonctionnalités utilisées ---

// Utilise la connexion série vers le PC
// Utilise l'interruption externe 0 (broche 2)
// Utilise optocoupleur infra-rouge en fourche, type LTH301-7,


// -------- Circuit à réaliser ---------

// La connexion série vers le PC utilise les broches 0 et 1 (via le câble USB)

// Broche 2 : La sortie du phototransistor d'un optocoupleur en fourche

// /////////////////////////////// 1. Entête déclarative ///////////////////////
// A ce niveau sont déclarées les librairies incluses, les constantes, les variables, les objets utiles...

// --- Déclaration des constantes ---

// --- Inclusion des librairies ---

// --- Déclaration des constantes utiles ---

// --- Déclaration des constantes des broches E/S numériques ---


// --- Déclaration des constantes des broches analogiques ---


// --- Déclaration des variables globales ---

volatile int comptageImpulsion=0; // variable accessible dans la routine interruption externe 0


// --- Déclaration des objets utiles pour les fonctionnalités utilisées ---


// ////////////////////////// 2. FONCTION SETUP = Code d'initialisation //////////////////////////
// La fonction setup() est exécutée en premier et 1 seule fois, au démarrage du programme

void setup()   { // debut de la fonction setup()

// --- ici instructions à exécuter 1 seule fois au démarrage du programme ---

// ------- Initialisation fonctionnalités utilisées -------  

Serial.begin(115200); // initialise connexion série à 115200 bauds
// IMPORTANT : régler le terminal côté PC avec la même valeur de transmission

attachInterrupt(0, gestionINT0, RISING); // attache l'interruption externe n°0 à la fonction gestionINT0()
// mode déclenchement possibles = LOW, CHANGE, RISING, FALLING


// ------- Broches en sorties numériques -------  

// ------- Broches en entrées numériques -------  

// ------- Activation si besoin du rappel au + (pullup) des broches en entrées numériques -------  

// ------- Initialisation des variables utilisées -------  

} // fin de la fonction setup()
// ********************************************************************************

////////////////////////////////// 3. FONCTION LOOP = Boucle sans fin = coeur du programme //////////////////
// la fonction loop() s'exécute sans fin en boucle aussi longtemps que l'Arduino est sous tension

void loop(){ // debut de la fonction loop()


// tout se passe dans la fonction de gestion de l'interruption externe

} // fin de la fonction loop() - le programme recommence au début de la fonction loop sans fin
// ********************************************************************************


// ////////////////////////// FONCTIONS DE GESTION DES INTERRUPTIONS ////////////////////

// ------------------- fonction de gestion l'interruption externe n°0 (broche 2) ----------------
// cette fonction est appelée à chaque fois que l'interruption a lieu selon le mode configuré (LOW, CHANGE, RISING, FALLING)

void gestionINT0() {// la fonction appelée par l'interruption externe n°0

comptageImpulsion=comptageImpulsion+1; // Incrémente la variable de comptage
// ATTENTION : delay() et millis() non dispo ici - données série perdues

//---- affiche le nombre d'impulsions sur le port série
Serial.print("Nombre impulsions = ");
Serial.println(comptageImpulsion);



}
