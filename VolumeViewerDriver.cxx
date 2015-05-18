#include <QApplication>
#include "VolumeViewer.h"



int main( int argc, char** argv )
{
  // QT Stuff
  QApplication app( argc, argv );
  
  VolumeViewer VolumeViewer;

  
  VolumeViewer.show();
  
  return app.exec();
}
