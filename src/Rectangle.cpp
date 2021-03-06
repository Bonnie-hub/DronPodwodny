#include"Rectangle.hh"


Rectangle::Rectangle(const Vector3D *nodes, const Vector3D &center, const MatrixRot &rotation, std::shared_ptr<drawNS::Draw3DAPI> gnuptr,const std::string & color)
: Figure(rotation, center, gnuptr, color)
{
    
    for(int i=0; i<8; i++)
    {
        Nodes[i] = nodes[i];
    }
}

Rectangle::~Rectangle()
{}

void Rectangle::move(double length)
{
    double dane[3]={length,0,0};
    Vector3D move(dane);
    Center+=Rotation*move;    
}

void Rectangle::move_to(const Vector3D & vec)
{
    Center = vec;
    draw();
}

void Rectangle::move_to(double x,double y,double z)
{
    Center[0]=x;
    Center[1]=y;
    Center[2]=z;
    draw();
}

void Rectangle::moveUpDown(double length, double angle)
{
    double dane[3]={length,0,0}, pi=3.14, rad=pi*angle/180;
    double daneRot[3][3]={{cos(rad),0,sin(rad)},{0,1,0},{-sin(rad),0,cos(rad)}};
    Vector3D move(dane);
    SMacierz<double,3> Mat1(daneRot);
    MatrixRot PomRot(Mat1);
    Center+=Rotation*(PomRot*move);
}

void Rectangle::rotate(double angle)
{
    MatrixRot PomRot(angle);    
    Rotation*=PomRot;
}

void Rectangle::rotateY(double angle)
{
    double pi=3.14, rad=pi*angle/180;
    double daneRot[3][3]={{cos(rad),0,sin(rad)},{0,1,0},{-sin(rad),0,cos(rad)}};
    SMacierz<double,3> Mat1(daneRot);
    MatrixRot PomRot(Mat1);
    Rotation*=PomRot;
}

void Rectangle::rotateX(double angle)
{
    double pi=3.14, rad=pi*angle/180;
    double daneRot[3][3]={{1,0,0},{0,cos(rad),-sin(rad)},{0,sin(rad),cos(rad)}};
    SMacierz<double,3> Mat1(daneRot);
    MatrixRot PomRot(Mat1);
    Rotation*=PomRot;
}

MatrixRot const Rectangle::GetRotation() const
{
    return Rotation;
}

void Rectangle::draw()
{
    using namespace std;
    
    Vector3D P[8];
    for (int i=0; i<8; i++)
    {
        P[i]=Center+Rotation*Nodes[i]; 
    }
    GnuPtr->erase_shape(Id);
    Id=GnuPtr->draw_polyhedron(vector<vector<drawNS::Point3D>>{{P[0].P3D(),P[1].P3D(),
    P[2].P3D(),P[3].P3D()},{P[4].P3D(),P[5].P3D(),P[6].P3D(),P[7].P3D()}},Color);
}

Vector3D & Rectangle::GetCenter()
{
    return Center;
}
/*
int Rectangle::AmountFigures()
{
    return HowManyFigures;
}
*/