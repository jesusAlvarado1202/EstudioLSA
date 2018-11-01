#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "treemodel.h"
#include "tablemodel.h"
#include <QFile>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <unistd.h>



using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    // Nombre del directorio actual
//    char cwd[1024];
//       if (getcwd(cwd, sizeof(cwd)) != NULL)
//           cout<<"path "<< string(cwd) <<endl;

    ui->setupUi(this);

    model_table = new QStandardItemModel(2,2,this);
    myData = new Data();
    myPlayer = new Player();
    myProcess = new cvProcess();

    //Directorio principal
    DisplayBrowsWindow();

    //Tabla de datos principal
    QStringList headers;
    headers << tr("Title") << tr("Description");

    QFile file("default.txt");
    file.open(QIODevice::ReadOnly);
    TreeModel *model = new TreeModel(headers, file.readAll());
    file.close();
    ui->tableView_project->setModel(model);

    for (int column = 0; column < model->columnCount(); ++column)
        ui->tableView_project->resizeColumnToContents(column);

    ui->tableView_project->setWordWrap(true);

    //Ubicacion de dockwidget
    QRect main_wind_size(0,0,1150,480);
    this->setGeometry(main_wind_size);
    ui->dockWidget->setGeometry(QRect(this->geometry().x()+(440*2),this->geometry().y()+(380),440,380));
    ui->dockWidget->setAllowedAreas(Qt::NoDockWidgetArea);

    // Configuracion de la lista de imagenes de caras
    ui->listWidget_rec->setViewMode(QListWidget::IconMode);
    ui->listWidget_rec->setIconSize(QSize(200,200));
    ui->listWidget_rec->setResizeMode(QListWidget::Adjust);
    ui->listWidget_rec->setMovement(QListView::Static);
    ui->listWidget_rec->setSelectionMode(QAbstractItemView::MultiSelection);

    //flag
    video_loaded_flag = false;
    stop_coding = false;
    enable_vsproc = enable_coding = enable_analisis = false;
    save_load_facerec_model = false;


    //Habilitar/Deshabilitar
    ui->pushButton_export->setDisabled(true);
    ui->listWidget_main->item(0)->setSelected(true);
//    ui->listWidget_main->item(1)->setFlags( ui->listWidget_main->item(1)->flags() & ~Qt::ItemIsSelectable);
//    ui->listWidget_main->item(2)->setFlags( ui->listWidget_main->item(2)->flags() & ~Qt::ItemIsSelectable);
//    ui->listWidget_main->item(3)->setFlags( ui->listWidget_main->item(3)->flags() & ~Qt::ItemIsSelectable);

    //Valores iniciales
    ui->progressBar_code->setValue(0);
    ui->progressBar_rec->setValue(1);

    //connect(ui->listWidget_main, SIGNAL(currentRowChanged(int)), ui->stackedWidget_main, SLOT(setCurrentIndex(int)));
    connect(ui->listWidget_main, SIGNAL(currentRowChanged(int)),this, SLOT(controlStack(int)));
    connect(myPlayer, SIGNAL(processedImage(QImage)),this, SLOT(updatePlayerUI(QImage)));
    connect(myProcess,SIGNAL(progressValue(int)),ui->progressBar_code,SLOT(setValue(int)));
    connect(ui->barPlot, SIGNAL(mousePress(QMouseEvent*)), SLOT(clickedGraph(QMouseEvent*)));
    connect(myProcess,SIGNAL(progressTime(double)),this,SLOT(elapseTime(double)));
    connect(ui->horizontalScrollBar_plot, SIGNAL(valueChanged(int)), this, SLOT(horzScrollBar_plot_Changed(int)));
    connect(ui->barPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(xAxisChanged(QCPRange)));
    connect(myProcess,SIGNAL(progressValue(int)),ui->progressBar_rec,SLOT(setValue(int)));
    connect(myProcess,SIGNAL(progressFinished()),this,SLOT(preTrainFinished()));
    connect(myProcess,SIGNAL(progressFrame(QImage)),this,SLOT(updatePlayerUI(QImage)));

//Mat frame;
//    VideoCapture cap;
//        // open the default camera using default API
//        cap.open("/home/treelab/Videos/test3.avi");

