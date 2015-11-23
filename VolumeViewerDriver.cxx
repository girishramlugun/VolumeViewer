#include <QApplication>
#include "VolumeViewer.h"
#include<qcoreapplication.h>


int main( int argc, char** argv )
{
  // QT Stuff
  QApplication app( argc, argv );
  
  VolumeViewer VolumeViewer;

  QCoreApplication::setOrganizationName("ABI");

  QCoreApplication::setApplicationName("Volume Viewer");

  
  VolumeViewer.show();
  
  return app.exec();
}
