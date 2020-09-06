from django.http import HttpResponse
from django.template import loader
from django.shortcuts import render,redirect
from .forms import ProductForm
from .models import ContactData,Custumer,Employee,Order,Product,Shop,Supplier,Product_Order,Product_Shop
import datetime

def index(request):
    template = loader.get_template('index.html')
    context = {}
    return HttpResponse(template.render(context,request))

def product_details(request,product_id):
    product = Product.objects.raw(
        '''SELECT * FROM lab6_7_product
                WHERE 
                    lab6_7_product.id = %d'''%product_id
    )
    
    template = loader.get_template('product_details.html')
    context = {
        'product': product[0]
    }
    return HttpResponse(template.render(context,request))

def products(request):
    products = Product.objects.raw('SELECT * FROM lab6_7_product')
    template = loader.get_template('products.html')
    context = {
        'products': products
    }
    return HttpResponse(template.render(context,request))

def product_add(request):
    if request.method == "POST":
        form = ProductForm(request.POST)
        if form.is_valid():
            product = form.save(commit=False)
            product.supply_date = datetime.datetime.now()
            product.save()
    else:
        form = ProductForm()
        
    return render(request, 'product_add.html', {'form': form})