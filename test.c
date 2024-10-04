#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int hauteur;
int hauteurBranches;
int hauteurTronc;
int hauteurPot;

  //sous fonctions de l'arbre
int main (){
//initialiser la variable de hauteur
/*  printf("Indiquez la taille de votre sapin.");
  scanf ("%d",&hauteur);*/
  hauteur=50;
  hauteurBranches = hauteur*0.8;
  hauteurTronc= hauteur*0.2;
  printf("%d hauteur", hauteur, "%d branches", hauteurBranches, "%d tronc", hauteurTronc);
}
