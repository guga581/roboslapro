#include "LabirintoTeste.h"
#include "R2D2.h"
#include "GL.h"
#include "C3po.h"
#include "Walle.h"



using namespace std;

int main(/*int argc, char *argv[]*/)
{
    GL::init();
    char* lab_file = "labirinto.txt";
    int maxSteps = 200;
    int robot    = 1;

    // Carga do labirinto
    Labirinto* lab = new LabirintoTeste();
    lab->loadMaze(lab_file);
    robot = lab->getRobot();

    Point posIni = lab->getIniPos();

    cout << "Pos ini: " << posIni.getX() << " , " << posIni.getY() << endl;
    cout<<lab->getRobot()<<endl;

    /*if(argc > 1)
    {
        lab_file = argv[1];
        if(argc > 2)
            maxSteps = atoi(argv[2]);
        if(argc > 3)
            robot = atoi(argv[3]);
    }*/

    Robo* robo;

    switch (robot)
    {
    case 1:
        robo = new C3po(posIni, lab, maxSteps);
        break;
    case 2:
        robo = new R2D2(posIni, lab, maxSteps);
        break;
    case 3:
        robo = new Walle(posIni, lab, maxSteps);
        break;
    }


    GL::setLabirintoRobo(lab, robo);
    // Inicializa janela grafica e inicia programa
    GL::loop();
}
