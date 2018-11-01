#include "videoposition.h"
#include "ui_videoposition.h"

VideoPosition::VideoPosition(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VideoPosition)
{
    ui->setupUi(this);

}

VideoPosition::~VideoPosition()
{
    delete ui;
}

void VideoPosition::on_pushButton_cancel_clicked()
{

    emit doneFlag();
    this->close();
}

void VideoPosition::on_pushButton_done_clicked()
{
    emit doneFlag();
    this->close();

}
