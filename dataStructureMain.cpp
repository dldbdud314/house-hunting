#include <iostream>
#include "PopulationDensity.cpp"
#include "PublicSecurity.cpp"
#include "Amenities.cpp"
#include "PublicTransportation.cpp"
#include "rent.cpp"
using namespace std;

int main() {
   string condition; //�����Է��ϴ�string 
      
   while(true){
         cout<<"���Ͻô� ������ �Է��� �ּ���(����, ����, ġ��, ����, �α��е� �� ��)";
         cin>>condition;
         
      if(condition!="����"&&condition!="����"&&condition!="ġ��"&&condition!="����"&&condition!="�α��е�") {
            cout<<"�ٽ� �Է��� �ּ���. . ."<<endl; 
            cout<<" "<<endl;
            continue;
         }
         cout<<"����ڰ� ������ ���� >>"<<" "<<condition<<endl;
         cout<<"������ Y, Ʋ���� N�� �Է��� �ּ���."<<endl;
      
      string userinput;
      
         cin>>userinput;
         
         if(userinput=="N" || userinput=="n"){
           cout<<"ó������ ���ư��ϴ�. . ."<<endl;
           cout<<" "<<endl;
          continue;
           }
           cout<<" "<<endl;
       if(condition=="����"){
        Rent rent;
        rent.getRent();
         
      //��������(�ּ� �ִ�) �Է�
      int minRent, maxRent; 
         
      cout << "����ڰ� ���ϴ� �ּ� ������ �Է��Ͻÿ�. (�ּ� ������ ";
      rent.minRent();
      cout<<"�Դϴ�)"<<endl; 
      cout<<"�ּ� ������ �Է��Ͻÿ�:"; 
      cin >> minRent;
      cout << "�ִ� ������ �Է��Ͻÿ�:";
      cin >> maxRent;
         
      //���������� �����ϴ� �� ��� 
      rent.printGu(minRent, maxRent);
   
   }
   else if(condition == "����"){
      PublicTransportation subway;
      subway.getSubwayStationNum();
      subway.sortSubwayStationNum(); //����ö�� ���� 5�� ��� 
      cout << endl;
         
      PublicTransportation bus;
      bus.getBusStationNum();
      bus.sortBusStationNum(); //���������� ���� 5�� ���   
      cout<<endl;   
   }
   else if(condition == "ġ��"){
         PublicSecurity crime;
         crime.getCrimeNum();
         crime.sortCrimeNum(); //���˹߻��Ǽ��� ���� 3�� ��� 
         cout << endl;
         
         PublicSecurity cctv;
         cctv.getCCTVNum();
         cctv.sortCCTVNum(); //CCTV�� ���� 3�� ���    
         cout<<endl;   
   }
   else if(condition == "�α��е�"){
      PopulationDensity population;
      population.getPopulationDensity();
          
      //��������(�ּ� �ִ�) �Է�
      int minPopulation, maxPopulation;
      cout << "����ڰ� ���ϴ� �ּ�ġ�� �Է��Ͻÿ�(�ּ�ġ��"<<" ";
      population.minpopulationDensity();
      cout<<"�Դϴ�)"<<endl;
      cout<<"�ּ�ġ�� �Է��Ͻÿ�:" ;
      cin >> minPopulation;
      cout << "�ִ�ġ�� �Է��Ͻÿ�:";
      cin >> maxPopulation;
         
      //���������� �����ϴ� �� ��� 
      population.printGu(minPopulation, maxPopulation);   
      cout<<endl;   
   }
   else if(condition == "����"){
      Amenities conv;
      conv.getConvienienceStoreNum();
      conv.sortConvienienceStoreNum(); //�������� ���� 5�� ��� 
      cout << endl;
         
      Amenities movies;
      movies.getTheaterNum();
      movies.sortTheaterNum(); //��ȭ���� ���� 5�� ��� 
      cout<<endl;         
   }
   cout<<endl; 
   cout<<"�� �˾ƺ��� ������ RE�� �׸� �˾ƺ��� ������ ESC�� �Է��� �ּ���."<<endl;
   string userchoice;
   cin>>userchoice;
   
   if(userchoice=="RE" || userchoice=="re"){
      cout<<" "<<endl;
         continue;
     }
   else if(userchoice=="ESC" || userchoice=="esc"){
      cout<<"�����մϴ�.";
         break;
        }
        
   return 0;
}
}
