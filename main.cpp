#include <QApplication>
#include <QThread>
#include <QMutex>
#include <QMessageBox>

#include <QColor>
#include <QLabel>
#include <QtDebug>
#include <QString>
#include <QPushButton>

#include "LeptonThread.h"
#include "MyLabel.h"


int main( int argc, char **argv )
{
	
	int WindowWidth = 340*2;
	int WindowHeight = 290*2;
	int ImageWidth = 320*2;
	int ImageHeight = 240*2;

	//create the app
	QApplication a( argc, argv );
	
	QWidget *myWidget = new QWidget;
	myWidget->setGeometry(400, 300, WindowWidth, WindowHeight);

	//create an image placeholder for myLabel
	//fill the top left corner with red, just bcuz
	QImage myImage;
	myImage = QImage(ImageWidth, ImageHeight, QImage::Format_RGB888);
	
	//create a label, and set it's image to the placeholder
	MyLabel myLabel(myWidget);
	myLabel.setGeometry(10, 10, ImageWidth, ImageHeight);
	myLabel.setPixmap(QPixmap::fromImage(myImage));

	//create a FFC button
	QPushButton *button1 = new QPushButton("Calibrar", myWidget);
	button1->setGeometry(ImageWidth/2-100, WindowHeight-60, 100, 30);
	
	//create a Snapshot button
	QPushButton *button2 = new QPushButton("Tirar foto", myWidget);
	button2->setGeometry(ImageWidth/2+50, WindowHeight-60, 100, 30);

	//create a thread to gather SPI data
	//when the thread emits updateImage, the label should update its image accordingly
	LeptonThread *thread = new LeptonThread();
	QObject::connect(thread, SIGNAL(updateImage(QImage)), &myLabel, SLOT(setImage(QImage)));
	
	//connect ffc button to the thread's ffc action
	QObject::connect(button1, SIGNAL(clicked()), thread, SLOT(performFFC()));
	//connect snapshot button to the thread's snapshot action
	QObject::connect(button2, SIGNAL(clicked()), thread, SLOT(snapshot()));

	thread->start();
	
	myWidget->showFullScreen();

	return a.exec();
}

