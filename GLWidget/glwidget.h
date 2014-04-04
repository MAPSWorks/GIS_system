#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QtOpenGL>
#include <QWidget>
#include <QString>
#include"PublicValue.h"
//#include <QtOpenGL>
#include"gps_map.h"
#include"Gps_algorithm.h"
namespace Ui {
class GLWidget;
}

class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    explicit GLWidget(QGLWidget *parent = 0);
    ~GLWidget();
    Gps_map * map;
    Gps_algorithm * al;
    vector <Gps_building> search_begin,search_end;

    void set_al(Gps_algorithm * a);
    void set_map(Gps_map * m);
    void DrawLine(int i,int type);
    void DrawPoint(int id);
    void DrawDirect(int line_id);
    void run();
    void to_here(double x,double y,int choice);

    void path_find();
    QList<QString>  getLoadTxt();
signals:
    void signalSendLocation(QStringList);
protected:
    void getScreenInfo();  //�õ���ǰ�������Ļ�ķֱ���
    void initializeGL();  //��ʼ��OpenGL���ڲ���
    void paintGL();  //��������OpenGL���ڣ�ֻҪ�и��·�������������ͻᱻ����
    void resizeGL(int width, int height); //�����ڴ�С�仯�¼��ģ���������״̬�µĿ�͸�
    void keyPressEvent(QKeyEvent *e);  //��괦����
    void mousePressEvent(QMouseEvent* event);
    void mousehandle();
    void mouseMoveEvent(QMouseEvent *);
    void getCurWinInfo ();
    void resizeEvent(QResizeEvent *);

protected:
    bool fullscreen;  //�ж��Ƿ�ȫ���ı���
    int g_nActScreenW;  //��ǰ�������Ļ�ֱ��ʿ�
    int g_nActScreenH;  //��ǰ�������Ļ�ֱ��ʸ�
    int g_curW;
    int g_curH;
    double focusx,focusy;
    GLfloat rTri;  //��ת
    float Movex;   //�����ƶ�
    float Movey;   //�����ƶ�
    float Scalez;  //ǰ���ƶ�
    float LineWidth; //�����ߵĿ��
    float fovy;//���ӽǶ�
    double div;//��߱�
    double height;//�߶�ֵ
    bool find_best_road;
    int from_id,to_id;
    int find_point();
private:
    Ui::GLWidget *ui;
};

#endif // GLWIDGET_H
