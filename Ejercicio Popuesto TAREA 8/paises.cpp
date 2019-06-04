/*Programa creado por: 
Edgar Antonio Reyes Ceron

N carnet: RC18050

Programacion 2 Ciclo 1-2019*/

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/fl_message.H>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

using namespace std;

class Paises : public Fl_Window{
Fl_Window *window;
Fl_Box *box;
Fl_Button *boton1;
Fl_Button *boton2;
Fl_Button *boton3;
Fl_Button *boton4;
Fl_Button *boton5;

int r1;
int r2;
int r3;
int r4;
int r5;

public:

const char* listaPaises[15] = {"Alemania", "Andorra", "Australia", "Belice", "Bolivia", "Brasil", "Canada", "Chile", "China", "Ecuador", "Egipto", "Estonia", "Grecia", "Guatemala", "Guyana"};

Paises() : Fl_Window(500,400){
      
      begin();
      srand(time(NULL));
      r1 = 0 + rand() % (15-1);
      r2 = 0 + rand() % (15-2);
      r3 = 0 + rand() % (15-3);
      r4 = 0 + rand() % (15-4);
      r5 = 0 + rand() % (15-5);

	//propiedades de la ventana
      box = new Fl_Box(120,2,260,100,"Paises.");
      box->box(FL_RFLAT_BOX);
      box->labelsize(30);
      box->color(FL_GREEN);
      box->labelfont(FL_BOLD+FL_ITALIC);

      const char* pais1 = listaPaises[r1];
      boton1 = new Fl_Button(80, 320, 120, 45, pais1);
      const char* pais2 = listaPaises[r2];
      boton2 = new Fl_Button(300, 320, 120, 45, pais2);
      const char* pais3 = listaPaises[r3];
      boton3 = new Fl_Button(300, 155, 120, 45, pais3);
      const char* pais4 = listaPaises[r4];
      boton4 = new Fl_Button(80, 155, 120, 45, pais4);
      const char* pais5 = listaPaises[r5];
      boton5 = new Fl_Button(190, 230, 120, 45, pais5);

      end();

//se usara solamente un callback para procesar cada boton 
      boton1->callback(Bt_CB, (void*)this);
      boton2->callback(Bt_CB, (void*)this);
      boton3->callback(Bt_CB, (void*)this);
      boton4->callback(Bt_CB, (void*)this);
      boton5->callback(Bt_CB, (void*)this);

};

//aqui se le otorga la funcion al callback (lo que hara el boton al presionarsele)
static void Bt_CB(Fl_Widget *w, void *data) {
//pero antes hacemos una pequeña evaluacion..
//Miramos el label del boton (el nombre que posee el boton, en este caso, el nombre seria el nombre del pais) y lo comparamos, con el valor de Alemania para este primer caso, si el boton Dice Alemania, entonces el flujo de ejecucion entra en este primer if, e imprime inmediatamente el nombre de la capital, que en este caso la capital de Alemania, es Berlin...

//Caso contrario seria que el boton no tenga por nombre Alemania, el flujo de ejecucion ignorara lo que sigue y pasara a evaluar en las siguientes condicionales, hasta dar con el nombre del boton que sea igual al valor que estamos evaluando, y asi sucesivamente
      if(strcmp(w->label(), "Alemania") == 0){
          fl_message("Berlin");
      }

      else if(strcmp(w->label(), "Andorra") == 0){
          fl_message("Andorra la vieja");
      }

      else if(strcmp(w->label(), "Australia") == 0){
          fl_message("Camberra");
      }

      else if(strcmp(w->label(), "Belice") == 0){
          fl_message("Belmopan");
      }

      else if(strcmp(w->label(), "Bolivia") == 0){
          fl_message("Sucre");
      }

      else if(strcmp(w->label(), "Brasil") == 0){
          fl_message("Brasilia");
      }

      else if(strcmp(w->label(), "Canada") == 0){
          fl_message("Ottawa");
      }

      else if(strcmp(w->label(), "Chile") == 0){
          fl_message("San jose");
      }

      else if(strcmp(w->label(), "China") == 0){
          fl_message("Pekin");
      }

      else if(strcmp(w->label(), "Ecuador") == 0){
          fl_message("Quito");
      }

      else if(strcmp(w->label(), "Egipto") == 0){
          fl_message("El Cairo");
      }

      else if(strcmp(w->label(), "Estonia") == 0){
          fl_message("Tallin");
      }

      else if(strcmp(w->label(), "Grecia") == 0){
          fl_message("Atena");
      }

      else if(strcmp(w->label(), "Guatemala") == 0){
          fl_message("Ciudad de guatemala");
      }

      else if(strcmp(w->label(), "Guyana") == 0){
          fl_message("Georgetown");
      }
}

};


int main(int argc, char **argv){
Paises *e = new Paises();
e->show();
//color al background
e->color(FL_CYAN);
return Fl::run();
}
