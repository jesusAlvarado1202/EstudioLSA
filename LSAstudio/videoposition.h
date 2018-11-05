#ifndef VIDEOPOSITION_H
#define VIDEOPOSITION_H

#include <QDialog>

namespace Ui {
class VideoPosition;
}

class VideoPosition : public QDialog
{
    Q_OBJECT

public:
    explicit VideoPosition(QWidget *parent = 0);
    ~VideoPosition();

//    bool done_flag;
signals:
    void doneFlag();

private slots:
    void on_pushButton_cancel_clicked();

    void on_pushButton_done_clicked();

private:
    Ui::VideoPosition *ui;
};

#endif // VIDEOPOSITION_H
