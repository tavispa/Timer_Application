

Steps to create GUI:

1.  Go to the Design menu on the left
2.  Add a 'Spin Box' under the 'Input Widgets' submenu, a 'Push Button' under the 'Buttons' submenu, and a 'Label' from under the 'Display Widgets' submenu on the left.
3.  Double-click the PushButton to change the name to 'Start'. Hit Enter.
4.  The PushButton should still be selected.  In the bottom right of the screen there is a set of properties you can change.  Under QObject, change objectName from 'pushButton' to pushButton_start.
    This gives it a meaningful name in the main files which is useful for coding.  For example if you have ten pushButtons instead of having to remember which one is pushButton_5, you could rename it to pushButton_cancel.
5.  Rename the label to 'seconds.'  Change the objectName if you choose to, but this README will leave spinBox and label as such for their objectNames.
6.  In the bar above the window you will have a dropdown menu that says 'mainwindow.ui*', beside that there are several icons.  Click the second one from the left 'Edit Signals/Slots.'  (or hit f4)
7.  Click the 'Start' button and drag along the window.  You will see a line appear with the electrical symbol for 'grounded.'  Drop it anywhere in the GUI.
8.  In the 'Configure Connection' window that appears, under the MainWindow Section on the right click 'Edit.'
9.  Click the top '+' sign to add the slot 'countdownStart().' Click OK to go back to the 'Configure Connection' window.
10. Highlight clicked() on the left, and click countdownStart() on the right.  Click OK.



Edit the mainwindow.h file:
1.  Go to the edit menu on the left.
2.  Click mainwindow.h
3.  Add #include <QTimer> at the top under #include <QMainWindow>
4.  Between public: ... and private:...  add 

public slots:
	void countdownStart();           //even though this was created in the Design section, you MUST manually add it yourself
	void subtractOne();
	
Slots are used in Qt to cause changes to objects.  These will allow us to update the spinBox based on events.

5.  Edit the section under private:, it will look like this:

private:
    Ui::MainWindow *ui;
	QTimer *timer;
	
This will enable us to use the Qtimer functions to change the value in the spinBox.



Edit the mainwindow.cpp file:
1.  Open the mainwindow.cpp file
2.  You are going to add the functions countdownStart() and subtractOne().  Do this where you feel appropriate.
3.  Add:

void MainWindow::countdownStart(){
    //ui->spinBox->setValue(40);
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(subtractOne()));
    timer->start(1000);
}

ui->spinBox->setValue(40) is commented out because it was where I was using the 'Start' button to set the value in the spinBox.  However, you can click the up/down arrows beside it to do the same thing.
timer = new QTimer();  //initiaties the timer variable we declared in the .h file.  If you do not include QTimer *timer; in the .h file you will get errors here.
connect(timer, SIGNAL(timeout()), this, SLOT(subtractOne()));  //this lets us use the timeout() signal from the timer variable.  This tells us when the timer has reached 0 (it restarts after doing this).  We will define the subtractOne() function in the next step.  We use the keyword 'this' because it refers to our whole class with all of the objects we put on the GUI.  
timer->start(1000); /tells the timer to send the timeout() signal every 1000ms

4.  Add:

void MainWindow::subtractOne(){
    ui->spinBox->setValue(ui->spinBox->value()-1);
}

When referring to objects we put on the GUI we need to use the syntax  
ui->
This line says to use the spinBox on the GUI, use the setValue function of the spinBox class, and set it to the current value - 1 whenever the subtractOne function is called.

5.  Run the program, you should have a working second counter.

NOTE:
If you want to use autocomplete after creating the GUI, you MUST build the project one time, otherwise Qt doesn't know they exist to use in the autocomplete feature.