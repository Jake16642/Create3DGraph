#include <iostream>
#include <fstream>
#include <cmath>
#include "Point.hpp"

using namespace std;

void sphere(float,float,float,float,int);
void torus(float,float,float,float,float,int,int);
void cone(float,float,float,float,float,int);
void cylinder(float,float,float,float,float,int);
void truncatedCone(float,float,float,float,float,float,int);
//void nurb(float,float,float,float,int);




int main()
{
    int choice, steps;
    
    cout << "Please choose a following graph you'd like to create \n 1. Sphere \n 2. Torus \n 3. Cone \n 4. Cylinder \n 5. Truncated Cone \n 6. Nurb" << endl;
    cin >> choice;
    
    ofstream WriteFile;
    WriteFile.open("./test.obj",ofstream::out);
    
    Point* P = new Point[4];

    for(int i=0; i<4; i++)
    {
        cout << "Please enter a x coordinate for point " << i+1 << ": ";
        cin >> P[i].x;
        cout << "Please enter a y coordinate for point " << i+1 << ": ";
        cin >> P[i].y;
        cout << "Please enter a z coordinate for point " << i+1 << ": ";
        cin >> P[i].z;
    }
    
    float step;
    int count=0;
    float X, Y, Z;
    cout << "How smooth do you want?";
    cin >> step;
    
    for(float t=0; t<=1; t=t+(1.0/step))
    {
        X = pow((float)(1-t), 3.0)*P[0].x+(pow((float)(3*(1-t)),2.0)*t)*P[1].x+((float)(3*(1-t))*pow(t,2.0))*P[2].x+pow(t,3.0)*P[3].x;
        Y = pow((float)(1-t), 3.0)*P[0].y+(pow((float)(3*(1-t)),2.0)*t)*P[1].y+((float)(3*(1-t))*pow(t,2.0))*P[2].y+pow(t,3.0)*P[3].y;
        Z = pow((float)(1-t), 3.0)*P[0].z+(pow((float)(3*(1-t)),2.0)*t)*P[1].z+((float)(3*(1-t))*pow(t,2.0))*P[2].z+pow(t,3.0)*P[3].z;
        WriteFile <<"v "<< X <<" "<< Y <<" "<< Z << endl;
        count++;
    }
    
    for(int i=1; i<=count; i++)
    {
        WriteFile <<"l "<< i <<" "<< i+1 << endl;
    }
    
    if(choice == 1){
        float radius, x_center, y_center, z_center;
        cout << "Please enter a radius of a sphere: ";
        cin >> radius;
        cout << "Please enter a x coordinate for a center: ";
        cin >> x_center;
        cout << "Please enter a y coordinate for a center: ";
        cin >> y_center;
        cout << "Please enter a z coordinate for a center: ";
        cin >> z_center;
        cout << "How smooth do you want?";
        cin >> steps;
    
        sphere(radius, x_center, y_center, z_center, steps);
    }
    if(choice == 2){
        float radius1, radius2, x_center, y_center, z_center;
        int angle;
        
        cout << "Please enter a radius of a torus: ";
        cin >> radius1;
        cout << "Please enter a radius of a tube: ";
        cin >> radius2;
        cout << "Please enter a x coordinate for a center: ";
        cin >> x_center;
        cout << "Please enter a y coordinate for a center: ";
        cin >> y_center;
        cout << "Please enter a z coordinate for a center: ";
        cin >> z_center;
        cout << "How smooth do you want?";
        cin >> steps;
        cout << "What angle do you want to cut from the torus";
        cin >> angle;
        
        torus(radius1, radius2, x_center, y_center, z_center, steps, angle);
    }
    
    if(choice == 3){
        float height, radius, x_center, y_center, z_center;
        cout << "Please enter a height of a cone: ";
        cin >> height;
        cout << "Please enter a radius of a cone: ";
        cin >> radius;
        cout << "Please enter a x coordinate for a center: ";
        cin >> x_center;
        cout << "Please enter a y coordinate for a center: ";
        cin >> y_center;
        cout << "Please enter a z coordinate for a center: ";
        cin >> z_center;
        cout << "How smooth do you want?";
        cin >> steps;
        
        cone(height, radius, x_center, y_center, z_center, steps);
    }
    
    if(choice == 4){
        float height, radius, x_center, y_center, z_center;
        cout << "Please enter a height of a cylinder: ";
        cin >> height;
        cout << "Please enter a radius of a cylinder: ";
        cin >> radius;
        cout << "Please enter a x coordinate for a center: ";
        cin >> x_center;
        cout << "Please enter a y coordinate for a center: ";
        cin >> y_center;
        cout << "Please enter a z coordinate for a center: ";
        cin >> z_center;
        cout << "How smooth do you want?";
        cin >> steps;
        
        cylinder(height, radius, x_center, y_center, z_center, steps);
    }
    
    if(choice == 5){
        float height, radiusB, radiusT, x_center, y_center, z_center;
        cout << "Please enter a height of a truncated cone: ";
        cin >> height;
        cout << "Please enter a radius of a bottom: ";
        cin >> radiusB;
        cout << "Please enter a radius of a top: ";
        cin >> radiusT;
        cout << "Please enter a x coordinate for a center: ";
        cin >> x_center;
        cout << "Please enter a y coordinate for a center: ";
        cin >> y_center;
        cout << "Please enter a z coordinate for a center: ";
        cin >> z_center;
        cout << "How smooth do you want?";
        cin >> steps;
        
        truncatedCone(height, radiusB, radiusT, x_center, y_center, z_center, steps);
    }
    ifstream ReadFile;
    ReadFile.open("test.obj");
    if(ReadFile.fail())
        cout << "FAIL!";
    else
        cout << "OK!";
    system ("pause");
    return 0;
}
// create truncated Cone
void truncatedCone(float h, float r1, float r2, float X, float Y, float Z, int steps)
{
    float x, y, z;
    
    ofstream WriteFile;
    WriteFile.open("./test.obj",ofstream::out);
    
    float theta;
    float count = (r1-r2)/h;
    
    for(int j = 0; j <= h; j++)
    {
        r1=r1-count;
        for(int i = 0; i <= steps; i++)
        {
            theta = (float)i * ((M_PI*2)/steps);
            x = r1*sin(theta) + X;
            y = j + Y;
            z = r1*cos(theta) + Z;
            WriteFile <<"v "<< x <<" "<< y <<" "<< z << endl;
        }
    }
    
    for(int i = 0; i < h; i++)//number of circle
    {
        for(int j = 0;j < steps;j++)//number vertex on a circle
        {
            int v1 = i*(steps+1)+j+1;
            int nextV1 = (i+1)*(steps+1)+j+1;
            int v2 = v1+1;
            int nextV2 = nextV1 +1;
            
            WriteFile <<"f "<< v1 <<" "<< nextV2 <<" "<< nextV1 << endl;
            WriteFile <<"f "<< v1 <<" "<< v2 <<" "<< nextV2 <<endl;
            
        }
    }
}
// Create cylinder
void cylinder(float h, float r, float X, float Y, float Z, int steps)
{
    float x, y, z;
    
    ofstream WriteFile;
    WriteFile.open("./test.obj",ofstream::out);
    
    float theta;
    
    for(int j = 0; j <= h; j++)
    {
        for(int i = 0; i <= steps; i++)
        {
            theta = (float)i * ((M_PI*2)/steps);
            x = r*cos(theta) + X;
            z = r*sin(theta) + Z;
            y = j + Y;
            WriteFile <<"v "<< x <<" "<< y <<" "<< z << endl;
        }
    }
    
    for(int i = 0; i < h; i++)//number of circle
    {
        for(int j = 0;j < steps; j++)//number vertex on a circle
        {
            int v1 = i*(steps+1)+j+1;
            int nextV1 = (i+1)*(steps+1)+j+1;
            int v2 = v1+1;
            int nextV2 = nextV1 +1;
            
            WriteFile <<"f "<< v1 <<" "<< nextV1 <<" "<< nextV2 << endl;
            WriteFile <<"f "<< v1 <<" "<< nextV2 <<" "<< v2 <<endl;
            
        }
    }
}
// Create cone
void cone(float h, float r, float X, float Y, float Z, int steps)
{
    float x, y, z;
    
    ofstream WriteFile;
    WriteFile.open("./test.obj",ofstream::out);
    
    float theta;
    
    for(int j = 0; j <= h; j++)
    {
        for(int i = 0; i <= steps; i++)
        {
            theta = (float)i * ((M_PI*2)/steps);
            x = ((h-j)/h)*r*cos(theta) + X;
            z = ((h-j)/h)*r*sin(theta) + Z;
            y = j + Y;
            WriteFile <<"v "<< x <<" "<< y <<" "<< z << endl;
        }
    }
    
    for(int i = 0; i < h; i++)//number of circle
    {
        for(int j = 0;j < steps;j++)//number vertex on a circle
        {
            int v1 = i*(steps+1)+j+1;
            int nextV1 = (i+1)*(steps+1)+j+1;
            int v2 = v1+1;
            int nextV2 = nextV1 +1;
            
            WriteFile <<"f "<< v1 <<" "<< nextV1 <<" "<< nextV2 << endl;
            WriteFile <<"f "<< v1 <<" "<< nextV2 <<" "<< v2 <<endl;
            
        }
    }
}
// Create torus
void torus(float r1, float r2, float X, float Y, float Z, int steps, int angle)
{
    float x, y, z;
    float run = ((float)angle/360)*(float)steps;
    
    ofstream WriteFile;
    WriteFile.open("./test.obj",ofstream::out);
    
    float phi, theta;
    
    for(int j = 0; j <= steps ; j++)
    {
        phi = (float)j * ((2*M_PI)/steps);
        for(int i = 0; i <= steps; i++)
        {
            theta = (float)i * ((2*M_PI)/steps);
            x = (r1 + r2*cos(phi))*cos(theta) + X;
            y = (r1 + r2*cos(phi))*sin(theta) + Y;
            z = r2*sin(phi) + Z;
            WriteFile <<"v "<< x <<" "<< y <<" "<< z << endl;
        }
    }
   
    cout << run << endl;
    
    for(int i = 0;i < steps; i++)//number of circle
    {
        for(int j = 0;j < run; j++)//number vertex on a circle
        {
            int v1 = i*(steps+1)+j+1;
            int nextV1 = (i+1)*(steps+1)+j+1;
            int v2 = v1+1;
            int nextV2 = nextV1 +1;
            
            WriteFile <<"f "<< v1 <<" "<< nextV2 <<" "<< nextV1 << endl;
            WriteFile <<"f "<< v1 <<" "<< v2 <<" "<< nextV2 <<endl;
            
        }
    }
}
// Create sphere
void sphere(float r, float X, float Y, float Z, int steps)
{
    float x, y, z;
    
    ofstream WriteFile;
    WriteFile.open("./test.obj",ofstream::out);
    
    float phi, theta;
    
    theta = 0.0*2*M_PI/steps;
    phi = 0.0*M_PI/steps - M_PI_2;
    x = r*cos(phi)*cos(theta) + X;
    y = r*cos(phi)*sin(theta) + Y;
    z = r*sin(phi) + Z;
    WriteFile <<"v "<< x <<" "<< y <<" "<< z << endl;
    
    theta = steps*2*M_PI/steps;
    phi = steps*M_PI/steps - M_PI_2;
    x = r*cos(phi)*cos(theta) + X;
    y = r*cos(phi)*sin(theta) + Y;
    z = r*sin(phi) + Z;
    WriteFile <<"v "<< x <<" "<< y <<" "<< z << endl;
    
    for(int j = 0; j <= steps; j++)
    {
        phi = j*M_PI/steps - M_PI_2;
        for(int i = 0; i <= steps; i++)
        {
            theta = i*2*M_PI/steps;
            x = r*cos(phi)*cos(theta) + X;
            y = r*cos(phi)*sin(theta) + Y;
            z = r*sin(phi) + Z;
            WriteFile <<"v "<< x <<" "<< y <<" "<< z << endl;
        }
    }
    
    for(int j=0;j<steps;j++)
    {
        int v1 = 0*(steps+1)+j+2;
        int v2 = v1+1;
        WriteFile <<"f "<< 1 <<" "<< v1 <<" "<< v2 << endl;
    }
    
    for(int i=0;i<steps;i++)//number of circle
    {
        for(int j=0;j<=steps;j++)//number vertex on a circle
        {
            int v1 = i*(steps+1)+j+1;
            int nextV1 = (i+1)*(steps+1)+j+1;
            int v2 = v1+1;
            int nextV2 = nextV1 +1;
            
            WriteFile <<"f "<< v1 <<" "<< nextV2 <<" "<< nextV1 << endl;
            WriteFile <<"f "<< v1 <<" "<< v2 <<" "<< nextV2 <<endl;
            
        }
    }
    
    for(int j=0;j<steps;j++)
    {
        int v1 = (steps*2-1)*(steps+1)+j+2;
        int v2 = v1+1;
        WriteFile <<"f "<< 0 <<" "<< v1 <<" "<< v2 << endl;
    }
    
    //ReadFile.close();
    WriteFile.close();
}

