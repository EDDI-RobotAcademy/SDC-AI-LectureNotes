#ifndef PRODUCT_H
#define PRODUCT_H

#ifdef __cplusplus
extern "C" {
#endif

struct Product {
    int productID;
    double price;
    char productName[100];
    char description[500];
};

struct Product createProduct(int id, double price, const char* name, const char* description);
void printProduct(const struct Product *product);

#ifdef __cplusplus
}
#endif

#endif // PRODUCT_H