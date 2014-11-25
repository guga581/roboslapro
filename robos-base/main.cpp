#include "LabirintoTeste.h"
#include "RoboB9.h"
<<<<<<< HEAD
#include "RoboR2-D2.h"
#include "RoboC3PO.h"
=======
<<<<<<< HEAD
=======

>>>>>>> 7bca2a40ea796e1b860aadde37fef2d234a3b1d0

#include "RoboR2-D2.h"


<<<<<<< HEAD
=======
#include "RoboR2-D2.h"
>>>>>>> 7bca2a40ea796e1b860aadde37fef2d234a3b1d0

#include "RoboC3PO.h"

>>>>>>> ddb903fb265354deddd888e92a4d83ab16943e7c
#include "GL.h"

using namespace std;

int main()
{
    GL::init();
    // Carga do labirinto
    Labirinto* lab = new LabirintoTeste();
<<<<<<< HEAD
    lab->loadMaze("labirinto.txt");

    Point posIni = lab->getIniPos();
    cout << "Pos ini: " << posIni.getX() << " , " << posIni.getY() << endl;
    RoboR2D2* robo = new RoboR2D2(posIni, lab); // 200 passos no maximo
=======
    lab->loadMaze("labirinto3.txt");

    Point posIni = lab->getIniPos();
    cout << "Pos ini: " << posIni.getX() << " , " << posIni.getY() << endl;

    RoboC3PO* robo = new RoboC3PO(posIni, lab, 200); // 200 passos no maximo

>>>>>>> 7bca2a40ea796e1b860aadde37fef2d234a3b1d0

    GL::setLabirintoRobo(lab, robo);
	// Inicializa janela grafica e inicia programa
        GL::loop();
}
