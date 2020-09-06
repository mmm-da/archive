from django.contrib import admin

from .models import ContactData,Custumer,Employee,Order,Product,Shop,Supplier,Product_Order,Product_Shop

admin.site.register(ContactData)
admin.site.register(Custumer)
admin.site.register(Employee)
admin.site.register(Order)
admin.site.register(Product)
admin.site.register(Shop)
admin.site.register(Supplier)
admin.site.register(Product_Order)
admin.site.register(Product_Shop)