//        for (;;)
//        {
//            // wait for a new frame from camera and store it into 'frame'
//            cap.read(frame);

////            cap >> frame;

//            // check if we succeeded
//            if (frame.empty()) {
//                cerr << "ERROR! blank frame grabbed\n";
//                break;
//            }
//            // show live and wait for a key with timeout long enough to show images
//            imshow("Live", frame);
//            waitKey();
////            if (waitKey() >= 0)
////                break;
//        }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::controlStack(int i)
{


    switch (i) {
    case 1:
        if(enable_vsproc) ui->stackedWidget_main->setCurrentIndex(i);
        break;
    case 2:
        if(enable_coding) ui->stackedWidget_main->setCurrentIndex(i);
        break;
    case 3:
        if(enable_analisis) ui->stackedWidget_main->setCurrentIndex(i);
        break;
    default:
        ui->stackedWidget_main->setCurrentIndex(0);
        break;
    }


//    if(i == 2)
//    {
//        ui->pushButton_Play->setDisabled(true);
//    }else{
//        ui->pushButton_Play->setDisabled(false);
//    }

}

void MainWindow::DisplayBrowsWindow()
{
    QString sPath = "/home";
    dirmodel = new QFileSystemModel(this); //Se crea la clase dirmodel
    dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::Files | QDir::AllDirs); //Se muestran solo los archivos y los directorios
    dirmodel->setRootPath(sPath);  //Se declara /home como la direccion principal del treeView

    //Lista de strings llamada filters y sus datos
    QStringList filters;
    filters << "*.avi" << "*.mpg" << "*.wmv";

    dirmodel->setNameFilters(filters); //Solo deja seleccionar los archivos con la terminacion declarada en filters
    ui->treeView_project->setModel(dirmodel); //Muestra el treeView
}

void MainWindow::on_treeView_project_pressed(const QModelIndex &index)
{

}

void MainWindow::on_pushButton_new_project_clicked()
{

}

void MainWindow::on_pushButton_open_project_clicked()
{

}

void MainWindow::on_pushButton_load_clicked()
{
    filename = QFileDialog::getOpenFileName(this,
                                          tr("Open Video"), ".",
                                          tr("Video Files (*.avi *.mpg *.mp4 *.wmv)"));
    QFileInfo name = filename;

    if (!filename.isEmpty()){
        if (!myPlayer->loadVideo(filename.toUtf8().constData()))//.toAscii().data()))
        {
            QMessageBox msgBox;
            msgBox.setText("The selected video could not be opened!");
            msgBox.exec();
        }
        else{
            this->setWindowTitle(name.fileName());

            /*Inicializar widgets*/


            ui->horizontalSlider->setEnabled(true);
            ui->horizontalSlider->setMaximum(myPlayer->getNumberOfFrames());
            ui->label_TotalTime->setText( getFormattedTime( (int)myPlayer->getNumberOfFrames()/(int)myPlayer->getFrameRate()) );

            load_image(1);

            /*Initicializar datos de otras clases*/
            myData->initilizeData((int)myPlayer->getNumberOfFrames());
            myProcess->y1.resize((int)myPlayer->getNumberOfFrames());
            myProcess->y.resize((int)myPlayer->getNumberOfFrames());


            myProcess->cap1 = myPlayer->capture;            
            ui->progressBar_code->setMaximum((int)myPlayer->getNumberOfFrames());
            ui->progressBar_code->setMinimum(0);
            ui->barPlot->xAxis->setRange(0,(int)myPlayer->getNumberOfFrames()/10);
            ui->barPlot->xAxis2->setRange(0,(int)myPlayer->getNumberOfFrames()/10);

            ui->horizontalScrollBar_plot->setRange((int)myPlayer->getNumberOfFrames()/20,(int)myPlayer->getNumberOfFrames()*9.5/10);

            cout<< "FR "<< (int)myPlayer->getFrameRate() <<endl;

            myVideoPos1 = new VideoPosition(this);
            connect(myVideoPos1,SIGNAL(doneFlag()),this,SLOT(faceAtPosition1()));

            myVideoPos2 = new VideoPosition(this);
            connect(myVideoPos2,SIGNAL(doneFlag()),this,SLOT(faceAtPosition2()));
//            connect(myVideoPos,SIGNAL(doneFlag()),this,SLOT(faceAtPosition1()));

            ui->timeEdit_start_rec->setMaximumTime(getFormattedTime1((int)myPlayer->getNumberOfFrames()));
            ui->timeEdit_end_rec->setMaximumTime(getFormattedTime1((int)myPlayer->getNumberOfFrames()));
            ui->timeEdit_start_rec->setTime(getFormattedTime1(0));
            ui->timeEdit_end_rec->setTime(getFormattedTime1((int)myPlayer->getNumberOfFrames()));


            ui->timeEdit_start_code->setMaximumTime(getFormattedTime1((int)myPlayer->getNumberOfFrames()));
            ui->timeEdit_end_code->setMaximumTime(getFormattedTime1((int)myPlayer->getNumberOfFrames()));
            ui->timeEdit_start_code->setTime(getFormattedTime1(0));
            ui->timeEdit_end_code->setTime(getFormattedTime1((int)myPlayer->getNumberOfFrames()));

            if(ui->timeEdit_end_rec->time().hour()>0)
            {
                ui->timeEdit_end_rec->setDisplayFormat(QString("HH:mm:ss"));
                ui->timeEdit_start_rec->setDisplayFormat(QString("HH:mm:ss"));

                ui->timeEdit_end_code->setDisplayFormat(QString("HH:mm:ss"));
                ui->timeEdit_start_code->setDisplayFormat(QString("HH:mm:ss"));
            }

            ui->progressBar_rec->setMinimum(1);
            ui->progressBar_rec->setMaximum((int)myPlayer->getNumberOfFrames());
            myProcess->framestart = 0;
            myProcess->framestop = timeToFrames(getFormattedTime1( (int)myPlayer->getNumberOfFrames() ));
            //Habilidar visual processing
            enable_vsproc = true;



        }
    }

}

