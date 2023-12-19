//
// Created by eddi on 23. 12. 15.
//

#include "product.h"
#include <stdio.h>
#include <stdlib.h>

struct Product createProduct(int id, double price, const char* name, const char* description) {
    struct Product newProduct;
    newProduct.productID = id;
    newProduct.price = price;
    snprintf(newProduct.productName, sizeof(newProduct.productName), "%s", name);
    snprintf(newProduct.description, sizeof(newProduct.description), "%s", description);
    return newProduct;
}

void printProduct(const struct Product *product) {
    printf("Product ID: %d\n", product->productID);
    printf("Price: %.2f\n", product->price);
    printf("Product Name: %s\n", product->productName);
    printf("Description: %s\n", product->description);
    printf("\n");
}