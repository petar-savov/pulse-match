#include "../include/header.h"
#include <iostream>

struct Order {
  int id;
  int quantity;
};

void matchOrders(Order buyOrder, Order sellOrder) {
  if (buyOrder.quantity > sellOrder.quantity) {
    std::cout << "Matched order: Buy Order " << buyOrder.id
              << " with Sell Order " << sellOrder.id << std::endl;
    buyOrder.quantity -= sellOrder.quantity;
    sellOrder.quantity = 0;
  } else if (buyOrder.quantity < sellOrder.quantity) {
    std::cout << "Matched order: Buy Order " << buyOrder.id
              << " with Sell Order " << sellOrder.id << std::endl;
    sellOrder.quantity -= buyOrder.quantity;
    buyOrder.quantity = 0;
  } else {
    std::cout << "Matched order: Buy Order " << buyOrder.id
              << " with Sell Order " << sellOrder.id << std::endl;
    buyOrder.quantity = 0;
    sellOrder.quantity = 0;
  }
}

int main() {
  Order buyOrder = {1, 10};
  Order sellOrder = {2, 5};

  matchOrders(buyOrder, sellOrder);

  std::cout << "Remaining quantity of Buy Order " << buyOrder.id << ": "
            << buyOrder.quantity << std::endl;
  std::cout << "Remaining quantity of Sell Order " << sellOrder.id << ": "
            << sellOrder.quantity << std::endl;

  return 0;
}