void MainWindow::on_pushButton_Play_clicked()
{
    if (myPlayer->isStopped())
    {
        myPlayer->Play();
        ui->pushButton_Play->setText(tr("Stop"));
    }else
    {
        myPlayer->Stop();
        ui->pushButton_Play->setText(tr("Play"));
    }

}

int MainWindow::timeToFrames(QTime time)
{
    return QTime(0, 0, 0).secsTo(time)*myPlayer->getFrameRate();
}

QTime MainWindow::getFormattedTime1(int timeInSeconds)
{
    timeInSeconds/=(int) myPlayer->getFrameRate();
    int seconds = (int) (timeInSeconds) % 60 ;
    int minutes = (int) ((timeInSeconds / 60) % 60);
    int hours   = (int) ((timeInSeconds / (60*60)) % 24);

        QTime t(hours, minutes, seconds);
        return t;
}

QString MainWindow::getFormattedTime(int timeInSeconds)
{
    int seconds = (int) (timeInSeconds) % 60 ;
    int minutes = (int) ((timeInSeconds / 60) % 60);
    int hours   = (int) ((timeInSeconds / (60*60)) % 24);

    QTime t(hours, minutes, seconds);
    if (hours == 0 )
        return t.toString("mm:ss");
    else
        return t.toString("h:mm:ss");
}



void MainWindow::on_horizontalSlider_sliderPressed()
{

    myPlayer->Stop();
}

void MainWindow::on_horizontalSlider_sliderReleased()
{
    cout<< "ui->horizontalSlider->value()" << ui->horizontalSlider->value() << endl;
    cout<<"ui->horizontalSlider->value()1 "<<  timeToFrames(getFormattedTime1(ui->horizontalSlider->value())) <<endl;
    cout<<"ui->horizontalSlider->value()2 "<< (int)(ui->horizontalSlider->value()/myPlayer->getFrameRate()) <<endl;
    cout<<"ui->horizontalSlider->value()3 "<< (int) (ui->horizontalSlider->value()/myPlayer->getFrameRate()) * myPlayer->getFrameRate()<<endl;
    cout<< "---------------------------" <<endl;
    load_image(ui->horizontalSlider->value());
}

