from django import forms
from .models import Product,Supplier

class ProductForm(forms.ModelForm):
    class Meta:
        model = Product
        fields = ('name','price','amount','supplier','supply_date')