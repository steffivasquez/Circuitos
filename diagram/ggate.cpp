#include "diagram/ggate.h"

GGate::GGate(int x, int y, long id)
{
    m_id = id;

    setX(x-70);
    setY(y-40);

    setFlag(QGraphicsPixmapItem::ItemIsMovable, true);

    m_vertexA = new GVertex(0, 0, 20, 20, GVertex::LEFT, this);
    m_vertexB = new GVertex(0, 0, 20, 20, GVertex::RIGHT, this);

    moveVertexs(x-70, y-40);
}

GGate::~GGate()
{
    if (m_vertexA!=nullptr)
        delete m_vertexA;
    if (m_vertexB!=nullptr)
        delete m_vertexB;
}

void GGate:: mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    QGraphicsItem::mouseMoveEvent(event);
    moveVertexs(x(), y());
}

void GGate::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    emit gateClicked(this);
}

bool GGate::isEqual(GGate *gate)
{
    return (gate->getVertexA()==m_vertexA && gate->getVertexB()==m_vertexB);
}

void GGate::disActiveVertex()
{
    if(m_vertexA!=nullptr) {
        m_vertexA->unSelect();
    }
    if(m_vertexB!=nullptr) {
        m_vertexB->unSelect();
    }
}

void GGate:: moveVertexs(int x, int y) {
    if(m_vertexA != nullptr)
         m_vertexA->setPosition(x-20, y+30);
    if(m_vertexB != nullptr)
        m_vertexB->setPosition(x+150, y+30);
}