void MainWindow::load_image(int position)
{
    QImage img1;
    Mat frame1,RGBframe1;
    myPlayer->setCurrentFrame(position-1);

    myPlayer->capture->read(frame1);
    if (frame1.channels()== 3){
        cv::cvtColor(frame1, RGBframe1,     cv::COLOR_RGB2BGR
);
        img1 = QImage((const unsigned char*)(RGBframe1.data),
                          RGBframe1.cols,RGBframe1.rows,QImage::Format_RGB888);
    }
    else
    {
        img1 = QImage((const unsigned char*)(frame1.data),
                             frame1.cols,frame1.rows,QImage::Format_Indexed8);
    }

    updatePlayerUI(img1);
}


void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    myPlayer->setCurrentFrame(position);
    ui->label_CurrentTime->setText( getFormattedTime( position/(int)myPlayer->getFrameRate()) );
    //load_image(position);
}

void MainWindow::updatePlayerUI(QImage img)
{
    if (!img.isNull())
    {
        ui->label_Screen->setAlignment(Qt::AlignCenter);
        ui->label_Screen->setPixmap(QPixmap::fromImage(img).scaled(ui->label_Screen->size(),
                                           Qt::KeepAspectRatio, Qt::FastTransformation));
        ui->horizontalSlider->setValue(myPlayer->getCurrentFrame());
        ui->label_CurrentTime->setText( getFormattedTime( (int)myPlayer->getCurrentFrame()/(int)myPlayer->getFrameRate()) );
    }
}


void MainWindow::setupPlot(QCustomPlot *customPlot)
{
    // add two new graphs and set their look:
    customPlot->addGraph();
    QPen blueDotPen;
    blueDotPen.setColor(QColor(255, 0, 0));
    blueDotPen.setWidthF(6);

    customPlot->graph(0)->setPen(blueDotPen);
    customPlot->addGraph();
    customPlot->graph(1)->setPen(QPen(Qt::blue)); // line color red for second graph
    customPlot->addGraph(customPlot->xAxis2, customPlot->yAxis2);
    customPlot->graph(2)->setPen(QPen(Qt::blue));

    // pass data points to graphs:
    customPlot->graph(0)->setData(myData->vframe, myData->vcode);

    // configure left axis text labels:
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTick(1, "Attention");
    textTicker->addTick(0, "No-Attention");
    customPlot->yAxis->setTicker(textTicker);
    customPlot->xAxis->setLabel("x");
    customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    customPlot->yAxis->setRange(0, 1.5);
    customPlot->xAxis2->setVisible(true);


    // configure bottom axis to show date instead of number:
    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
    dateTicker->setDateTimeFormat("mm:ss");

//    customPlot->xAxis2->setTickLength(30);
    customPlot->xAxis2->setTicker(dateTicker);

    // same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):
    // Note: we could have also just called customPlot->rescaleAxes(); instead
    // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:
    //customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    customPlot->replot();

}


void MainWindow::on_pushButton_code_clicked()
{
    if (myProcess->isStopped())
    {
        if(stop_coding){
            myProcess->framestart = stoped_code_frame+1;
            stop_coding = false;
        }

        myProcess->modes = myProcess->gaze;
        ui->pushButton_export->setDisabled(true);

        myProcess->Start();
        ui->pushButton_code->setText(tr("Stop"));
    }else
    {
        myProcess->Stop();
        stoped_code_frame = myProcess->cap1->get(CAP_PROP_POS_FRAMES);
        ui->pushButton_code->setText(tr("Start"));
        ui->pushButton_export->setDisabled(false);
        stop_coding = true;
    }
}

void MainWindow::codingFinished()
{

    stoped_code_frame = myProcess->cap1->get(CAP_PROP_POS_FRAMES);
    ui->pushButton_code->setText(tr("Finished"));
}


void MainWindow::clickedGraph(QMouseEvent *event)
{
    int x=ui->barPlot->xAxis->pixelToCoord(event->pos().x());
    if(x>0 && x < myPlayer->getNumberOfFrames())
    load_image(x);

}

void MainWindow::elapseTime(double time)
{
    ui->label_elapse_time->setText(QString::number(time/1000000000.0));
}

