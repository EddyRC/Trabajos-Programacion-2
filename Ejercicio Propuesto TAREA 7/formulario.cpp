/*Programa creado por: 
Edgar Antonio Reyes Ceron

N carnet: RC18050

Programacion 2 Ciclo 1-2019*/

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/fl_message.H>
#include <FL/Fl_Round_Button.H>
#include <stdio.h>
#include <errno.h>
#include <string.h>

class Ventana : public Fl_Window {
Fl_Window *window;
Fl_Box *box;
Fl_Button *boton;
Fl_Button *boton2;
Fl_Round_Button *botonCircular;
Fl_Round_Button *botonCircular2;
Fl_Input *cod;
Fl_Input *nom;
Fl_Input *ape;

public:
 Ventana() : Fl_Window(500,400) {
      begin();
	//propiedades de la ventana
      box = new Fl_Box(120,2,260,100,"Clientes");
      box->box(FL_RFLAT_BOX);
      box->labelsize(20);
      box->color(FL_CYAN);
      box->labelfont(FL_BOLD+FL_ITALIC);

	//botones
      boton = new Fl_Button(80, 320, 120, 45, "Guardar");
      boton2 = new Fl_Button(300, 320, 120, 45, "Salir");
      boton->color(FL_YELLOW);
      botonCircular = new Fl_Round_Button(180, 240, 80, 80,"F");
      botonCircular2 = new Fl_Round_Button(270, 240, 80, 80,"M");

      //campos a rellenar
      cod = new Fl_Input(156, 110, 200, 45, "Codigo:");
      cod->value("Escriba su codigo aqui");
      nom = new Fl_Input(156, 150, 200, 45, "Nombre:");
      nom->value("Escriba su nombre aqui");
      ape = new Fl_Input(156, 195, 200, 45, "Apellido:");
      ape->value("Escriba su apellido aqui");
      box = new Fl_Box(80,250,120,45,"Genero:");


      end();
      boton->callback(Guardar_CB, (void*)this);
      boton2->callback(Cancelar_CB, (void*)this);
}

 static void Guardar_CB(Fl_Widget *w, void *data) {
       Ventana *e = (Ventana*)data;
	if (e->Guardar("bitacora.txt") == 0){
   	 fl_message("Datos almacenados");
	}
   
 }

static void Cancelar_CB(Fl_Widget *w, void *data) {

	Ventana *e = (Ventana*)data;
	e->hide();                      

}

int Guardar(const char *filename){

        FILE *fp = fopen(filename, "a");
        if ( !fp ) {
            fl_message("%s: %s", filename, strerror(errno));
            return -1;
        }
	else{
            fprintf(fp, "Codigo: %s\n" "Nombre: %s\n" "Apellido: %s\n" "-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/ \n",cod->value(), nom->value(), ape->value());
        fclose(fp);
            return 0;
}

}
       
};

int main(int argc, char **argv){
Ventana *e=new Ventana();
e->show();
//color al background
e->color(FL_GREEN);
return Fl::run();
}
