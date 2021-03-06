#include"Figure.hh"


#ifndef RECTANGLE
#define RECTANGLE


/*!
* \brief Klasa Rectangle, przedstawiająca prostopadłościan
*/
class Rectangle : public Figure
{
    protected:
    //static int HowManyFigures;
    /*!
    * \brief Wierzchołki prostopadłościanu
    */
    Vector3D Nodes[8];
    
    public:
    /*!
    * \brief Usunięty bezparametryczny konstruktor
    */
    Rectangle() = delete;
    /*!
    * \brief Konstruktor z parametrami
    * \param nodes Wierzchołki figury
    * \param center Środek figury
    * \param rotation Rotacja figury
    * \param gnuptr Wkaźnik do łącza do gnuplota
    * \param color Kolor figury
    */
    Rectangle(const Vector3D *nodes, const Vector3D &center, const MatrixRot &rotation, std::shared_ptr<drawNS::Draw3DAPI> gnuptr,const std::string & color);
    /*!
    * \brief Destruktor
    */
    ~Rectangle();
    /*!
    * \brief Narysowanie figury
    */
    void draw() override;
    /*!
    * \brief Przesunięcie prostopadłościanu o daną długość na wprost
    * \param length Długość przesunięcia
    */ 
    void move(double length) override;
    /*!
    * \brief Teleportacja figury
    * \param vec Wektor wpółrzednej
    */
    void move_to(const Vector3D & vec)override;
    /*!
    * \brief Natychmiastowe narysowanie figury w podanym miejscu
    * \param x Koordynaty X
    * \param y Koordynaty Y
    * \param z Koordynaty Z
    */
    void move_to(double x,double y,double z)override;
    /*!
    * \brief Poruszanie drona do przodu pod kątem
    * \param length Długość przesunięcia 
    * \param angle Kąt przesunięcia
    */
    void moveUpDown(double length, double angle) override;
    /*!
    * \brief Obrót drona
    * \param angle Kąt obrotu
    */
    void rotate(double angle) override;
    /*!
    * \brief Obrót drona oś Y)
    * \param angle Kąt obrotu
    */
    void rotateY(double angle)override;
    /*!
    * \brief Obrót drona oś X
    * \param angle Kąt obrotu
    */
    void rotateX(double angle)override;
    /*!
    * \brief Zwrócenie macierzy rotacji figury
    */
    MatrixRot const GetRotation() const;
    /*!
    * \brief Zwrócenie środka figury
    */
    Vector3D & GetCenter()override;

    //int AmountFigures()override;
};

//int Rectangle::HowManyFigures=0;

#endif