void MainWindow::manageTable()
{
        model_table->setHorizontalHeaderItem(0, new QStandardItem(QString("TimeStamp")));
        model_table->setHorizontalHeaderItem(1, new QStandardItem(QString("Attention")));

        for(int i = 0; i < myData->vtable_med_code.size() ; i++ )
        {
            model_table->setItem(i,0,new QStandardItem(getFormattedTime(myData->vtable_med_code.at(i)[0])));
            QString code = (myData->vtable_med_code.at(i)[1] == 1)? "ONT" : "OFT";
            model_table->setItem(i,1,new QStandardItem(code));

        }

        ui->tableView_code->setModel(model_table);
}

void MainWindow::on_pushButton_export_clicked()
{
//    QString textData;
//    int rows = model_table->rowCount();
//    int columns = model_table->columnCount();

//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < columns; j++) {

//                textData += model_table->data(model_table->index(i,j)).toString();
//                textData += " " ;     // for .csv file format
//        }
//        textData += "\n";             // (optional: for new line segmentation)
//    }

    QString textData;
    int rows = myProcess->result_vector.size();
//    int columns = model_table->columnCount();

    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < columns; j++) {

       textData +=  QString::number(myProcess->result_vector.at(i).head_angle_x);
       textData += " " ;
       textData +=  QString::number(myProcess->result_vector.at(i).head_angle_y);
       textData += " " ;
       textData +=  QString::number(myProcess->result_vector.at(i).head_angle_z);
       textData += " " ;
       textData +=  QString::number(myProcess->result_vector.at(i).left_eye_loc_x);
       textData += " " ;
       textData +=  QString::number(myProcess->result_vector.at(i).left_eye_loc_y);
       textData += " " ;
       textData +=  QString::number(myProcess->result_vector.at(i).right_eye_loc_x);
       textData += " " ;
       textData +=  QString::number(myProcess->result_vector.at(i).right_eye_loc_y);
       textData += " " ;
       textData +=  QString::number(myProcess->result_vector.at(i).face_found);
       textData += " " ;
       textData +=  QString::number(myProcess->result_vector.at(i).frame_idx);
//        }
        textData += "\n";             // (optional: for new line segmentation)
    }

    QString tPath = QFileDialog::getSaveFileName(this, tr("Save File"), "",tr("Text Files (*.txt)"));

    QFile txtFile(tPath);
    if(txtFile.open(QIODevice::WriteOnly | QIODevice::Truncate)) {

        QTextStream out(&txtFile);
        out << textData;

        txtFile.close();
    }



    QString textData2;
    textData2 += "Video: ";
    textData2 += filename;
    textData2 += "\n";
    textData2 += "Started at: ";
    textData2 += getFormattedTime1( myProcess->framestart).toString("h:mm:ss");
    textData2 += " Finished at: ";
    textData2 += getFormattedTime1(stoped_code_frame).toString("h:mm:ss");
    textData2 += "\n";
    textData2 += "Coding time: ";
    textData2 += ui->label_elapse_time->text();
    textData2 += "\n";
    textData2 += "Video frame rate: ";
    textData2 += QString::number( myPlayer->getFrameRate() );
    textData2 += "\n";
    textData2 += "Coding results stored in: ";
    textData2 += tPath;
    textData2 += "\n";
    textData2 += "--------------------Parameters-------------------\n";
    textData2 += "Neural Blob: Width ";
    textData2 += QString::number( myProcess->inWidth);
    textData2 += " Height ";
    textData2 += QString::number(myProcess->inHeight);
    textData2 += "\n";
    textData2 += "Face model size: Width ";
    textData2 += QString::number(myProcess->im_rec_width);
    textData2 += " Height ";
    textData2 += QString::number(myProcess->im_rec_height);

    if(save_load_facerec_model){
        textData2 += "\n";
        textData2 += "Face model file: ";
        textData2 +=facerec_Path;
    }


    QFile txtFile2(tPath+".info");
    if(txtFile2.open(QIODevice::WriteOnly | QIODevice::Truncate)) {

        QTextStream out2(&txtFile2);
        out2 << textData2;

        txtFile2.close();
    }

}

void MainWindow::on_spinBox_filter_valueChanged(int arg1)
{
    if(stop_coding){
        myData->manageData((int)myPlayer->getFrameRate(),arg1);
        setupPlot(ui->barPlot);
        manageTable();
    }

}

