#include <SDL2/SDL.h>
#include <unistd.h>
#include "function.h"
#include <time.h>
#include <SDL2/SDL_ttf.h>

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000
#define FPS 60

// Dans l'ordre créer montagnes puis sapin puis décoration
//usleep a la fin des boucles de chaque colonne pour faire une "construction"

//position du carre dessiné dans drawGame()
int x = 500;
int y = 300;
int xOrigin = 500;
int yOrigin = 300;

//definir la hauteur totale de l'arbre et la taille de chaque élément de l'arbre
int hauteur=100;
int hauteurBranches;
int hauteurTronc;
int hauteurPot;
  
  //sous fonctions de l'arbre
void appel (){
//initialiser la variable de hauteur
/*  printf("Indiquez la taille de votre sapin.");
  scanf ("%d",&hauteur);*/
  hauteur=100;
  hauteurBranches = hauteur*0.7;
  hauteurTronc= hauteur*0.2;
  hauteurPot= hauteur*0.1;
}

void reset(){
  x=xOrigin;
  y=yOrigin;
}

void montagne(){
  for (int i=0;i<=400;i++){
    y=200+2*i;
    x=200-i;
      if (i<=100){
        for (int j=0;j<=(400-(400-i));j++){
            x=x+2;
            changeColor (  86, 101, 115  );
            drawSquare (x,y,3);
        }
        reset();
      }
      else {
        for (int j=0;j<=(400-(400-i));j++){
          x=x+2;
          changeColor (33,47,61);
          drawSquare (x,y,3);
        }
      }
  } 
  reset();
  for (int i=0;i<=600;i++){
    y=100+2*i;
    x=750-i;
      if (i<=100){
        for (int j=0;j<=(600-(600-i));j++){
            x=x+2;
            changeColor ( 204, 209, 209 );
            drawSquare (x,y,2);
        }
        reset();
      }
      else {
        for (int j=0;j<=(600-(600-i));j++){
          x=x+2;
          changeColor (  52, 73, 94 );
          drawSquare (x,y,2);
        }
      }
  } 
  reset();
}

//option 1
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
//  guirlandes();
//  boules();
} 

//A modifier
//générer les bornes RAND_MIN et RAND_MAX

void guirlandes(){
  for (int i=0;i<=hauteur-1;i++){
    y=y+10*i;
    x=x-15-5*i;
    if (i%5==1){
      for (int j=0;j<=(hauteur-(hauteur-i));j++){
        x=x+10;
        changeColor( 241, 196, 15 );
        drawSquare(350,100,20);
      }
      reset();
    }
    reset();
  }
}

void boules (){   
  for (int i=0;i<=hauteur-1;i++){
    y=y+10*i;
    x=x-15-5*i;
    if (i%5==1){
      for (int j=0;j<=(hauteur-(hauteur-i));j++){
        x=x+10;
        if (i==0){
          changeColor(212,25,6);
          drawCircle (x,y,100);
        }
        else if (j==0) {
          changeColor (243,221,39);
          drawCircle (x,y,20);
        }
        else {
        }
      }
    }
      else if (i%7==0){
      for (int j=0;j<=(hauteur-(hauteur-i));j++){
        x=x+10;
        if (i==0){
          changeColor(212,25,6);
          drawCircle(350,100,20);
        }
        else if (j==0) {
          changeColor (243,221,39);
          drawCircle (x,y,20);
        }
        else {
        }
      }
    }
    else {
        for (int j=0;j<=(hauteur-(hauteur-i));j++){
        x=x+10;
        if (i==0){
          changeColor(212,25,6);
          drawCircle(350,100,20);
        }
        else if (j==0) {
          changeColor (243,221,39);
          drawCircle (x,y,20);
        }
        else if (j==(hauteur-(hauteur-i))){
          changeColor (243,221,39);
          drawCircle (x,y,20);
        }
        else if (rand()%20==0) {
          changeColor (22,16,30);
          drawCircle (x,y,12);
        }
        else if (rand()%20==1) {
          changeColor (220,11,60);
          drawCircle (x,y,12);
        }
        else {
        }
      }
    }
    reset();
  }
} 

//option 1
void tronc(){
  int largeur=hauteurTronc*2;
  reset();
  for (int l=1;l<=hauteurTronc;l++){ //hauteur du tronc
      y=yOrigin+(10*hauteurTronc)-10+10*l;
      x=xOrigin-((largeur/10)/2)*10;
    for (int k=0;k<=largeur/20;k++){ //largeur du tronc
      x=x+10;
      changeColor (90,50,29);
      drawSquare (x,y,10);
    }
    reset();
  }
}



/*void pot(){
  int largeur=hauteur*2; 
    for (int i=0;i<=hauteurPot;i++){
    y=yOrigin+(10*hauteur)+(hauteur/4)-10+10*i;
    x=xOrigin-((largeur/10)/2)*10;
    y=y+10*i;
    x=x-15-5*i;
    if (i==0){
      for (int j=0;j<=(hauteur-(hauteur-i));j++){
        x=x+10;
        changeColor( 86, 101, 115 );
        drawSquare (350,100,20);
      }
    }
    else {
      for (int j=(hauteur-(hauteur-i));j>=0;j--){
        x=x+10;
        changeColor(  91, 44, 111  );
        drawSquare (350,100,20);
      }    
    }
  }
} */

int arbre(){
  montagne();
  appel();
  corps();
  tronc();
}

void init_game(){
    //mettre votre code d'initialisation ici
}


void drawGame(){
    /* Ici je dessine mon jeu
     * exemple position x, y modifiés dans KeyPressed() et utilisés pour
     * pouvoir deplacer la figure à chaque boucle de gameLoop()
     */
    clear();
    arbre();
    actualize();
    usleep(1000000 / FPS); // 60 images par seconde | 1000000 = 1 seconde
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
    /** @description 3 fonctions dans le main qui permettent de créer l'application et la maintenir ouverte :
     *  init(...) : initialiser la SDL/ fenêtre
     *  gameLoop() : boucle de jeu dans laquelle l'application reste ouverte
     *  freeAndTerminate() : quitte le programme proprement
     */
    init(WINDOW_WIDTH, WINDOW_HEIGHT);
    srand (time (NULL));
    init_game();
    gameLoop();
    printf("Fin du programme\n");
    freeAndTerminate();
}


//option 2 du tronc
/*void tronc(){
  int largeur=hauteur*2;
  reset();
  for (int l=1;l<=hauteur/4;l++){ //hauteur du tronc
      y=yOrigin+(10*hauteur)-10+10*l;
    for (int k=0;k<=largeur/20;k++){ //largeur du tronc
      x=x-10;
      changeColor (90,50,29);
      drawSquare (x,y,10);
    }
    reset();
    y=yOrigin+(10*hauteur)-10+10*l;
    x=x-10;
    for (int k=0;k<=largeur/20;k++){ //largeur du tronc
    x=x+10;
    changeColor (90,50,29);
    drawSquare (x,y,10);
    }
    reset();
  }
} */

//option 2 des branches
/* void branches (){   

  for (int i=0;i<=hauteur-1;i++){
    y=y+10*i;
    for (int j=0;j<=(hauteur-(hauteur-i));j++){
      x=x-5;
      changeColor (22,116,30);
      drawSquare (x,y,10);    
    }
    reset();
    y=y+10*i;
    x=x-10;
    for (int j=0;j<=(hauteur-(hauteur-i));j++){
    x=x+5;
    drawSquare (x,y,10);
    }
    reset();
  }
} */
