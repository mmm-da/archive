from django.db import models

class ContactData(models.Model):
    phone = models.CharField(max_length= 255,blank = False)
    first_name = models.CharField(max_length= 255,blank = False)
    second_name = models.CharField(max_length= 255,blank = False)
    email = models.CharField(max_length= 255)

class Custumer(models.Model):
    contact_data = models.ForeignKey(ContactData,models.CASCADE)
    discount = models.CharField(max_length= 255)

class Employee(models.Model):
    contact_data = models.ForeignKey(ContactData,models.CASCADE)
    shop = models.ForeignKey('Shop',models.CASCADE)
    post = models.CharField(max_length= 255)

class Order(models.Model):
    employee = models.ForeignKey(Employee,models.CASCADE)
    custumer = models.ForeignKey(Custumer,models.CASCADE)
    order_date = models.DateTimeField()
    cart = models.ManyToManyField(
        'Product',
        through='Product_Order',
        through_fields=('order','product')
    )

class Product(models.Model):
    supplier = models.ForeignKey('Supplier',models.CASCADE)
    price = models.PositiveIntegerField(default=0)
    name = models.CharField(max_length= 500)
    supply_date = models.DateTimeField()
    amount = models.PositiveIntegerField(default=0)
    
class Shop(models.Model):
    adress = models.CharField(max_length= 500,blank = False)
    warehouse = models.ManyToManyField(
        Product,
        through='Product_Shop',
        through_fields=('shop','product')
    )

class Supplier(models.Model):
    adress = models.CharField(max_length= 500,blank = False)

class Product_Shop(models.Model):
    shop = models.ForeignKey(Shop,on_delete = models.CASCADE)
    product = models.ForeignKey(Product,on_delete = models.CASCADE)
    count = models.PositiveIntegerField(default=0)

class Product_Order(models.Model):
    order = models.ForeignKey(Order,on_delete = models.CASCADE)
    product = models.ForeignKey(Product,on_delete = models.CASCADE)
    count = models.PositiveIntegerField(default=0)