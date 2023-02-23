#include <string>
using namespace std;
class Item
{
public:
    Item(string item_description, double item_price);
};

class Order
{
public:
    Order(string customer_name, string item_description, double item_price);
private:
    Item article;
    string customer;
};

Order::Order(string customer_name, string item_description, double item_price)
        : article(item_description, item_price), customer(customer_name)
{
}