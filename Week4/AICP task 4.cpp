#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

    float area;
	int peri;
	int a=120;          //one angle of hexagon=120
	int angle;  
	 
class hexagon{
	
public:
	
void calcArea(int lastDigit){        //Area of hexagon

	area=1.5 * 1.732 * pow(lastDigit,2);       //Area of hexagon= 1.5*1.732*s 
}
void calcPeri(int lastDigit){
	
	peri=6*lastDigit;               //perimeter of hexagon= 6*s
}
void calcAngleSum(){
	
	angle=6*a;                     //Sum of all the angles of hexagon= 6*a
}

void display(){                   //display Hexagon measurements
    std::cout<<"\t\t\t\t ------------------------------------------"<<std::endl;
    std::cout<<"\t\t\t\t|\t Hexagon Measurements\t\t   |"<<std::endl;
	std::cout<<"\t\t\t\t|\t\t\t\t\t   |"<<std::endl;
    std::cout<<"\t\t\t\t| Area of Hexagon: "<<area<<"\t\t   |"<<std::endl;
	std::cout<<"\t\t\t\t| Perimeter of Hexagon:"<<peri<<"\t\t   |"<<std::endl;
	std::cout<<"\t\t\t\t| Sum of all angles of Hexagon:"<<angle<<"\t   |";
	std::cout<<"\n\t\t\t\t|\t\t\t\t\t   |"<<std::endl;
	std::cout<<"\t\t\t\t ------------------------------------------"<<std::endl;	  
}
};

//Length of one side of square=last digit of CNIC + 1
//Length of one side of square 6+1=7
class square{
	
public:
	
void calcAreaSquare(int length){
	
   area=pow(length,2);	     //Area of square= (length)2
}
void calcPeriSquare(int length){
	
   peri=(length)*4;     //4*length	
}
void display1(){        //display square measurements

	std::cout<<"\t\t\t\t------------------------------------"<<std::endl;
	std::cout<<"\t\t\t\t|\t Square Measurements\t   |"<<std::endl;
	std::cout<<"\t\t\t\t|\t\t\t\t   |"<<std::endl;
    std::cout<<"\t\t\t\t|  Area of Square: "<<area<<"\t\t   |"<<std::endl;
	std::cout<<"\t\t\t\t| Perimeter of Square:"<<peri<<"\t   |";
	std::cout<<"\n\t\t\t\t|\t\t\t\t   |"<<std::endl;
	std::cout<<"\t\t\t\t------------------------------------"<<std::endl;	
}
};

void displayMenu(){      //Main Display 

	std::cout << "\n\n\t\t\t\t\t\tMain Display:" << std::endl;
	std::cout << "\t\t\t\t\tPlease select any option"<<std::endl;
	std::cout << "\t\t\t\t ********************************************"<<std::endl;
    std::cout << "\t\t\t\t|  1.Enter 1 to calculate the\t\t     |" << std::endl;
    std::cout << "\t\t\t\t|\t-----------------------------\t     |"<<std::endl;
    std::cout << "\t\t\t\t|\t Area of Hexagon\t\t     |" << std::endl;
    std::cout << "\t\t\t\t|\t Perimeter of Hexagon\t\t     |" << std::endl;
    std::cout << "\t\t\t\t|\t Sum of all angles of Hexagon\t     |" << std::endl;
    std::cout << "\t\t\t\t|\t\t\t\t\t     |"<<std::endl;
    std::cout << "\t\t\t\t|\t-----------------------------\t     |"<<std::endl;
    std::cout << "\t\t\t\t|\t\t\t\t\t     |"<<std::endl;
    std::cout << "\t\t\t\t|  2.Enter 2 to calculate the\t\t     |" << std::endl;
    std::cout << "\t\t\t\t|\t-----------------------------\t     |"<<std::endl;
    std::cout << "\t\t\t\t|\t Area of Square\t\t\t     |" << std::endl;
    std::cout << "\t\t\t\t|\t Perimeter of Square\t\t     |" << std::endl;
    std::cout << "\t\t\t\t|\t Sum of all angles of Square\t     |" << std::endl;
    std::cout << "\t\t\t\t|\t-----------------------------\t     |"<<std::endl;
    std::cout << "\t\t\t\t| Press any other key to exit\t\t     |" << std::endl;
    std::cout << "\t\t\t\t|\t\t\t\t\t     |"<<std::endl;
    std::cout << "\t\t\t\t ********************************************"<<std::endl;
}

int main(){
	
	hexagon hexagon1;
	square square1;
	 int lastDigit;
    char choice;
    
    std::cout << "\n\t\t\t\tEnter the last digit of your CNIC: ";
    std::cin >> lastDigit;
    
    int length=(lastDigit+1);
    
    do {
        displayMenu();
        std::cout << "\t\t\t\t";
        std::cin >> choice;
        switch (choice) {
            case '1':
            	 hexagon1.calcArea(lastDigit);
            	 hexagon1.calcPeri(lastDigit);
            	 hexagon1.calcAngleSum();
            	 hexagon1.display();
                break;
            case '2':
            	square1.calcAreaSquare(length);
            	square1.calcPeriSquare(length);
            	square1.display1();
                break;
            default:
                std::cout << "Exiting the program." << std::endl;
                return 0;
        }
    } while (true);

    return 0;
}


