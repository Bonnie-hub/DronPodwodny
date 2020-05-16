#include "SixPrism.hh"

SixPrism::SixPrism(const Vector3D node, const Vector3D & center, const MatrixRot & rotation, std::shared_ptr<drawNS::Draw3DAPI> gnuptr)
: Figure(rotation, center, gnuptr)
{
    for(int i=0; i<12; i++)
    {
        Node=node;
    }
}

SixPrism::~SixPrism()
{
    
}

void SixPrism::draw()
{
    using namespace std;
    MatrixRot PomRot(60.0), PomRot2=Rotation;
    Vector3D P[12];
    for (int i=0; i<6; i++)
    {
        PomRot2*=PomRot;
        P[i]=Center+PomRot2*Node;
        P[i+6]=Center+PomRot2*Node;
        P[i+6][2]=-Node[2];
    }
    GnuPtr->erase_shape(Id);
    Id=GnuPtr->draw_polyhedron(vector<vector<drawNS::Point3D>>
    {{P[0].P3D(),P[1].P3D(),P[2].P3D(),P[3].P3D(),P[4].P3D(),P[5].P3D()},
    {P[6].P3D(),P[7].P3D(),P[8].P3D(),P[9].P3D(),P[10].P3D(),P[11].P3D()}},
    "blue");
    GnuPtr->redraw();
}

void SixPrism::move(double length, double angle)
{
    double dane[3]={length/100,0,0};
    Vector3D move(dane);
    MatrixRot PomRot(angle);
    std::cout<<"Rotacja przed: "<<std::endl<<Rotation<<std::endl;
    PomRot*=Rotation;
    
    std::cout<<"PomRot*move: "<<std::endl<<PomRot*move<<std::endl;
    
    //Rotation*=PomRot;
    std::cout<<"Center przed: "<<std::endl<<Center<<std::endl;
    for (int i=0; i<100; i++)
    {
        Center+=PomRot*move;    
        GnuPtr->erase_shape(Id);
        draw();
    }
    std::cout<<"Center po: "<<std::endl<<Center<<std::endl;
}

void SixPrism::moveUpDown(double length, double angle)
{
    double dane[3]={length/100,0,0}, pi=3.14, rad=pi*angle/180;
    //std::cout<<"Rad: "<<rad<<std::endl;
    double daneRot[3][3]={{cos(rad),0,sin(rad)},{0,1,0},{-sin(rad),0,cos(rad)}};
    Vector3D move(dane);
    SMacierz<double,3> Mat1(daneRot);
    MatrixRot PomRot(Mat1);
    move=Rotation*move;

    for (int i=0; i<100; i++)
    {
        Center+=PomRot*move;
        GnuPtr->erase_shape(Id);
        draw();
    }
}

void SixPrism::rotate(double angle)
{
    MatrixRot PomRot(angle/100);    
    for (int i=0; i<100; i++)
    {
        Rotation*=PomRot;
        GnuPtr->erase_shape(Id);
        draw();
    }
}