void MainWindow::on_radioButton_clicked(bool checked)
{
        myProcess->showpoints = checked;
}

void MainWindow::horzScrollBar_plot_Changed(int value)
{
  if (qAbs(ui->barPlot->xAxis->range().center()-value/1.0) > 0.01) // if user is dragging plot, we don't want to replot twice
  {
    ui->barPlot->xAxis->setRange(value, ui->barPlot->xAxis->range().size(), Qt::AlignCenter);
    ui->barPlot->xAxis2->setRange(value, ui->barPlot->xAxis->range().size(), Qt::AlignCenter);
    ui->barPlot->replot();
  }
}

void MainWindow::xAxisChanged(QCPRange range)
{
  ui->horizontalScrollBar_plot->setValue(qRound(range.center()*1.0)); // adjust position of scroll bar slider
  ui->horizontalScrollBar_plot->setPageStep(qRound(range.size()*1.0)); // adjust size of scroll bar slider
}


void MainWindow::on_listWidget_rec_itemSelectionChanged()
{
    QModelIndexList indexes_rec = ui->listWidget_rec->selectionModel()->selectedIndexes();
    cout<< indexes_rec.size() <<endl;
    ui->label_rec_item_selected->setText(QString::number( indexes_rec.size() ));
    total_rec_item_selected = indexes_rec.size();
}

void MainWindow::on_pushButton_start_rec_clicked()
{
     ui->progressBar_rec->setMaximum(myProcess->framestop);
     ui->progressBar_rec->setMinimum(myProcess->framestart + 1);

    if (myProcess->isStopped())
    {
        myProcess->modes = myProcess->train;
        myProcess->Start();
        ui->pushButton_start_rec->setText(tr("Stop"));

    }else
    {
        myProcess->Stop();
        ui->pushButton_start_rec->setText(tr("Start"));
        showFaces(); // problema al reintentar: redundancia en calculos

    }

}

void MainWindow::showFaces()
{
    ui->listWidget_rec->clear();
    for(int i=0;i<myProcess->preTrainingFaces.size();i++)
    {
        cv::resize(myProcess->preTrainingFaces[i],myProcess->preTrainingFaces[i], Size(myProcess->im_rec_width,myProcess->im_rec_height), 0, 0, INTER_LINEAR_EXACT);
        QImage img1;
        Mat RGBframe1;
        cv::cvtColor(myProcess->preTrainingFaces[i], RGBframe1, cv::COLOR_RGB2BGR);
        img1 = QImage((const unsigned char*)(RGBframe1.data),
                        RGBframe1.cols,RGBframe1.rows,QImage::Format_RGB888);
        ui->listWidget_rec->addItem(new QListWidgetItem(QPixmap::fromImage(img1),""));

    }
}

void MainWindow::preTrainFinished()
{
    ui->progressBar_rec->setValue(myProcess->framestop);
    ui->pushButton_start_rec->setText(tr("Finished"));
    showFaces();
}

void MainWindow::on_pushButton_add_rec_clicked()
{
    QModelIndexList indexes_rec = ui->listWidget_rec->selectionModel()->selectedIndexes();
    std::vector<int> indexList;
    foreach(QModelIndex index, indexes_rec){
        indexList.push_back(index.row());
        myProcess->TrainingFaces.push_back(myProcess->preTrainingFaces[index.row()]);
        myProcess->labels.push_back(ui->listWidget_class_rec->model()->rowCount());

    }

    if(indexList.size()>0 && ui->lineEdit_classname_rec->text() != ""){
    QImage img1;
    Mat RGBframe1;
    cv::cvtColor(myProcess->preTrainingFaces[indexList[0]], RGBframe1, cv::COLOR_RGB2BGR);
    img1 = QImage((const unsigned char*)(RGBframe1.data),
                    RGBframe1.cols,RGBframe1.rows,QImage::Format_RGB888);
    ui->listWidget_class_rec->addItem(new QListWidgetItem(QPixmap::fromImage(img1),ui->lineEdit_classname_rec->text()));
    ui->listWidget_rec->selectedItems().clear();
    ui->listWidget_rec->clearSelection();
    ui->lineEdit_classname_rec->clear();

    }

}


