#include "MapBgi.h"

void MapBgi::Start()
{
    enim->intPutTexture("      __(`````)                       __(`````)                                         __(`````)                           __(`````)            ");
    enim->intPutTexture("     (______)                        (______)                          __(`````)       (______)                            (______)              ");
    enim->intPutTexture("                       __(`````)                      __(`````)       (______)                            __(`````)                              ");
    enim->intPutTexture("                      (______)                       (______)                                            (______)                                ");
    enim->intPutTexture("                                                                                                                                                 ");
    enim->intPutTexture("       (````)                     (````)                     (````)                      (````)                                                  ");
    enim->intPutTexture("      (      )                   (      )                   (      )        (````)      (      )      (````)                  (````)             ");
    enim->intPutTexture("     (        )       (````)    (        )                 (        )      (      )    (        )    (      )     (````)     (      )    (````)  ");
    enim->intPutTexture("       -|  |         (      )     -|  |          (````)      -|  |           |  |        -|  |         |  |      (      )   (        )  (      ) ");
    enim->intPutTexture("        |  |/          |  |        |  |/        (      )      |  |/         -|  |         |  |/       -|  |        |  |       -|  |       |  |   ");
    enim->intPutTexture("        |  |          -|  |        |  |           |  |        |  |           |  |/        |  |         |  |/      -|  |        |  |/     -|  |   ");
    

    Info.Scale.x = enim->getXsize();
    Info.Scale.y = enim->getYsize();
}

int MapBgi::Update()
{


    return 0;
}

void MapBgi::Render()
{
    CursorManager::GetInstance()->RenderObj(*enim, Info.Position.x, Info.Position.y, 2);
}

void MapBgi::Release()
{
}

MapBgi::MapBgi()
{
}

MapBgi::~MapBgi()
{
}
