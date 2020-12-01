#include<iostream>
#include "Sales_data.h"

int main(){
    /*Sales_data item;
    double price;
    std::cin>>item.bookNo>>item.units_sold>>price;
    item.revenue = item.units_sold * price;
    std::cout<<item.bookNo<<" "<<item.units_sold<<" "<<item.revenue<<std::endl;*/

    /*Sales_data item1, item2;
    double price1, price2;
    std::cin>>item1.bookNo>>item1.units_sold>>price1;
    item1.revenue = item1.units_sold * price1;
    std::cin>>item2.bookNo>>item2.units_sold>>price2;
    item2.revenue = item2.units_sold * price2;
    std::cout<<item1.bookNo<<" "<<item1.units_sold+item2.units_sold<<" "<<item1.revenue+item2.revenue<<std::endl;*/

    /*Sales_data total;
    double price;
    if(std::cin>>total.bookNo>>total.units_sold>>price){
        total.revenue = total.units_sold*price;
        Sales_data trans;
        double p;
        while(std::cin>>trans.bookNo>>trans.units_sold>>p){
            trans.revenue = trans.units_sold*p;
            if(trans.bookNo==total.bookNo){
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            }
            else{
                std::cout<<total.bookNo<<" "<<total.units_sold<<" "<<total.revenue<<std::endl;
                total = trans;
            }
        }
        std::cout<<total.bookNo<<" "<<total.units_sold<<" "<<total.revenue<<std::endl;
    }*/

    /*Sales_data currItem, item;
    double price, p;
    if(std::cin>>currItem.bookNo>>currItem.units_sold>>price){
        currItem.revenue = currItem.units_sold*price;
        int cnt=1;
        while(std::cin>>item.bookNo>>item.units_sold>>p){
            item.revenue = item.units_sold*p;
            if(currItem.bookNo==item.bookNo){
                cnt++;
            }
            else{
                std::cout<<currItem.bookNo<<" occurs "<<cnt<<" times"<<std::endl;
                currItem = item;
                cnt = 1;
            }
        }
        std::cout<<currItem.bookNo<<" occurs "<<cnt<<" times"<<std::endl;
    }*/

    Sales_data total;
    double price;
    if(std::cin>>total.bookNo>>total.units_sold>>price){
        total.revenue = total.units_sold*price;
        Sales_data trans;
        double p;
        while(std::cin>>trans.bookNo>>trans.units_sold>>p){
            trans.revenue = trans.units_sold*p;
            if(total.bookNo==trans.bookNo){
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            }
            else{
                std::cout<<total.bookNo<<" "<<total.units_sold<<" "<<total.revenue<<std::endl;
                total = trans;        
            }
        }
        std::cout<<total.bookNo<<" "<<total.units_sold<<" "<<total.revenue<<std::endl;
    }

    else{
        std::cerr<<"No data?!"<<std::endl;
        return -1;
    }

    return 0;
}