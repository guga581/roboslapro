#include "LabirintoTeste.h"
#include "RoboB9.h"
#include "RoboR2-D2.h"
#include "RoboC3PO.h"


#include "GL.h"

using namespace std;

int main()
{

    GL::init();
    // Carga do labirinto
    Labirinto* lab = new LabirintoTeste();

    lab->loadMaze("labirinto3.txt");

    Point posIni = lab->getIniPos();
    cout << "Pos ini: " << posIni.getX() << " , " << posIni.getY() << endl;

    int r = lab->getRobot();
    cout << "Robo: " << r << endl;
    Robo* robo;
    robo = new RoboR2D2(posIni, lab);
    /*
    switch(r)
    {
    case 1:
        robo = new RoboC3PO(posIni, lab, 200); // 200 passos no maximo
        break;
    case 2:
        robo = new RoboR2D2(posIni, lab);
        break;
    case 3: //robo = new RoboWalle(posIni, lab);
        break;
    }
*/


    GL::setLabirintoRobo(lab, robo);
    // Inicializa janela grafica e inicia programa
    GL::loop();
}