void MainWindow::on_pushButton_remove_class_clicked()
{
    QList<QListWidgetItem*> items = ui->listWidget_class_rec->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        delete ui->listWidget_class_rec->takeItem(ui->listWidget_class_rec->row(item));
    }

}


void MainWindow::on_pushButton_clear_rec_clicked()
{
    ui->listWidget_rec->clearSelection();
}

void MainWindow::on_pushButton_ready_rec_clicked()
{
    myProcess->faceRecognitionTraining();

    myProcess->framestart = 0;
    myProcess->framestop = (int)myPlayer->getNumberOfFrames();
    ui->timeEdit_start_code->setTime(getFormattedTime1( myProcess->framestart ));
    ui->timeEdit_end_code->setTime(getFormattedTime1( myProcess->framestop ));

    ui->progressBar_code->setMinimum(1);
    ui->progressBar_code->setMaximum(myProcess->framestop);

    //Habilitar coding
    enable_coding = true;
}


void MainWindow::on_pushButton_minus_clicked()
{
    current_frame = timeToFrames(getFormattedTime1(ui->horizontalSlider->value()));

    if(current_frame-myPlayer->getFrameRate()>0)
         load_image(current_frame-myPlayer->getFrameRate());
    else
         load_image(0);
}

void MainWindow::on_pushButton_plus_clicked()
{
    current_frame = timeToFrames(getFormattedTime1(ui->horizontalSlider->value()));

    if(current_frame+myPlayer->getFrameRate()<=myPlayer->getNumberOfFrames())
         load_image(current_frame + myPlayer->getFrameRate());
    else
        load_image((int)(myPlayer->getNumberOfFrames()));
}



void MainWindow::on_pushButton_set_start_rec_clicked()
{
    myVideoPos1->show();
    pos_idx = start;
}

void MainWindow::on_pushButton_set_end_rec_clicked()
{
    myVideoPos1->show();
    pos_idx = end;
}

void MainWindow::faceAtPosition1()
{
    current_frame = timeToFrames(getFormattedTime1(ui->horizontalSlider->value()));

    switch (pos_idx) {
    case start:

        if(timeToFrames(ui->timeEdit_end_rec->time()) < current_frame){
        myProcess->framestart = timeToFrames(ui->timeEdit_end_rec->time()) - (int)myPlayer->getFrameRate();
        }else{
        myProcess->framestart = current_frame;
        }
        ui->timeEdit_start_rec->setTime(getFormattedTime1( myProcess->framestart ));
//        ui->progressBar_rec->setMinimum(myProcess->framestart);


        break;
    case end:

        if(timeToFrames(ui->timeEdit_start_rec->time()) > current_frame){
        myProcess->framestop = timeToFrames(ui->timeEdit_start_rec->time()) + (int)myPlayer->getFrameRate();
        }else{
        myProcess->framestop = current_frame;
        }
        ui->timeEdit_end_rec->setTime(getFormattedTime1( myProcess->framestop ));
//        ui->progressBar_rec->setMaximum(myProcess->framestop);

        cout<<"framestop "<< myProcess->framestop <<endl;

        break;
    default:
        break;
    }

}

void MainWindow::faceAtPosition2()
{
    current_frame = timeToFrames(getFormattedTime1(ui->horizontalSlider->value()));

    switch (pos_idx) {
    case start:

        if(timeToFrames(ui->timeEdit_end_code->time()) < current_frame){
        myProcess->framestart = timeToFrames(ui->timeEdit_end_code->time()) - (int)myPlayer->getFrameRate();
        }else{
        myProcess->framestart = current_frame;
        }
        ui->timeEdit_start_code->setTime(getFormattedTime1( myProcess->framestart ));

        break;
    case end:

        if(timeToFrames(ui->timeEdit_start_code->time()) > current_frame){
        myProcess->framestop = timeToFrames(ui->timeEdit_start_code->time()) + (int)myPlayer->getFrameRate();
        }else{
        myProcess->framestop = current_frame;
        }
        ui->timeEdit_end_code->setTime(getFormattedTime1( myProcess->framestop ));

        break;
    default:
        break;
    }

}


