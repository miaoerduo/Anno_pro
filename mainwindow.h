#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <string>
namespace Ui {

class MainWindow;
}

class MainWindow : public QMainWindow
{
    enum AnnoState {
        UNKNOWN = 0,  // 未标注
        YES = 1,      // 匹配
        NO = 2,       // 不匹配
        UNSURE = 3    // 不确定
    };
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_save_clicked();

    void on_pushButton_ok_clicked();

    void on_pushButton_no_clicked();

    void on_pushButton_unsure_clicked();

    void on_pushButton_next_clicked();

    void on_pushButton_prev_clicked();

    void on_pushButton_switch_clicked();

    void on_horizontalSlider_progress_sliderReleased();

private:
    void display();

private:
    Ui::MainWindow *ui; // 自带的，ui界面的接口
    std::vector<std::string> image_list_1;  // 用来存放左边的图片的list
    std::vector<std::string> image_list_2;  // 用来存放右边的图片的list
    int current_idx;                        // 当前图片对的id
    int total_pair_num;                     // 总共的图片对的数目
    std::vector< AnnoState > annotation_list;  // 标注的结果
};

#endif // MAINWINDOW_H
