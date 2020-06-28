#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <QWidget>
#include <QGLWidget>
#include <QT>
#include <QTimer>
#include <QVector2D>
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>
#include "objload.h"
#include "vertex.h"
#include "face.h"
#include "camera.h"
#include <QQuaternion>
#include <QObject>
#include <QMatrix4x4>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QGLFramebufferObjectFormat>

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = nullptr);
    bool toggleRotation();
    bool toggleCulling();
    bool toggleTranslation();
    double increaseScale();
    double decreaseScale();
    void setScale();
    void initializeGL();
    void paintGL();
    void drawObject();
    void drawAxes();
    void resetView();
    void grabObj(objLoad objFile);
    void grabColor(double r, double g, double b);
    void resizeGL(int w, int h);
    void mouseMoveEvent(QMouseEvent *e);
    QQuaternion drag2Rotate(float dx, float dy);
    void drag2Translate(float dx, float dy);
    void drag2Zoom(float dy);

    double rotate_y=0;
    double rotate_x=0;
    double rotate_z=0;

private:
    QTimer timer;
    /* .obj Information */
    objLoad *objPtr = 0;
    std::vector<Vertex> vertices;
    std::vector<face> faces;
    std::vector<float> center;
    std::vector<float> maxCoords;
    std::vector<float> minCoords;
    QQuaternion currQ;
    /* Frustrum Things */
    float radius;
    float fdist;
    double dNear;
    double dFar;
    double viewAngle;
    float w0;
    float h0;
    /* User Control */
    camera cam;
    /* Rotation */
    bool mouseHeld;
    bool rotationOK;
    /* Culling */
    bool cullingOK;
    bool translateOK;
    bool scaleOK;
    /* Zoom */
    bool zoomOK;
    float zoomF;
    double scale;
    /* Color Pick */
    double red,green,blue;
    bool needsReset;
    QVector3D axisOfRotation;
    int x,y,dx,dy,x0,y0;
    int prevPos[2];
    float mag;

signals:
    void Mouse_Pressed();
    void Mouse_Pos();
    void Mouse_Released();
protected:
    void mousePressEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *e) Q_DECL_OVERRIDE;

};

#endif // GLWIDGET_H