void MainWindow::on_pushButton_set_start_code_clicked()
{
    myVideoPos2->show();
    pos_idx = start;

}

void MainWindow::on_pushButton_set_end_code_clicked()
{
    myVideoPos2->show();
    pos_idx = end;

}

void MainWindow::on_timeEdit_start_rec_editingFinished()
{
    current_frame = timeToFrames(ui->timeEdit_start_rec->time());

    if(timeToFrames(ui->timeEdit_end_rec->time()) < current_frame){
    myProcess->framestart = timeToFrames(ui->timeEdit_end_rec->time()) - (int)myPlayer->getFrameRate();
    ui->timeEdit_start_rec->setTime(getFormattedTime1(myProcess->framestart));
    }else{
    myProcess->framestart = current_frame;
    }
//    ui->progressBar_rec->setMinimum(myProcess->framestart);

    cout<< current_frame <<endl;
    load_image(current_frame);

}

void MainWindow::on_timeEdit_end_rec_editingFinished()
{
    current_frame = timeToFrames(ui->timeEdit_end_rec->time());

    if(timeToFrames(ui->timeEdit_start_rec->time()) > current_frame){
    myProcess->framestop = timeToFrames(ui->timeEdit_start_rec->time()) + (int)myPlayer->getFrameRate();
    ui->timeEdit_end_rec->setTime(getFormattedTime1(myProcess->framestart));

    }else{
    myProcess->framestop = current_frame;
    }
//    ui->progressBar_rec->setMaximum(myProcess->framestop);
    load_image(current_frame);

}

void MainWindow::on_timeEdit_start_code_editingFinished()
{
    current_frame = timeToFrames(ui->timeEdit_start_code->time());

    if(timeToFrames(ui->timeEdit_end_code->time()) < current_frame){
    myProcess->framestart = timeToFrames(ui->timeEdit_end_code->time()) - (int)myPlayer->getFrameRate();
    ui->timeEdit_start_code->setTime(getFormattedTime1(myProcess->framestart));

    }else{
    myProcess->framestart = current_frame;
    }
    ui->progressBar_code->setMinimum(myProcess->framestart);
    load_image(current_frame);

}

void MainWindow::on_timeEdit_end_code_editingFinished()
{
    current_frame = timeToFrames(ui->timeEdit_end_code->time());

    if(timeToFrames(ui->timeEdit_start_code->time()) > current_frame){
    myProcess->framestop = timeToFrames(ui->timeEdit_start_code->time()) + (int)myPlayer->getFrameRate();
    ui->timeEdit_end_code->setTime(getFormattedTime1(myProcess->framestart));

    }else{
    myProcess->framestop = current_frame;
    }
    ui->progressBar_code->setMaximum(myProcess->framestop);
    load_image(current_frame);

}

void MainWindow::on_pushButton_load_rec_clicked()
{
    facerec_Path = QFileDialog::getOpenFileName(this, tr("load File"), "",tr("Text Files (*.yml)"));
    myProcess->loadFaceModel(facerec_Path.toStdString());

    myProcess->framestart = 0;
    myProcess->framestop = (int)myPlayer->getNumberOfFrames();
    ui->timeEdit_start_code->setTime(getFormattedTime1( myProcess->framestart ));
    ui->timeEdit_end_code->setTime(getFormattedTime1( myProcess->framestop ));

    save_load_facerec_model =true;
    //Habilitar coding
    enable_coding = true;
    ui->progressBar_code->setMinimum(1);
    ui->progressBar_code->setMaximum(myProcess->framestop);

}

void MainWindow::on_pushButton_save_rec_clicked()
{
    facerec_Path = QFileDialog::getSaveFileName(this, tr("Save File"), "",tr("Text Files (*.yml)"));
    cout<< "tPath "<< facerec_Path.toStdString() <<endl;
    myProcess->saveFaceModel(facerec_Path.toStdString());
//    QFile txtFile(tPath);

   save_load_facerec_model=true;

   myProcess->framestart = 0;
   myProcess->framestop = (int)myPlayer->getNumberOfFrames();
   ui->progressBar_code->setMinimum(1);
   ui->progressBar_code->setMaximum(myProcess->framestop);

}
