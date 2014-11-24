#include "LabirintoTeste.h"
#include "RoboB9.h"
<<<<<<< HEAD

#include "RoboR2-D2.h"

=======
#include "RoboR2-D2.h"
>>>>>>> b5115e40f3ff650e456b60bdd873ad0cdd57143c
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
    RoboR2D2* robo = new RoboR2D2(posIni, lab, 1000); // 200 passos no maximo

    GL::setLabirintoRobo(lab, robo);
	// Inicializa janela grafica e inicia programa
        GL::loop();
}
