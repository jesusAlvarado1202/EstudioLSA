#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QFileDialog>
#include <QTime>
#include <QModelIndex>
#include <QMessageBox>
#include <treemodel.h>
#include <player.h>
#include <cvprocess.h>
#include <qcustomplot.h>
#include <data.h>
#include <QMutex>
#include <videoposition.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QMutex mutex;
    QString filename;

    bool video_loaded_flag;
    bool stop_coding;
    bool save_load_facerec_model;

    QString facerec_Path;
    int stoped_code_frame;

    int current_frame;
    int total_rec_item_selected;

    //QVector<double> y_2;
    int start_coding_pos,old_start_coding_pos;
    QStandardItemModel *model_table;


    void DisplayBrowsWindow();
    QRect docksize;

    enum posplayer {start,end} pos_idx;
    bool enable_vsproc,enable_coding,enable_analisis;




private slots:

    //void killLoop() { stop_coding = true; }
    //Display video frame in player UI
    void updatePlayerUI(QImage img);

    void on_treeView_project_pressed(const QModelIndex &index);

    void on_pushButton_new_project_clicked();

    void on_pushButton_open_project_clicked();


    void on_horizontalSlider_sliderPressed();

    void on_horizontalSlider_sliderReleased();

    void on_horizontalSlider_sliderMoved(int position);

    QString getFormattedTime(int timeInSeconds);

    void load_image(int position);

//    void load_image1(Mat frame);

    void on_pushButton_Play_clicked();

    void on_pushButton_load_clicked();

//    void manageDock(int position);

//    void on_dockWidget_topLevelChanged(bool topLevel);

//    void on_horizontalSlider_1_sliderMoved(int position);

//    void on_horizontalSlider_1_sliderPressed();

//    void on_pushButton_Play_1_clicked();

    void setupPlot(QCustomPlot *customPlot);

//    void initilize_plot(int length);

//    void manage_plot(int size);

//    void codeProcess();

    void on_pushButton_code_clicked();

//    void on_pushButton_code_toggled(bool checked);

//    void on_pushButton_code_stop_clicked(bool checked);

    void clickedGraph(QMouseEvent *event);

    void elapseTime(double time);

    void manageTable();

    void controlStack(int i);



    void on_pushButton_export_clicked();

    void on_spinBox_filter_valueChanged(int arg1);

    void on_radioButton_clicked(bool checked);

    void horzScrollBar_plot_Changed(int value);

    void xAxisChanged(QCPRange range);

//    void plot_mousewheel(QMouseEvent *event);

    void on_listWidget_rec_itemSelectionChanged();

    void on_pushButton_start_rec_clicked();

    void on_pushButton_add_rec_clicked();

    void on_pushButton_remove_class_clicked();

    void on_pushButton_clear_rec_clicked();

    void on_pushButton_ready_rec_clicked();

    void on_pushButton_set_start_rec_clicked();

    void on_pushButton_minus_clicked();

    void on_pushButton_plus_clicked();

    void faceAtPosition1();

    void faceAtPosition2();

    void on_pushButton_set_end_rec_clicked();

    QTime getFormattedTime1(int timeInSeconds);

    int timeToFrames(QTime time);

    void showFaces();

    void preTrainFinished();

    void codingFinished();







    void on_pushButton_set_start_code_clicked();

    void on_pushButton_set_end_code_clicked();

    void on_timeEdit_start_rec_editingFinished();

    void on_timeEdit_end_rec_editingFinished();

    void on_timeEdit_start_code_editingFinished();

    void on_timeEdit_end_code_editingFinished();

    void on_pushButton_load_rec_clicked();

    void on_pushButton_save_rec_clicked();

private:
    Ui::MainWindow *ui;
    QFileSystemModel *dirmodel;
    Player* myPlayer;
    cvProcess* myProcess;
    Data* myData;
    VideoPosition* myVideoPos1;
    VideoPosition* myVideoPos2;

};

#endif // MAINWINDOW_H
