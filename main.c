#include <SDL2/SDL.h>
#include <unistd.h>
#include "function.h"
#include <time.h>
#include <SDL2/SDL_ttf.h>

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000
#define FPS 60

// pour compiler : gcc main.c function.c -o main.out -lSDL2main -lSDL2
// pour lancer ./main.out

// Dans l'ordre créer montagnes puis sapin puis décoration
//ajouter traineau qui se déplace dans le ciel

//position du haut du sapin principal
int xOrigin = 650;
int yOrigin = 500;
int x;
int y;

//definir la hauteur totale de l'arbre et la taille de chaque élément de l'arbre
//Attention, hauteur sera utilisé pour représenter le nombre de rangs du sapin. C'est donc différent du nb de pixel (pour le calcul de la modification des coordonnées).
int hauteur;
int hauteurBranches;
int hauteurTronc;

//position du traineau
int xTraineau=-150;
int yTraineau=300;

//reset le haut du sapin pour ne pas avoir de décalage à chaque boucle du jeu
void reset(){
  x=xOrigin;
  y=yOrigin;
}

void background(){
  int a=0;
  int b=-10;
  int red=3;
  int green=20;
  int blue=37;
  for (int i=0;i<=100;i++){
    b=b+10;
    red=red+2.36;
    green=green+1.12;
    blue=blue-0.33;
    for (int k=0;k<=100;k++){ //largeur du tronc
      changeColor (red,green,blue);
      drawSquare (a,b,10);
      a=a+10;
    }
    a=-10;
  }
}

void montagne(){
  int yMontagne;
  int xMontagne;
  for (int i=0;i<=400;i++){
    yMontagne=150+2*i;
    xMontagne=500-i;
      if (i<=100){
        for (int j=0;j<=(400-(400-i));j++){
            xMontagne=xMontagne+2;
            changeColor ( 62, 74, 98 );
            drawSquare (xMontagne,yMontagne,3);
        }
      }
      else {
        for (int j=0;j<=(400-(400-i));j++){
          xMontagne=xMontagne+2;
          changeColor ( 23, 32, 42 );
          drawSquare (xMontagne,yMontagne,3);
        }
      }
  } 
  for (int i=0;i<=400;i++){
    yMontagne=200+2*i;
    xMontagne=200-i;
      if (i<=100){
        for (int j=0;j<=(400-(400-i));j++){
            xMontagne=xMontagne+2;
            changeColor (  86, 101, 115  );
            drawSquare (xMontagne,yMontagne,3);
        }
      }
      else {
        for (int j=0;j<=(400-(400-i));j++){
          xMontagne=xMontagne+2;
          changeColor (33,47,61);
          drawSquare (xMontagne,yMontagne,3);
        }
      }
  } 
  for (int i=0;i<=600;i++){
    yMontagne=100+2*i;
    xMontagne=750-i;
      if (i<=100){
        for (int j=0;j<=(600-(600-i));j++){
            xMontagne=xMontagne+2;
            changeColor ( 204, 209, 209 );
            drawSquare (xMontagne,yMontagne,2);
        }
      }
      else {
        for (int j=0;j<=(600-(600-i));j++){
          xMontagne=xMontagne+2;
          changeColor (  52, 73, 94 );
          drawSquare (xMontagne,yMontagne,2);
        }
      }
  } 
}

void traineau(){
  xTraineau=xTraineau+20;
  yTraineau=yTraineau-3;
  sprite(xTraineau,yTraineau,"traineau.bmp");
  if (xTraineau>1020){
    xTraineau=-150;
    yTraineau=300;
  }
}

  //sous fonctions de l'arbre
void appel (){
  hauteur=0;
  hauteurBranches=0;
  hauteurTronc=0;
    do {
      printf("Indiquez la taille de votre sapin : 1 pour petit, 2 pour moyen, 3 pour grand\n");
      scanf ("%d",&hauteur);
      } while (hauteur != 1 && hauteur != 2 && hauteur != 3);
    if (hauteur==1){
      hauteur=30;
    }
    else if (hauteur==2){
      hauteur =40;
    }
    else {
      hauteur=50;
    }  
    hauteurBranches = hauteur*0.8;
    hauteurTronc= hauteur*0.2;
}

//a améliorer
void guirlandes(){
    for (int i=0;i<=hauteurBranches;i++){
    y=y+10*i;
    x=x-5-5*i;
      for (int j=0;j<=(hauteurBranches-(hauteurBranches-i+1));j++){
        x=x+10;
          if (y%7==0){
          changeColor (255,255,255);
          drawCircle (x,y,5);
          }
          else if (y%7==2){
          changeColor (255,0,0);
          drawCircle (x,y,5);
          }
      }
     reset();
  }
}

void bougies (){   
  for (int i=0;i<=hauteurBranches+1;i++){
    y=y-5+10*i;
    x=x-10-5*i;
    if (i%5==1){
      for (int j=0;j<=(hauteurBranches-(hauteurBranches-i));j++){
        x=x+10;
        if (j==0) { //bougie côté gauche
          changeColor (243,221,39);
          drawCircle (x,y,5);
        }
        else if (j==(hauteurBranches-(hauteurBranches-i))){ //bougies côté droit
          changeColor (243,221,39);
          drawCircle (x,y,5);
        }
        else {
        }
      }
    }
    else {
        for (int j=0;j<=(hauteurBranches-(hauteurBranches-i));j++){
        x=x+10;
        if (j==0) {
          changeColor (243,221,39); //bougies côté gauche
          drawCircle (x,y,5);
        }
        else if (j==(hauteurBranches-(hauteurBranches-i))){ //bougies côté droit
          changeColor (243,221,39);
          drawCircle (x,y,5);
        }
        else {
        }
      }
    }
    reset();
  }
} 

