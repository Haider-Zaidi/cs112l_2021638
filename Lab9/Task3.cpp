#include<iostream>
#include<math.h>
using namespace std;

// Lab 9 Task 3

class Shape{

protected:
    float length;
    float width;

public:

    Shape()
    {
        length = 0;
        width = 0;
    }

    Shape(float len, float wid)
    {
        length = len;
        width = wid;
    }

    virtual void setValues()
    {
        cout << "\nEnter the Length: ";
        cin >> length;
        cout << "Enter the Width: ";
        cin >> width;
    }

    virtual float area()=0;

    virtual void getValues()
    {
        cout << "\nLength: " << length << " units" << endl;
        cout << "Width: " << width << " units" << endl;
    }
};

class TwoD: public Shape{

public:

    TwoD():Shape()
    {
        length = 0;
        width = 0;
    }

    TwoD(float len, float wid):Shape(len, wid){}

    virtual void setValues()
    {
        cout << "\nEnter the Length: ";
        cin >> length;
        cout << "Enter the Width: ";
        cin >> width;
    }

    virtual float area()=0;

    virtual void getValues()
    {
        cout << "\nLength: " << length << " units" << endl;
        cout << "Width: " << width << " units" << endl;
    }
};

class ThreeD: public Shape{

public:

    ThreeD():Shape()
    {
        length = 0;
        width = 0;
    }

    ThreeD(float len, float wid):Shape(len, wid){}

    virtual void setValues()
    {
        cout << "\nEnter the Length: ";
        cin >> length;
        cout << "Enter the Width: ";
        cin >> width;
    }

    virtual float area()=0;
    virtual float volume()=0;

    virtual void getValues()
    {
        cout << "\nLength: " << length << " units" << endl;
        cout << "Width: " << width << " units" << endl;
    }

};

class Circle: public TwoD{

private:
    float radius;
    string colour;

public:

    Circle():TwoD()
    {
        radius = 0;
        colour = " ";
    }

    Circle(float rad, string col)
    {
        radius = rad;
        colour = col;
    }

    void setValues()
    {
        cout << "\nEnter the Radius: ";
        cin >> radius;
        cout << "Enter the Colour: ";
        cin >> colour;
    }

    float area()
    {
        return M_PI*pow(radius, 2);
    }

    void getValues()
    {
        cout << "\nRadius: " << radius << " units" <<endl;
        cout << "Colour: " << colour << endl;
        cout << "Area: " << area() << " units^2" << endl;
    }
};

class Square: public TwoD{

private:
    float side;
    string colour;

public:

    Square():TwoD()
    {
        side = 0;
        colour = " ";
    }

    Square(float s, string col)
    {
        side = s;
        colour = col;
    }

    void setValues()
    {
        cout << "\nEnter the Side Length: ";
        cin >> side;
        cout << "Enter the Colour: ";
        cin >> colour;
    }

    float area()
    {
        return pow(side, 2);
    }

    void getValues()
    {
        cout << "\nSide Length: " << side << " units" << endl;
        cout << "Colour: " << colour << endl;
        cout << "Area: " << area() << " units^2" << endl;
    }
};

class Cube: public ThreeD{

private:
    float height;

public:

    Cube():ThreeD()
    {
        height = 0;
    }

    Cube(float len, float wid, float hei):ThreeD(len, wid){
        height = hei;
    }

    void setValues()
    {
        Shape::setValues();
        cout << "Enter the Height: ";
        cin >> height;    
    }

    float area()
    {
        if(length == width && length == height && width == height)
            return 6*pow(height, 2);
        else
            cout << "Dimensions are not equal" << endl;
            return 0;
    }

    float volume()
    {
        if(length == width && length == height && width == height)
            return length*width*height;
        else   
            cout << "Dimensions are not equal" << endl;
            return 0;
    }


    void getValues()
    {
        Shape::getValues();
        cout << "Height: " << height << " units" << endl;
        cout << "Area: " << area() << " units^2" << endl;
        cout << "Volume: " << volume() << " units^3" << endl;
    }

};

class Pyramid: public ThreeD{

private:
    float base;
    float height;

public:

    Pyramid():ThreeD()
    {
        height = 0;
        base = length*width;
    }

    void setValues()
    {
        Shape::setValues();
        cout << "Enter the Height: ";
        cin >> height;    
    }

    float area()                                    
    {
        return (length*width) + (length * sqrt(pow(width/2, 2) + pow(height, 2))) + (width * sqrt(pow(length/2, 2) + pow(height, 2)));
    }

    float volume()
    {
        return (length*width*height)/3;
    }

    void getValues()
    {
        Shape::getValues();
        cout << "Height: " << height << " units" << endl;
        cout << "Base Area: " << length*width << " units^2" << endl;
        cout << "Area: " << area() << " units^2" << endl;
        cout << "Volume: " << volume() << " units^3" << endl;
    }
    
};

bool exit()
{
    char in;
    cout << "\nPress Y/y to Exit or Any other key to continue: ";
    cin >> in;

    if(in == 'Y' || in == 'y')
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{

    Shape* s1;
    Shape* s2;
    Shape* s3;
    Shape* s4;

    Circle cir;
    Square sq;
    Cube cu;
    Pyramid py;

    s1 = &cir;
    s2 = &sq;
    s3 = &cu;
    s4 = &py;

    int menu;
    bool running = true;
    
    while (running)
    {
       cout << "\n\n********** MENU **********\n\n(Following Methods are invoked through Shape Class Pointers)\n" << endl;
       cout << "Enter 1 for Setting Values for Circle Class" << endl;
       cout << "Enter 2 for Getting Values for Circle Class" << endl;
       cout << "Enter 3 for Setting Values for Square Class" << endl;
       cout << "Enter 4 for Getting Values for Square Class" << endl;
       cout << "Enter 5 for Setting Values for Cube Class" << endl;
       cout << "Enter 6 for Getting Values for Cube Class" << endl;
       cout << "Enter 7 for Setting Values for Pyramid Class" << endl;
       cout << "Enter 8 for Getting Values for Pyramid Class" << endl;
       cout << "Enter 9 to Exit" << endl;
       cout << "\n\nEnter Option: ";
       cin >> menu;
    
       switch (menu)
       {
            case 1:
                s1->setValues();
                cout << endl << "Enter 2 in the Main Menu to see the result" << endl;
                running = exit();
                break;
    
            case 2:
                s1->getValues();
                running = exit();
                break;
    
            case 3:
                s2->setValues();
                cout << endl << "Enter 4 in the Main Menu to see the result" << endl;
                running = exit();
                break;
    
            case 4:
                s2->getValues();
                running = exit();
                break;

            case 5:
                s3->setValues();
                cout << endl << "Enter 6 in the Main Menu to see the result" << endl;
                running = exit();
                break;
    
            case 6:
                s3->getValues();
                running = exit();
                break;

            case 7:
                s4->setValues();
                cout << endl << "Enter 8 in the Main Menu to see the result" << endl;
                running = exit();
                break;
    
            case 8:
                s4->getValues();
                running = exit();
                break;

            case 9:
                running = false;
                break;    

            default:
                cout << "\nWrong Input\n";
                break;
        }
    }

    return 0;
}