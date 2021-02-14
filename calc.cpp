#include <iostream>
#include <math.h>

void add(double n1_1,double n1_2, double n2_1, double n2_2, double array[]);
void phase(double n1, double n2, double array[]);
void imaginary(double n1, double n2, double array[]);
double degree(double n1);
double rad(double n1);

int main (int argc, char *argv[]){
    std::string select = argv[1];
    char *p;
    double num1_1 = std::strtod(argv[2], &p);
    double num1_2 = std::strtod(argv[3], &p); 
    //double num2_1 = std::strtod(argv[4], &p);
    //double num2_2 = std::strtod(argv[5], &p);

    std::cout<< select << " " << num1_1 << " " << num1_2 << " " <<  std::endl;

    double array[4] = {0,0,0,0};
    if(select == "p"){//phase and magnitude       
        phase(num1_1,num1_2, array);
        double mag = array[0];
        double phase = array[1];

        std::cout << mag << " <" << phase << std::endl;
    }
    else if(select == "i"){//x+jy
        imaginary(num1_1,num1_2,array);
        double x = array[0];
        double y = array[1];

        std::cout << x << "+ j" << y << std::endl;
    }
    else {
        double num2_1 = std::strtod(argv[4], &p);
        double num2_2 = std::strtod(argv[5], &p);

        if(select == "a"){
            add(num1_1, num1_2, num2_1, num2_2, array);
            double x = array[0];
            double y = array[1];

            std::cout << x << "+ j" << y << std::endl;
        }
    }
    return 0;
}
void add(double n1_1,double n1_2, double n2_1, double n2_2, double array[]){
    imaginary(n1_1, n1_2, array);
    double x = array[0];
    double y = array[1];
    imaginary(n2_1, n2_2, array);
    x = x + array[0];
    y = y + array[1];

    array[0] = x;
    array[1] = y;
}

void phase(double n1, double n2, double array[]){
    double mag = sqrt((pow(n1,2))+(pow(n2,2)));
    double phase = degree(atan(n2/n1));
    if(n1 < 0)phase+=180;
    array[0] = mag;
    array[1] = phase;
}
void imaginary(double n1, double n2, double array[]){
    double phi = rad(n2);
    double x = n1*(cos(phi));
    double y = n1*(sin(phi));

    array[0] = x;
    array[1] = y;
}

//math calc only works with rad.
double degree(double n1){ //takes rad and converts to degree
    return (n1*180/3.14159265);
}
double rad(double n1){ // takes degree converts to rad
    return (n1*3.14159265/180);
}