void boules (){   
  for (int i=0;i<=hauteurBranches+1;i++){
    y=y-5+10*i;
    x=x-5*i;
    if (i%5==1){
      for (int j=0;j<=(hauteurBranches-(hauteurBranches-i+2));j++){
        x=x+10;
        if (rand()%15==1) {
          changeColor (220,11,60);
          drawCircle (x,y,5);
        }
        else {
        }
      }
    }
    else if (i%5==3){
      for (int j=0;j<=(hauteurBranches-(hauteurBranches-i+2));j++){
        x=x+10;
        if (rand()%15==1) {
          changeColor (225,128,0);
          drawCircle (x,y,5);
        }
        else {
        }
      }
    }
    reset();
  }
} 


void drapeau(){
  sprite (xOrigin-15,yOrigin-40, "snowflake.bmp");
}

//branches de l'arbre
void corps (){   
  for (int i=0;i<=hauteurBranches;i++){
    y=y+10*i;
    x=x-15-5*i;
      for (int j=0;j<=(hauteurBranches-(hauteurBranches-i));j++){
        x=x+10;
          if (x%3==0){
          changeColor (22,116,30);
          drawSquare (x,y,10);
          }
          else {
          changeColor ( 30, 132, 73 );
          drawSquare (x,y,10);
          }
      }
     reset();
  }
  reset();
  guirlandes();
  bougies();
  boules();
  drapeau();
} 

void tronc(){
  y=yOrigin+hauteurBranches*10;
  for (int l=0;l<=(hauteurTronc);l++){ //hauteur du tronc
    x=xOrigin-5-(hauteurTronc*10*0.3); // pour passer du nb de rang à la position de x en pixel, prendre en compte la largeur du carré (10px). Pour prendre en compte le fait d'aligner autour de xOrigin à partir de coordonnées dans le coin en haut gauche du carré : -5px soit 1/2 carré
    y=y+10;
    for (int k=0;k<=(hauteurTronc*0.3);k++){ //largeur du tronc
      x=x+10;
      changeColor (90,50,29);
      drawSquare (x,y,10);
    }
  }
}

int arbre(){
  background();
  montagne();
  traineau();
  corps();
  tronc();
}

void init_game(){
    //mettre votre code d'initialisation ici
}


void drawGame(){
    clear();
    arbre();
    actualize();
    usleep(10000000 / FPS); // 60 images par seconde | 1000000 = 1 seconde
}
void KeyPressed(SDL_Keycode touche){
    /** @brief event.key.keysym.sym renvoi la touche appuyé
     *
     */
    switch (touche) {
        // Voir doc SDL_Keycode pour plus de touches https://wiki.libsdl.org/SDL_Keycode
        // ici exemple ou appuyer sur les touches Q | D modifie x (position du carré dans drawGame())
        case SDLK_q:
            //touche q appuyé
            printf("Q\n");
            x--;
            break;
        case SDLK_d:
            //touche d appuyé
            printf("D\n");
            x++;
            break;
        case SDLK_ESCAPE:
            freeAndTerminate();
            break;
        default:
            break;
    }
}
void joyButtonPressed(){
}

void gameLoop() {
    int programLaunched = 1;
    while (programLaunched == 1) {
        // Boucle pour garder le programme ouvert
        // lorsque programLaunched est different de 1
        // on sort de la boucle, donc de la fonction
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            // boucle pour la gestion d'évenement
            switch (event.type) {
                /** event.type renvoi le type d'evenement qui se passe
                 * (si on appuie sur une touche, clique de souris...)
                 * en fonction du type d'évènement on à alors
                 * différentes information accessibles
                 * voir doc pour plus d'event https://wiki.libsdl.org/SDL_EventType
                 */
                case SDL_QUIT:
                    // quand on clique sur fermer la fénêtre en haut à droite
                    programLaunched = 0;
                    break;
                case SDL_MOUSEBUTTONUP:
                    /* clique de la souris
                     * event.motion.y | event.motion.x pour les positions de la souris
                     */
                    printf("position de la souris x : %d , y : %d\n", event.motion.x, event.motion.y);
                    break;
                case SDL_KEYDOWN:
                    KeyPressed(event.key.keysym.sym);
                    break;
                case SDL_JOYBUTTONDOWN:
                    break;
                default:
                    break;
            }
        }
        /* coder ici pour que le code s'execute après chaque évenement
         * exemple dessiner un carré avec position int x, int y qu'on peut
         * deplacer lorsqu'on appuie sur une touche
         */
        drawGame();
    }
}

int main(){
    appel();
    init(WINDOW_WIDTH, WINDOW_HEIGHT);
    srand (time (NULL));
    init_game();
    gameLoop();
    printf("Fin du programme\n");
    freeAndTerminate();
}
