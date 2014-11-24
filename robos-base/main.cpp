#include "LabirintoTeste.h"
#include "RoboB9.h"


#include "RoboR2-D2.h"


#include "RoboR2-D2.h"

#include "RoboC3PO.h"

#include "GL.h"

using namespace std;

int main()
{
    GL::init();
    // Carga do labirinto
    Labirinto* lab = new LabirintoTeste();
    lab->loadMaze("labirinto4.txt");

    Point posIni = lab->getIniPos();
    cout << "Pos ini: " << posIni.getX() << " , " << posIni.getY() << endl;
<<<<<<< HEAD
    RoboR2D2* robo = new RoboR2D2(posIni, lab, 200); // 200 passos no maximo
=======
    RoboR2D2* robo = new RoboR2D2(posIni, lab, 1000); // 200 passos no maximo
>>>>>>> 491a9608ced5ce3eeb076350667a9e4351f9a69f

    GL::setLabirintoRobo(lab, robo);
	// Inicializa janela grafica e inicia programa
        GL::loop();
}
